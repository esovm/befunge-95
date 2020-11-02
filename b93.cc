#include <cstdio>
#include <cinttypes>
#include <string_view>
#include <array>
#include <vector>
#include <random>

namespace
{
    constexpr std::size_t max_row_size = 25;
    constexpr std::size_t max_col_size = 80;
    
    struct grid_t 
    { 
        std::array<char, max_row_size * (max_col_size + 1)> data; 
        std::size_t rows = max_row_size; 
        std::size_t cols = max_col_size + 1; 
    };
    
    grid_t readfile(std::string_view filepath)
    {
        grid_t result = {};
        
        /* open a file for reading */
        if(std::FILE * const file = std::fopen(filepath.data(), "r"); file != nullptr) 
        {
            /* read the file into a buffer */
            std::array<char, max_row_size * max_col_size> data = {};
            std::size_t const bytes_read = std::fread(data.data(), 1, data.size(), file);

            /* copy the buffer to the result */
            for(std::size_t i = 0, j = 0, cols = 0; i < bytes_read; ++i, ++j)
            {
                /* skip charecters that are not a unicode code point */
                if((reinterpret_cast<unsigned char*>(data.data())[i] & 0xC0u) == 0x80u) 
                {
                    --j;
                    continue;
                }

                /* for every newline increase the row count */
                if(data[i] == '\n')
                {
                    j += result.cols - cols - 1;
                    cols = 0;
                    continue;
                }

                ++cols;
                result.data[j] = data[i];
            }

            /* close the file */
            std::fclose(file);
            return result;
        }
        else
        {
            std::fprintf(stderr, "Error: could not open %s", filepath.data());
            std::exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char **argv)
{
    for (int i = 0; i + 1 < argc; ++i)
    {
        bool extensions = false;
        if(std::string_view argv_sv = std::string_view{argv[i + 1]}; argv_sv.substr(0, 12) == "--extensions")
        {
            if (argv_sv.find("true", 12) != std::string_view::npos)
            {
                extensions = true;
            }
            else if (argv_sv.find("false", 12) != std::string_view::npos)
            {
                extensions = false;
            }
            else
            {
                std::fprintf(stderr, "Error: invalid arguments\n");
                return EXIT_FAILURE;
            }

            i += 1;
            if(i + 1>= argc)
            {
                std::fprintf(stderr, "Error: exptected a file\n");
                return EXIT_FAILURE;
            }
        }

        auto[data, rows, cols] = readfile(argv[i + 1]);

        /* create a stack */
        std::vector<std::int32_t> stack;
        auto push = [&](std::int32_t value) -> void { stack.push_back(value); };
        auto pop = [&]() -> std::int32_t
        {
            if (stack.empty())
            {
                return 0;
            } 
            else
            {
                std::int32_t temp = stack.back();
                stack.pop_back();
                return temp;
            }
        };

        /* hold the position of the cursor and the direction of it */
        std::array<std::ptrdiff_t, 2> pos = {}, dir = {1, 0};
        auto move = [&, cols = cols, rows = rows]() -> void
        {
            pos[0] = ((pos[0] + dir[0]) % cols + cols) % cols;
            pos[1] = ((pos[1] + dir[1]) % rows + rows) % rows;
        };

        /* setup an prng */
        std::mt19937 engine{std::random_device{}()};
        std::uniform_int_distribution <std::int32_t> dist{0, 3};

        for (;;)
        {
            /* see https://catseye.tc/view/Befunge-93/doc/Befunge-93.markdown for what every instruction means */
            switch (char ins = data[pos[1] * cols + pos[0]])
            {
                case '+':
                {
                    push(pop() + pop());
                } break;

                case '-':
                {
                    std::int32_t a = pop();
                    std::int32_t b = pop();
                    push(b - a);
                } break;

                case '/':
                {
                    std::int32_t a = pop();
                    std::int32_t b = pop();
                    push(b / a);
                } break;

                case '*':
                {
                    push(pop() * pop());
                } break;

                case '%':
                {
                    std::int32_t a = pop();
                    std::int32_t b = pop();
                    push(b % a);
                } break;

                case '!':
                {
                    if (stack.empty())
                    {
                        /* 0 == 0 is true */
                        push(1);
                    } 
                    else
                    {
                        stack.back() = stack.back() == 0;
                    }
                } break;

                case '`':
                {
                    std::int32_t a = pop();
                    std::int32_t b = pop();
                    push(b > a);
                } break;

                case '^':
                {
                    north:
                    dir[1] = -1;
                    dir[0] = 0;
                } break;

                case 'v':
                {
                    south:
                    dir[1] = 1;
                    dir[0] = 0;
                } break;

                case '>':
                {
                    east:
                    dir[1] = 0;
                    dir[0] = 1;
                } break;

                case '<':
                {
                    west:
                    dir[1] = 0;
                    dir[0] = -1;
                } break;

                case '_':
                {
                    bool value = pop() != 0;
                    if (value) goto west;
                    else goto east;
                } break;

                case '|':
                {
                    bool value = pop() != 0;
                    if (value) goto north;
                    else goto south;
                } break;

                case '"':
                {
                    move();

                    /* while the current ch is not a quote push its ascii value */
                    for (;;)
                    {
                        if (char ch = data[pos[1] * cols + pos[0]]; ch != '"')
                        {
                            push(ch);
                            move();
                        } 
                        else
                        {
                            break;
                        }
                    }
                } break;

                case ':':
                {
                    push(stack.empty() ? 0 : stack.back());
                } break;

                case '\\':
                {
                    /* NOTE: this is needed because the \ op
                     * is the same as:
                     * a = pop()
                     * b = pop()
                     * push(a)
                     * push(b)
                     */
                    switch (stack.size())
                    {
                        default:
                        {
                            std::swap(stack.end()[-1], stack.end()[-2]);
                        } break;

                        case 0: break;

                        case 1:
                        {
                            push(0);
                        } break;
                    }
                } break;

                case '$':
                {
                    pop();
                } break;

                case '.':
                {
                    std::int32_t value = pop();
                    std::printf("%" PRId32 " ", value);
                } break;

                case ',':
                {
                    char value = static_cast<char>(pop());
                    std::printf("%c", value);
                } break;

                case '#':
                {
                    move();
                } break;

                case 'g':
                {

                    std::ptrdiff_t y = static_cast<std::ptrdiff_t>(pop());
                    std::ptrdiff_t x = static_cast<std::ptrdiff_t>(pop());

                    push(x >= 0 && x < static_cast<std::ptrdiff_t>(max_col_size) &&
                         y >= 0 && y < static_cast<std::ptrdiff_t>(max_row_size)
                         ? data[y * cols + x] : 0);
                } break;

                case 'p':
                {
                    std::ptrdiff_t y = (static_cast<std::ptrdiff_t>(pop()));
                    std::ptrdiff_t x = (static_cast<std::ptrdiff_t>(pop()));
                    std::int32_t value = pop();

                    /* check for out of bounds */
                    if(x >= 0 && x < static_cast<std::ptrdiff_t>(max_col_size) &&
                       y >= 0 && y < static_cast<std::ptrdiff_t>(max_row_size))
                    {
                        data[y * cols + x] = value;
                    }
                } break;

                case '&':
                {
                    std::int32_t value;
                    std::scanf("%" SCNi32, &value);
                    push(value);
                } break;

                case '~':
                {
                    char value;
                    std::scanf("%c", &value);
                    push(value);
                } break;

                /* exit the program */
                case '@': goto end_of_loop;

                /* for a number push its numeric value onto the stack */
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                {
                    push(ins - '0');
                } break;

                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                {
                    if (!extensions) break;

                    push(ins - 'a' + 10);
                } break;

                case '?':
                {
                    switch (dist(engine))
                    {
                        case 0: goto north;
                        case 1: goto south;
                        case 2: goto east;
                        case 3: goto west;
                    }
                } break;

                case '\'':
                {
                    if (!extensions) break;

                    move();
                    push(data[pos[1] * cols + pos[0]]);
                } break;
            }

            move();
        }

        end_of_loop:;
    }
}

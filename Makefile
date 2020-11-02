cxx = clang++
flags = -Ofast -march=native -s -Wall -Wextra -pedantic -std=c++17

all: b93.cc
	$(cxx) $(flags) b93.cc -o b93

clean:
	rm b93

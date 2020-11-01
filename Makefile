cxx = g++
flags = -O2 -Wall -Wextra -pedantic -fanalyzer -std=c++17

all: b93.cc
	$(cxx) $(flags) b93.cc -o main

clean:
	rm main

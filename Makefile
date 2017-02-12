all:
	clang++ main.cpp EnterA.cpp Command.cpp Sign.cpp Word.cpp Register.cpp Memory.cpp Machine.cpp -std="c++14" -o mix

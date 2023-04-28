opt = -c -Wall -Wextra -std=c11

test_permutation.exe : test_permutation.o p_permutation.o p_base.o
	gcc -o test_permutation.exe test_permutation.o p_permutation.o p_base.o

p_permutation.o : p_permutation.c p_permutation.h
	gcc ${opt} p_permutation.c

test_permutation.o : test_permutation.c p_permutation.h
	gcc ${opt} test_permutation.c

p_base.o : p_base.c p_base.h
	gcc ${opt} p_base.c

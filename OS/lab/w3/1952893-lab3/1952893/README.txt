First, type "make all" to compile all the necessary files.
Problem 1:
To view value of Pi using Monte Carlo calculation:
	- Serial : "./pi_serial 1000000" ( 1000000 can be changed to any positive integer)
	- Multi-threaded : "./pi_multi-thread 1000000" ( also, 1000000 can be changed to any positive integer)

Problem 2:
The problem can be fixed with adding "pthread_join(tid[i], NULL);" after pthread_create call.

To view the result of code.c , just type : "./code" if you have already done the first step.
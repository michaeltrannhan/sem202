all: code pi_serial pi_multi-thread

code: code.o
	gcc -pthread -o code code.o

pi_serial: pi_serial.o
	gcc -o pi_serial pi_serial.c 

pi_multi-thread: pi_multi-thread.o
	gcc -fopenmp -o pi_multi-thread pi_multi-thread.c

clean:
	rm -f *.o code pi_serial pi_multi-thread

# all: code.c pi_serial.c pi_multi-thread.c
# 	gcc code.c -c 
# 	gcc pi_serial.c -c 
# 	gcc pi_multi-thread.c -c
# 	gcc *.o -o -pthread code
# 	gcc *.o -o -fopenmp pi_multi-thread
# 	gcc *.o -o pi_serial

# clean:
# 	rm -f *.o code pi_multi-thread pi_serial
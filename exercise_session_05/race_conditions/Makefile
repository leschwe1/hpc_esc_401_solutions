CFLAGS = -O3 -ffast-math -fopenmp
CC = gcc


all: parallel_1 parallel_full parallel_full_atomic_critical serial
serial: serial.c 
	$(CC) $(CFLAGS) serial.c -o serial
parallel_1: parallel_1.c
	$(CC) $(CFLAGS) parallel_1.c -o parallel_1
parallel_full: parallel_full.c
	$(CC) $(CFLAGS) parallel_full.c -o parallel_full
parallel_full_atomic_critical: parallel_full_atomic_critical.c 
	$(CC) $(CFLAGS) parallel_full_atomic_critical.c -o parallel_full_atomic_critical


clean:
	rm -f parallel_1 parallel_full parallel_full_atomic_critical
CFLAGS = -O3 -ffast-math -fopenmp
CC = CC


all: parallel_1 parallel_full
parallel_1: parallel_1.c
	$(CC) $(CFLAGS) parallel_1.c -o parallel_1
parallel_full: parallel_full.c
	$(CC) $(CFLAGS) parallel_full.c -o parallel_full

clean:
	rm -f parallel_1 parallel_full
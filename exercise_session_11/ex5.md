timing output after omp edits (50000):

    3.25user 0.02system 0:00.05elapsed 6433%CPU (0avgtext+0avgdata 8416maxresident)k
    340inputs+0outputs (4major+898minor)pagefaults 0swaps



changed to 500000

    193.34user 0.04system 0:02.06elapsed 9374%CPU (0avgtext+0avgdata 22452maxresident)k
    340inputs+0outputs (4major+4858minor)pagefaults 0swaps




about the times:
- real = elapsed actual time that elapsed while ruinng the program
- user = sum of cpu time across all threads 
- system cpu time spent by os


For N = 50,000, the program ran extremely fast—only 0.05 seconds in real time—because all 128 threads worked together, which is why the CPU time sums to 3.25 seconds and CPU% is over 6,000%.

For N = 500,000, the problem is much bigger, so the program took 2.06 seconds in real time, even though the total CPU time across all threads is 193.34 seconds and CPU% is over 9,300%.

to sum it up real time tells you how long  it ran user time tells us how much total work all cores did, and the high CPU% shows that many threads were running in parallel.



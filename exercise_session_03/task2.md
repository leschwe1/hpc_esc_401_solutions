# Task 2


## first commit:
Results:
-O0: error - ran out of memory while computing!
-O1: ran in approx 0.73s
-O2: ran in qpprox 0.72s
-O3: ran in approx 0.72s 

--> So O0 stopped and ran out of memory, this can be reasoned through the inefficient usage i guess - at least i did not change anything in the whole process exept the flag and the others worked fine

Between the other optimizations, we only see minimal speed-up. But O1 is slower than O2 and O3. Don't know if the code is just too simple to really enhance more through different optimizations? This might cause the minimal differences in timing...


other timings: didn't know any but just looked up clock() from the time.h lib which seems really simple

compiler optimization (had to look this up :) ):
O0: none
O1: basic ones like code removal simplification and allocations
O2: + loop unrolling, subexpression elimination, instruction scheduling, partial inlining
O3 full inining, vectorization, loop fusion, prefetching

--> so my guess from above could be right that all the tools above O1 are just not useful for this short code and thus doesn't speed up the computation 

Make it faster? --> parallelization! or running on more threads


## second commit:
i inserted the line just before the loop, cause that's what we want to speed up. In addition i loaded the module omp.h at the beginning to make the parallelization work 
I compiled on level O3 just to ensure it is maximum fast


so my makefile looks like this:
sum_p: sum_p.c getTime.c getTime.h
        gcc -O3 -fopenmp -o sum_p sum_p.c getTime.c -lm

all: sum_p

clean:
        rm -f sum_p



If you want to have a look on the files: 
Makefile: Make_sum_p
Code file: sum_p.c

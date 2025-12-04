received output:
    
    
    [daint][lschweis@nid006549 convol]$ make
    cc -c main.c
    nvcc -c convol.cu
    nvcc main.o convol.o
    [daint][lschweis@nid006549 convol]$ ls -l
    total 922
    -rwxr-xr-x 1 lschweis uzh8 921384 Nov 25 14:43 a.out
    -rw-r--r-- 1 lschweis uzh8   1891 Nov 25 14:36 convol.cu
    -rw-r--r-- 1 lschweis uzh8  13408 Nov 25 14:43 convol.o
    -rw-r--r-- 1 lschweis uzh8   1643 Nov 24 17:35 main.c
    -rw-r--r-- 1 lschweis uzh8   4016 Nov 25 14:43 main.o
    -rw-r--r-- 1 lschweis uzh8    167 Nov 24 17:35 makefile
    [daint][lschweis@nid006549 convol]$ ./a.out
    Convolution took  0.010894 sec. on GPU
    Convolution took  0.004780 sec. on CPU
    PASSED
    [daint][lschweis@nid006549 convol]$ 

--> passed, so my code should be ok.

we see that the GPU version took roughly twice as long to execute. 
The CPU is porbably faster because the load with N = 1000 and small kernel is not enogh load per thread. With the rather small workload, the overhead gains significance and makes the GPU slower than the CPU; would flip if size / kernel becomes bigger.
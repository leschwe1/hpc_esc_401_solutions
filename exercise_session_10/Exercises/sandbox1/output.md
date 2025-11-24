received output:


    [daint][lschweis@daint-ln002 sandbox1]$ nvcc setvec.cu
    [daint][lschweis@daint-ln002 sandbox1]$ ls -l
    total 901
    -rwxr-xr-x 1 lschweis uzh8 921024 Nov 24 17:49 a.out
    -rw-r--r-- 1 lschweis uzh8   1407 Nov 24 17:49 setvec.cu
    [daint][lschweis@daint-ln002 sandbox1]$ srun -A uzh8 --time=00:30:00 --partition=debug --pty bash
    [daint][lschweis@nid006546 sandbox1]$ ./a.out
    11.000000       11.000000       11.000000       11.000000       11.000000       11.000000       11.000000       11.000000       11.000000       11.000000
    11.000000       11.000000       11.000000       11.000000       11.000000       11.000000       11.000000       11.000000       11.000000       11.000000
    PASSED !!


As i passed; my implementation of the code should be correct
received output:

    [daint][lschweis@daint-ln004 sandbox2]$ srun -A uzh8 --time=00:30:00 --partition=debug --pty bash
    [daint][lschweis@nid006549 sandbox2]$ ls -l
    total 903
    -rw-r--r-- 1 lschweis uzh8   2864 Nov 24 19:33 addongpu.cu
    -rwxr-xr-x 1 lschweis uzh8 920984 Nov 24 19:34 a.out
    [daint][lschweis@nid006549 sandbox2]$ ./a.out
    PASSED
    [daint][lschweis@nid006549 sandbox2]$ 


    --> Passed so my solution should be correct!

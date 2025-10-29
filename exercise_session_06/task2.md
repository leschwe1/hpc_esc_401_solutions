my approximated value:


I ran it twice, one with nproc = 4 and once with nproc = 16 - these are my results:

    [eiger][lschweis@eiger-ln001 exercise_session_06]$ srun -n 4 ./pi_leibnitz
    srun: job 5895025 queued and waiting for resources
    srun: job 5895025 has been allocated resources
    Approximation of pi = 3.141592652589210


    [eiger][lschweis@eiger-ln001 exercise_session_06]$ srun -n 16 ./pi_leibnitz
    srun: job 5895028 queued and waiting for resources
    srun: job 5895028 has been allocated resources
    Approximation of pi = 3.141592652590205
    [eiger][lschweis@eiger-ln001 exercise_session_06]$ 


--> small difference, probably from float rounding which differes because of differen process numbers?  

3.1415926535897932384   correct pi
3.141592652589210       4nproc
3.141592652590205       16nproc

--> less nprocs seems more exact!
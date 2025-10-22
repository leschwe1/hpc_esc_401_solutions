I ran my first version of the code and had these outputs:

    [eiger][lschweis@eiger-ln002 race_conditions]$ export OMP_NUM_THREADS=1
    [eiger][lschweis@eiger-ln002 race_conditions]$ ./parallel_1
    Size of integer array/file: 1000000
    max number in file: 38747
    number of 0s in file: 646016
    true number of 0s in file: 646016
    [eiger][lschweis@eiger-ln002 race_conditions]$ ./parallel_full
    Size of integer array/file: 1000000
    max number in file: 38747
    number of 0s in file: 646016
    true number of 0s in file: 646016
    [eiger][lschweis@eiger-ln002 race_conditions]$ export OMP_NUM_THREADS=2
    [eiger][lschweis@eiger-ln002 race_conditions]$ ./parallel_1
    Size of integer array/file: 1000000
    max number in file: 38747
    number of 0s in file: 646016
    true number of 0s in file: 646016
    [eiger][lschweis@eiger-ln002 race_conditions]$ ./parallel_full
    Size of integer array/file: 1000000
    max number in file: 38747
    number of 0s in file: 646016
    true number of 0s in file: 646016
    [eiger][lschweis@eiger-ln002 race_conditions]$ export OMP_NUM_THREADS=4
    [eiger][lschweis@eiger-ln002 race_conditions]$ ./parallel_1
    Size of integer array/file: 1000000
    max number in file: 38747
    number of 0s in file: 646016
    true number of 0s in file: 646016
    [eiger][lschweis@eiger-ln002 race_conditions]$ ./parallel_full
    Size of integer array/file: 1000000
    max number in file: 38747
    number of 0s in file: 646016
    true number of 0s in file: 646016
    [eiger][lschweis@eiger-ln002 race_conditions]$ export OMP_NUM_THREADS=8
    [eiger][lschweis@eiger-ln002 race_conditions]$ ./parallel_1
    Size of integer array/file: 1000000
    max number in file: 38747
    number of 0s in file: 646016
    true number of 0s in file: 646016
    [eiger][lschweis@eiger-ln002 race_conditions]$ ./parallel_full
    Size of integer array/file: 1000000
    max number in file: 38747
    number of 0s in file: 646016
    true number of 0s in file: 646016


so as i used the reduction version from the start, the output was correct and i never had incorrect outputs.
I never ran into a race situation, it was prevented in this version already.

In addition i then made an extra parallel_full_atomic_critical version as well.
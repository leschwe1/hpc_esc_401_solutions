First run:


    [eiger][lschweis@eiger-ln001 nbody]$ time srun ./nbody

    real    0m16.668s
    user    0m0.017s
    sys     0m0.016s



Second run:

    [eiger][lschweis@eiger-ln001 nbody]$ time srun ./nbody
    srun: job 6056460 queued and waiting for resources
    srun: job 6056460 has been allocated resources

    real    0m30.895s
    user    0m0.015s
    sys     0m0.018s


--> did not work, so I try again a different way:

making a slurm script to time and now it worked

pre change output:

    12.61user 0.00system 0:12.63elapsed 99%CPU (0avgtext+0avgdata 5120maxresident)k
    320inputs+0outputs (2major+616minor)pagefaults 0swaps


post-change output:

    7.19user 0.00system 0:07.20elapsed 99%CPU (0avgtext+0avgdata 4864maxresident)k
    332inputs+0outputs (4major+613minor)pagefaults 0swaps


--> we went down from 12.63 seconds to 7.20 so with the change, the code obviously runs much faster, about 43% faster.
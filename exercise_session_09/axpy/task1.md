# Task 1

**comment on the execution time.**

- OpenMP time remains basically constant for all n except 24, where it takes longer
- same for the openacc, but here, n = 16 is slowest, while the others are at the same speed - this is probably because of the GPU initialization

- the OpenMP is much faster in this case, about factor 10, even in the last  (largest) run, where it takes longer

- cpu variant is probably faster because gpu runtime is increased by data transfer (host - device) which dominates the runtime of the gpu even  if the actual processing is faster 


## Copy of output

    n = 16
    memcopy and daxpy test of size 65536
    -------
    timings
    -------
    axpy (openmp): 0.0622855 s
    axpy (openacc): 0.853402 s

    ============ PASSED
    n = 18
    memcopy and daxpy test of size 262144
    -------
    timings
    -------
    axpy (openmp): 0.0622945 s
    axpy (openacc): 0.709986 s

    ============ PASSED
    n = 20
    memcopy and daxpy test of size 1048576
    -------
    timings
    -------
    axpy (openmp): 0.0618567 s
    axpy (openacc): 0.711268 s

    ============ PASSED
    n = 22
    memcopy and daxpy test of size 4194304
    -------
    timings
    -------
    axpy (openmp): 0.0624101 s
    axpy (openacc): 0.716074 s

    ============ PASSED
    n = 24
    memcopy and daxpy test of size 16777216
    -------
    timings
    -------
    axpy (openmp): 0.105345 s
    axpy (openacc): 0.711597 s

    ============ PASSED
    ~                                  
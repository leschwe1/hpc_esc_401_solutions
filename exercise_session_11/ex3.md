with -fopt-info-vec we get some output during compilation:

    [eiger][lschweis@eiger-ln001 nbody]$ make
    CC -O3 -march=native -ffast-math -fopt-info-vec -g -o nbody nbody.cpp
    nbody.cpp:44:14: optimized: basic block part vectorized using 32 byte vectors
    /usr/include/c++/12/bits/vector.tcc:515:30: optimized: basic block part vectorized using 32 byte vectors
    /usr/include/c++/12/bits/random.tcc:412:42: optimized: loop vectorized using 32 byte vectors
    /usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 32 byte vectors
    /usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 16 byte vectors
    /usr/include/c++/12/bits/vector.tcc:96:27: optimized: basic block part vectorized using 32 byte vectors
    /usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors



This means we have vectorization happening now. Tthe compiler processes 8 interactions in parallel for vectorized parts of the loop. So the structural change worked and vectorization is working


After changes in nbody.cpp according to task 3 to to individual vectors:

    [eiger][lschweis@eiger-ln001 nbody]$ make
    CC -O3 -march=native -ffast-math -fopt-info-vec -g -o nbody nbody.cpp
    /usr/include/c++/12/bits/vector.tcc:699:31: optimized: basic block part vectorized using 32 byte vectors
    /usr/include/c++/12/bits/random.tcc:412:42: optimized: loop vectorized using 32 byte vectors
    /usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 32 byte vectors
    /usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 16 byte vectors
    /usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors
    /usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors


--> the  `basic block part vectorized` is gone as we now have contiguous memory arrays with fully applied vectorization

Runtime:

    7.03user 0.00system 0:07.04elapsed 99%CPU (0avgtext+0avgdata 5128maxresident)k
    320inputs+0outputs (2major+615minor)pagefaults 0swaps



--> so now the code runs even faster than in task 2, but the increase is not crazy. We go from 7.20 to 7.03 seconds of runtime, about 2% faster.

We see a speedup but the vectorization does not cut the sqrtf computing part time as it does not tackle the calculation. That's why the optimization in time is modest

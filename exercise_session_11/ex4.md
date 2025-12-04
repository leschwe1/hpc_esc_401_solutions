after eliminating the divergence:

    [eiger][lschweis@eiger-ln001 nbody]$ make
    CC -O3 -march=native -ffast-math -fopt-info-vec -g -o nbody nbody.cpp
    nbody.cpp:63:31: optimized: loop vectorized using 32 byte vectors
    nbody.cpp:63:31: optimized: loop vectorized using 16 byte vectors
    nbody.cpp:50:27: optimized: loop vectorized using 32 byte vectors
    nbody.cpp:50:27: optimized: loop vectorized using 16 byte vectors
    /usr/include/c++/12/bits/vector.tcc:699:31: optimized: basic block part vectorized using 32 byte vectors
    /usr/include/c++/12/bits/random.tcc:412:42: optimized: loop vectorized using 32 byte vectors
    /usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 32 byte vectors
    /usr/include/c++/12/bits/random.tcc:404:32: optimized: loop vectorized using 16 byte vectors
    /usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors
    /usr/include/c++/12/bits/stl_vector.h:100:4: optimized: basic block part vectorized using 32 byte vectors


--> the compile now has foll vectorization on both split loops. Not basic block part vectorized like before. We are now free of part vectorized elements


Timing:

    1.52user 0.00system 0:01.53elapsed 99%CPU (0avgtext+0avgdata 4928maxresident)k
    320inputs+0outputs (2major+616minor)pagefaults 0swaps


--> Time increase is massive. We go down from 7 secs to 1.52. Eliminating the divergence now put the vectorization done previously to full power and we now compute much faster!
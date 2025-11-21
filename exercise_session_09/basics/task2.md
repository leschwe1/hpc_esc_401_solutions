# Task 2

*to not have to compile twice and run twice, i copied the blur script and made a ".nocopies" version, where i used the nocopies function. this way i could run both variants to compare in one job script at the same time*

**What is the problem with this approach?**

we find a massive overhead as we create many copies. in > buffer > buffer > out = 4 memory allocations. (copyin and copyout)

This dominates runtime --> GPU slowed down

In addition to that, my runs failed. I tried to fix this through boundary conditions, but this was unsuccessful. 

I tried with three different versions (see outputs v1-v3) but was not able to fix it so that it does not fail?
I added the naive function used in each output at the top of each version. the nocopies was not edited.
S

Timing wise, we see that the naive version ran rather slow. All sizes / runs took about 0.7-1 sec
The GPU took almost a second (0.7-0.8) to run in all runs while the host took different amounts of time depending on size. these spread from very quick in small cases to >1sec for big ones. 

**What is the difference with the naive implementation?**

in the nocopies variant, exactly the copying mentioned above is reduced. This speeds up the process. 
With this approch i have success results - i pass the validation 
The new version keeps all data in the GPU and does not need any repeated transfers. Only the final output is copied back instead of the four copies made above.



**What is the difference in execution time?**

The optimized version should perform much faster for above reasons imo. But we cannot see this in the output? Could be for the reason that my naive version is just incorrect but I don't konw where the error is.

So the GPU timing for nocopies is consistent in the 0.7 to 0.8s region. It cannot compete with host for small arrays but the bigger the array becomes, the more beneficial it is to run the GPU version.


So the host timings 


OUTPUT 1

    ===== Running naive GPU version =====
    Running blur 20 100
    dispersion 1D test of length n = 1048580 : 8.00003MB
    item 0 differs (expected, found): 1 != 0
    ==== failure ====
    Host version took 0.0715948 s (0.000715948 s/step)
    GPU version took 0.875967 s (0.00875967 s/step)

    Running blur 16 100
    dispersion 1D test of length n = 65540 : 0.500031MB
    item 0 differs (expected, found): 1 != 0
    ==== failure ====
    Host version took 0.00405556 s (4.05556e-05 s/step)
    GPU version took 0.706194 s (0.00706194 s/step)
    
    Running blur 24 100
    dispersion 1D test of length n = 16777220 : 128MB
    item 0 differs (expected, found): 1 != 0
    ==== failure ====
    Host version took 1.32881 s (0.0132881 s/step)
    GPU version took 1.11581 s (0.0111581 s/step)
    
    Running blur 20 50
    dispersion 1D test of length n = 1048580 : 8.00003MB
    item 0 differs (expected, found): 1 != 0
    ==== failure ====
    Host version took 0.0284438 s (0.000568875 s/step)
    GPU version took 0.711228 s (0.0142246 s/step)
    
    Running blur 20 200
    dispersion 1D test of length n = 1048580 : 8.00003MB
    item 0 differs (expected, found): 1 != 0
    ==== failure ====
    Host version took 0.115532 s (0.000577661 s/step)
    GPU version took 0.743097 s (0.00371548 s/step)




    ===== Running nocopies GPU version =====
    
    Running blur 20 100
    dispersion 1D test of length n = 1048580 : 8.00003MB
    ==== success ====
    Host version took 0.057746 s (0.00057746 s/step)
    GPU version took 0.708416 s (0.00708416 s/step)
    
    Running blur 16 100
    dispersion 1D test of length n = 65540 : 0.500031MB
    ==== success ====
    Host version took 0.00379941 s (3.79941e-05 s/step)
    GPU version took 0.699796 s (0.00699796 s/step)
    
    Running blur 24 100
    dispersion 1D test of length n = 16777220 : 128MB
    ==== success ====
    Host version took 1.2965 s (0.012965 s/step)
    GPU version took 0.887938 s (0.00887938 s/step)
    
    Running blur 20 50
    dispersion 1D test of length n = 1048580 : 8.00003MB
    ==== success ====
    Host version took 0.0294874 s (0.000589748 s/step)
    GPU version took 0.702894 s (0.0140579 s/step)
    
    Running blur 20 200
    dispersion 1D test of length n = 1048580 : 8.00003MB
    ==== success ====
    Host version took 0.119687 s (0.000598435 s/step)
    GPU version took 0.718724 s (0.00359362 s/step)

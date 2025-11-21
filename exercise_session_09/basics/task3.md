# Task 3

**Why is this function prone to race conditions?**
Because all threads on the GPU want to update a single variable which is shared (sum) at the same time. This cannot work

    sum += x[i] * y[i];

This happens as the loop here is parallelized.

**What keyword is used to prevent this?**

we can use the keyword `reduction`. This performs a parallel reduction across the threads and leads to the correct updating and result for sum

**How well does the GPU code perform compared to the CPU version?**
We see here, that the host outperforms the GPU clearly. As the vecors are rather small and fit into CPU cache . To use the GPU would only be beneficial if vectors are much larger and dont fit into CPU cache anymore. Befor this happens it will be better to use the CPU for such a task.



OUTPUT:

    Running dot product on GPU and CPU

    dot product OpenACC of length n = 65536 : 0.5MB
    expected 588374 got 588374: success
    Host kernel took 0.0744573 s
    GPU kernel took 2.81562 s

    dot product OpenACC of length n = 262144 : 2MB
    expected 2.35962e+06 got 2.35962e+06: success
    Host kernel took 0.0628447 s
    GPU kernel took 2.54446 s

    dot product OpenACC of length n = 1048576 : 8MB
    expected 9.44282e+06 got 9.44282e+06: success
    Host kernel took 0.0750759 s
    GPU kernel took 2.56155 s

    dot product OpenACC of length n = 4194304 : 32MB
    expected 3.77762e+07 got 3.77762e+07: success
    Host kernel took 0.0625646 s
    GPU kernel took 2.57355 s

# Task 3


Superlinear = more than linear --> Speedup higher than increase in processors

Seens impossible at first, but reasons for it to happen are
- Cache Use: workload is split --> each processor works on a small piece --> fits well into its cache --> reduces slow memory access --> computation speedup

- Reduced Memory Contention: more processors = access memory more efficient in parallel --> less bottlenecks than with less processors (or single one)

- ALgorithmic effects: splitting problem might change the way of computational behaviour 

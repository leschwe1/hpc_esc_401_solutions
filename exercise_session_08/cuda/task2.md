# comment on the output:


    PI = 3.14159265358979 computed in 0.04853 seconds


output from openacc to compare:



    PI = 3.141592653589793 computed in 1.014 seconds
    PI = 3.141592653589793 computed in 0.00115 seconds
    PI = 3.141592653589793 computed in 0.001141 seconds
    PI = 3.141592653589793 computed in 0.001142 seconds
    PI = 3.141592653589793 computed in 0.001136 seconds


So we can state: 
- the Cuda version only ran once (no loop in code), producing only one output
- The output result is the same as in the openacc version, but missing one decimal place
- execution time is about 0.05s; this is way faster than the initial openacc run but significantly solwer than the openacc runs 2-5
- time diff makes sense as it is explici which is faster for this single run but becomes slower than openacc (as it would take this amount of time for each run) for multiple iterations as openacc profits from the 'ready-system'

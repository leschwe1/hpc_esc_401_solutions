# Interpretation of results

Results found:

the 'normal' version takes about 1.5s to run, while the 'mpi' version is significantly faster and runs in about 0.61seconds.

Reasoning:
The MPI version is faster because the workload is divided in parallel to multiple processes. This isn't the case for the serial cpi version. Through this parallelization speeds the process up but brings some overhead as well, thus we do not find linear speedup 

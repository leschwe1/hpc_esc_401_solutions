**Do you observe any changes in the terminal output compared to usual compilation during the previous sessions?**


--> Yes, I now get a more detail4ed output of the compiling process, which looks as follows in my case:

    [eiger][lschweis@eiger-ln001 nbody]$ make
    CC -O3 -march=native -ffast-math -g -o nbody nbody.cpp
    WARNING: PerfTools is saving object files from a temporary directory into directory '/users/lschweis/.craypat/nbody/97652'
    INFO: creating the PerfTools-instrumented executable 'nbody' (lite-samples) ...OK

In addition to that, a `nbody+orig` file was created, same size as nbody.cpp


and also during the run we get much, much deeper output to the console, including stats
    [eiger][lschweis@eiger-ln001 nbody]$ srun ./nbody
    srun: job 6056068 queued and waiting for resources
    srun: job 6056068 has been allocated resources
    CrayPat/X:  Version 23.12.0 Revision 67ffc52e7 sles15.4_x86_64  11/13/23 21:04:20

    #################################################################
    #                                                               #
    #            CrayPat-lite Performance Statistics                #
    #                                                               #
    #################################################################

    CrayPat/X:  Version 23.12.0 Revision 67ffc52e7 sles15.4_x86_64  11/13/23 21:04:20
    Experiment:                  lite  lite-samples
    Number of PEs (MPI ranks):      1
    Numbers of PEs per Node:        1
    Numbers of Threads per PE:      1
    Number of Cores per Socket:    64
    Execution start time:  Thu Dec  4 10:25:52 2025
    System name and speed:  nid001541  2.260 GHz (nominal)
    AMD   Rome                 CPU  Family: 23  Model: 49  Stepping:  0
    Core Performance Boost:  1 PE has CPB capability


    Avg Process Time: 12.68 secs         
    High Memory:       53.6 MiBytes 53.6 MiBytes per PE

    Notes for table 1:

    This table shows functions that have significant exclusive sample
        hits, averaged across ranks.
    For further explanation, use:  pat_report -v -O samp_profile ...

    Table 1:  Sample Profile by Function

    Samp% |    Samp | Group
            |         |  Function=[MAX10]
        
    100.0% | 1,263.0 | Total
    |------------------------------------
    | 100.0% | 1,263.0 | USER
    ||-----------------------------------
    || 100.0% | 1,263.0 | main
    |====================================

    Notes for table 2:

    This table shows functions, and line numbers within functions, that
        have significant exclusive sample hits, averaged across ranks.
    For further explanation, use:  pat_report -v -O samp_profile+src ...

    Table 2:  Sample Profile by Group, Function, and Line

    Samp% |    Samp | Group
            |         |  Function=[MAX10]
            |         |   Source
            |         |    Line
        
    100.0% | 1,263.0 | Total
    |----------------------------------------------------------------------------
    | 100.0% | 1,263.0 | USER
    ||---------------------------------------------------------------------------
    || 100.0% | 1,263.0 | main
    |||--------------------------------------------------------------------------
    3||  81.9% | 1,035.0 | hpc_esc_401_solutions/exercise_session_11/nbody/nbody.cpp
    ||||-------------------------------------------------------------------------
    4|||   3.7% |    47.0 | line.38
    4|||  22.7% |   287.0 | line.39
    4|||  55.3% |   699.0 | line.40
    ||||=========================================================================
    3||  18.1% |   228.0 | c++/12/bits/stl_vector.h
    4||        |         |  line.386
    |============================================================================

    Observation:  MPI utilization

        No suggestions were made because each node has only one rank.


    Notes for table 3:

    This table shows memory traffic for numa nodes, taking for each numa
        node the maximum value across nodes. It also shows the balance in
        memory traffic by showing the top 3 and bottom 3 node values.
    For further explanation, use:  pat_report -v -O mem_bw ...

    Table 3:  Memory Bandwidth by Numanode

    Memory |    Read |   Write |    Thread |  Memory |  Memory | Numanode
    Traffic |  Memory |  Memory |      Time | Traffic | Traffic | 
    GBytes | Traffic | Traffic |           |  GBytes |       / | 
            |  GBytes |  GBytes |           |   / Sec | Nominal | 
            |         |         |           |         |    Peak | 
    |------------------------------------------------------------------------
    |    0.00 |    0.00 |    0.00 | 12.660538 |    0.00 |    0.0% | numanode.7
    |========================================================================

    Notes for table 4:

    This table shows energy and power usage for the nodes with the
        maximum, mean, and minimum usage, as well as the sum of usage over
        all nodes.
        Energy and power for accelerators is also shown, if available.
    For further explanation, use:  pat_report -v -O program_energy ...

    Table 4:  Program Energy and Power Usage from Cray PM

    Total

    
    ===========================================================
    Total
    -----------------------------------------------------------
    PM Energy Node    215 W     2,730 J
    PM Energy Cpu      55 W       703 J
    PM Energy Memory  121 W     1,536 J
    Process Time            12.679667 secs
    ===========================================================

    Program invocation:
    /users/lschweis/hpc_esc_401_solutions/exercise_session_11/nbody/./nbody

    For a complete report with expanded tables and notes, run:
    pat_report /users/lschweis/hpc_esc_401_solutions/exercise_session_11/nbody/nbody+192479-1757634945s

    For help identifying callers of particular functions:
    pat_report -O callers+src /users/lschweis/hpc_esc_401_solutions/exercise_session_11/nbody/nbody+192479-1757634945s
    To see the entire call tree:
    pat_report -O calltree+src /users/lschweis/hpc_esc_401_solutions/exercise_session_11/nbody/nbody+192479-1757634945s

    For interactive, graphical performance analysis, run:
    app2 /users/lschweis/hpc_esc_401_solutions/exercise_session_11/nbody/nbody+192479-1757634945s

    ================  End of CrayPat-lite output  ==========================



The for the output we get a full folder `nbody+192479-1757634945s`.

ap2-files contains binary results.
- binary performance database used by the GUI tool app2

xf-files contains binary results.
- raw sampling/trace data


rpt-files contains the same as shown in the console output.

**which parts of the code took the most CPU time? Can you make sense of why?**

- 100% of time in main function --> makes sense as that is called and calls other funcs

- Tables 2 reveal that lines 38–40 of nbody.cpp account for ~82% of all samples. These lines correspond to the inner pair-interaction loop of the N-body simulation where distances and gravitational forces are computed. 

    ax += dx * ir3;
    ay += dy * ir3;
    az += dz * ir3;


Another ~18% of samples appear inside stl_vector.h,.

Memory bandwidth is reported as 0 GB/s as we do not collect hardware counter data by default.
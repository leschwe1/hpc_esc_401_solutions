# comment on the output:

Pi has been computed five times in the script. :


    PI = 3.141592653589793 computed in 1.014 seconds
    PI = 3.141592653589793 computed in 0.00115 seconds
    PI = 3.141592653589793 computed in 0.001141 seconds
    PI = 3.141592653589793 computed in 0.001142 seconds
    PI = 3.141592653589793 computed in 0.001136 seconds

All executions come to the exact same result.
In timing, we find differences. The first execution took way longer, > 1 second. the other for execution were all about the same time, rapidly fast at 0.001 s approx. 

These timings make sense. The long first execution is caused by one-time GPU setup (war up), for the rest is rapid fast as te GPU is initialized already (actual computation of first is probably the same but GPU prep is timed as well).
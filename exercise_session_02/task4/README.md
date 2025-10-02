#Process
So I first generated all files:

cpi_omp: compiled in prior tasks
cpi_omp_00_ compiled with compression level 0 (with Makefile00)
Makefile_00: to compile on level 0
run thread1: run file for one thread
run.thread10: run file for ten threads
run.verO0: run one 128threads but with the compilation level zero files.

now i executed all runners.

I checked for errors but all error logs are empty - success

#Conclusion
If we run on one or 10 threads speeds the process up quite a bit. Computation time goes down from 4.5 seconds to 1.2 seconds. But the compilation level has a way larger impact. With O0 we end on a computation time of 23.6 seconds. This is way higher than the other two even if it was run on 128 threads which should be much faster than 1 or ten (thread-wise)

speeds the process up quite a bit. Computation time goes down from 4.5 seconds to 1.2 seconds. But the compilation level has a way larger impact. With O0 we end on a computation time of 23.6 seconds. This is way higher than the other two even if it was run on 128 threads which should be much faster than 1 or ten (thread-wise)




#output thread1
Thread rank: 0
pi is approximately 3.1415926542566006, Error is 0.0000000006668075
Computed in 4.479 seconds

#output thread10
Thread rank: 9
Thread rank: 2
Thread rank: 1
Thread rank: 8
Thread rank: 3
Thread rank: 4
Thread rank: 0
Thread rank: 6
Thread rank: 5
Thread rank: 7
pi is approximately 3.1415926542564856, Error is 0.0000000006666925
Computed in 1.177 seconds

#output verO0
Thread rank: 4
Thread rank: 1
Thread rank: 2
Thread rank: 3
Thread rank: 5
Thread rank: 9
Thread rank: 88
Thread rank: 11
Thread rank: 6
Thread rank: 10
Thread rank: 7
Thread rank: 13
Thread rank: 105
Thread rank: 12
Thread rank: 122
Thread rank: 8
Thread rank: 14
Thread rank: 15
Thread rank: 80
Thread rank: 17
Thread rank: 18
Thread rank: 64
Thread rank: 16
Thread rank: 95
Thread rank: 20
Thread rank: 19
Thread rank: 21
Thread rank: 23
Thread rank: 24
Thread rank: 26
Thread rank: 25
Thread rank: 28
Thread rank: 27
Thread rank: 30
Thread rank: 32
Thread rank: 31
Thread rank: 41
Thread rank: 22
Thread rank: 37
Thread rank: 35
Thread rank: 52
Thread rank: 127
Thread rank: 39
Thread rank: 29
Thread rank: 43
Thread rank: 36
Thread rank: 42
Thread rank: 34
Thread rank: 68
Thread rank: 48
Thread rank: 33
Thread rank: 38
Thread rank: 66
Thread rank: 44
Thread rank: 40
Thread rank: 47
Thread rank: 50
Thread rank: 46
Thread rank: 45
Thread rank: 107
Thread rank: 103
Thread rank: 70
Thread rank: 62
Thread rank: 91
Thread rank: 118
Thread rank: 119
Thread rank: 0
Thread rank: 82
Thread rank: 124
Thread rank: 111
Thread rank: 54
Thread rank: 101
Thread rank: 86
Thread rank: 89
Thread rank: 117
Thread rank: 114
Thread rank: 112
Thread rank: 59
Thread rank: 51
Thread rank: 67
Thread rank: 104
Thread rank: 83
Thread rank: 74
Thread rank: 73
Thread rank: 94
Thread rank: 61
Thread rank: 76
Thread rank: 97
Thread rank: 96
Thread rank: 75
Thread rank: 57
Thread rank: 120
Thread rank: 81
Thread rank: 77
Thread rank: 79
Thread rank: 125
Thread rank: 116
Thread rank: 63
Thread rank: 65
Thread rank: 109
Thread rank: 49
Thread rank: 85
Thread rank: 106
Thread rank: 71
Thread rank: 100
Thread rank: 126
Thread rank: 60
Thread rank: 110
Thread rank: 102
Thread rank: 99
Thread rank: 90
Thread rank: 69
Thread rank: 72
Thread rank: 55
Thread rank: 121
Thread rank: 92
Thread rank: 108
Thread rank: 93
Thread rank: 58
Thread rank: 84
Thread rank: 98
Thread rank: 78
Thread rank: 115
Thread rank: 87
Thread rank: 56
Thread rank: 123
Thread rank: 53
Thread rank: 113
pi is approximately 3.1466615811169425, Error is 0.0050689275271494
Computed in 23.61 seconds

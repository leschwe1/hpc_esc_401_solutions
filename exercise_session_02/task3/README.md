squeue gives a printout which can be customised
What command would you run in order to get the output with following
fields

--> we want to display JOBID USER PRIORITY ACCOUNT NAME NODES ST REASON START_TIME TIME_LEFT PRIORITY

So in the squeue --help if found that we can specify the items via -O 
under squeue --helFormat, we find all the items. so i generate the command

USED COMMAND:
squeue -O jobid,UserName,priority,account,name,numnodes,state,reason,starttime,timeleft,priority

I had to edit user to UserName, nodes to numnodes as looked up on squeue --helpFormat



the cpu-bind=non flag disables pinning --> OpenMP threads run on any available CPU core --> might improve performance

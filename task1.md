**What happens when you run the code? Why?**
So in this first version we have the following issue: all processes try to send simultaneously. But this is not possible as we would need to receive first (SSend blocks until received), before we can send.
So no process is able to send, no process will receive so we are in a deadlock.

**Run the code again. What changed and why did it solve the problem? Is it an optimal solution?**
In this solution now we split the processes into two grops. one sends first, the other one receives first. Thsi breaks the deadlock we had befor as half of the processes are receiving while the others are sending. 
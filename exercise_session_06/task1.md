**ring.c: What happens when you run the code? Why?**
So in this first version we have the following issue: all processes try to send simultaneously. But this is not possible as we would need to receive first (SSend blocks until received), before we can send.
So no process is able to send, no process will receive so we are in a deadlock.

**ring_1.c:Run the code again. What changed and why did it solve the problem? Is it an optimal solution?**
In this solution now we split the processes into two grops. one sends first, the other one receives first. Thsi breaks the deadlock we had befor as half of the processes are receiving while the others are sending. 


**ring_2.c: Why are these methods better solutions than synchronous communication for our ring problem?**
First of all we can see the code is much shorter and less complex. In addition to this, we do not need even/odd ordering anymore, with the now used methods, all processes can send and receive at the same time, but without ending in a deadlock. So in short it is solved more elegant

**ring_3.c: Describe what advantage the new communicator provides.**
The big advantage we can find in upscaling. With the cartesian system implemented, it's much easier to exted to higher dimensions. neighbours are calculated automatically and the peridic BC as well.
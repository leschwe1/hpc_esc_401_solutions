# Exercise 1

**p = 10, 20, 30, 40, 50, 60, 70, 80, 90, 100** (an integer array)

**a. What C/C++ type is p?**

Type int[10]

**b. What is the type of \*p?**

int 

**c. What is the type of &p?**

int (*)[10] (pointer to whole array p)

**d. What is the value of \*p?**

10 (points to first element of array, dereferenced)


**e. What is the value of p[0]?**

10

**f. What is the value of p[3]?**

40

**g. What is the value of \*(p+5)?**

60

**h. What is the value of \*p+5?**

15

**i. In some languages (e.g. Python), p[-1] = 42 sets the last (10th) element to 42. What does p[-1] = 42 mean in C/C++?**

points to position before array start "left of p[0]" so it is undefined at the moment. 
With the above, the value left to p[0] would be set to 42.
But this is not defined and will not work


**j. Let: int \*q = p-1; What is the value of q[0]. Careful!**

if we set *q = p-1, q[0] is still not filled but q is positioned before p so 

q[0] is not set as (i) did not succeed 

**k. What is the value of \*(q+10)?**

100

**l. What is the value of \*(q+11)**

not defined (points behind array)
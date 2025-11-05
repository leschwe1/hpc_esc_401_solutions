# Exercise 2


Consider the following C++ code.

    int ** M = new int *[2];
    M [0] = new int [5]{0 ,1 ,2 ,3 ,4};
    M [1] = new int [5]{5 ,6 ,7 ,8 ,9};


if the above does not work with your compiler, you can simply use:

    int ** M = new int *[2];
    M [0] = new int [5];
    M [1] = new int [5];

    for (int i =0; i <5; i ++){
        M [0][ i ] = i ;
        M [1][ i ] = 5+ i ;
    }


Answer the following questions:

**a. What data type is M (integer, pointer to integer, . . . )?**

pointer to a pointer to an int


**b. What are M, \*M, \*\*M?** 

- M: type int** --> address of first pointer (M[0])
- \*M: type int\*  --> first element of M = pointer to the first int array (M[0])
- **M: int --> first value of the first int array = 0 


**c. What is M[1][3], \*(M[0]+1), \*(\*(M+1)+3)?**

- M[1][3] = fourth element of second array = 8
- \*(M[0]+1) = second element of first array = 1
- \*(\*(M+1)+3) = fourth element of second array = 8


**d. Are the M[0] and M[1] arrays stored next to each other in the memory? In other words, is it true that \*(M[0]+5)==M[1][0]?**

Not it is usually not the case

as we used new to create M[0] and M[1] the program can place the arrays anywhere in memory, not necessarily beside each other


**Write a short code that would initialize the array M as above and code a function that will swap**
**the array along axis 0, thus the result should be M2, where M2[0] contains vector [9,8,7,6,5]**
**and M2[1] vector [4,3,2,1,0]. In your code, you are NOT ALLOWED to access the values**
**using bracket notation (e.g. M[1][2]) but should instead use * to get the needed values.**

--> see separate file ex2.c

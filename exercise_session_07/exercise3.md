# Exercise 3

In class we learned that 2D arrays (or more generally n-dimensional arrays) are stored contiguously in memory in either row-major or column-major order. Consider a 2D array with
x and y coordinates with 14 elements along x and 6 elements along y. We use the notation
(row index, column index).

Answer the following questions.


**a. Which variable (x or y) tells you which row it is, and which tells you the column?**
- x: column
- y: row

**b. How many total elements are in the table?**

x * y = 14 * 6 = 84 elements


**c. Are the elements (1, 3) and (1, 4) adjacent in memory, or is it rather (1, 3) and (2, 3)?**

Through the comment "We use the notation (row index, column index)" I would say that we are in a row-major order as the row is named first. But I am not fully convinced that the information given is a 100% clear which system is the case here. 
For a above case, the row first assumed, same row and next-column elements are adjacent.
--> (1, 3) and (1, 4) are adjacent in memory


**d. Is one of these choices “better”? Why or why not?**

No there is no clear better choice. It even differs between languages which is used by default. There is no better / worse in useing row or column first in general but it might be for certain use cases (iterations over either row by row or column by column). 


**e. From now on assume “row-major” order, meaning that elements in each row are adjacent to each other. The “stride” tells you the distance between elements in the given**
**direction. What is the stride for the x dimension?**

The stride for x is 1 as we are in row major so we iterate over the columns going row by row. Thus in x direction we have adjacent elements

**f. What is the stride of the y dimension?**

14 as we have to 'skip' a full row which has length 14. to and a row further


**g. Remember again that elements are stored adjacent in memory. Assume that rows are**
**stored adjacent to each other. This means that if you have a table of integers (int *A)**
**then the element (0, 0) is at A[0], element (0, 1) is at A[1] and so on. Where is element**
**(0, 10)?**


(0,10) = row 0, column 10 --> is A[10]

**h. Where is element (3, 0)?**

(3, 0) = row 3, column 0 --> 0 + 3 * 14 = 3 * 14 = 42 --> A[42]


**i. Where is element (7, 4)?**

(7, 4) = row 7, column 4 --> 4 + 7 * 14 = 4 + 98 = 102 --> A[102]
but row 7, column 4 // A[102] is out of bounds as our array is 6 X 13 in size


**Write a function ii(x,y) that takes x and y and returns the location of the element in A.**
**You function will look like this:**

    // Given an x and y coordinate , return the
    // index into an array of 14 columns by 6 rows
    int ii (int x ,int y ) {
        return ...
    }

**You will need to use both index variables and their strides. Write a test program similar to**
**the following to verify your results.**

    int main () {
        int x , y ;
        for( x =0; x <14; ++ x ) {
            for ( y =0; y <6; ++ y ) {
                printf ("(%d ,%d) %d\n",x ,y , ii (x , y ));
            }
        }
    }

--> solution in ex3.cpp
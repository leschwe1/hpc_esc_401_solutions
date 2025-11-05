/*

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
    }s

--> solution in ex3.cpp

*/
#include <stdio.h>



// Given an x and y coordinate, return the
// index into an array of 14 columns by 6 rows
int ii(int x, int y) {
    return y * 14 + x; //14 number columns
}


int main() {
    int x, y;
    printf("having a row-major system \n") ;
    printf("Printing (row index = y, column index = x) location \n");

    for (y = 0; y < 6; ++y) {//row major
        for (x = 0; x < 14; ++x){
            printf("(%d,%d) A[%d]\n", y, x, ii(x, y));
        }
    }
    return 0;
}
//**Write a short code that would initialize the array M as above and code a function that will swap**
//**the array along axis 0, thus the result should be M2, where M2[0] contains vector [9,8,7,6,5]**
//**and M2[1] vector [4,3,2,1,0]. In your code, you are NOT ALLOWED to access the values**
//**using bracket notation (e.g. M[1][2]) but should instead use * to get the needed values.**

#include <iostream>
using namespace std;

void swapArrays(int **M, int cols) {
    //reverse elements in ech row
    for (int i = 0; i < 2; i++) {
        int *rowPtr = *(M + i); //pointer to the start of row i
        for (int j = 0; j < cols / 2; j++) {
            int temp = *(rowPtr + j);   //save left element
            *(rowPtr + j) = *(rowPtr + (cols - 1 - j)); //swap with right element
            *(rowPtr + (cols - 1 - j)) = temp;  //complete swap
        }
    }

    //swap row pointers
    int *tempRow = *(M + 0);
    *(M + 0) = *(M + 1);
    *(M + 1) = tempRow;
}

int main() {

    //as given from task (I guess i'm allowed to use this?)
    int ** M = new int *[2];
    M [0] = new int [5]{0 ,1 ,2 ,3 ,4};
    M [1] = new int [5]{5 ,6 ,7 ,8 ,9};


    //print the original
    cout << "Original" << endl; //title

    for (int i = 0; i < 2; i++) { //loop over dim0
        for (int j = 0; j < 5; j++) { //loop over dim1
            cout << *(*(M + i) + j) << " "; //print value + space
        }
        cout << endl; //print linebreak
    }

    swapArrays(M, 5); //execute function

    //print edited (same loop as above)
    cout << "\nAfter swapping" << endl;

    for (int i = 0; i < 2; i++) { //loop over dim0
        for (int j = 0; j < 5; j++) { //loop over dim1
            cout << *(*(M + i) + j) << " "; //print value + space
        }
        cout << endl; //print linebreak
    }


    return 0;
}
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    /*
    row: int[4] array
    col: int
    */
    using int_array = int[4];
    for(int_array &row: arr) {
        for(int col: row) {
            cout << col << ' ';
        }
        cout << endl;
    }

    for(size_t i = 0; i < 3; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    /*
    row: int (*) [4]
    *row: int[4]
    col: int* or an int[4] array name
    */
    for(int_array *row = arr; row != arr + 3; ++row) {
        for(int *col = *row; col != *row + 4; ++col) {
            cout << *col << ' ';
        }
        cout << endl;
    }
    return 0;
}

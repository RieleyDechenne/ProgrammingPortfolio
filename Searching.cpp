/*                                      PROGRAM INFORMATION:
    NAME: Rieley Dechenne

    OVERVIEW: This is a pass assignment from one of my computer science classes,
              that deals with linear and binary searches of arrays and vectors in C++.
              The code that I wrote includes everything written under the "write test code",
              and all the function defintions at the bottom of the program.

    NOTES: 
*/ 

#include <iostream>
#include <vector>
#include <cassert>

int linear_search(int arr[], int size, int value);
int linear_search(std::vector<int> vec, int value);
int binary_search(int arr[], int size, int value);
int binary_search(std::vector<int> vec, int value);

int main() {

    /* write test code here */

    std::cout << "All tests have successfully passed!" << std::endl;

    /* Please do not modify */
    int arr[10] = {23, 45, 12, 83, 15, 10, 80, 65, 38, 11};
    int sorted_arr[10] = {0, 3, 7, 13, 21, 31, 37, 51, 59, 65};

    std::vector<int> vect = {87, 53, 76, 78, 13, 36, 55, 74, 97, 51};
    std::vector<int> sorted_vect = {22, 25, 44, 51, 53, 63, 70, 72, 91, 93};

    assert(linear_search(arr, 10, 23) == 0);
    assert(linear_search(arr, 10, 45) == 1);
    assert(linear_search(arr, 10, 12) == 2);
    assert(linear_search(arr, 10, 83) == 3);
    assert(linear_search(arr, 10, 15) == 4);
    assert(linear_search(arr, 10, 10) == 5);
    assert(linear_search(arr, 10, 80) == 6);
    assert(linear_search(arr, 10, 65) == 7);
    assert(linear_search(arr, 10, 38) == 8);
    assert(linear_search(arr, 10, 11) == 9);
    assert(linear_search(arr, 10, -5) == -1);
    assert(linear_search(arr, 10, 99) == -1);

    assert(linear_search(vect, 87) == 0);
    assert(linear_search(vect, 53) == 1);
    assert(linear_search(vect, 76) == 2);
    assert(linear_search(vect, 78) == 3);
    assert(linear_search(vect, 13) == 4);
    assert(linear_search(vect, 36) == 5);
    assert(linear_search(vect, 55) == 6);
    assert(linear_search(vect, 74) == 7);
    assert(linear_search(vect, 97) == 8);
    assert(linear_search(vect, 51) == 9);
    assert(linear_search(vect, -5) == -1);
    assert(linear_search(vect, 99) == -1);

    assert(binary_search(sorted_arr, 10, 0) == 0);
    assert(binary_search(sorted_arr, 10, 3) == 1);
    assert(binary_search(sorted_arr, 10, 7) == 2);
    assert(binary_search(sorted_arr, 10, 13) == 3);
    assert(binary_search(sorted_arr, 10, 21) == 4);
    assert(binary_search(sorted_arr, 10, 31) == 5);
    assert(binary_search(sorted_arr, 10, 37) == 6);
    assert(binary_search(sorted_arr, 10, 51) == 7);
    assert(binary_search(sorted_arr, 10, 59) == 8);
    assert(binary_search(sorted_arr, 10, 65) == 9);
    assert(binary_search(sorted_arr, 10, -5) == -1);
    assert(binary_search(sorted_arr, 10, 99) == -1);

    assert(binary_search(sorted_vect, 22) == 0);
    assert(binary_search(sorted_vect, 25) == 1);
    assert(binary_search(sorted_vect, 44) == 2);
    assert(binary_search(sorted_vect, 51) == 3);
    assert(binary_search(sorted_vect, 53) == 4);
    assert(binary_search(sorted_vect, 63) == 5);
    assert(binary_search(sorted_vect, 70) == 6);
    assert(binary_search(sorted_vect, 72) == 7);
    assert(binary_search(sorted_vect, 91) == 8);
    assert(binary_search(sorted_vect, 93) == 9);
    assert(binary_search(sorted_vect, -5) == -1);
    assert(binary_search(sorted_vect, 99) == -1);
    return 0;
}

int linear_search(int arr[], int size, int value){
    /* Your Code Goes here */
    bool found = false;
    int position = -1;
    int index = 0;

    while (index < size && !found) {
        if (arr[index] == value) {     
            found = true;
            position = index;
        }
        index++;
    }

    return position;
}

int linear_search(std::vector<int> vec, int value){
    /* Your Code Goes here */
    int position = -1;
    bool found = false;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == value) {
            found = true;
            return i;
        }
    }
    return position;
}

int binary_search(int arr[], int size, int value){
    /* Your Code Goes here */
    int first = 0;
    int last = size - 1;
    bool found = false;
    int position = -1;

    while (!found && first <= last) {
        int middle = first + (last - first) / 2;

        if (arr[middle] == value) {
            found = true;
            position = middle;
        } else if (arr[middle] > value) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }
    return position;
}

int binary_search(std::vector<int> vec, int value){
    /* Your Code Goes here */
    int first = 0;
    int last = vec.size()-1;
    bool found = false;
    int position = -1;
    
    while(!found && first <= last) {
        int middle = (first + last) / 2;
        if (value == vec.at(middle)) {
            found = true; 
            position = middle;
        }
        else if (value < vec.at(middle)) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
    }
    return position;
}

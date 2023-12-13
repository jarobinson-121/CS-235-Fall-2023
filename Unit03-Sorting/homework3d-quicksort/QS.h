#pragma once

#include <vector>
#include <algorithm>

using namespace std;

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    int mid = (left + right) / 2;

    if(array[mid] < array[left]) {
        if(array[left] > array[right]) {
            if(array[mid] < array[right]) {
                swap(array[mid], array[left]);
                swap(array[mid], array[right]);
            }
            else {
                swap(array[right], array[left]);
            }
        }
        else {
            swap(array[left], array[mid]);
        }
    }
    else {
        if(array[mid] > array[right]) {
            if(array[left] > array[right]) {
                swap(array[right], array[mid]);
                swap(array[left], array[mid]);
            }
            else {
                swap(array[right], array[mid]);
            }
        }
    }
    // if(array[right] < array[left]) {
    //     swap(array[right], array[left]);
    // }
    // if(array[mid] < array[right]) {
    //     swap(array[mid], array[right]);
    // }

    // swap(array[mid], array[right]);

    return mid;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    int middle = medianOfThree(array, left, right);
    swap(array[left], array[middle]);

    int up = left + 1;
    int down = right;

    do {
        while(array[up] <= array[left] && up < right) {
            up++;
        }
        while(array[down] > array[left] && down > left) {
            down--;
        }
        if(up < down) {
            swap(array[up], array[down]);
        }
    } while(up < down);

    swap(array[left], array[down]);

    return down;
}

template <class T>
bool isSorted(vector<T>& array) {
    bool temp = true;
    for(int i = 0; i < array.size() - 1; i++) { 
        if(array[i] > array[i + 1]) {
            return false;
        }
    }
    return temp;
}

// template <class T>
// bool isSortedReverse(vector<T>& array) {
//     bool temp = true;
//     for(int i = 0; i < array.size() - 1; i++) { 
//         if(array[i] < array[i + 1]) {
//             return false;
//         }
//     }
//     return temp;
// }

template<class T>
void sort_helper(vector<T>& array, int left, int right) {
    if(!isSorted(array) /* && !isSortedReverse(array)*/) {
        if(left == right) {
            return;
        }
        else {
            int pivInd = partition(array, left, right);

            sort_helper(array, left, pivInd - 1);
            sort_helper(array, pivInd + 1, right);
        }
    }
}

template<class T>
void sort(std::vector<T>& array) {
        sort_helper(array, 0, (array.size() - 1));
}




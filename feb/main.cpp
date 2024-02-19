#include <iostream>
#include "res.h"

std::vector<int> Algorythm::mergeSort(std::vector<int> arr) {
    if (arr.size() == 1) {
        return arr;
    } 

    int midIndex = arr.size() / 2;

    std::vector<int> left(arr.begin(), arr.begin() + midIndex); 
    std::vector<int> right(arr.begin() + midIndex, arr.end());

    std::vector<int> sortedLeft = mergeSort(left);
    std::vector<int> sortedRight = mergeSort(right);

    return merge(sortedLeft, sortedRight);
}

std::vector<int> Algorythm::merge(std::vector<int> left, std::vector<int> right) {
    std::vector<int> output;

    while (left.size() > 0 && right.size() > 0 ) {
        if (left[0] > right[0]) {
            output.push_back(left[0]);
            left.erase(left.begin());
        }
        else {
            output.push_back(right[0]);
            right.erase(right.begin());
        }
    }

    while (left.size() > 0) {
        output.push_back(left[0]);
        left.erase(left.begin());
    }

    while (right.size() > 0) {
        output.push_back(right[0]);
        right.erase(right.begin());
    }

    return output;
}

int main() {
    Algorythm test;

    std::vector<int> test1 = {5, 2, 8, 1, 9};
    std::vector<int> test2 = {10, 3, 7, 4, 6};
    std::vector<int> test3 = {9, 6, 3, 2, 1};
    std::vector<int> test4 = {4, 8, 2, 7, 5};

    // Might turn this into a function later
    std::cout << "Test case no. 1 input array: " << std::endl;
    for (int i = 0; i < test1.size(); i++) {
        std::cout << test1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Test case no. 1 sorted array: " << std::endl;
    std::vector<int> result1 = test.mergeSort(test1);
    for (int i = 0; i < result1.size(); i++) {
        std::cout << result1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Test case no. 2 input array: " << std::endl;
    for (int i = 0; i < test2.size(); i++) {
        std::cout << test2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Test case no. 2 sorted array: " << std::endl;
    std::vector<int> result2 = test.mergeSort(test2);
    for (int i = 0; i < result2.size(); i++) {
        std::cout << result2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Test case no. 3 input array: " << std::endl;
    for (int i = 0; i < test3.size(); i++) {
        std::cout << test3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Test case no. 3 sorted array: " << std::endl;
    std::vector<int> result3 = test.mergeSort(test3);
    for (int i = 0; i < result3.size(); i++) {
        std::cout << result3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Test case no. 4 input array: " << std::endl;
    for (int i = 0; i < test4.size(); i++) {
        std::cout << test4[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Test case no. 4 sorted array: " << std::endl;
    std::vector<int> result4 = test.mergeSort(test4);
    for (int i = 0; i < result4.size(); i++) {
        std::cout << result4[i] << " ";
    }
    std::cout << std::endl;
    
}
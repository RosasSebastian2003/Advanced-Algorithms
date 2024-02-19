#include <iostream>
#include <vector>

class Algorythm {
    private:
        std::vector<int> merge(std::vector<int> left, std::vector<int> right);
    public:
        std::vector<int> mergeSort(std::vector<int> arr);
};
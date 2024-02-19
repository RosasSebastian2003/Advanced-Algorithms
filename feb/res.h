#include <iostream>
#include <vector>

class Algorythm {
    private:
        std::vector<double> merge(std::vector<double> left, std::vector<double> right);

        // User-in
        double testing = true;
        
    public:
        std::vector<double> mergeSort(std::vector<double> arr);

        void userTest();
};
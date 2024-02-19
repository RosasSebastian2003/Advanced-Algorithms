/*
Sebastián Rosas Maciel - A01233989
*/

#include <iostream>
#include "res.h"

std::vector<double> Algorythm::mergeSort(std::vector<double> arr) {
    if (arr.size() == 1 || arr.size() == 0) {
        return arr;
    } 

    double midIndex = arr.size() / 2;

    std::vector<double> left(arr.begin(), arr.begin() + midIndex); 
    std::vector<double> right(arr.begin() + midIndex, arr.end());

    std::vector<double> sortedLeft = mergeSort(left);
    std::vector<double> sortedRight = mergeSort(right);

    return merge(sortedLeft, sortedRight);
}

std::vector<double> Algorythm::merge(std::vector<double> left, std::vector<double> right) {
    std::vector<double> output;

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

void Algorythm::userTest() {
    bool active = true;
    while (active) {
        int size;
        double input;

        std::vector<double> userIn;
        std::vector<double> userSorted;

        std::cout << "¿Cuantos números desea ingresar?: ";
        std::cin >> size;
        std::cout << "\n" << "Inserte " << size << " numeros de uno por uno: " << std::endl;
        while (userIn.size() < size) {
            std::cin >> input;
            userIn.push_back(input);
        }

        std::cout << "\n" << std::endl;

        std::cout << "Arreglo introducido: ";

        for (int i = 0; i < userIn.size(); i++) {
            std::cout << userIn[i] << " ";
        }

        std::cout << "\n" << "Arreglo ordenado: ";
        userSorted = mergeSort(userIn);

        for (int i = 0; i < userSorted.size(); i++) {
            std::cout << userSorted[i] << " ";
        }
        std::cout << "\n" << std::endl;  

        int choice;
        std::cout <<  "Desea continuar?: " << "\n 1) Si" << "\n 2) No" << "\n entrada: ";

        std::cin >> choice;
        switch(choice) {
            case 1:
                break;
            case 2:
                active = false;
                break;
        }
    }
}

int main() {
    Algorythm test;

    std::vector<double> test1 = {1.2, 3.4, 2.2, 0.8, 5.6, 4.4};
    std::vector<double> test2 = {9.8, 7.6, 5.4, 3.2, 1.0};
    std::vector<double> test3 = {0.1, 0.2, 0.3, 0.4, 0.5};
    std::vector<double> test4 = {1.1, 1.1, 1.1, 1.1, 1.1};

    std::cout << "Caso de prueba no. 1" << std::endl;
    std::cout << "Vector seleccionado: ";
    for (int i = 0; i < test1.size(); i++) {
        std::cout << test1[i] << " ";
    }
    std::cout << std::endl;
    std::vector<double> sorted = test.mergeSort(test1);
    std::cout << "Vector ordenado: ";
    for (int i = 0; i < sorted.size(); i++) {
        std::cout << sorted[i] << " ";
    }
    std::cout << "\n" << std::endl;  

    std::cout << "Caso de prueba no. 2" << std::endl;
    std::cout << "Vector seleccionado: ";
    for (int i = 0; i < test2.size(); i++) {
        std::cout << test2[i] << " ";
    }
    std::cout << std::endl;
    std::vector<double> sorted2 = test.mergeSort(test2);
    std::cout << "Vector ordenado: ";
    for (int i = 0; i < sorted2.size(); i++) {
        std::cout << sorted2[i] << " ";
    }
    std::cout << "\n" << std::endl;  

    std::cout << "Caso de prueba no. 3" << std::endl;
    std::cout << "Vector seleccionado: ";
    for (int i = 0; i < test3.size(); i++) {
        std::cout << test3[i] << " ";
    }  
    std::cout << std::endl;
    std::vector<double> sorted3 = test.mergeSort(test3);
    std::cout << "Vector ordenado: ";
    for (int i = 0; i < sorted3.size(); i++) {
        std::cout << sorted3[i] << " ";
    }
    std::cout << "\n" << std::endl;  

    std::cout << "Caso de prueba no. 4" << std::endl;
    std::cout << "Vector seleccionado: ";
    for (int i = 0; i < test4.size(); i++) {
        std::cout << test4[i] << " ";
    }
    std::cout << std::endl;
    std::vector<double> sorted4 = test.mergeSort(test4);
    std::cout << "Vector ordenado: ";
    for (int i = 0; i < sorted4.size(); i++) {
        std::cout << sorted4[i] << " ";
    }
    std::cout << "\n" << std::endl;  

    test.userTest();    

    return 0;
}
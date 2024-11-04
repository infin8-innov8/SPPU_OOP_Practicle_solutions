// Q.   Write a function template selection Sort. Write a program that inputs, sorts and outputs 
//      an int array and a float array.

#include<iostream>

int n; // for number of elements
const int size = 10;

template<class T> void sort(T A[]) {
    int i, j, min;
    T temp;

    for (i = 0; i < n - 1; i++) {
        min=i;

        for (j = i + 1; j < n; j++) {
            if(A[j] < A[min]) min = j;
        }

        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

    std::cout << "\nSorted array : ";
    for (i = 0; i < n; i++) {
        std::cout <<"  " << A[i];
    }
    std::cout << std::endl; 
}

int main() {
    int arr1[size];
    float arr2[size];
    int i;
    
    std::cout << "\t\t ==| for integer array |==" << std::endl; 
    try { 
        std::cout << "Enter total number of integer elements (> 1): ";
        std::cin >> n;

        if (n < 0) throw std::runtime_error("Exception : Array size cannot be negative."); 
        else if (n == 0) throw std::runtime_error("Exception : empty array is invalid."); 
        else if (n == 1 ) throw std::runtime_error("Exception : single element cannot be sorted.");
    } catch (std::exception& exp) { 
        std::cout << exp.what() << std::endl; 
    }

    std::cout << "\nEnter all elements : ";

    for(i = 0; i < n; i++) {
        std::cin >> arr1[i];
    }

    sort(arr1);

    std::cout << "\n\t\t ==| for floating point array |==" << std::endl; 

    std::cout << "\nEnter all elements : ";

    for(i = 0; i < n; i++) {
        std::cin>> arr2[i];
    }

    sort(arr2);

    std::cout << "\n\t\t **Program executed successfully** " << std::endl; 
    return 0;
}
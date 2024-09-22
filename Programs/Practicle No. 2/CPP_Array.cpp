// Title: Implement a class CppArray which is identical to one dimensional C++ array  
// (i.e, the index set is a set of consecutive integers starting at 0) except for the following :
//    1. performs range checking .
//    2. allows one to be assigned to another array through the use of the assignment operator (i.e cp1 = cp2).
//    3. supports a function that returns the size of array.
//    4. allows the reading and printing of array through the use cout and cin.

#include <iostream> 

class CppArray { 
    private : 
        int* data;
        unsigned int size;
    
    public : 
        // Explicit parameterized constructor 
        CppArray(int num) : size(num) {
            std::cout << "(constructor invoked)" << std::endl;
            data = new int[size];
        }

        // destructor
        ~CppArray() {
            std::cout << "(destructor invoked)" << std::endl; 
            delete[] data;
        }

        // overloading '=' operator
        CppArray& operator =(const CppArray& arr) {
            delete[] data; // arrays may have different sizes
            size = arr.size;
            data = new int[size];

            for(int i = 0; i < size; i++) {
                data[i] = arr.data[i];
            }

            return *this;
        }

        // overlading output variable (<<)
        friend std::ostream& operator << (std::ostream& output, const CppArray& other ) { 
            std::cout << "\tArray is :  "; 

            for(int i = 0; i < other.size; i++) { 
                std::cout << other.data[i] << " ";
            }

            std::cout << std::endl;
            return output; 
        }

        // overlading input variable ('>>')
        friend std::istream& operator >> (std::istream& input, CppArray& other) { 
            std::cout << "\tEnter elements in the array : "; 
            
            for(int i = 0; i < other.size; i++) { 
                std::cin >> other.data[i];
            }

            return input; 
        }

        // overloading {} operator 
        int& operator [] (int index) { 
            if (index < 0 or index >= this->size) { 
                std::cout << "\tarray index is out of bound" << std::endl; 
            } 

            return data[index];
        }
        // to return the zize of array
        int calculate_size() { 
            std::cout << "(size function invoked)" << std::endl; 
            return size;
        }
};

int main() { 
    int s; 
    std::cout << "\tEnter the size of array : " ; 
    std::cin >> s; 

    CppArray arr(s);

    std::cin >> arr; 

    std::cout << arr; 

    std::cout << "\n--- Range checking ---" << std::endl; 
    std::cout << "\telement at arr[15] = " << arr[15] << std::endl; 

    std::cout << "\n--- overloading '=' operator ---" << std::endl; 
    CppArray arr2 = arr; 
    std::cout << arr2; 
    
    std::cout << "\n--- main function terminated ---" << std::endl; 
    std::cout << "\n===| Code execution successful |===" << std::endl; 
    return 0;
}
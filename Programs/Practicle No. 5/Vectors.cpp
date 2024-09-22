// Title :Create a class template to represent a generic vector. Include following member functions:
//       To create the vector.
//       To modify the value of a given element.
//       To multiply by a scalar value.
//       To display the vector in the form (10,20,30,… ).

#include <iostream> 

namespace Vectors { 
    class Vector { 
        private : 
            double i, j, k; 

        public : 
            // Default constructor to initialize data members.
            Vector() : i(0), j(0), k(0) {
                std::cout << "(default constructor invoked)" << std::endl;
            } 

            // Parameterized constructor.
            Vector(double x, double y, double z) : i(x), j(y), k(z) { 
                std::cout << "(parameterized constructor invoked)" << std::endl;
            } 

            // Function to display the vector porperly.
            void display_vector() const { 
                std::cout << "(display function invoked)" << std::endl;
                std::cout << "\tThe vector is : (" << i << ")i + (" << j << ")j + (" << k << ")k " << std::endl;
            }

            // Function to multiply a scalar value to the vector.
            void Multiply_by_scaler() { 
                int num; 
                std::cout << "\tEnter any scanlar number to multiply given vector : "; 
                std::cin >> num; 
                i *= num; 
                j *= num; 
                k *= num;  
                std::cout << "\tThe resultant vector is :";
                std::cout << "(" << i << ")i + (" << j << ")j + (" << k << ")k" << std::endl;
            }

            // Function to assign data members or modify members
            void scan_vector() { 
                std::cout << "\tEnter the values in vector (x)i + (y)j + (z)k :" << std::endl;
                std::cout << "\t\tx = " ;
                std::cin >> i; 

                std::cout << "\t\ty = "; 
                std::cin >> j; 

                std::cout << "\t\tz = ";
                std::cin >> k; 
            }
    }; // endl of the class Vector
}


int main() { 
    // creating an object of class Vector 
    Vectors::Vector v1;
    std::cout << "(An object is created)" << std::endl;
    v1.scan_vector();
    v1.display_vector();

    std::cout << "\n--- Multiplication by scalar value ---" << std::endl;
    v1.Multiply_by_scaler(); 

    std::cout << "\n--- Modification of vector ---" << std::endl;
    v1.scan_vector(); 
    v1.display_vector(); 

    std::cout << "\n(main function terminated)" << std::endl; 

    std::cout << "\n\t=== Program execution successful ===" << std::endl;
}

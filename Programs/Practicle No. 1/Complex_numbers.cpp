// Title: Implement a class CppArray which is identical to one dimensional C++ array ( i.e ,the index set is a set of consecutive integers starting at 0)except for the following :
//       It performs range checking .
//       It allows one to be assigned to another array through the use of the assignment operator (i.e cp1=cp2).
//       It supports a function that returns the size of array.
//       It allows the reading and printing of array through the use cout and cin.

#include <iostream>

namespace complex_numbers {
    class Complex {
        public : 
            // complex numbers consist of real and imaginary part. 
            double real; 
            double imag; 

            // creating explicit constructor of the class complex. 
            Complex(void) { 
                std::cout << "(Explicit default constructor invoked.)" << std::endl;
                real = 0;
                imag = 0;
            }

            // creating explicit copy constructor of the class
            Complex( const Complex& other) { 
                std::cout << "(Explicit copy constructor invoked.)" << std::endl;
                real = other.real; 
                imag = other.imag;

            }

            // operator overloading for addition of the complex numbers. 
            Complex operator + ( const Complex &num) {
                std::cout << "(The operator + is overloaded.)" << std::endl; 
                Complex temp;
                temp.real = real + num.real;
                temp.imag = imag + num.imag;
                return temp;
            }
            
            // operator overloading for multiplication of complex numbers. 
            Complex operator * (const Complex &num) {
                std::cout << "(The operator * is overloaded.)" << std::endl; 
                Complex temp;
                temp.real = real * num.real;
                temp.imag = imag * num.imag;
                return temp;
            }

            // operator overloading for printing the resultant complex number.
            friend std::ostream &operator  << (std::ostream &output, const Complex& num) {
                output << "The number is : " << num.real << " + " << num.imag << "i " << std::endl;
                return output;
            }

            // operator overloading for scanning complex numbers from user.
            friend std::istream& operator >> (std::istream& input, Complex& num) {
                std::cout << "\t\tEnter the real part of the number : ";
                input >> num.real;

                std::cout << "\t\tEnter the imaginary part of the number : ";
                input >> num.imag;

                return input;
            }
    };
} 

int main() { 
    complex_numbers::Complex num1; // object is created as num1.

    std::cout << "\tEnter the first number : " << std::endl;
    std::cin >> num1;

    complex_numbers::Complex num2; // another object is created as num2.
    std::cout << "\tEnter the second number : " << std::endl;
    std::cin >> num2; 

    complex_numbers::Complex resultant_num; // complex resultant_num is for storing the result.  

    resultant_num = (num1 + num2);
    std::cout << "\tThe sum of the given two complex numbers is : " << resultant_num << std::endl; 

    resultant_num = (num1 * num2);
    std::cout << "\tThe multiplication of the given two complex numbers is : " << resultant_num << std::endl; 

    std::cout << "(main function terminated)" << std::endl;

    std::cout << "===| Code Executed Successfuly |===" << std::endl;
}

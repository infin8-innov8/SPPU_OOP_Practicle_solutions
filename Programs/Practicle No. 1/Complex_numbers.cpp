// Title : Implement a class complex which represent the Complex Number data type. Implement the following operations:
//         1. Constructor (include a default constructor which creates the complex number 0+0i )
//         2. Overloaded operator + to add two polynomials of degree 2.
//         3. Overloaded operator * to multiply two complex number.
//         4. Overloaded << and >> to print and read Complex Number.

// file name : "Complex_numbers.cpp"
#include <iostream>

namespace complex_numbers {
    class Complex {
        public : 
            // complex numbers consist of two parts, real and imaginary part.
            double real; 
            double imag; 

            // creating constructor of the class complex. 
            Complex(void) { 
                real = 0;
                imag = 0;
            }

            // operator overloading of unary plus for addition of the complex numbers. 
            Complex operator + ( Complex num) {
                Complex temp;
                temp.real = real + num.real;
                temp.imag = imag + num.imag;
                return temp;
            }
            
            // operator overloading of '*' for multiplication of complex numbers. 
            Complex operator * ( Complex num) {
                Complex temp;
                temp.real = real * num.real;
                temp.imag = imag * num.imag;
                return temp;
            }

            // operator overloading of insertion operator for printing the resultant complex number.
            friend std::ostream &operator  << (std::ostream &output, Complex &num) {
                output << "The number is : " << num.real << " + " << num.imag << "i " << std::endl;
                return output;
            }

            // operator overloading of extraction operator for scanning complex numbers from user.
            friend std::istream &operator >> (std::istream &input, Complex &num) {
                std::cout << "\tEnter the real part of the number : ";
                input >> num.real;

                std::cout << "\tEnter the imaginary part of the number : ";
                input >> num.imag;
                return input;
            }
    };
} 

int main() { 
    complex_numbers::Complex num1; // object is created as num1.

    std::cout << "Enter the first number : " << std::endl;
    std::cin >> num1;

    complex_numbers::Complex num2; // another object is created as num2.
    std::cout << "Enter the second number : " << std::endl;
    std::cin >> num2; 

    complex_numbers::Complex resultant_num; // for storing the result.  

    resultant_num = (num1 + num2);
    std::cout << "The sum of the given two complex numbers is : " << resultant_num << std::endl; 

    resultant_num = (num1 * num2);
    std::cout << "The multiplication of the given two complex numbers is : " << resultant_num << std::endl; 
    
}

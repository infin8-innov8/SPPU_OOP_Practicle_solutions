#include <iostream>

namespace complex_numbers {
    class Complex {
        public : 
            // complex numbers consist of two parts, real and imaginary  part.
            double real; 
            double imag; 

            // creating constructor for the class complex. 
            Complex(void) { 
                real = 0;
                imag = 0;
            }

            // operator overloading for addition of the complex numbers. 
            Complex operator + ( Complex num) {
                Complex temp;
                temp.real = real + num.real;
                temp.imag = imag + num.imag;
                return temp;
            }
            
            // operator overloading for multiplication of complex numbers. 
            Complex operator * ( Complex num) {
                Complex temp;
                temp.real = real * num.real;
                temp.imag = imag * num.imag;
                return temp;
            }

            // operator overloading for printing the resultant complex number.
            friend std::ostream &operator  << (std::ostream &output, Complex &num) {
                output << "The number is : " << num.real << " + " << num.imag << "i " << std::endl;
                return output;
            }

            // operator overloading for scanning complex numbers from user.
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

    complex_numbers::Complex resultant_num; // complex resultant_num is for storing the result.  

    resultant_num = (num1 + num2);
    std::cout << "The sum of the given two complex numbers is : " << resultant_num << std::endl; 

    resultant_num = (num1 * num2);
    std::cout << "The multiplication of the given two complex numbers is : " << resultant_num << std::endl; 
    
}
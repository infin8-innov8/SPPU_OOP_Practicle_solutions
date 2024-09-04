// Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The program should take two operands from user and performs the operation 
// on those two operands depending upon the operator entered by user. Use a switch statement to select the operation. Finally, display the result .

//file name : "Calculator.cpp"

#include <iostream> 

namespace Calculators { 
    class Calculator { 
        private : 
            double num1;
            double num2; 
            char opr; // ie. operator
    
        public : 
            // creating default constructor
            Calculator (void) { 
                num1 = 0; 
                num2 = 0;
                opr = '\0';
            }
            // far scanning for num1, num2 and opr
            void scan() { 
                std::cout << "Enter the fist number : "; 
                std::cin >> num1;
                
                std::cout << "Enter the operation to be performed (+ , - , * , /): ";
                std::cin >> opr;
                
                std::cout << "Enter the second number : "; 
                std::cin >> num2; 
  
            }
            // for canluation and printing the result 
            void calculate() { 
                switch (opr) { 
                    case '+' :
                        std::cout << "Tthe sum of the given two number is : " << num1 + num2 << std::endl; 
                        break;
                    
                    case '-' : 
                        std::cout << "The subtraction of the given two numbers is : " << num1 - num2 << std::endl; 
                        break; 

                    case '*' : 
                        std::cout << "The multiplication of the given two numbers is : " << num1 * num2 << std::endl;
                        break; 
                    
                    case '/' : 
                        if(num2 == 0) { 
                            std::cout << "Any number divided by 0 is undifined." << std::endl;
                        } 
                        else { 
                            std::cout << "The division of the given numbers is : " << num1 / num2 << std::endl; 
                        }
                        break;

                    default : 
                        std::cout << "We can conclude that the given inputs aren't valid, try again :)" << std::endl; 
                }
            }
    };
}
int main() { 
    Calculators::Calculator operation1; // an object has been created

    operation1.scan(); 

    operation1.calculate();

    return 0;
}

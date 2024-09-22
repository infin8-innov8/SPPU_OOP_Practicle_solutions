// Q.   Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The program should take two operands from user and performs the operation 
//      on those two operands depending upon the operator entered by user. Use a switch statement to select the operation. Finally, display the result .

#include <iostream> 

namespace Calculators { 
    class Calculator { 
    private : 
        double num1; // data membeer of first operend
        double num2; // data member of second operend
        char opr; // data member for operator

    public : 
        // creating explici default constructor
        Calculator (void) { 
            std::cout << "(The explicit default constructor invoked.)" << std::endl;
            num1 = 0; 
            num2 = 0;
            opr = '\0';
        }
        
        // for scanning for num1, num2 and opr
        void scan() { 
            std::cout << "(scanner function invoked.)" << std::endl; 
            
            std::cout << "\tEnter the fist number : "; 
            std::cin >> num1;
            
            std::cout << "\tEnter the operation to be performed (+ , - , * , /): ";
            std::cin >> opr;
            
            std::cout << "\tEnter the second number : "; 
            std::cin >> num2; 

        }
        // for canluation and printing the result 
        void calculate() { 
            switch (opr) { 
                case '+' :
                    std::cout << "\tThe sum of the given two number is : " << num1 + num2 << std::endl; 
                    break;
                
                case '-' : 
                    std::cout << "\tThe subtraction of the given two numbers is : " << num1 - num2 << std::endl; 
                    break; 

                case '*' : 
                    std::cout << "\tThe multiplication of the given two numbers is : " << num1 * num2 << std::endl;
                    break; 
                
                case '/' : 
                    if(num2 == 0) { 
                        std::cout << "\tAny number divided by 0 is undifined." << std::endl;
                    } 
                    else { 
                        std::cout << "\tThe division of the given numbers is : " << num1 / num2 << std::endl; 
                    }
                    break;

                default : 
                    std::cout << "\tWe can conclude that the given inputs aren't valid, try again :)" << std::endl; 
            }
        }
    };
}
int main() { 
    Calculators::Calculator operations[6]; 
    
    for (Calculators::Calculator object : operations) { 
        object.scan(); 
        object.calculate() ; 
    }

    std::cout << "(main function terminated)" << std::endl;
    std::cout << "===| Code Execution Successfull |===" << std::endl << std::endl; 
    return 0;
}

// Create a class Rational Number (fractions) with the following capabilities:
//      a)  Create a constructor that prevents a 0 denominator in a fraction, reduces or simplifies
//              fractions that are not in reduced form and avoids negative denominators.
//      b)  Overload the addition, subtraction, multiplication and division operators for this class.
//      c)  Overload the relational and equality operators for this class.

#include <iostream>

namespace Rational_numbers { 
    

    class Rational_num { 
        private : 
            int num, denom; 
            // to get gcd : gretest common deviser
            int gcd(int a, int b) {
                int result = (b > a) ? a : b; // assign the minimum number to result

                while (result > 0) { 
                    if (a % result == 0 and b % result == 0) { 
                    break; 
                }
                    result--;
                }
                return result; 
            }

        public : 
            // to reduce / simplify the fraction
            void simplify_num() { 
                std::cout << "(simplify function invoked)" << std::endl;
                int diviser = gcd(num, denom); 
                num /=diviser; 
                denom /= diviser;
            }
            
            // default constructor
            Rational_num() : num(0), denom(0) { 
                std::cout << "(Default constructor invoked)" << std::endl; 
            }

            // function to scan and assign number
            void scan_num() { 
                std::cout << "(scan function invoked)" << std::endl;
                std::cout << "\tEnter the numbers in the fraction : " << std::endl;
                std::cout << "\t\tnumerator = "; 
                std::cin >> num; 
                do { 
                    std::cout << "\t\tdenominator = ";
                    std::cin >> denom; 

                    if (denom == 0) { 
                        std::cout << "\tDenominator cannot be 0, enter again -" << std::endl;
                    }
                } while(denom == 0); // denominator cannot be 0.

                this -> display_num(); 
                this -> simplify_num();
                std::cout << "\tAfter simplification, " << std::endl;
                this -> display_num(); 
            }

            // function to pint numbers properly 
            void display_num() const { 
                std::cout << "(display function invoked)" << std::endl;
                std::cout << "\tThe number is : "; 
                std::cout << num << " / " << denom << std::endl;
            }

            // overloadig operators for operations on rational numbers
            Rational_num operator + (const Rational_num &other) { 
                Rational_numbers::Rational_num temp; 
                temp.num = (num * other.denom) + (denom * other.num); 
                temp.denom = denom * other.denom; 
                return temp;
            }

            Rational_num operator - (const Rational_num &other) { 
                Rational_numbers::Rational_num temp; 
                temp.num = (num * other.denom) - (denom * other.num); 
                temp.denom = denom * other.denom; 
                return temp;
            }

            Rational_num operator * (const Rational_num &other) { 
                Rational_numbers::Rational_num temp; 
                temp.num = num * other.num; 
                temp.denom = denom * other.denom; 
                return temp;
            }

            Rational_num operator / (const Rational_num &other) { 
                Rational_numbers::Rational_num temp; 
                temp.num = num * other.denom; 
                temp.denom = denom * other.num; 
                return temp;
            }

            // to assign a rational number from another rational number
            Rational_num operator = (const Rational_num&other) { 
                this -> num = other.num; 
                this -> denom = other.denom; 
                return *this;
            }

            // some relational operator overloadings to compare rational numbers
            bool operator == ( Rational_num &other) { 
                return (this -> num == other.num and this -> denom == other.denom);
            }

            bool operator > ( Rational_num &other) { 
                return (this -> num > other.num and this -> denom > other.denom);
            }

            bool operator < ( Rational_num &other) { 
                return (this -> num < other.num and this -> denom < other.denom);
            }

            bool operator != ( Rational_num &other) { 
                return (this -> num != other.num and this -> denom != other.denom);
            }

            // output operator overloading to print rational numbers in abstracted manner
            friend std::ostream& operator << (std::ostream& os, Rational_num other) {
                os << other.num << " / " << other.denom;
                return os;
            }
    }; // endl of tha class
}

int main() { 
    Rational_numbers::Rational_num fraction1; 
    std::cout << "\tEnter value of first number (fraction1) :" << std::endl;
    fraction1.scan_num(); 

    Rational_numbers::Rational_num fraction2;  
    std::cout << "\tEnter value of second number (fraction2) :" << std::endl;
    fraction2.scan_num(); 

    std::cout << "\n--- comparing both numbers ---" << std::endl;

    if(fraction1 == fraction2) { 
        std::cout << "\tFraction1 and fraction2 are equal." << std::endl;
    } 
    else if (fraction1 != fraction2) { 
        std::cout << "\tfraction1 and fraction2 are not equal";

        if(fraction1 < fraction2) { 
            std::cout << ", fraction1 is less than fraction2. " << std::endl;
        }
        else { 
            std::cout << ", fraction1 is greater than fraction2." << std::endl;
        }
    }
    
    std::cout << "\n--- Basic operations ----" << std::endl; 

    std::cout << "\tfraction1 + fraction2 = " << fraction1 + fraction2 << std::endl; 
    std::cout << "\tfraction1 * fraction2 = " << fraction1 * fraction2 << std::endl; 
    std::cout << "\tfraction1 - fraction2 = " << fraction1 - fraction2 << std::endl; 
    std::cout << "\tfraction1 / fraction2 = " << fraction1 / fraction2 << std::endl; 

    std::cout << "\n(main function terminated)" << std::endl;
    std::cout << "\n=== Program executed successfuly ===" << std::endl;
}

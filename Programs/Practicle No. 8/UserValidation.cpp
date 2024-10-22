//  Q.  Create User defined exception to check the following conditions and throw the exception if the
//     criterion does not meet.
//         a. User has age between 18 and 55
//         b. User stays has income between Rs. 50,000 – Rs. 1,00,000 per month
//         c. User stays in Pune/ Mumbai/ Bangalore / Chennai
//         d. User has 4-wheeler
//     Accept age, Income, City, Vehicle from the user and check for the conditions mentioned above. If any
//     of the condition not met then throw the exception.

#include <iostream> 

int main()  { 
    int age, income;
    std::string address; 
    std::string yn;         // for input yes or NO

    try { 
        std::cout << "Enter your age : \n\t";
        std::cin >> age; 

        if (age < 18 or age > 55) throw std::runtime_error("Exception occured, age is not valid");  

        std::cout << "Enter your income : \n\t";
        std::cin >> income; 

        if (income < 50000 || income > 1000000) throw std::runtime_error("Exception occured, income is not valid"); 

        std::cout << "Enter your state : \n\t"; 
        std::cin >> address; 

        if (address == "Pune" || address == "Mumbai" || address == "Banglore" || address == "Chennai"); 
        else throw std::runtime_error("Exception occured, state is not valid"); 

        std::cout << "Do you have four wheeler vehicle ? \n\t"; 
        std::cin >> yn; 
        
        if (yn == "no" || yn == "false") throw std::runtime_error("Excetion occured, you don't have four wheeler vehicle."); 

    } catch (std::exception& exp) {   
        std::cout << exp.what() << std::endl; 
        sts::cout << "Execution terminated" << std::endl;
        return 1;       // not 0, because exception occured within the execution.
    }

    std::cout << "Program executed succefully." << std::endl; 
}

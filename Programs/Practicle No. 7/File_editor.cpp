// Q.   Write a C++ program that creates an output file, writes information to it,  closes the
//      file and openit again as an input file and read the information from the file.

#include <iostream> 
#include <fstream> 

int main() { 
    std::string content;    // to hold the user input
    std::cout << "Enter the line : \n\t"; 
    getline(std::cin, content);

    std::ofstream write; 
    write.open("sample.txt",std::ios::out);

    // to check if the file is successfully opened
    if (!write.is_open()) { 
        std::cout << "failure while openning the file." << std::endl; 
        return 1; 
    }

    write << content;
    write.close();     // to ensure data is saved and resources are released

    std::ifstream read;
    read.open("sample.txt", std::ios::in); 
    std::string data;
    std::cout << "\nHere is what you wrote : "; 

    while(getline(read, data)) {  // to read each line and print
        std::cout << std::endl << "\t" <<  data << std::endl; 
    }

    read.close();   // to release resources
}   
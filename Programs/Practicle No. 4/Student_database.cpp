// Q.   Develop an object oriented program in C++ to create a database of student information system containing the
//      following information : 
//          @ Name
//          @ Roll number
//          @ Class
//          @ Division
//          @ Date of Birth
//          @ Blood group
//          @ ontact address
//          @ Telephone number
//          @ Driving license no.
//      Construct the database with suitable member functions for initializing and destroying the data viz 
//          @ Constructor
//          @ Default constructor
//          @ Copy constructor
//          @ Destructor
//          @ Static member functions
//          @ friend class
//          @ this pointer
//          @ inline code
//          @ dynamic memory allocation operators-new and delete

#include <iostream> 
#include <string> // Include this to use std::string

namespace Student_database {
    // Forward declaration of class Student_basic_info
    class Student_basic_info;
    
    // implimentation of Class to store additional information about students
    class Student_additional_info {
        private:
            int8_t* dob_d;              // Day of birth
            int8_t* dob_m;              // Month of birth
            int16_t* dob_y;             // Year of birth
            std::string* blood_group;    // Blood group
            std::string* address;        // Contact address
            std::string* phone_no;       // Phone number
            std::string* licence_no;     // Driving license number
    
    
        public:
            // Static member variables
            static size_t regi_count;    // Registered student count
            static size_t count;         // Active student count
            static size_t unregi_count;  // Unregistered student count
    
            // Constructor to initialize all fields
            Student_additional_info() {
                this->dob_d = new int8_t(0);
                this->dob_m = new int8_t(0);
                this->dob_y = new int16_t(0);
                this->blood_group = new std::string("Blood group not available.");
                this->address = new std::string("Address not available.");
                this->phone_no = new std::string("Phone number not available.");
                this->licence_no = new std::string("License number not available.");
                increment_regi_count();  // Increment registered student count on creation
            }
    
            // Destructor to free allocated memory and update unregistered student count
            ~Student_additional_info() {
                delete dob_d;
                delete dob_m;
                delete dob_y;
                delete blood_group;
                delete address;
                delete phone_no;
                delete licence_no;
                increment_unregi_count();  // Increment unregistered student count on deletion
            }
    
            // Copy constructor for deep copying of all fields
            Student_additional_info(const Student_additional_info &obj) {
                this->dob_d = new int8_t(*obj.dob_d);
                this->dob_m = new int8_t(*obj.dob_m);
                this->dob_y = new int16_t(*obj.dob_y);
                this->blood_group = new std::string(*obj.blood_group);
                this->address = new std::string(*obj.address);
                this->phone_no = new std::string(*obj.phone_no);
                this->licence_no = new std::string(*obj.licence_no);
                increment_regi_count();  // Each copy is counted as a new registration
            }
    
            // Increment the number of registered students
            static void increment_regi_count() { 
                regi_count++; 
                count++; 
            }
    
            // Increment the number of unregistered students
            static void increment_unregi_count() { 
                count--; 
                unregi_count++; 
            }
    
            // Static member function to set the initial counts (can be called without an object)
            inline static void set_count(size_t r, size_t c, size_t u) { 
                regi_count = r; 
                count = c; 
                unregi_count = u; 
            }
    
            // Function to print all the additional information for a student
            inline void print_all_info (const Student_basic_info &obj);
    
            // Function to scan both additional and basic info from user input
            inline void scan_info(Student_basic_info &obj);
            // function to print both additional and basic info.
            inline static void const print_count ();
    };

    // Class to store basic information about students
    class Student_basic_info {
    private:
        std::string* class_name;  // Class name (e.g., B.Sc)
        char* division;           // Division (e.g., A or B)
        size_t* roll_no;          // Roll number
        std::string* name;        // Student's name

    public:
        // Friend class declaration to allow access to private members by Student_additional_info
        friend class Student_additional_info;

        // Default constructor to initialize data members
        Student_basic_info() {
            class_name = new std::string("\0");
            division = new char('\0');
            roll_no = new size_t(0);
            name = new std::string("\0");
        }

        // Destructor to clean up allocated memory
        ~Student_basic_info() {
            delete class_name;
            delete division;
            delete roll_no;
            delete name;
        }

        // Copy constructor for deep copying of all fields
        Student_basic_info(const Student_basic_info &obj) {
            class_name = new std::string(*obj.class_name);
            division = new char(*obj.division);
            roll_no = new size_t(*obj.roll_no);
            name = new std::string(*obj.name);
        }
    };

    // Implementation of scan_info function to input student details
    inline void Student_additional_info::scan_info(Student_basic_info &obj) {
        std::string s;
        int8_t in8;
        int16_t in16;
        size_t sz;
        char c;

        // Input for basic information
        std::cout << "\tEnter name of class: ";
        std::getline(std::cin, s);
        *obj.class_name = s;

        std::cout << "\tEnter Division: ";
        std::cin >> c;
        *obj.division = c;

        std::cout << "\tEnter Roll No. : ";
        std::cin >> sz;
        *obj.roll_no = sz;

        std::cin.ignore(); 

        std::cout << "\tEnter Student Name: ";
        std::getline(std::cin, s);
        *obj.name = s;

        // Input for additional information
        std::cout << "\tDate of birth (d m yyyy) : ";
        std::cin >> in8;
        *dob_d = in8;
        std::cin >> in8;
        *dob_m = in8;
        std::cin >> in16;
        *dob_y = in16;

        std::cin.ignore();
        std::cout << "\tEnter Blood group: ";
        std::getline(std::cin, s);
        *blood_group = s;

        std::cout << "\tEnter Contact address: ";
        std::getline(std::cin, s);
        *address = s;

        std::cout << "\tEnter Phone no.(xxxx xx xxxx) : ";
        std::getline(std::cin, s);
        *phone_no = s;

        std::cout << "\tEnter Driving licence No.: ";
        std::getline(std::cin, s);
        *licence_no = s;
    }

    // Implementation of print_all_info function to display student details
    inline void Student_additional_info::print_all_info(const Student_basic_info &obj) {
        std::cout << "\n--- Student Information ---\n";
        std::cout << "\tClass Name\t\t: " << *obj.class_name << std::endl;
        std::cout << "\tDivision\t\t: " << *obj.division << std::endl;
        std::cout << "\tRoll No.\t\t: " << *obj.roll_no << std::endl;
        std::cout << "\tName of Student\t\t: " << *obj.name << std::endl;
        std::cout << "\tDate of Birth\t\t: " << (int)*dob_d << "/" << (int)*dob_m << "/" << *dob_y << std::endl;
        std::cout << "\tBlood Group\t\t: " << *blood_group << std::endl;
        std::cout << "\tContact Address\t\t: " << *address << std::endl;
        std::cout << "\tPhone No.\t\t: " << "+91 " << *phone_no << std::endl;
        std::cout << "\tDriving License No.\t: " << *licence_no << std::endl;
    }

    // Static variables to track the number of registered and unregistered students
    size_t Student_additional_info::regi_count = 0;
    size_t Student_additional_info::count = 0;
    size_t Student_additional_info::unregi_count = 0;

    inline void const Student_database::Student_additional_info::print_count(){ 
        std::cout << "Total number of student registered : " << regi_count << std::endl;
        std::cout << "Total number of student active : " << count << std::endl; 
        std::cout << "Total number of student unregistered : " << unregi_count << std::endl; 
    }

} // End of namespace Student_database

int main() { 
    // Initialize the static count variables
    Student_database::Student_additional_info::set_count(0, 0, 0);
    
    // Creating objects for Student_basic_info and Student_additional_info
    Student_database::Student_basic_info s1_b;
    Student_database::Student_additional_info s1_a;

    // Input student information
    std::cout << "Enter the information of the student: \n";
    s1_a.scan_info(s1_b);

    // Display student information
    s1_a.print_all_info(s1_b);

    // Demonstrating the copy constructor by creating a new student
    std::cout << "\nCreating a new student using the copy constructor...\n";
    Student_database::Student_basic_info s2_b(s1_b);
    Student_database::Student_additional_info s2_a(s1_a);

    // Display the copied student's information
    std::cout << "\n--- Copied Student Information ---\n";
    s2_a.print_all_info(s2_b);

    std::cout << std::endl << std::endl;
    Student_database::Student_additional_info::print_count(); 

    std::cout << "\n\n===| Code Executed Successfully |===" << std::endl << std::endl;  

    return 0;
}

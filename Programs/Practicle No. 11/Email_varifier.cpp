// Q. Design an E-mail Verifier which accepts the email address from the user. Depending 
//      upon the input given byuser display appropriate results. Use the following concepts 
//      in the Project – Constructor, Destructor, new, delete,exceptional handling, string 
//      handling functions, etc.

#include <iostream>
#include <string>
#include <regex> 
using namespace std;

class EmailVerifier {
    private:
        string *email;  
        bool isValid;

    public:
        EmailVerifier(string inputEmail) {
            try {
                email = new string(inputEmail);  // Allocate memory for email
                cout << "(Memory allocated for email verification.)\n";

                // Validate the email format
                isValid = validateEmail(*email);
            } catch (bad_alloc &e) {  // Catch memory allocation exceptions
                cout << "Memory allocation failed: " << e.what() << endl;
                isValid = false;
            }
        }

        ~EmailVerifier() {
            delete email;
            cout << "(EmailVerifier object is destroyed, Memory deallocated.)\n";
        }

        // Method to validate email using basic rules and regex
        bool validateEmail(const string &email) {
            // Simple regex pattern for a basic email structure
            const regex pattern(R"((\w+)(\.{0,1})(\w*)@(\w+)(\.[a-zA-Z]{2,3}))");

            if (regex_match(email, pattern)) {
                return true;
            } else {
                return false;
            }
        }

        // to Display email verification result
        void displayResult() const {
            if (isValid) cout << "The email '" << *email << "' is verified, and it is valid!\n";
            else cout << "The email '" << *email << "' is not valid.\n";
    }
};

int main() {
    string inputEmail;
    cout << "Enter the email address to verify: ";
    getline(cin, inputEmail);  
    EmailVerifier *verifier = new EmailVerifier(inputEmail);
    verifier->displayResult();
    delete verifier;  

    std::cout << "\t\t ** Program executed successfully ** " << std::endl; 
    return 0;
}
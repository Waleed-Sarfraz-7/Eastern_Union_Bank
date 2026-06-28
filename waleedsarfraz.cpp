#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;
// Declaration of all the functions//
// Function to print the first interface of the program
void printFirstInterface();
// Function to print the header1
void header1();
// Function to print "EUB"
void eub();
// Function to print the header
void printHeader();
// Function representing the first interface of the program
void firstInterface();
// Function to handle user sign-up
void signUp(int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int &admincount, string &reservoir);
// Function to check if a user can sign in
bool checksignIn(int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string signInName, string signInPassword, int &indexInAlmostAllArrays);
// Function to update a user's password
void updatePass(int indexInAlmostAllArrays, int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string signInName, string signInPassword);
// Function to handle admin menu
void adminMenu();
// Function to handle employee menu
void employeeMenu();
// Function to handle user menu
void userMenu();
// Function representing the program exit
void exit();
// Function to subtract money from an account
float subtract(float accountMoney, float withdraw);
// Function representing the first option in the main menu
void firstOption(float accountMoney[], int indexInAlmostAllArrays);
// Function representing the main second option in the program
void mainSecondOption(int indexInAlmostAllArrays, int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string &signInName, string &signInPassword, string role[], int selectOption, float accountMoney[], int signupCount, string feedbacks[], int &countOfFeedbacks, int idx, int &admincount, string loan[], string &reservoir, string &salaryEmployee);
// Function to check the account balance
float balance(int indexInAlmostAllArrays, float accountMoney[], int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string signInName, string signInPassword);
// Function to transfer money between accounts
void moneyTransfer(int indexInAlmostAllArrays, float accountMoney[]);
// Function to check the length of the password during sign-up
void pasLenSignUp(int signupCount, string passwordOfUser[]);
// Function to delete a user account
void Delete(int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int &idx, int &admincount, string &reservoir);
// Function to delete an employee account
void empDelete(int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int indexInAlmostAllArrays, int &a);
// Function to view user details
void view(int signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[]);
// Function to check and convert currency
float currency(int indexInAlmostAllArrays, float accountMoney[], int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string signInName, string signInPassword);
// Function to provide user feedback
void feedback(string feedbacks[], int &countOfFeedbacks);
// Function to display user feedback
void showfeed(int countOfFeedbacks, string feedbacks[]);
// Function representing the main second option for admin
void mainSecondAdmin(int selectOption, int sizeOfArray, int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int indexInAlmostAllArrays, string signInName, string signInPassword, int &countOfFeedbacks, string feedbacks[], int idx, int &admincount, string &reservoir);
// Function representing the main second option for manager
void mainSecondManager(int selectOption, int sizeOfArray, int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int &indexInAlmostAllArrays, string signInName, string signInPassword, int &countOfFeedbacks, string feedbacks[], int idx, int &admincount, string &reservoir, string &salaryEmployee);
// Function representing the main second option for employee
void mainSecondEmployee(int selectOption, int &signupCount, int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int indexInAlmostAllArrays, int &countOfFeedbacks, string feedbacks[], string signInName, string signInPassword, int &admincount, string &reservoir);
// Function representing the main second option for user
void mainSecondUser(int selectOption, float accountMoney[], int &indexInAlmostAllArrays, int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string signInName, string signInPassword, string feedbacks[], int &countOfFeedbacks, string loan[], string &reservoir, int signupCount, string role[], int admincount);
// Function to deposit money into an account
void deposit(int indexInAlmostAllArrays, float accountMoney[]);

// Function to handle different types of loans
string loan1();
void homeLoan(int signUpCount, string loan[], float accountMoney[], string &reservoir, int admincount, int signupCount, string nameOfUSer[], string passwordOfUser[], string role[]);
void studentLoan(int signUpCount, string loan[], float accountMoney[], string &reservoir, int admincount, int signupCount, string nameOfUSer[], string passwordOfUser[], string role[]);
void debtConsolidationloan(int signUpCount, string loan[], float accountMoney[], string &reservoir, int admincount, int signupCount, string nameOfUSer[], string passwordOfUser[], string role[]);
// Function to check if a string contains only spaces
bool nameSpace(string input);

// Function to check if a string contains only enter key
bool onlyEnter(string string);

// Function to check if a password contains spaces
bool passwordSpace(string input);

// Function to display information about loans
void seeLoan(string Loan[], int signupCount);

// Function to pay off a loan
void payLoan(string loan[], int signupCount, string &reservoir, float accountMoney[], int admincount);

// Function to get the type of bill to pay
string payBill();

// Functions to pay water, electricity, and gas bills
void waterBill(float accountMoney[], int indexInAlmostAllArrays);
void electricityBill(float accountMoney[], int indexInAlmostAllArrays);
void gasBill(float accountMoney[], int indexInAlmostAllArrays);

// Function to display the list of employees
void seeEmployeeList(int signupCount, string role[], string nameOfUSer[]);

// Function for manager to sign up new users
void signUpByManager(int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int &admincount, string &reservoir);

// Function to extract a specific field from a record
string getField(string record, int field);

// Functions to store and read data from external sources
void storeSignUpOption(string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int signupCount);
void storeReservoir(string reservoir, int admincount);
void storeLoan(string loan[], int signupCount);
void storeFeedback(string feedbacks[], int &countOfFeedbacks);
void storeSalaryEmployee(string salaryEmployee);
void readReservoir(string &reservoir, int &admincount);
void readLoan(string loan[], int signupCount);
void readSignUpOption(string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int &signupCount);
void readFeedback(string feedbacks[], int &countOfFeedbacks);
void readSalaryEmployee(string salaryEmployee);


// bool variables
bool checkUpPass(int signupCount, string arr[], string pass);
bool checkInt(string check);
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int x, int y); // To print statement at a specific location
int x = 25;
int y = 17;
int p = 0;
int q = 0;
main()
{
    system("cls"); // Clears previous commands on the concole.
    printFirstInterface();
    system("cls");
    header1();
    string salaryEmployee = "0";
    string loan[10];
    for (int i = 0; i < 10; i++)
    {
        loan[i] = "0";
    }
    const int sizeOfArray = 10;     // Limits the size of total users to 10.
    int indexInAlmostAllArrays;     // index number in most of the arrays at which the informations are stored parallely.
    int selectOption;               // Takes option in almost all the interfaces/ scenarios.
    int signupCount = 0;            // Keeps count of the users that have signed up.
    int countOfFeedbacks = 0;       // Keeps count of how many feedbacks have been submitted.
    string signInName;              // Stores name of the person who signs in.
    string signInPassword;          // Stores the pasword of thhe person who signs in.
    string nameOfUSer[sizeOfArray]; // All names are stored in this array.
    for (int i = 0; i < 10; i++)
    {
        nameOfUSer[i] = "\t\t";
    }
    string passwordOfUser[sizeOfArray]; // All passwords according to names are stored in this array.
    for (int i = 0; i < 10; i++)
    {
        passwordOfUser[i] = "\t\t";
    }
    string role[sizeOfArray];        // The roles of all the users are stored in this array in a sequence.
    float accountMoney[sizeOfArray]; // The money in the accounts of different users is stored in this array parallely.
    string feedbacks[sizeOfArray];   // Holds the information of feedbacks given by different users in a sequence.
    int idx = -1;
    int admincount = 0;
    string reservoir = "0";

    // main variables
    int counting;         // Variable in which integer type of converted string will be stored.
    string options = "0"; // String which will take input from the user in first place.
    int flag = 0;
    readSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
    readLoan(loan, signupCount);
    readReservoir(reservoir, admincount);
    readFeedback(feedbacks, countOfFeedbacks);
    readSalaryEmployee(salaryEmployee);
    while (true) // Main while loop for running the whole program, that's why its value is always true.
    {
        SetConsoleTextAttribute(h, 15);
        system("cls");
        printHeader();    // Prints Header
        firstInterface(); // Prints the menu which asks for sign-in/sign-up or exit.
        SetConsoleTextAttribute(h, 15);
        cout << "\t\t\t\t\t\t\tWhat can we do for you? ";
        // cin.ignore();
        SetConsoleTextAttribute(h, 6);
        getline(cin, options);
        SetConsoleTextAttribute(h, 15);
        while (true) // Another always true while loop which asks for input and checks its validity.
        {
            // Takes input from the user.
            if (options == "")
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid Input." << endl;
                SetConsoleTextAttribute(h, 15);
                cout << "\t\t\t\t\t\t\tWhat can we do for you? ";
                SetConsoleTextAttribute(h, 6);
                getline(cin, options);
                SetConsoleTextAttribute(h, 15);
            }
            else if (nameSpace(options) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid Input." << endl;
                SetConsoleTextAttribute(h, 15);
                cout << "\t\t\t\t\t\t\tWhat can we do for you? ";
                SetConsoleTextAttribute(h, 6);
                getline(cin, options);
                SetConsoleTextAttribute(h, 15);
            }

            else if (options != "1" && options != "2" && options != "3") // Checks if the input contains only integer values.
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                cout << "\t\t\t\t\t\t\tWhat can we do for you? ";
                SetConsoleTextAttribute(h, 6);
                getline(cin, options); // Loop breaks if only integers are in the input.
                SetConsoleTextAttribute(h, 15);
            }
            else
            {
                break; // If input contains at least one non-integer, command is invalid.
            }
        }
        counting = stoi(options); // Converts options string to integer and stores in int variable, counting.
        // all if commands

        while (true)
        {

            if (counting < 4 && counting >= 1) // Checks if the input was 1, 2 or 3, which are valid inputs.
            {

                if (counting == 1 && signupCount < sizeOfArray) // If condition for first option.
                {                                               // Sign-up function.
                    signUp(signupCount, nameOfUSer, passwordOfUser, role, accountMoney, admincount, reservoir);
                    signupCount++;
                    storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
                    exit();
                    break;
                }
                else if (counting == 2) // If condition for second option.
                {
                    mainSecondOption(indexInAlmostAllArrays, sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword, role, selectOption, accountMoney, signupCount, feedbacks, countOfFeedbacks, idx, admincount, loan, reservoir, salaryEmployee);
                    break;
                }

                else if (counting == 3) // If copndition for third option.
                {
                    flag++;
                    system("cls");
                    break;
                }
                else if (signupCount >= sizeOfArray)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tSorry! You cannot sign Up because limit has been exceeded." << endl;
                    SetConsoleTextAttribute(h, 15);
                    exit();
                    break;
                }
            }
            else // If option was >3 or <1, else works.
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command! " << endl;
                SetConsoleTextAttribute(h, 15);
                exit(); // For invalid input, it exits.
                break;
            }
        }
        if (flag > 0)
        {
            break;
        }
    }
}
// Prints Header
void printHeader()
{
    SetConsoleTextAttribute(h, 11);
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                      -|                      -|=========================================================================|                      -|                      -|" << endl;
    cout << " -|                  -|  -|                  -|  ========================================================================= -|                  -|  -|                  -|  " << endl;
    cout << "   -|              -|      -|              -|                ";
    SetConsoleTextAttribute(h, 13);
    cout << "###########";
    SetConsoleTextAttribute(h, 11);
    cout << "     ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "         ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "     ";
    SetConsoleTextAttribute(h, 13);
    cout << "###########";
    SetConsoleTextAttribute(h, 11);
    cout << "                 -|              -|      -|              -|    " << endl;
    cout << "     -|          -|          -|          -|                  ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "             ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "         ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "     ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "       ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "";
    SetConsoleTextAttribute(h, 11);
    cout << "                 -|          -|          -|          -|      " << endl;
    cout << "       -|      -|              -|      -|                    ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "             ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "         ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "     ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "        ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "";
    SetConsoleTextAttribute(h, 11);
    cout << "                  -|      -|              -|      -|        " << endl;
    cout << "         -|  -|       / - \\      -|  -|                      ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "             ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "         ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "     ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "       ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "";
    SetConsoleTextAttribute(h, 11);
    cout << "                     -|  -|      / - \\       -|  -|          " << endl;
    cout << "           -|         | O |        -|                        ";
    SetConsoleTextAttribute(h, 13);
    cout << "###########";
    SetConsoleTextAttribute(h, 11);
    cout << "     ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "         ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "     ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 13);
    cout << " ########";
    SetConsoleTextAttribute(h, 11);
    cout << "                        -|        | O |         -|            " << endl;
    cout << "         -|  -|       \\ - /      -|  -|                      ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "             ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "         ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "     ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "       ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "";
    SetConsoleTextAttribute(h, 11);
    cout << "                     -|  -|      \\ - /       -|  -|          " << endl;
    cout << "       -|      -|              -|      -|                    ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "             ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "         ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "     ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "        ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "";
    SetConsoleTextAttribute(h, 11);
    cout << "                  -|      -|              -|      -|        " << endl;
    cout << "     -|          -|          -|          -|                  ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "             ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "         ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "     ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "       ";
    SetConsoleTextAttribute(h, 13);
    cout << "###";
    SetConsoleTextAttribute(h, 11);
    cout << "";
    SetConsoleTextAttribute(h, 11);
    cout << "                 -|          -|          -|          -|      " << endl;
    cout << "   -|              -|      -|              -|                ";
    SetConsoleTextAttribute(h, 13);
    cout << "###########";
    SetConsoleTextAttribute(h, 11);
    cout << "       ";
    SetConsoleTextAttribute(h, 13);
    cout << "###########";
    SetConsoleTextAttribute(h, 11);
    cout << "       ";
    SetConsoleTextAttribute(h, 13);
    cout << "############";
    SetConsoleTextAttribute(h, 11);
    cout << "                -|              -|      -|              -|    " << endl;
    cout << " -|                  -|  -|                  -|  ========================================================================= -|                  -|  -|                  -|  " << endl;
    cout << "|                      -|                      -|=========================================================================|                      -|                      -|" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl
         << endl;
    SetConsoleTextAttribute(h, 2);
    cout << "\t\t\t\t\t\t\t**********Welcome to EASTERN UNION BANK!**********" << endl
         << endl
         << endl;
    SetConsoleTextAttribute(h, 6);
}
// First Interface for every user
void firstInterface()
{
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\t1. Sign up" << endl;
    cout << "\t\t\t\t\t\t\t2. Sign in" << endl;
    cout << "\t\t\t\t\t\t\t3. Exit" << endl;
    SetConsoleTextAttribute(h, 15);
}
// Admin's Menu
void adminMenu()
{
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\t\t\t  Admin Menu\n";
    cout << "\t\t\t\t\t\t\t       ************************************\n";
    cout << "\t\t\t\t\t\t\t1. Withdraw money." << endl;
    cout << "\t\t\t\t\t\t\t2. Check balance." << endl;
    cout << "\t\t\t\t\t\t\t3. Money transfer." << endl;
    cout << "\t\t\t\t\t\t\t4. Deposit money." << endl;
    cout << "\t\t\t\t\t\t\t5. Pay Bills." << endl;
    cout << "\t\t\t\t\t\t\t6. Update password." << endl;
    cout << "\t\t\t\t\t\t\t7. Delete account." << endl;
    cout << "\t\t\t\t\t\t\t8. View accounts." << endl;
    cout << "\t\t\t\t\t\t\t9. View feedbacks." << endl;
    cout << "\t\t\t\t\t\t\t10. Add reservoir." << endl;
    cout << "\t\t\t\t\t\t\t11. See available reservoir." << endl;
    cout << "\t\t\t\t\t\t\t12. Exit." << endl;
}
//Manager's Menu
void managerMenu()
{
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\t\t\t  Manager Menu\n";
    cout << "\t\t\t\t\t\t\t       ************************************\n";
    cout << "\t\t\t\t\t\t\t1. Check balance." << endl;
    cout << "\t\t\t\t\t\t\t2. Deposit Money." << endl;
    cout << "\t\t\t\t\t\t\t3. Withdraw Money." << endl;
    cout << "\t\t\t\t\t\t\t4. Money Transfer." << endl;
    cout << "\t\t\t\t\t\t\t5. Update Password." << endl;
    cout << "\t\t\t\t\t\t\t6. View Feedbacks" << endl;
    cout << "\t\t\t\t\t\t\t7. Add Account." << endl;
    cout << "\t\t\t\t\t\t\t8. View Reservoir." << endl;
    cout << "\t\t\t\t\t\t\t9. Pay Bills." << endl;
    cout << "\t\t\t\t\t\t\t10. Delete Account." << endl;
    cout << "\t\t\t\t\t\t\t11. See the List of Employees." << endl;
    cout << "\t\t\t\t\t\t\t12. Decide the Employee's Salary." << endl;
    cout << "\t\t\t\t\t\t\t13. Total Expenditures on Employee." << endl;
    cout << "\t\t\t\t\t\t\t14. Exit." << endl;
    SetConsoleTextAttribute(h, 15);
}
//Employee Menu
void employeeMenu()
{
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\t\t\t  Employee Menu\n";
    cout << "\t\t\t\t\t\t\t       ************************************\n";
    cout << "\t\t\t\t\t\t\t1. Withdraw money." << endl;
    cout << "\t\t\t\t\t\t\t2. Check balance." << endl;
    cout << "\t\t\t\t\t\t\t3. Money transfer." << endl;
    cout << "\t\t\t\t\t\t\t4. Pay bills." << endl;
    cout << "\t\t\t\t\t\t\t5. Update password." << endl;
    cout << "\t\t\t\t\t\t\t6. View accounts." << endl;
    cout << "\t\t\t\t\t\t\t7. Delete account." << endl;
    cout << "\t\t\t\t\t\t\t8. View feedbacks." << endl;
    cout << "\t\t\t\t\t\t\t9. Exit " << endl;
}
//User's Menu
void userMenu()
{
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\t\t\t    User Menu\n";
    cout << "\t\t\t\t\t\t\t       ************************************\n";
    cout << "\t\t\t\t\t\t\t1. Withdraw money." << endl;
    cout << "\t\t\t\t\t\t\t2. Check balance." << endl;
    cout << "\t\t\t\t\t\t\t3. Money transfer." << endl;
    cout << "\t\t\t\t\t\t\t4. Update password." << endl;
    cout << "\t\t\t\t\t\t\t5. Deposit amount" << endl;
    cout << "\t\t\t\t\t\t\t6. Deposit amount in dollars" << endl;
    cout << "\t\t\t\t\t\t\t7. Enter feedback." << endl;
    cout << "\t\t\t\t\t\t\t8. Loan " << endl;
    cout << "\t\t\t\t\t\t\t9. See your aggregate debt" << endl;
    cout << "\t\t\t\t\t\t\t10. Pay your DEBT." << endl;
    cout << "\t\t\t\t\t\t\t11. Pay your BILLS." << endl;
    cout << "\t\t\t\t\t\t\t12. Exit." << endl;
}
// Checks validations for passwords
void pasLenSignUp(int signupCount, string passwordOfUser[])
{
    while (true)
    {
        if (passwordSpace(passwordOfUser[signupCount]) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tSpaces are not allowed in password." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter password: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, passwordOfUser[signupCount]);
            SetConsoleTextAttribute(h, 15);
        }
        else if (passwordOfUser[signupCount].size() != 8)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tEnter password of 8 characters." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter Password: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, passwordOfUser[signupCount]);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
}
// Sign up for all users with validations
void signUp(int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int &admincount, string &reservoir) // Sign-up function.
{
    system("cls");
    printHeader();
    string options = "0";
    float money;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\t\t\t  Signup Menu\n";
    cout << "\t\t\t\t\t\t\t       ************************************\n";
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter name: ";
    SetConsoleTextAttribute(h, 6);
    ////////cin.ignore();
    getline(cin, nameOfUSer[signupCount]);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {

        if (onlyEnter(nameOfUSer[signupCount]) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty" << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter name: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, nameOfUSer[signupCount]);
            SetConsoleTextAttribute(h, 15);
        }
        else if (nameSpace(nameOfUSer[signupCount]) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tSpace cannot be enter at last or first letter." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter name: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, nameOfUSer[signupCount]);
            SetConsoleTextAttribute(h, 15);
        }

        else if (checkUpPass(signupCount, nameOfUSer, nameOfUSer[signupCount]))
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tYou cannot take this username as it has been already taken." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter name: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, nameOfUSer[signupCount]);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        SetConsoleTextAttribute(h, 15);
        cout << "\t\t\t\t\t\t\tEnter password: ";
        SetConsoleTextAttribute(h, 6);
        getline(cin, passwordOfUser[signupCount]);
        SetConsoleTextAttribute(h, 15);
        pasLenSignUp(signupCount, passwordOfUser);
        break;
    }
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter role (admin/manager/employee/user): ";
    // cin.ignore();
    SetConsoleTextAttribute(h, 6);
    getline(cin, role[signupCount]);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        if (role[signupCount] != "admin" && role[signupCount] != "user" && role[signupCount] != "employee" && role[signupCount] != "manager")
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tEnter valid role: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, role[signupCount]);
            SetConsoleTextAttribute(h, 15);
        }
        else if (admincount == 1 && role[signupCount] == "admin")
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tThere cannot be more than one admin." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter any other role: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, role[signupCount]);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            if (role[signupCount] == "admin")
            {
                admincount++;
            }
            break;
        }
    }
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter amount in account: ";
    ////////cin.ignore();
    SetConsoleTextAttribute(h, 6);
    getline(cin, options);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        if (onlyEnter(options) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter amount in account: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, options);
            SetConsoleTextAttribute(h, 15);
        }
        else if (checkInt(options) == 1)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid amount.\n";
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter amount in account: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, options);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    if (role[signupCount] == "admin")
    {
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the total reservior of BANK: ";
            //////cin.ignore();
            SetConsoleTextAttribute(h, 6);
            getline(cin, reservoir);
            SetConsoleTextAttribute(h, 15);
            if (onlyEnter(reservoir) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid amount." << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (checkInt(reservoir) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid amount." << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else
            {
                storeReservoir(reservoir, admincount);
                break;
            }
        }
    }
    money = stof(options);
    accountMoney[signupCount] = money;
    SetConsoleTextAttribute(h, 2);
    cout << "\t\t\t\t\t\t\tYour account has successfully been created." << endl;
    SetConsoleTextAttribute(h, 15);
}
// Checks if the specific user has already signed up or not
bool checksignIn(int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string signInName, string signInPassword, int &indexInAlmostAllArrays)
{
    bool result = false;
    for (int i = 0; i < sizeOfArray; i++)
    {
        if (nameOfUSer[i] == signInName && passwordOfUser[i] == signInPassword)
        {
            indexInAlmostAllArrays = i;
            result = true;
            break;
        }
    }
    return result;
}
// Exit Function. Terminates on main menu, and goes back from other menus.
void exit()
{
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tPress any key to exit...";
    getch();
    cout << endl;
}
// Withdraw Money Function
void firstOption(float accountMoney[], int indexInAlmostAllArrays)
{
    int invalid_invalid = 0;
    float withdraw;
    string options;
    while (true)
    {
        SetConsoleTextAttribute(h, 15);
        cout << "\t\t\t\t\t\t\tEnter amount: ";
        SetConsoleTextAttribute(h, 6);
        getline(cin, options);
        SetConsoleTextAttribute(h, 15);
        while (true)
        {
            if (onlyEnter(options) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid Input.\n";
                SetConsoleTextAttribute(h, 15);
                cout << "\t\t\t\t\t\t\tEnter amount: ";
                SetConsoleTextAttribute(h, 6);
                getline(cin, options);
                SetConsoleTextAttribute(h, 15);
            }

            else if (checkInt(options) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                cout << "\t\t\t\t\t\t\tEnter amount: ";
                SetConsoleTextAttribute(h, 6);
                getline(cin, options);
                SetConsoleTextAttribute(h, 15);
            }
            else
            {
                break;
            }
        }
        withdraw = stof(options);
        if (accountMoney[indexInAlmostAllArrays] >= withdraw)
        {
            if (withdraw < 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tAmount can't be negative." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
                continue;
            }
            accountMoney[indexInAlmostAllArrays] = accountMoney[indexInAlmostAllArrays] - withdraw;
            SetConsoleTextAttribute(h, 2);
            cout << "\t\t\t\t\t\t\tOperation has been successfuly completed." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tAmount left in your account is: " << accountMoney[indexInAlmostAllArrays] << endl;
            exit();
            break;
        }
        else
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tYou don't have enough money!" << endl;
            SetConsoleTextAttribute(h, 15);
            exit();
            break;
        }
    }
}
// Takes inputs from admin and executes respective command by calling different functions.
void mainSecondAdmin(int selectOption, int sizeOfArray, int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int indexInAlmostAllArrays, string signInName, string signInPassword, int &countOfFeedbacks, string feedbacks[], int idx, int &admincount, string &reservoir) // Sign-up function.

{
    while (true)
    {
        system("cls");
        printHeader();
        adminMenu();
        string options;
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter key: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, options);
            SetConsoleTextAttribute(h, 15);
            if (onlyEnter(options) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
            else if (checkInt(options) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
            else
            {
                break;
            }
        }
        selectOption = stoi(options);
        if (selectOption == 1)
        {
            firstOption(accountMoney, indexInAlmostAllArrays);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
        }
        else if (selectOption == 2)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tAmount in your account is: ";
            SetConsoleTextAttribute(h, 2);
            cout << balance(indexInAlmostAllArrays, accountMoney, sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword) << endl;
            exit();
        }
        else if (selectOption == 3)
        {
            moneyTransfer(indexInAlmostAllArrays, accountMoney);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
        }
        else if (selectOption == 4)
        {
            deposit(indexInAlmostAllArrays, accountMoney);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            exit();
        }
        else if (selectOption == 5)
        {
            string p = payBill();
            if (p == "1")
            {
                electricityBill(accountMoney, indexInAlmostAllArrays);
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            }
            else if (p == "2")
            {
                gasBill(accountMoney, indexInAlmostAllArrays);
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            }
            else
            {
                waterBill(accountMoney, indexInAlmostAllArrays);
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            }
        }
        else if (selectOption == 6)
        {
            updatePass(indexInAlmostAllArrays, sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword);
            exit();
        }
        else if (selectOption == 7)
        {
            Delete(signupCount, nameOfUSer, passwordOfUser, role, accountMoney, idx, admincount, reservoir);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
        }
        else if (selectOption == 8)
        {
            view(signupCount, nameOfUSer, passwordOfUser, role, accountMoney);
            exit();
        }
        else if (selectOption == 9)
        {
            showfeed(countOfFeedbacks, feedbacks);
        }

        else if (selectOption == 10)
        {
            string addReservoir;
            while (true)
            {
                SetConsoleTextAttribute(h, 15);
                cout << "\t\t\t\t\t\t\tEnter the amount of money you want to add: ";
                SetConsoleTextAttribute(h, 6);
                getline(cin, addReservoir);
                SetConsoleTextAttribute(h, 15);
                if (onlyEnter(addReservoir) == 0)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tInvalid input...\n";
                    SetConsoleTextAttribute(h, 15);
                }
                else if (checkInt(addReservoir) == 1)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tInvalid input...\n";
                    SetConsoleTextAttribute(h, 15);
                }
                else
                {
                    int p = stof(addReservoir);
                    int k = stof(reservoir);
                    int j = p + k;
                    reservoir = to_string(j);
                    SetConsoleTextAttribute(h, 15);
                    cout << "\t\t\t\t\t\t\tThe reservoir is now ";
                    SetConsoleTextAttribute(h, 2);
                    cout << reservoir;
                    storeReservoir(reservoir, admincount);
                    SetConsoleTextAttribute(h, 15);
                    cout << ".";
                    getch();
                    break;
                }
            }
        }
        else if (selectOption == 11)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tThe reservoir in your bank is: ";
            SetConsoleTextAttribute(h, 2);
            cout << reservoir;
            getch();
        }
        else if (selectOption == 12)
        {
            break;
        }
        else if (selectOption > 12 || selectOption < 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid command.";
            SetConsoleTextAttribute(h, 15);
            exit();
        }
    }
}
// Takes inputs from employee and executes respective command by calling different functions.
void mainSecondEmployee(int selectOption, int &signupCount, int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int indexInAlmostAllArrays, int &countOfFeedbacks, string feedbacks[], string signInName, string signInPassword, int &admincount, string &reservoir)
{
    while (true)
    {
        string options;
        system("cls");
        printHeader();
        employeeMenu();
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter key: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, options);
            SetConsoleTextAttribute(h, 15);

            if (onlyEnter(options) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
            else if (checkInt(options) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
            else
            {
                break;
            }
        }
        selectOption = stoi(options);
        if (selectOption == 1)
        {
            firstOption(accountMoney, indexInAlmostAllArrays);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
        }
        else if (selectOption == 2)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tAmount in your account is: ";
            SetConsoleTextAttribute(h, 2);
            cout << balance(indexInAlmostAllArrays, accountMoney, sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword) << endl;
            exit();
        }
        else if (selectOption == 3)
        {
            moneyTransfer(indexInAlmostAllArrays, accountMoney);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
        }
        else if (selectOption == 4)
        {
            string p = payBill();
            if (p == "1")
            {
                electricityBill(accountMoney, indexInAlmostAllArrays);
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            }
            else if (p == "2")
            {
                gasBill(accountMoney, indexInAlmostAllArrays);
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            }
            else
            {
                waterBill(accountMoney, indexInAlmostAllArrays);
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            }
        }
        else if (selectOption == 5)
        {
            updatePass(indexInAlmostAllArrays, sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            exit();
        }
        else if (selectOption == 6)
        {
            view(signupCount, nameOfUSer, passwordOfUser, role, accountMoney);
            exit();
        }
        else if (selectOption == 7)
        {
            int a;
            empDelete(signupCount, nameOfUSer, passwordOfUser, role, accountMoney, indexInAlmostAllArrays, a);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            if (a == -1)
            {
                break;
            }
        }
        else if (selectOption == 8)
        {
            showfeed(countOfFeedbacks, feedbacks);
        }
        else if (selectOption == 9)
        {
            break;
        }
        else if (selectOption > 12 || selectOption < 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid command.";
            SetConsoleTextAttribute(h, 15);
            exit();
        }
    }
}
// Takes inputs from user and executes respective command by calling different functions.
void mainSecondUser(int selectOption, float accountMoney[], int &indexInAlmostAllArrays, int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string signInName, string signInPassword, string feedbacks[], int &countOfFeedbacks, string loan[], string &reservoir, int signupCount, string role[], int admincount)
{
    while (true)
    {
        string options;
        system("cls");
        printHeader();
        userMenu();
        SetConsoleTextAttribute(h, 15);
        cout << "\t\t\t\t\t\t\tEnter key: ";
        SetConsoleTextAttribute(h, 6);
        getline(cin, options);
        SetConsoleTextAttribute(h, 15);
        while (true)
        {

            if (onlyEnter(options) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                cout << "\t\t\t\t\t\t\tEnter key: ";
                SetConsoleTextAttribute(h, 6);
                getline(cin, options);
                SetConsoleTextAttribute(h, 15);
                exit();
            }
            else if (checkInt(options) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                cout << "\t\t\t\t\t\t\tEnter key: ";
                SetConsoleTextAttribute(h, 6);
                getline(cin, options);
                SetConsoleTextAttribute(h, 15);
                exit();
            }
            else
            {
                break;
            }
        }
        selectOption = stoi(options);
        if (selectOption == 1)
        {
            firstOption(accountMoney, indexInAlmostAllArrays);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
        }
        else if (selectOption == 2)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tAmount in your account is: ";
            SetConsoleTextAttribute(h, 2);
            cout << balance(indexInAlmostAllArrays, accountMoney, sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword) << endl;
            exit();
        }
        else if (selectOption == 3)
        {
            moneyTransfer(indexInAlmostAllArrays, accountMoney);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
        }
        else if (selectOption == 4)
        {
            updatePass(indexInAlmostAllArrays, sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            exit();
        }
        else if (selectOption == 5)
        {
            deposit(indexInAlmostAllArrays, accountMoney);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            exit();
        }
        else if (selectOption == 6)
        {
            currency(indexInAlmostAllArrays, accountMoney, sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            SetConsoleTextAttribute(h, 2);
            cout << "\t\t\t\t\t\t\tNow amount in your account is: " << accountMoney[indexInAlmostAllArrays] << endl;
            exit();
        }
        else if (selectOption == 7)
        {
            feedback(feedbacks, countOfFeedbacks);
            storeFeedback(feedbacks, countOfFeedbacks);
        }
        else if (selectOption == 8)
        {
            if (loan[indexInAlmostAllArrays] == "0")
            {
                system("cls");
                printHeader();
                string option = loan1();
                if (option == "1")
                {
                    homeLoan(indexInAlmostAllArrays, loan, accountMoney, reservoir, admincount, signupCount, nameOfUSer, passwordOfUser, role);
                    storeLoan(loan, signupCount);
                }
                else if (option == "2")
                {
                    studentLoan(indexInAlmostAllArrays, loan, accountMoney, reservoir, admincount, signupCount, nameOfUSer, passwordOfUser, role);
                    storeLoan(loan, signupCount);
                }
                else if (option == "3")
                {
                    debtConsolidationloan(indexInAlmostAllArrays, loan, accountMoney, reservoir, admincount, signupCount, nameOfUSer, passwordOfUser, role);
                    storeLoan(loan, signupCount);
                }
                else
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tInvalid Input...";
                    SetConsoleTextAttribute(h, 15);
                }
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tPay your previous loan first.";
                SetConsoleTextAttribute(h, 15);
                getch();
            }
        }
        else if (selectOption == 9)
        {
            seeLoan(loan, indexInAlmostAllArrays);
        }
        else if (selectOption == 10)
        {
            payLoan(loan, indexInAlmostAllArrays, reservoir, accountMoney, admincount);
            storeLoan(loan, signupCount);
        }
        else if (selectOption == 11)
        {
            string p = payBill();
            if (p == "1")
            {
                electricityBill(accountMoney, indexInAlmostAllArrays);
            }
            else if (p == "2")
            {
                gasBill(accountMoney, indexInAlmostAllArrays);
            }
            else if (p == "3")
            {
                waterBill(accountMoney, indexInAlmostAllArrays);
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid Input" << endl;
                SetConsoleTextAttribute(h, 15);
                getch();
            }
        }
        else if (selectOption == 12)
        {
            break;
        }
        else if (selectOption > 9 || selectOption < 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid command.";
            SetConsoleTextAttribute(h, 15);
            exit();
        }
    }
}
// Takes credentials from users and opens a menu according to given credentials, also checks validtions.
void mainSecondOption(int indexInAlmostAllArrays, int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string &signInName, string &signInPassword, string role[], int selectOption, float accountMoney[], int signupCount, string feedbacks[], int &countOfFeedbacks, int idx, int &admincount, string loan[], string &reservoir, string &salaryEmployee)
{
    system("cls");
    printHeader();
    cout << "\t\t\t\t\t\t\t\t\t  Signin Menu\n";
    cout << "\t\t\t\t\t\t\t       ************************************\n";
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter your name: ";
    //////cin.ignore();
    SetConsoleTextAttribute(h, 6);
    getline(cin, signInName);
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter your password: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, signInPassword);
    SetConsoleTextAttribute(h, 15);
    if (checksignIn(sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword, indexInAlmostAllArrays))
    {
        if (role[indexInAlmostAllArrays] == "admin")
        {
            mainSecondAdmin(selectOption, sizeOfArray, signupCount, nameOfUSer, passwordOfUser, role, accountMoney, indexInAlmostAllArrays, signInName, signInPassword, countOfFeedbacks, feedbacks, idx, admincount, reservoir); // Sign-up function.
        }
        else if (role[indexInAlmostAllArrays] == "employee")
        {
            mainSecondEmployee(selectOption, signupCount, sizeOfArray, nameOfUSer, passwordOfUser, role, accountMoney, indexInAlmostAllArrays, countOfFeedbacks, feedbacks, signInName, signInPassword, admincount, reservoir);
        }
        else if (role[indexInAlmostAllArrays] == "user")
        {
            mainSecondUser(selectOption, accountMoney, indexInAlmostAllArrays, sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword, feedbacks, countOfFeedbacks, loan, reservoir, signupCount, role, admincount);
        }
        else
        {
            mainSecondManager(selectOption, sizeOfArray, signupCount, nameOfUSer, passwordOfUser, role, accountMoney, indexInAlmostAllArrays, signInName, signInPassword, countOfFeedbacks, feedbacks, idx, admincount, reservoir, salaryEmployee);
        }
    }
    else
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\t\t\t\tInvalid information" << endl;
        SetConsoleTextAttribute(h, 15);
        getch();
    }
}
// Check Balance Function
float balance(int indexInAlmostAllArrays, float accountMoney[], int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string signInName, string signInPassword)
{
    if (checksignIn(sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword, indexInAlmostAllArrays))
    {
        return accountMoney[indexInAlmostAllArrays];
    }
}
// Updates the password with validations.
void updatePass(int indexInAlmostAllArrays, int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string signInName, string signInPassword)
{
    string password;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter new password: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, password);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {

        if (password == passwordOfUser[indexInAlmostAllArrays])
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tNew Password cannot be same as a old password." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter new password: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, password);
            SetConsoleTextAttribute(h, 15);
        }
        else if (onlyEnter(password) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter new password: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, password);
            SetConsoleTextAttribute(h, 15);
        }
        else if (passwordSpace(password) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tSpaces are not allowed in password." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter new password: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, password);
            SetConsoleTextAttribute(h, 15);
        }
        else if (password.size() != 8)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tEnter password of 8 characters." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter new password: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, password);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    passwordOfUser[indexInAlmostAllArrays] = password;
    SetConsoleTextAttribute(h, 2);
    cout << "\t\t\t\t\t\t\tPassword has been updated.\n";
}
// Money transfer function
void moneyTransfer(int indexInAlmostAllArrays, float accountMoney[])
{
    firstOption(accountMoney, indexInAlmostAllArrays);
}
// Deducts money from account
float subtract(float accountMoney, float withdraw)
{
    float left = accountMoney - withdraw;
    return left;
}

// Adds money to account
void deposit(int indexInAlmostAllArrays, float accountMoney[])
{
    string money;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter the amount of money you want to deposit: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, money);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        if (onlyEnter(money) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput can't be empty.\n";
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter a valid input: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, money);
            SetConsoleTextAttribute(h, 15);
        }
        else if (nameSpace(money) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tSpaces are not allowed.\n";
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter a valid input: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, money);
            SetConsoleTextAttribute(h, 15);
        }
        else if (stof(money) < 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tAmount can't be negative." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amount of money you want to deposit: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, money);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    accountMoney[indexInAlmostAllArrays] = accountMoney[indexInAlmostAllArrays] + stof(money);
    SetConsoleTextAttribute(h, 2);
    cout << "\t\t\t\t\t\t\t" << money << " rupees have been deposited to your account." << endl;
    SetConsoleTextAttribute(h, 15);
}
// Delets account
void Delete(int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int &idx, int &admincount, string &reservoir)
{
    string Name, Password;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter name: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, Name);
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter password: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, Password);
    SetConsoleTextAttribute(h, 15);
    for (int i = 0; i < signupCount; i++)
    {
        if (nameOfUSer[i] == Name && passwordOfUser[i] == Password && role[i] == "admin")
        {
            admincount = 0;
            idx = i;
            reservoir = "0";
            storeReservoir(reservoir, admincount);
            break;
        }
        else if (nameOfUSer[i] == Name && passwordOfUser[i] == Password)
        {
            idx = i;
            break;
        }
    }
    if (idx >= 0)
    {
        nameOfUSer[idx] = false;
        passwordOfUser[idx] = false;
        role[idx] = false;
        accountMoney[idx] = false;
        signupCount--;
        storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
    }
    if (idx == -1)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "Invalid Command.";
        SetConsoleTextAttribute(h, 15);
        cout << "Please enter a valid one...";
        getch();
    }
    if (idx >= 0)
    {
        SetConsoleTextAttribute(h, 2);
        cout << "\t\t\t\t\t\t\tAccount Deleted successfuly";
        SetConsoleTextAttribute(h, 15);
        exit();
    }
}
// Delete user function for emplyee and manager
void empDelete(int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int indexInAlmostAllArrays, int &a)
{
    int b = -1;
    string Name, Password;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter name: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, Name);
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter password: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, Password);
    SetConsoleTextAttribute(h, 15);

    for (int i = 0; i < signupCount; i++)
    {
        if (nameOfUSer[i] == Name && passwordOfUser[i] == Password)
        {
            if (role[i] == "admin")
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tWrong Credentials" << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
                continue;
            }
            if (role[i] != "admin" && role[i]!="manager" && i == indexInAlmostAllArrays)
            {
                a = indexInAlmostAllArrays;
                b = i;
                nameOfUSer[i] = false;
                passwordOfUser[i] = false;
                role[i] = false;
                accountMoney[i] = false;
                SetConsoleTextAttribute(h, 2);
                cout << "\t\t\t\t\t\t\tYour account has been deleted" << endl;
                SetConsoleTextAttribute(h, 15);
                signupCount--;
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
                exit();
                break;
            }
            if (role[i] != "admin")
            {
                b = i;
                nameOfUSer[i] = false;
                passwordOfUser[i] = false;
                role[i] = false;
                accountMoney[i] = false;
                SetConsoleTextAttribute(h, 2);
                cout << "\t\t\t\t\t\t\tOperation successful." << endl;
                SetConsoleTextAttribute(h, 15);
                signupCount--;
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
                exit();
                break;
            }
        }
    }
    if (b == -1)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\t\t\t\tWrong Credentials!" << endl;
        SetConsoleTextAttribute(h, 15);
        exit();
    }
}
// Shows accounts of all the users
void view(int signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[])
{
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\tName\tPassword\tRole\tAccout Money" << endl;
    SetConsoleTextAttribute(h, 15);
    for (int i = 0; i < signupCount; i++)
    {
        cout << "\t\t\t\t\t\t\t" << i + 1 << "." << nameOfUSer[i] << "\t" << passwordOfUser[i] << "\t" << role[i] << "\t" << accountMoney[i] << endl;
    }
}
// Deposit amount in dollars function
float currency(int indexInAlmostAllArrays, float accountMoney[], int sizeOfArray, string nameOfUSer[], string passwordOfUser[], string signInName, string signInPassword)
{
    float money;
    if (checksignIn(sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword, indexInAlmostAllArrays))
    {
        string options;
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter amount in dollars to add in account: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, options);
            SetConsoleTextAttribute(h, 15);
            if (checkInt(options) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
            else
            {
                SetConsoleTextAttribute(h, 2);
                cout << "\t\t\t\t\t\t\t" << options << " dollars have been added to your account." << endl;
                SetConsoleTextAttribute(h, 15);
                getch();
                break;
            }
        }
        money = stof(options);
        accountMoney[indexInAlmostAllArrays] = accountMoney[indexInAlmostAllArrays] + (money * 285);
        return accountMoney[indexInAlmostAllArrays];
    }
}
// Takes a valid input from the user
void feedback(string feedbacks[], int &countOfFeedbacks)
{
    string feed;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter your feedback:" << endl;
    SetConsoleTextAttribute(h, 6);
    getline(cin, feed);
    SetConsoleTextAttribute(h, 15);
    feedbacks[countOfFeedbacks] = feed;
    countOfFeedbacks++;
    SetConsoleTextAttribute(h, 2);
    cout << "\t\t\t\t\t\t\tYour feedback has been sent to the admin.";
    SetConsoleTextAttribute(h, 15);
    getch();
}
// Shows feedback of the users to administrators
void showfeed(int countOfFeedbacks, string feedbacks[])
{
    if (countOfFeedbacks == 0)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\t\t\t\tThere is no feedback yet." << endl;
        SetConsoleTextAttribute(h, 15);
        getch();
    }
    else
    {
        for (int i = 0; i < countOfFeedbacks; i++)
        {
            SetConsoleTextAttribute(h, 6);
            cout << feedbacks[i] << endl;
            SetConsoleTextAttribute(h, 15);
            getch();
        }
    }
}
// Checks wether password entered by user is present in the database
bool checkUpPass(int signupCount, string arr[], string pass)
{
    bool result = false;
    for (int i = 0; i < signupCount; i++)
    {
        if (pass == arr[i])
        {
            result = true;
        }
    }
    return result;
}
bool checkInt(string check)// Checks if the input string contains all the integers and not at least even one non-integer.
{
    for (int q = 0; check[q] != '\0'; q++) // The loop runs the time the length of the input string.
    {
        int b = check[q];
        if (b != 48 && b != 49 && b != 50 && b != 51 && b != 52 && b != 53 && b != 54 && b != 55 && b != 56 && b != 57)// Checks if input is greater than or equal to 0(ASCII=48) and less than or equal to 9(ASCII=57).
        {
            return 1;
        }
    }
    return 0;
}
//Main interface of all loan functionalities
string loan1()
{
    string option;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\t\t\t    Loan Menu\n";
    cout << "\t\t\t\t\t\t\t       ************************************\n";
    cout << "\t\t\t\t\t\t\t1. Home loan" << endl;
    cout << "\t\t\t\t\t\t\t2. Student loan " << endl;
    cout << "\t\t\t\t\t\t\t3. Debt consolidation loan" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter key: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, option);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {

        if (option != "1" && option != "2" && option != "3")
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid option" << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter a valid key: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, option);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    return option;
}
// Home loan function
void homeLoan(int indexConfirm, string loan[], float accountMoney[], string &reservoir, int admincount, int signupCount, string nameOfUSer[], string passwordOfUser[], string role[])
{
    system("cls");
    printHeader();
    string grade;
    string confirm;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\tHome loan ranges from 25000 Rs to 50000 Rs" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tYou are a goverment officer(Yes/No): ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, confirm);
    SetConsoleTextAttribute(h, 15);
    if (confirm == "No" || confirm == "NO" || confirm == "no" || confirm == "nO" || confirm == "N" || confirm == "n")
    {
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amount of loan you need:  Rs";
            SetConsoleTextAttribute(h, 6);
            getline(cin, loan[indexConfirm]);
            SetConsoleTextAttribute(h, 15);
            string p = (loan[indexConfirm]);
            if (onlyEnter(p) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (checkInt(p) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (stof(p) > 50000 || stof(p) < 25000)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tOut of range..." << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else
            {
                if (stof(reservoir) >= stof(loan[indexConfirm]))
                {
                    int l = stof(reservoir) - stof(loan[indexConfirm]);
                    reservoir = to_string(l);
                    accountMoney[indexConfirm] = accountMoney[indexConfirm] + stof(loan[indexConfirm]);
                    SetConsoleTextAttribute(h, 2);
                    cout << "\t\t\t\t\t\t\tLoan of amount " << loan[indexConfirm] << " rupees has been added to your account. Remember to pay your installments on time.";
                    SetConsoleTextAttribute(h, 15);
                    storeReservoir(reservoir, admincount);
                    storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
                    getch();
                    break;
                }
                else if (stof(reservoir) <= stof(loan[indexConfirm]))
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tSorry, BANK reservoir is not enough as per your demands.";
                    SetConsoleTextAttribute(h, 15);
                    getch();
                    break;
                }
            }
        }
    }
    else if (confirm == "Yes" || confirm == "yes" || confirm == "Y" || confirm == "yES" || confirm == "yEs" || confirm == "yeS" || confirm == "YeS" || confirm == "y" || confirm == "YEs")
    {
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tWhat is your grade: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, grade);
            SetConsoleTextAttribute(h, 15);
            if (onlyEnter(grade) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (checkInt(grade) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid Input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (stoi(grade) > 22 || stoi(grade) < 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid Input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else
            {
                break;
            }
        }
        int a = stoi(grade);
        if (a > 16)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tSorry, You are not eligible for this loan.";
            SetConsoleTextAttribute(h, 15);
            getch();
        }
        else if (a <= 16)
        {
            while (true)
            {
                SetConsoleTextAttribute(h, 15);
                cout << "\t\t\t\t\t\t\tEnter the amount of loan you need:  Rs";
                SetConsoleTextAttribute(h, 6);
                getline(cin, loan[indexConfirm]);
                SetConsoleTextAttribute(h, 15);
                if (onlyEnter(loan[indexConfirm]) == 0)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                    SetConsoleTextAttribute(h, 15);
                }

                else if (checkInt(loan[indexConfirm]) == 1)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tInvalid input\n";
                    SetConsoleTextAttribute(h, 15);
                }
                else if (stof(loan[indexConfirm]) < 25000 || stof(loan[indexConfirm]) > 50000)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tOut of range\n";
                    SetConsoleTextAttribute(h, 15);
                }
                else
                {
                    if (stof(reservoir) >= stof(loan[indexConfirm]))
                    {
                        int l = stof(reservoir) - stof(loan[indexConfirm]);
                        reservoir = to_string(l);
                        accountMoney[indexConfirm] = accountMoney[indexConfirm] + stof(loan[indexConfirm]);
                        SetConsoleTextAttribute(h, 2);
                        cout << "\t\t\t\t\t\t\tLoan of amount " << loan[indexConfirm] << " rupees has been added to your account. Remember to pay your installments on time.";
                        storeReservoir(reservoir, admincount);
                        storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
                        SetConsoleTextAttribute(h, 15);
                        getch();
                        break;
                    }
                    else if (stof(reservoir) <= stof(loan[indexConfirm]))
                    {
                        SetConsoleTextAttribute(h, 4);
                        cout << "\t\t\t\t\t\t\tSorry, BANK reservoir is not enough as per your demands.";
                        SetConsoleTextAttribute(h, 15);
                        getch();
                        break;
                    }
                }
            }
        }
    }
    else
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\t\t\t\tInvalid Input..." << endl;
        SetConsoleTextAttribute(h, 15);
        getch();
    }
}
// Student loan function
void studentLoan(int signUpCount, string loan[], float accountMoney[], string &reservoir, int admincount, int signupCount, string nameOfUSer[], string passwordOfUser[], string role[])
{
    system("cls");
    printHeader();
    string standard;
    while (true)
    {
        SetConsoleTextAttribute(h, 15);
        cout << "\t\t\t\t\t\t\tEnter your standard: " << endl;
        cout << "\t\t\t\t\t\t\t(0 for less than MATRIC, 1 for MATRIC, 2 for FSC, 3 for BACHELORS, 4 for MASTERS, 5 for PhD)";
        SetConsoleTextAttribute(h, 6);
        getline(cin, standard);
        SetConsoleTextAttribute(h, 15);
        if (onlyEnter(standard) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid input" << endl;
            SetConsoleTextAttribute(h, 15);
        }
        else if (checkInt(standard) == 1)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid Input..." << endl;
            SetConsoleTextAttribute(h, 15);
        }
        else if (stoi(standard) < 0 || stoi(standard) > 5)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid Input..." << endl;
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    if (standard == "0")
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\t\t\t\tSorry, You are not eligible for this loan..." << endl;
        SetConsoleTextAttribute(h, 15);
        getch();
    }
    else if (standard == "1")
    {
        SetConsoleTextAttribute(h, 6);
        cout << "\t\t\t\t\t\t\tStudent loan for MATRIC standard ranges from 500 Rs to 1000 Rs" << endl;
        SetConsoleTextAttribute(h, 15);
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amount of loan you need: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, loan[signUpCount]);
            SetConsoleTextAttribute(h, 15);
            if (onlyEnter(loan[signUpCount]) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (checkInt(loan[signUpCount]) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (stof(loan[signUpCount]) < 500 || stof(loan[signUpCount]) > 1000)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else
            {
                if (stof(reservoir) >= stof(loan[signUpCount]))
                {
                    int l = stof(reservoir) - stof(loan[signUpCount]);
                    reservoir = to_string(l);
                    accountMoney[signUpCount] = accountMoney[signUpCount] + stof(loan[signUpCount]);
                    SetConsoleTextAttribute(h, 2);
                    cout << "\t\t\t\t\t\t\tLoan of amount " << loan[signUpCount] << " rupees has been added to your account. Remember to pay your installments on time.";
                    storeReservoir(reservoir, admincount);
                    storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
                    SetConsoleTextAttribute(h, 15);
                    getch();
                    break;
                }
                else if (stof(reservoir) >= stof(loan[signUpCount]))
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tSorry, BANK reservoir is not enoungh as per your demand.";
                    SetConsoleTextAttribute(h, 15);
                    getch();
                    break;
                }
            }
        }
    }
    else if (standard == "2")
    {
        SetConsoleTextAttribute(h, 6);
        cout << "\t\t\t\t\t\t\tStudent loan for FSC standard ranges from 500 Rs to 2000 Rs" << endl;
        SetConsoleTextAttribute(h, 15);
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amount of loan you need: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, loan[signUpCount]);
            SetConsoleTextAttribute(h, 15);
            if (onlyEnter(loan[signUpCount]) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (checkInt(loan[signUpCount]) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid Input..." << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (stof(loan[signUpCount]) < 500 || stof(loan[signUpCount]) > 2000)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid Input..." << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else
            {
                if (stof(reservoir) >= stof(loan[signUpCount]))
                {
                    int l = stof(reservoir) - stof(loan[signUpCount]);
                    reservoir = to_string(l);
                    accountMoney[signUpCount] = accountMoney[signUpCount] + stof(loan[signUpCount]);
                    SetConsoleTextAttribute(h, 2);
                    cout << "\t\t\t\t\t\t\tLoan of amount " << loan[signUpCount] << " rupees has been added to your account. Remember to pay your installments on time.";
                    storeReservoir(reservoir, admincount);
                    storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
                    SetConsoleTextAttribute(h, 15);
                    getch();
                    break;
                }
                else if (stof(reservoir) <= stof(loan[signUpCount]))
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tSorry, BANK reservoir is not enough as per your demands.";
                    SetConsoleTextAttribute(h, 15);
                    getch();
                    break;
                }
            }
        }
    }
    else if (standard == "3")
    {
        SetConsoleTextAttribute(h, 6);
        cout << "\t\t\t\t\t\t\tStudent loan for BACHELORS standard ranges from 1000 Rs to 3000 Rs" << endl;
        SetConsoleTextAttribute(h, 15);
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amount of loan you need: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, loan[signUpCount]);
            SetConsoleTextAttribute(h, 15);
            if (onlyEnter(loan[signUpCount]) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (checkInt(loan[signUpCount]) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (stof(loan[signUpCount]) < 1000 || stof(loan[signUpCount]) > 3000)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else
            {
                if (stof(reservoir) >= stof(loan[signUpCount]))
                {
                    int l = stof(reservoir) - stof(loan[signUpCount]);
                    reservoir = to_string(l);
                    accountMoney[signUpCount] = accountMoney[signUpCount] + stof(loan[signUpCount]);
                    SetConsoleTextAttribute(h, 2);
                    cout << "\t\t\t\t\t\t\tLoan of amount " << loan[signUpCount] << " rupees has been added to your account. Remember to pay your installments on time.";
                    storeReservoir(reservoir, admincount);
                    storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
                    SetConsoleTextAttribute(h, 15);
                    getch();
                    break;
                }
                else if (stof(reservoir) <= stof(loan[signUpCount]))
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tSorry, BANK reservoir is not enough as per your demand.";
                    SetConsoleTextAttribute(h, 15);
                    getch();
                    break;
                }
            }
        }
    }
    else if (standard == "4")
    {
        SetConsoleTextAttribute(h, 6);
        cout << "\t\t\t\t\t\t\tStudent loan for MASTERS standard ranges from 2000 Rs to 4000 Rs" << endl;
        SetConsoleTextAttribute(h, 15);
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amount of loan you need: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, loan[signUpCount]);
            SetConsoleTextAttribute(h, 15);
            if (onlyEnter(loan[signUpCount]) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (checkInt(loan[signUpCount]) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (stof(loan[signUpCount]) < 2000 || stof(loan[signUpCount]) > 4000)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else
            {
                if (stof(reservoir) >= stof(loan[signUpCount]))
                {
                    int l = stof(reservoir) - stof(loan[signUpCount]);
                    reservoir = to_string(l);
                    accountMoney[signUpCount] = accountMoney[signUpCount] + stof(loan[signUpCount]);
                    SetConsoleTextAttribute(h, 2);
                    cout << "\t\t\t\t\t\t\tLoan of amount " << loan[signUpCount] << " rupees has been added to your account. Remember to pay your installments on time.";
                    storeReservoir(reservoir, admincount);
                    storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
                    SetConsoleTextAttribute(h, 15);
                    getch();
                    break;
                }
                else if (stof(reservoir) <= stof(loan[signUpCount]))
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tSorry, BANK reservoir is not enough as per your demnad.";
                    SetConsoleTextAttribute(h, 15);
                    getch();
                    break;
                }
            }
        }
    }
    else if (standard == "5")
    {
        cout << "\t\t\t\t\t\t\tStudent loan for MATRIC standard ranges from 2500 Rs to 5000 Rs" << endl;
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amount of loan you need: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, loan[signUpCount]);
            SetConsoleTextAttribute(h, 15);
            if (onlyEnter(loan[signUpCount]) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (checkInt(loan[signUpCount]) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else if (stof(loan[signUpCount]) < 2500 || stof(loan[signUpCount]) > 5000)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid input" << endl;
                SetConsoleTextAttribute(h, 15);
            }
            else
            {
                if (stof(reservoir) >= stof(loan[signUpCount]))
                {
                    int l = stof(reservoir) - stof(loan[signUpCount]);
                    reservoir = to_string(l);
                    accountMoney[signUpCount] = accountMoney[signUpCount] + stof(loan[signUpCount]);
                    SetConsoleTextAttribute(h, 2);
                    cout << "\t\t\t\t\t\t\tLoan of amount " << loan[signUpCount] << " rupees has been added to your account. Remember to pay your installments on time.";
                    storeReservoir(reservoir, admincount);
                    storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
                    SetConsoleTextAttribute(h, 15);
                    getch();
                    break;
                }
                else if (stof(reservoir) <= stof(loan[signUpCount]))
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tSorry, BANK reservoir is not enough as per your demnad.";
                    SetConsoleTextAttribute(h, 15);
                    getch();
                    break;
                }
            }
        }
    }
    else
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\t\t\t\tInvalid Input..." << endl;
        SetConsoleTextAttribute(h, 15);
        exit();
    }
}
// Debt Consolidation Loan
void debtConsolidationloan(int signUpCount, string loan[], float accountMoney[], string &reservoir, int admincount, int signupCount, string nameOfUSer[], string passwordOfUser[], string role[])
{
    system("cls");
    printHeader();
    string underLoan;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\tDebt consolidation loan ranges  upto 25000 Rs." << endl;
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        SetConsoleTextAttribute(h, 15);
        cout << "\t\t\t\t\t\t\tHow much debt you are under: " << endl;
        SetConsoleTextAttribute(h, 6);
        //////cin.ignore();
        getline(cin, underLoan);
        SetConsoleTextAttribute(h, 15);
        if (onlyEnter(underLoan) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid input" << endl;
            SetConsoleTextAttribute(h, 15);
        }
        else if (checkInt(underLoan) == 1)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid input" << endl;
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        SetConsoleTextAttribute(h, 15);
        cout << "\t\t\t\t\t\t\tEnter the amount of loan you need: ";
        //////cin.ignore();
        SetConsoleTextAttribute(h, 6);
        getline(cin, loan[signUpCount]);
        SetConsoleTextAttribute(h, 15);
        if (onlyEnter(loan[signUpCount]) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid input" << endl;
            SetConsoleTextAttribute(h, 15);
        }
        else if (checkInt(loan[signUpCount]) == 1)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid input" << endl;
            SetConsoleTextAttribute(h, 15);
        }
        else if (stof(loan[signUpCount]) > 25000)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid input" << endl;
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            if (stof(reservoir) >= stof(loan[signUpCount]))
            {
                int l = stof(reservoir) - stof(loan[signUpCount]);
                reservoir = to_string(l);
                accountMoney[signUpCount] = accountMoney[signUpCount] + stof(loan[signUpCount]);
                SetConsoleTextAttribute(h, 2);
                cout << "\t\t\t\t\t\t\tLoan of amount " << loan[signUpCount] << " rupees has been added to your account. Remember to pay your installments on time.";
                storeReservoir(reservoir, admincount);
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
                SetConsoleTextAttribute(h, 15);
                getch();
                break;
            }
            else if (stof(reservoir) <= stof(loan[signUpCount]))
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tSorry, BANK reservoir is not enough a per your demand.";
                SetConsoleTextAttribute(h, 15);
                getch();
                break;
            }
        }
    }
}
// Checks if there is no space in the name
bool nameSpace(string input)
{
    int num;
    for (int i = 0; input[i] != '\0'; i++)
    {
        num = i;
    }
    if (input[0] == ' ' || input[num] == ' ' || input[0] == '\0')
    {
        return false;
    }

    return true;
}
// Shows error if user presses enter without putting an input
bool onlyEnter(string string)
{
    if (string == "")
    {
        return false;
    }
    return true;
}
// Checks if there is no password in the password field
bool passwordSpace(string input)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            return 0;
        }
    }
    return 1;
}
// Shows the user his aggregate loan
void seeLoan(string Loan[], int signupCount)
{
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\tThe aggregate loan amount: " << Loan[signupCount] << endl;
    SetConsoleTextAttribute(h, 15);
    getch();
}
// Pay loan function for the user.
void payLoan(string loan[], int signupCount, string &reservoir, float accountMoney[], int admincount)
{
    string payloan;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tThe aggregate loan amount: ";
    SetConsoleTextAttribute(h, 6);
    cout << loan[signupCount] << endl;
    ;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter the amount of loan you want to pay: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, payloan);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        if (onlyEnter(payloan) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amount of loan you want to pay: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, payloan);
            SetConsoleTextAttribute(h, 15);
        }
        else if (checkInt(payloan) == 1)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tEnter integer values please." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amount of loan you want to pay: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, payloan);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    if (accountMoney[signupCount] >= stof(payloan))
    {
        if (stof(loan[signupCount]) >= stof(payloan))
        {
            int a = stof(loan[signupCount]) - stof(payloan);
            loan[signupCount] = to_string(a);
            int b = stof(reservoir) + stof(payloan);
            reservoir = to_string(b);
            int c = (accountMoney[signupCount]) - stof(payloan);
            accountMoney[signupCount] = c;
            SetConsoleTextAttribute(h, 2);
            cout << "\t\t\t\t\t\t\tThe remaining debt is: " << a;
            storeReservoir(reservoir, admincount);
            SetConsoleTextAttribute(h, 15);
            getch();
        }
        else
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tThe entered amount is greater aggregate loan." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tPlease enter a value less than or equal to loan.";
            SetConsoleTextAttribute(h, 6);
            getch();
            SetConsoleTextAttribute(h, 15);
        }
    }
    else
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\t\t\t\tNot enough Balance" << endl;
        SetConsoleTextAttribute(h, 15);
        getch();
    }
}
// Pay Bill Menu
string payBill()
{
    system("cls");
    printHeader();
    cout << "\t\t\t\t\t\t\t\t\t    Bill Menu\n";
    cout << "\t\t\t\t\t\t\t       ************************************\n";
    string option;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\t1. Electricity Bill" << endl;
    cout << "\t\t\t\t\t\t\t2. Gas Bill" << endl;
    cout << "\t\t\t\t\t\t\t3. Water Bill" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter key...";
    SetConsoleTextAttribute(h, 6);
    getline(cin, option);
    SetConsoleTextAttribute(h, 15);
    return option;
}
// Function for paying the gas bill.
void gasBill(float accountMoney[], int indexInAlmostAllArrays)
{

    string bill;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter the amonut of Water Bill you want to pay: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, bill);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        if (onlyEnter(bill) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty" << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amonut of Water Bill you want to pay: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, bill);
            SetConsoleTextAttribute(h, 15);
        }
        else if (checkInt(bill) == 1)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty" << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amonut of Water Bill you want to pay: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, bill);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    if (accountMoney[indexInAlmostAllArrays] >= stof(bill))
    {
        int k = (accountMoney[indexInAlmostAllArrays]) - stof(bill);
        accountMoney[indexInAlmostAllArrays] = k;
        SetConsoleTextAttribute(h, 2);
        cout << "\t\t\t\t\t\t\tYour Bill of " << bill << " has been paid.";
        SetConsoleTextAttribute(h, 15);
        getch();
    }
    else
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\t\t\t\tNot Enough Balance." << endl;
        SetConsoleTextAttribute(h, 15);
        getch();
    }
}
// Function for paying the electricity bill.
void electricityBill(float accountMoney[], int indexInAlmostAllArrays)
{
    string bill;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter the amonut of Electricity Bill you want to pay: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, bill);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        if (onlyEnter(bill) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty" << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amonut of Electricity Bill you want to pay: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, bill);
            SetConsoleTextAttribute(h, 15);
        }
        else if (checkInt(bill) == 1)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty" << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amonut of Electricity Bill you want to pay: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, bill);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    if (accountMoney[indexInAlmostAllArrays] >= stof(bill))
    {
        int k = (accountMoney[indexInAlmostAllArrays]) - stof(bill);
        accountMoney[indexInAlmostAllArrays] = k;
        SetConsoleTextAttribute(h, 2);
        cout << "\t\t\t\t\t\t\tYour Bill of " << bill << " has been paid.";
        SetConsoleTextAttribute(h, 15);
        getch();
    }
    else
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\t\t\t\tNot Enough Balance." << endl;
        SetConsoleTextAttribute(h, 15);
        getch();
    }
}
// Function for paying the water bill.
void waterBill(float accountMoney[], int indexInAlmostAllArrays)
{
    string bill;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter the amonut of Gas Bill you want to pay: ";
    SetConsoleTextAttribute(h, 6);
    getline(cin, bill);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        if (onlyEnter(bill) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty" << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amonut of Gas Bill you want to pay: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, bill);
            SetConsoleTextAttribute(h, 15);
        }
        else if (checkInt(bill) == 1)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty" << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the amonut of Gas Bill you want to pay: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, bill);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    if (accountMoney[indexInAlmostAllArrays] >= stof(bill))
    {
        int k = (accountMoney[indexInAlmostAllArrays]) - stof(bill);
        accountMoney[indexInAlmostAllArrays] = k;
        SetConsoleTextAttribute(h, 2);
        cout << "\t\t\t\t\t\t\tYour Bill of " << bill << " has been paid.";
        SetConsoleTextAttribute(h, 15);
        getch();
    }
    else
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\t\t\t\tNot Enough Balance." << endl;
        SetConsoleTextAttribute(h, 15);
        getch();
    }
}
// All functions of manager with validations.
void mainSecondManager(int selectOption, int sizeOfArray, int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int &indexInAlmostAllArrays, string signInName, string signInPassword, int &countOfFeedbacks, string feedbacks[], int idx, int &admincount, string &reservoir, string &salaryEmployee)
{
    while (true)
    {
        int a;
        system("cls");
        printHeader();
        managerMenu();
        string options;
        while (true)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter key: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, options);
            SetConsoleTextAttribute(h, 15);
            if (onlyEnter(options) == 0)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
            else if (checkInt(options) == 1)
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tInvalid command." << endl;
                SetConsoleTextAttribute(h, 15);
                exit();
            }
            else
            {
                break;
            }
        }
        selectOption = stoi(options);
        if (selectOption == 1)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tAmount in your account is: ";
            SetConsoleTextAttribute(h, 2);
            cout << balance(indexInAlmostAllArrays, accountMoney, sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword) << endl;
            SetConsoleTextAttribute(h, 15);
            exit();
        }
        else if (selectOption == 2)
        {
            deposit(indexInAlmostAllArrays, accountMoney);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            exit();
        }
        else if (selectOption == 3)
        {
            firstOption(accountMoney, indexInAlmostAllArrays);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
        }
        else if (selectOption == 4)
        {
            moneyTransfer(indexInAlmostAllArrays, accountMoney);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
        }
        else if (selectOption == 5)
        {
            updatePass(indexInAlmostAllArrays, sizeOfArray, nameOfUSer, passwordOfUser, signInName, signInPassword);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            exit();
        }
        else if (selectOption == 6)
        {
            showfeed(countOfFeedbacks, feedbacks);
        }
        else if (selectOption == 7)
        {
            if (signupCount < sizeOfArray)
            {
                signUpByManager(signupCount, nameOfUSer, passwordOfUser, role, accountMoney, admincount, reservoir); // Sign-up function.
                signupCount++;
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t\t\t\tYou cannot add account as limit has been exceeded." << endl;
                SetConsoleTextAttribute(h, 15);
            }
        }
        else if (selectOption == 8)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tThe reservoir in your bank is: ";
            SetConsoleTextAttribute(h, 2);
            cout << reservoir;
            getch();
        }
        else if (selectOption == 9)
        {
            string p = payBill();
            if (p == "1")
            {
                electricityBill(accountMoney, indexInAlmostAllArrays);
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            }
            else if (p == "2")
            {
                gasBill(accountMoney, indexInAlmostAllArrays);
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            }
            else if (p == "3")
            {
                waterBill(accountMoney, indexInAlmostAllArrays);
                storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
            }
            else
            {
                SetConsoleTextAttribute(h, 4);
                cout << "Invalid Input" << endl;
                SetConsoleTextAttribute(h, 15);
                getch();
            }
        }
        else if (selectOption == 10)
        {
            empDelete(signupCount, nameOfUSer, passwordOfUser, role, accountMoney, indexInAlmostAllArrays, a);
            storeSignUpOption(nameOfUSer, passwordOfUser, role, accountMoney, signupCount);
        }

        else if (selectOption == 11)
        {
            seeEmployeeList(signupCount, role, nameOfUSer);
        }
        else if (selectOption == 12)
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter the salary of each Employee: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, salaryEmployee);
            SetConsoleTextAttribute(h, 15);
            while (true)
            {
                if (onlyEnter(salaryEmployee) == 0)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tInput cannot be Empty." << endl;
                    SetConsoleTextAttribute(h, 15);
                    cout << "\t\t\t\t\t\t\tEnter the salary of each Employee";
                    SetConsoleTextAttribute(h, 6);
                    getline(cin, salaryEmployee);
                    SetConsoleTextAttribute(h, 15);
                }
                else if (checkInt(salaryEmployee) == 1)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\t\t\t\tInvalid Input." << endl;
                    SetConsoleTextAttribute(h, 15);
                    cout << "\t\t\t\t\t\t\tEnter the salary of each Employee: ";
                    SetConsoleTextAttribute(h, 6);
                    getline(cin, salaryEmployee);
                    SetConsoleTextAttribute(h, 15);
                }
                else
                {
                    storeSalaryEmployee(salaryEmployee);
                    SetConsoleTextAttribute(h, 2);
                    cout << "\t\t\t\t\t\t\tSalary updated successfully!";
                    getch();
                    break;
                }
            }
        }
        else if (selectOption == 13)
        {
            int employeeCount = 0;
            for (int i = 0; i < signupCount; i++)
            {
                if (role[i] == "employee")
                {
                    employeeCount++;
                }
            }
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tAggregrate of Employee's salary: ";
            SetConsoleTextAttribute(h, 6);
            cout << (stof(salaryEmployee) * employeeCount);
            SetConsoleTextAttribute(h, 15);
            getch();
        }
        else if (selectOption == 14)
        {
            exit();
            break;
        }
        if (a == indexInAlmostAllArrays)
        {
            break;
        }
    }
}
// Shows employee list
void seeEmployeeList(int signupCount, string role[], string nameOfUSer[])
{
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\tName of Employee" << endl;
    cout << endl;
    SetConsoleTextAttribute(h, 15);
    for (int i = 0; i < signupCount; i++)
    {
        if (role[i] == "employee")
        {
            cout << "\t\t\t\t\t\t\t" << nameOfUSer[i] << endl;
        }
    }
    getch();
}
// Add user fuction when credentials given by the manager.
void signUpByManager(int &signupCount, string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int &admincount, string &reservoir) // Sign-up function.
{
    string options = "0";
    float money;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter name: ";
    ////////cin.ignore();
    SetConsoleTextAttribute(h, 6);
    getline(cin, nameOfUSer[signupCount]);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {

        if (onlyEnter(nameOfUSer[signupCount]) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty" << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter name: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, nameOfUSer[signupCount]);
            SetConsoleTextAttribute(h, 15);
        }
        else if (nameSpace(nameOfUSer[signupCount]) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tSpace cannot be enter at last or first letter." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter name: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, nameOfUSer[signupCount]);
            SetConsoleTextAttribute(h, 15);
        }

        else if (checkUpPass(signupCount, nameOfUSer, nameOfUSer[signupCount]))
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tYou cannot take this username as it has been already taken." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter name: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, nameOfUSer[signupCount]);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        SetConsoleTextAttribute(h, 15);
        cout << "\t\t\t\t\t\t\tEnter password: ";
        SetConsoleTextAttribute(h, 6);
        getline(cin, passwordOfUser[signupCount]);
        SetConsoleTextAttribute(h, 15);
        pasLenSignUp(signupCount, passwordOfUser);
        break;
    }
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter role (employee/user): ";
    ////////cin.ignore();
    SetConsoleTextAttribute(h, 6);
    getline(cin, role[signupCount]);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        if (role[signupCount] != "user" && role[signupCount] != "employee")
        {
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter valid role: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, role[signupCount]);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\tEnter amount in account: ";
    ////////cin.ignore();
    SetConsoleTextAttribute(h, 6);
    getline(cin, options);
    SetConsoleTextAttribute(h, 15);
    while (true)
    {
        if (onlyEnter(options) == 0)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInput cannot be empty." << endl;
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter amount in account: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, options);
            SetConsoleTextAttribute(h, 15);
        }
        else if (checkInt(options) == 1)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\t\t\t\tInvalid amount.\n";
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\t\t\t\tEnter amount in account: ";
            SetConsoleTextAttribute(h, 6);
            getline(cin, options);
            SetConsoleTextAttribute(h, 15);
        }
        else
        {
            break;
        }
    }
    money = stof(options);
    accountMoney[signupCount] = money;
    SetConsoleTextAttribute(h, 2);
    cout << "\t\t\t\t\t\t\tYour account has successfully been created." << endl;
    SetConsoleTextAttribute(h, 15);
    getch();
}
// File handling function for storing information of all those who sign up.
void storeSignUpOption(string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int signupCount)
{
    fstream line;
    line.open("SignUpOption.txt", ios::out);
    for (int i = 0; i < signupCount; i++)
    {
        line << nameOfUSer[i] << "," << passwordOfUser[i] << "," << role[i] << "," << accountMoney[i] << endl;
    }
    line.close();
}
// Extracts the data from the file.
void readSignUpOption(string nameOfUSer[], string passwordOfUser[], string role[], float accountMoney[], int &signupCount)
{
    string record;
    fstream line;
    string b;
    line.open("SignUpOption.txt", ios::in);
    while (!(line.eof()))
    {
        getline(line, record);
        if (record == "")
        {
            break;
        }
        nameOfUSer[signupCount] = getField(record, 1);
        passwordOfUser[signupCount] = getField(record, 2);
        role[signupCount] = getField(record, 3);
        b = getField(record, 4);
        if (b == "")
        {
            b = "0";
        }
        accountMoney[signupCount] = stof(b);
        signupCount++;
    }
}
// Storesthe record of all the debtors.
void storeLoan(string loan[], int signupCount)
{
    fstream line;
    line.open("Loan.txt", ios::out);
    for (int i = 0; i < signupCount; i++)
    {
        line << loan[i] << endl;
    }
    line.close();
}
// Reads the data of all the debtors from the file.
void readLoan(string loan[], int signupCount)
{
    int i = 0;
    fstream line;
    string record;
    string b;
    line.open("Loan.txt", ios::in);
    while (!(line.eof()))
    {
        getline(line, record);
        b = getField(record, 1);
        if (b == "")
        {
            b = "0";
        }
        loan[i] = b;
        i++;
    }
}
// Stores the data of reservoir in the file from the app.
void storeReservoir(string reservoir, int admincount)
{
    fstream line;
    line.open("Reservoir.txt", ios::out);
    line << reservoir << "," << admincount;
    line.close();
}
// Reads the data from the file of the reservoir.
void readReservoir(string &reservoir, int &admincount)
{
    string a;
    string b;
    fstream line;
    string record;
    line.open("Reservoir.txt", ios::in);
    for (int i = 0; i < 1; i++)
    {
        getline(line, record);
        if (record == "")
        {
            break;
        }
        b = getField(record, 1);
        a = getField(record, 2);
        if (b == "")
        {
            b = "0";
        }
        if (a == "")
        {
            a = "0";
        }
        reservoir = b;
        admincount = stoi(a);
    }
    line.close();
}
// Stores the salary of employee.
void storeSalaryEmployee(string salaryEmployee)
{
    fstream line;
    line.open("SalaryEmployee.txt", ios::out);
    line << salaryEmployee;
    line.close();
}

// Reads the salary of employee from the file.
void readSalaryEmployee(string salaryEmployee)
{

    string a;
    string record;
    fstream line;
    line.open("SalaryEmployee.txt", ios::in);
    getline(line, record);
    a = getField(record, 1);
    if (a == "")
    {
        a = "0";
    }
    a = salaryEmployee;
    line.close();
}
// Stores the record of feedbacks from the user.
void storeFeedback(string feedbacks[], int &countOfFeedbacks)
{
    fstream line;
    line.open("Storefeedback.txt", ios::out);
    for (int i = 0; i < countOfFeedbacks; i++)
    {
        line << feedbacks[i] << endl;
    }
    line.close();
}
// Reads all the feedbacks from the users.
void readFeedback(string feedbacks[], int &countOfFeedbacks)
{
    countOfFeedbacks = 0;
    string record;
    fstream line;
    line.open("Storefeedback.txt", ios::in);
    while (!(line.eof()))
    {
        getline(line, record);
        feedbacks[countOfFeedbacks] = getField(record, 1);
        countOfFeedbacks++;
    }
}
string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}
// From now on, begins the animation of the first interface.
void printFirstInterface()
{
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                                    .:++:.                                              " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                                    .:++:.                                              " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                           .:;:...    ;;       :;:.                                     " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                             ..       ..       ..                                       " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                 ..;+        ;;      ;++;      :;..     .+;..                           " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                 ..:;       ;++;     ++++:    ;++;..  ...;:..                           " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                    .+;     ;+++;. .++++++   ;++++:. ..;+.                              " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                    .+++    ++++++;++++++++;+++++++   +++.                              " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                     :++++++++++++++++++++++++++++++++++:                               " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                     .++++++++++++++++++++++++++++++++++.                               " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                     ..;.:;++++++++;;;;;;;;++++++++;:.;..                               " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                      .:++;:++++++++++++++++++++++:;++;.                                " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                      .;+.++++++++++++++++++++++++++.+;.                                " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                      ...:;++++++++++++++++++++++++;:..                                 " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 6);
    cout << "                                                                          ....:;;;::::::::::;;;:...                                     " << endl;
    Sleep(25);
    SetConsoleTextAttribute(h, 13);
    cout << "                                           ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; " << endl;

    cout << "                                                                                                    " << endl;

    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 12, y);
    SetConsoleTextAttribute(h, 11);
    cout << "        +++++++++++    ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 12, y + 1);
    SetConsoleTextAttribute(h, 11);
    cout << "         ;++    ++++   ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 12, y + 2);
    SetConsoleTextAttribute(h, 11);
    cout << "         ;++     +++   ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 12, y + 3);
    SetConsoleTextAttribute(h, 11);
    cout << "         +++     +++   ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 12, y + 4);
    SetConsoleTextAttribute(h, 11);
    cout << "         +++++;+++;    ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 12, y + 5);
    SetConsoleTextAttribute(h, 11);
    cout << "         ++++  +++++;  ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 12, y + 6);
    SetConsoleTextAttribute(h, 11);
    cout << "         +++      ++++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 12, y + 7);
    SetConsoleTextAttribute(h, 11);
    cout << "         ;++:      +++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 12, y + 8);
    SetConsoleTextAttribute(h, 11);
    cout << "         ;++:      +++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 12, y + 9);
    SetConsoleTextAttribute(h, 11);
    cout << "         ++++    ;+++  ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 12, y + 10);
    SetConsoleTextAttribute(h, 11);
    cout << "        +++++++++++    ";
    SetConsoleTextAttribute(h, 11);
    Sleep(200);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36, y + 0);
    SetConsoleTextAttribute(h, 11);
    cout << "            ++;         ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36, y + 1);
    SetConsoleTextAttribute(h, 11);
    cout << "           ++++         ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36, y + 2);
    SetConsoleTextAttribute(h, 11);
    cout << "          ++++++        ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36, y + 3);
    SetConsoleTextAttribute(h, 11);
    cout << "         ++ ++++       ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36, y + 4);
    SetConsoleTextAttribute(h, 11);
    cout << "        +++  +++;      ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36, y + 5);
    SetConsoleTextAttribute(h, 11);
    cout << "       +++    +++;     ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36, y + 6);
    SetConsoleTextAttribute(h, 11);
    cout << "      ++++++++++++     ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36, y + 7);
    SetConsoleTextAttribute(h, 11);
    cout << "     +++       ++++    ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36, y + 8);
    SetConsoleTextAttribute(h, 11);
    cout << "    +++         ++++   ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36, y + 9);
    SetConsoleTextAttribute(h, 11);
    cout << "   +++          +++++  ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36, y + 10);
    SetConsoleTextAttribute(h, 11);
    cout << " ++++++          ++++++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(200);
    SetConsoleTextAttribute(h, 11);

    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25, y + 0);
    SetConsoleTextAttribute(h, 11);
    cout << "      ++            +++++";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25, y + 1);
    SetConsoleTextAttribute(h, 11);
    cout << "      ++++           +++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25, y + 2);
    SetConsoleTextAttribute(h, 11);
    cout << "      ++++++         +++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25, y + 3);
    SetConsoleTextAttribute(h, 11);
    cout << "      +; ++++;       +++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25, y + 4);
    SetConsoleTextAttribute(h, 11);
    cout << "      ++   +++++     +++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25, y + 5);
    SetConsoleTextAttribute(h, 11);
    cout << "      ++     ++++;   +++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25, y + 6);
    SetConsoleTextAttribute(h, 11);
    cout << "      ++      +++++  +++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25, y + 7);
    SetConsoleTextAttribute(h, 11);
    cout << "      ++        +++++;++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25, y + 8);
    SetConsoleTextAttribute(h, 11);
    cout << "      ++          ++++++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25, y + 9);
    SetConsoleTextAttribute(h, 11);
    cout << "     :++            ++++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25, y + 10);
    SetConsoleTextAttribute(h, 11);
    cout << "   +++++++            ++ ";
    SetConsoleTextAttribute(h, 11);
    Sleep(200);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25 + 26, y + 1);
    SetConsoleTextAttribute(h, 11);
    cout << "        +++;    ++++       " << endl;
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25 + 26, y + 0);
    SetConsoleTextAttribute(h, 11);
    cout << "      ++++++      +++++    " << endl;
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25 + 26, y + 2);
    SetConsoleTextAttribute(h, 11);
    cout << "        +++:   ++;         " << endl;
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25 + 26, y + 3);
    SetConsoleTextAttribute(h, 11);
    cout << "        +++ ;+++           " << endl;
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25 + 26, y + 4);
    SetConsoleTextAttribute(h, 11);
    cout << "        ++++++             " << endl;
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25 + 26, y + 5);
    SetConsoleTextAttribute(h, 11);
    cout << "        ++++++;            " << endl;
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25 + 26, y + 6);
    SetConsoleTextAttribute(h, 11);
    cout << "        +++ ;++++          " << endl;
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25 + 26, y + 7);
    SetConsoleTextAttribute(h, 11);
    cout << "        +++;  ;++++        " << endl;
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25 + 26, y + 8);
    SetConsoleTextAttribute(h, 11);
    cout << "        +++;    +++++      " << endl;
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25 + 26, y + 9);
    SetConsoleTextAttribute(h, 11);
    cout << "       +++++      +++++    " << endl;
    SetConsoleTextAttribute(h, 11);
    Sleep(20);
    SetConsoleTextAttribute(h, 11);
    gotoxy(x + 36 + 25 + 26, y + 10);
    SetConsoleTextAttribute(h, 11);
    cout << "      ++++++++      +++++++" << endl;
    SetConsoleTextAttribute(h, 11);
    getch();
}
void gotoxy(int x, int y) // to specifiy location of output
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void header1()
{
    gotoxy(p, q);
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    gotoxy(p, q + 1);
    cout << "|                      -|                      -|=========================================================================|                      -|                      -|";
    gotoxy(p, q + 2);
    cout << " -|                  -|  -|                  -|  ========================================================================= -|                  -|  -|                  -|  ";
    gotoxy(p, q + 3);
    cout << "   -|              -|      -|              -|                                                                                -|              -|      -|              -|    ";
    gotoxy(p, q + 4);
    cout << "     -|          -|          -|          -|                                                                                    -|          -|          -|          -|      ";
    gotoxy(p, q + 5);
    cout << "       -|      -|              -|      -|                                                                                        -|      -|              -|      -|        ";
    gotoxy(p, q + 6);
    cout << "         -|  -|       / - \\      -|  -|                                                                                            -|  -|      / - \\       -|  -|          ";
    gotoxy(p, q + 7);
    cout << "           -|         | O |        -|                                                                                                -|        | O |         -|            ";
    gotoxy(p, q + 8);
    cout << "         -|  -|       \\ - /      -|  -|                                                                                            -|  -|      \\ - /       -|  -|          ";
    gotoxy(p, q + 9);
    cout << "       -|      -|              -|      -|                                                                                        -|      -|              -|      -|        ";
    gotoxy(p, q + 10);
    cout << "     -|          -|          -|          -|                                                                                    -|          -|          -|          -|      ";
    gotoxy(p, q + 11);
    cout << "   -|              -|      -|              -|                                                                                -|              -|      -|              -|    ";
    gotoxy(p, q + 12);
    cout << " -|                  -|  -|                  -|  ========================================================================= -|                  -|  -|                  -|  ";
    gotoxy(p, q + 13);
    cout << "|                      -|                      -|=========================================================================|                      -|                      -|";
    gotoxy(p, q + 14);
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    eub();
}
void eub()
{
    SetConsoleTextAttribute(h, 13);
    gotoxy(p + 61, q + 3);
    cout << "###########     ###         ###     ###########   ";
    Sleep(50);
    gotoxy(p + 61, q + 4);
    cout << "###             ###         ###     ###       ### ";
    Sleep(50);
    gotoxy(p + 61, q + 5);
    cout << "###             ###         ###     ###        ###";
    Sleep(50);
    gotoxy(p + 61, q + 6);
    cout << "###             ###         ###     ###       ###";
    Sleep(50);
    gotoxy(p + 61, q + 7);
    cout << "###########     ###         ###     ### ########  ";
    Sleep(50);
    gotoxy(p + 61, q + 8);
    cout << "###             ###         ###     ###       ###";
    Sleep(50);
    gotoxy(p + 61, q + 9);
    cout << "###             ###         ###     ###        ###";
    Sleep(50);
    gotoxy(p + 61, q + 10);
    cout << "###             ###         ###     ###       ### ";
    Sleep(50);
    gotoxy(p + 61, q + 11);
    cout << "###########       ###########       ############  ";
}
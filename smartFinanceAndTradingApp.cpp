#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
     BinarySearchTree database;
     database.makeTree();

     char choice;
     string account_number;

     do
     {
          cout << endl
               << endl
               << "MENU" << endl
               << endl;
          cout << endl
               << "1. Create Account" << endl;
          cout << "2. Login" << endl;
          cout << "3. Lock Account" << endl;
          cout << "4. Forgot Pin" << endl;
          cout << "5. Exit" << endl;
          cout << endl
               << "Enter choice: ";
          cin >> choice;

          if (choice == '1')
          {
               database.create_account();
          }
          else if (choice == '2')
          {
               cout << endl
                    << "Enter Account Number: ";
               cin >> account_number;
               database.login(account_number);
          }
          else if (choice == '3')
          {
               cout << endl
                    << "Enter Account Number: ";
               cin >> account_number;
               database.lock_account(account_number);
          }
          else if (choice == '4')
          {
               cout << endl
                    << "Enter Account Number: ";
               cin >> account_number;
               database.forgot_pin(account_number);
          }
          else if (choice == '5')
          {
               cout << endl
                    << "EXIT" << endl;
               break;
          }
          else
          {
               cout << endl
                    << "Invalid Choice" << endl;
          }

     } while (1);

     return 0;
}
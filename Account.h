#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <ctime>
#include "Queue.h"
#include "StocksAndCryptoTrading.h"
using namespace std;

void srand(int seed);

const int ACCOUNT_NUMBER_LENGTH = 4; // change value to increase/decrease account number length
const int OTP_LENGTH = 3;
const short PIN_LENGTH = 4;

char numbers[] = "0123456789";
char small_letters[] = "abcdefghijklmnopqrstuvwxyz";
char capital_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Account
{
private: // Data Members
    string account_number;
    string name;
    long cnic;
    long mobile_number;
    double balance;
    string pin;
    string status;
    double stocks_or_crypto;

public: // Member Functions
    //_______________________________________________________________________________________________
    // Constructors/Destructor
    //_______________________________________________________________________________________________
    Account()
    {
        balance = 0;
        status = "unlocked";
        stocks_or_crypto = 0;
    }
    Account(string name, long cnic, long mobile_number, string pin)
    {
        this->name = name;
        this->cnic = cnic;
        this->mobile_number = mobile_number;
        balance = 0;
        this->pin = pin;
        status = "unlocked";
        stocks_or_crypto = 0;
    }
    ~Account()
    {
    }
    //_______________________________________________________________________________________________
    // Cin/Cout
    //_______________________________________________________________________________________________
    friend istream &operator>>(istream &cin, Account &account)
    {
        string pass;
        char character;

        cout << endl << "Enter Name: ";
        cin >> account.name;
        cout << "Enter CNIC: ";
        cin >> account.cnic;
        cout << "Enter Mobile Number: ";
        cin >> account.mobile_number;
        cout << "Enter Pin: ";
        for (int i = 0; i < PIN_LENGTH; i++)
        {
            while (true)
            {
                cin >> character;
                if (character >= '0' && character <= '9')
                {
                    break;
                }
                cout << "Enter digits from 0-9: ";
            }
            pass += character;
        }
        account.pin = pass;

        return cin;
    }
    friend ostream &operator<<(ostream &cout, const Account &account)
    {
        cout << endl << "Account Number: " << account.account_number << endl;
        cout << "Name: " << account.name << endl;
        cout << "CNIC: " << account.cnic << endl;
        cout << "Mobile Number: " << account.mobile_number << endl;
        cout << "Balance: " << account.balance << endl;
        cout << "Status: " << account.status << endl;
        cout << "Stocks: " << account.stocks_or_crypto << endl;

        return cout;
    }
    //_______________________________________________________________________________________________
    // Mutators
    //_______________________________________________________________________________________________
    void set_account_number(string account_number)
    {
        this->account_number = account_number;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_cnic(long cnic)
    {
        this->cnic = cnic;
    }
    void set_mobile_number(long mobile_number)
    {
        this->mobile_number = mobile_number;
    }
    void set_balance(double balance)
    {
        this->balance = balance;
    }
    void set_pin(string pin)
    {
        this->pin = pin;
    }
    void set_status(string status)
    {
        this->status = status;
    }
    void set_stocks_or_crypto(double stocks_or_crypto)
    {
        this->stocks_or_crypto = stocks_or_crypto;
    }
    //_______________________________________________________________________________________________
    // Accessors
    //_______________________________________________________________________________________________
    string get_account_number()
    {
        return account_number;
    }
    string get_name()
    {
        return name;
    }
    long get_cnic()
    {
        return cnic;
    }
    long get_mobile_number()
    {
        return mobile_number;
    }
    double get_balance()
    {
        return balance;
    }
    string get_pin()
    {
        return pin;
    }
    string get_status()
    {
        return status;
    }
    double get_stocks_or_crypto()
    {
        return stocks_or_crypto;
    }
    // Create Files
    void create_needed_files()
    {
        ofstream ofile;

        string file1 = "Accounts.txt";
        create_file(file1);
        string file2 = "accountNumbers.txt";
        create_file(file2);
        string file3 = "largeDecrease.txt";
        ofile.open(file3);
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << "................................__...................\n";
        ofile << "...............................|..|..................\n";
        ofile << "........................__.....|..|__................\n";
        ofile << ".......................|..|....|.....|...............\n";
        ofile << "......................|....|__|......|...............\n";
        ofile << "...............__....|................|..............\n";
        ofile << "..............|..|...|.................|.............\n";
        ofile << "__...........|....|__..................|__...........\n";
        ofile << "..|.........|.............................|..........\n";
        ofile << "..|__....__|..............................|..........\n";
        ofile << ".....|__|.................................|_.........\n";
        ofile << "............................................|..._....\n";
        ofile << "............................................|__|.|...\n";
        ofile << ".................................................|_..\n";
        ofile << "...................................................|.";
        ofile.close();
        string file4 = "largeIncrease.txt";
        ofile.open(file4);
        ofile << "...................................__................\n";
        ofile << "..................................|..|........__...__\n";
        ofile << "................................__....|....__|..|..|.\n";
        ofile << "...............................|.......|__|.....|__|.\n";
        ofile << "........................__.....|.....................\n";
        ofile << ".......................|..|....|.....................\n";
        ofile << "......................|....|__|......................\n";
        ofile << "...............__....|...............................\n";
        ofile << "..............|..|...|...............................\n";
        ofile << "__...........|....|__................................\n";
        ofile << "..|.........|........................................\n";
        ofile << "..|__....__|.........................................\n";
        ofile << ".....|__|............................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................";
        ofile.close();
        string file5 = "mediumDecrease.txt";
        ofile.open(file5);
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << "....._............................._.................\n";
        ofile << "....|.|...........................|.|................\n";
        ofile << "...|..|.........._...............|...|...............\n";
        ofile << "..|....|_.......|.|.............|....|_..............\n";
        ofile << "__|......|...._|...|..........__|......|...__........\n";
        ofile << ".........|...|.....|.........|.........|..|..|.......\n";
        ofile << "..........|__.......|.......|...........__|...|......\n";
        ofile << ".....................|.....|...................|...__\n";
        ofile << "......................|___|....................|_..|.\n";
        ofile << ".................................................|_|.\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................";
        ofile.close();
        string file6 = "mediumIncrease.txt";
        ofile.open(file6);
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".............................................._....__\n";
        ofile << "...........................................__|.|___|.\n";
        ofile << "....._............................._......|..........\n";
        ofile << "....|.|...........................|.|....|...........\n";
        ofile << "...|..|.........._...............|...|__|............\n";
        ofile << "..|....|_.......|.|.............|....................\n";
        ofile << "__|......|...._|...|..........__|....................\n";
        ofile << ".........|...|.....|.........|.......................\n";
        ofile << "..........|__.......|.......|........................\n";
        ofile << ".....................|.....|.........................\n";
        ofile << "......................|___|..........................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................";
        ofile.close();
        string file7 = "smallDecrease.txt";
        ofile.open(file7);
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................__..........__..................\n";
        ofile << "....................|..|........|..|.................\n";
        ofile << "....__............_|....|......|....|................\n";
        ofile << "___|..|..........|.......__...|......|.........__....\n";
        ofile << "......|.........|..........|__|.......|_......|..|...\n";
        ofile << ".......|__.....|........................|..._|....|__\n";
        ofile << "..........|...|..........................|__|........\n";
        ofile << "..........|___|......................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................";
        ofile.close();
        string file8 = "smallIncrease.txt";
        ofile.open(file8);
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << "..........................................._.........\n";
        ofile << "....._............................._......|.|........\n";
        ofile << "....|.|...........................|.|...._|..|_...__.\n";
        ofile << "...|..|.........._...............|...|__|......|.|...\n";
        ofile << "..|....|_.......|.|.............|..............|_|...\n";
        ofile << "__|......|...._|...|..........__|....................\n";
        ofile << ".........|...|.....|.........|.......................\n";
        ofile << "..........|__.......|.......|........................\n";
        ofile << ".....................|.....|.........................\n";
        ofile << "......................|___|..........................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................\n";
        ofile << ".....................................................";
        ofile.close();
    }
    // to create a file with specific names
    void create_file(string filename)
    {
        ifstream ifile;
        ofstream ofile;

        ifile.open(filename);
        if (!ifile)
        {
            ofile.open(filename);
            ofile.close();
        }
    }
    void delete_files(string account_number)
    {
        string filename1 = "transactions_" + account_number + ".txt";
        string filename2 = "OTP_" + account_number + ".txt";

        remove(filename1.c_str());
        remove(filename2.c_str());
    }

    bool existing_account_number(const string &check)
    {
        ifstream infile("accountNumbers.txt");

        string temp_account_number;
        while (infile >> temp_account_number)
        {
            if (temp_account_number == check)
            {
                infile.close();
                return true;
            }
        }

        infile.close();
        return false;
    }
    string generate_account_number()
    {
        string account_number = "";

        static bool seeded = false;
        if (!seeded)
        {
            srand(static_cast<unsigned>(time(0)));
            seeded = true;
        }

        while (true) // Unlimited attempts until a unique account number is found
        {
            account_number = "";

            int random_number = 1 + (rand() % 3); // generate (1-3)

            for (int i = 0; i < ACCOUNT_NUMBER_LENGTH; i++)
            {
                if (random_number == 1)
                {
                    random_number = 1 + (rand() % 10); // generate (0-9)
                    if (random_number < 0 || random_number > 9)
                    {
                        random_number = 1 + (rand() % 10); // generate (0-9)
                    }
                    account_number += numbers[random_number];
                }
                else if (random_number == 2)
                {
                    random_number = 1 + (rand() % 25); // generate (0-25)
                    if (random_number < 0 || random_number > 25)
                    {
                        random_number = 1 + (rand() % 25); // generate (0-25)
                    }
                    account_number += small_letters[random_number];
                }
                else
                {
                    random_number = 1 + (rand() % 25); // generate (0-25)
                    if (random_number < 0 || random_number > 25)
                    {
                        random_number = 1 + (rand() % 25); // generate (0-25)
                    }
                    account_number += capital_letters[random_number];
                }
            }

            // Check for NULL character and replace with a random character from (a-z), (A-Z), or (0-9)
            for (int i = 0; i < account_number.length(); i++)
            {
                char &ch = account_number[i];
                if (ch == '\0')
                {
                    char replacement;
                    if (rand() % 3 == 0)
                        replacement = '0' + rand() % 10; // Random digit (0-9)
                    else if (rand() % 2 == 0)
                        replacement = 'A' + rand() % 26; // Random capital letter (A-Z)
                    else
                        replacement = 'a' + rand() % 26; // Random small letter (a-z)

                    ch = replacement;
                }
            }
            if (!existing_account_number(account_number))
            {
                break; // Exit the loop if the account number is unique
            }
        }

        ofstream outfile("accountNumbers.txt", ios::app);

        outfile << endl << account_number;

        outfile.close();

        return account_number;
    }

    string generate_otp(string account_number)
    {
        string filename = "OTP_" + account_number + ".txt";
        create_file(filename);

        ofstream ofile;
        ofile.open(filename);

        string otp = "";

        static bool seeded = false;
        if (!seeded)
        {
            srand(static_cast<unsigned>(time(0)));
            seeded = true;
        }

        for (int i = 0; i < OTP_LENGTH; i++)
        {
            int choice = rand() % 3;

            switch (choice)
            {
            case 0:
                otp += numbers[rand() % 10];
                break;
            case 1:
                otp += small_letters[rand() % 26];
                break;
            case 2:
                otp += capital_letters[rand() % 26];
                break;
            }
        }

        ofile << otp;

        return otp;
    }

    // To Create a new Account
    Account create_account()
    {
        ofstream ofile;
        ofile.open("Accounts.txt", ios::app);

        Account account;
        account.account_number = generate_account_number();

        cin >> account;

        ofile << endl
              << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;

        cout << endl
             << "Account created Successfully!" << endl;

        ofile.close();
        return account;
    }
    // To deposit money
    void deposit(string account_number, Account *acc)
    {
        string filename = "transactions_" + account_number + ".txt";
        create_file(filename);

        ifstream ifile;
        ifile.open("Accounts.txt");
        ofstream ofile;
        ofile.open("temp.txt");
        ofstream tfile;
        tfile.open(filename, ios::app);

        Account account;

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number == account.account_number)
            {
                double amount;
                cout << "Enter amount you want to deposit : ";
                cin >> amount;
                while (amount < 0)
                {
                    cout << "Amount can not be negative, enter a positive value! " << endl;
                    cin >> amount;
                }
                account.balance += amount;
                acc->balance += amount;
                cout << "Amount deposited successfully!" << endl;
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
                tfile << endl
                      << 1 << " " << amount << " " << 0 << " " << account.balance;
            }
            else
            {
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
        }

        tfile.close();
        ifile.close();
        ofile.close();
        // Delete the original file
        remove("Accounts.txt");
        // Rename the temporary file to the original filename
        rename("temp.txt", "Accounts.txt");
    }
    // To Withdraw money
    void withdraw(string account_number, Account *acc)
    {
        string filename = "transactions_" + account_number + ".txt";
        create_file(filename);

        ifstream ifile;
        ifile.open("Accounts.txt");
        ofstream ofile;
        ofile.open("temp.txt");
        ofstream tfile;
        tfile.open(filename, ios::app);

        Account account;

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number == account.account_number)
            {
                double amount;
                int check = 0;
                while (check == 0)
                {
                    cout << "Enter amount you want to withdraw : ";
                    cin >> amount;
                    while (amount < 0)
                    {
                        cout << "Amount can not be negative, enter a positive value! " << endl;
                        cin >> amount;
                    }
                    if (account.balance >= amount)
                    {
                        account.balance -= amount;
                        acc->balance -= amount;
                        ofile << endl
                              << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
                        check = 1;
                        tfile << endl
                              << 2 << " " << amount << " " << 0 << " " << account.balance;
                        cout << "Amount Withdraw Successful!" << endl;
                    }
                    else
                    {
                        cout << "Insufficient Balance!" << endl;
                    }
                }
            }
            else
            {
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
        }

        tfile.close();
        ofile.close();
        ifile.close();

        remove("Accounts.txt");
        rename("temp.txt", "Accounts.txt");
    }

    // To Transfer Money
    void transfer(string account_number_from, string account_number_to, Account *acc_from, Account *acc_to)
    {
        string filename_from = "transactions_" + account_number_from + ".txt";
        create_file(filename_from);

        ifstream ifile;
        ifile.open("Accounts.txt");
        ofstream ofile;
        ofile.open("temp.txt");
        ofstream tfile;
        tfile.open(filename_from, ios::app);

        Account account;
        double transfer_amount;

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number_from == account.account_number)
            {
                double amount;
                int check = 0;
                while (check == 0)
                {
                    cout << "Enter amount you want to transfer : ";
                    cin >> amount;
                    while (amount < 0)
                    {
                        cout << "Amount can not be negative, enter a positive value! " << endl;
                        cin >> amount;
                    }
                    if (account.balance >= amount)
                    {
                        transfer_amount = amount;
                        account.balance -= transfer_amount;
                        acc_from->balance -= transfer_amount;
                        ofile << endl
                              << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
                        tfile << endl
                              << 3 << " " << transfer_amount << " " << account_number_to << " " << account.balance;
                        check = 1;
                    }
                    else
                    {
                        cout << "Insufficient Balance!" << endl;
                    }
                }
            }
            else
            {
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
        }
        tfile.close();
        ofile.close();
        ifile.close();

        remove("Accounts.txt");
        rename("temp.txt", "Accounts.txt");

        string filename_to = "transactions_" + account_number_to + ".txt";
        create_file(filename_to);

        ifile.open("Accounts.txt");
        ofile.open("temp.txt");
        tfile.open(filename_to, ios::app);

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number_to == account.account_number)
            {
                account.balance += transfer_amount;
                acc_to->balance += transfer_amount;
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
                tfile << endl
                      << 4 << " " << transfer_amount << " " << account_number_from << " " << account.balance;
                cout << "Amount transferred successfully!" << endl;
            }
            else
            {
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
        }
        tfile.close();
        ifile.close();
        ofile.close();
        // Delete the original file
        remove("Accounts.txt");
        // Rename the temporary file to the original filename
        rename("temp.txt", "Accounts.txt");
    }
    // to lock account
    void lock_unlock_account(string account_number, string status)
    {
        ifstream ifile;
        ifile.open("Accounts.txt");
        ofstream ofile;
        ofile.open("temp.txt");

        Account account;

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number == account.account_number)
            {
                account.status = status;
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
            else
            {
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
        }

        ifile.close();
        ofile.close();

        remove("Accounts.txt");
        rename("temp.txt", "Accounts.txt");
    }
    // To get the bank statement of an account
    void transactions(string account_number)
    {
        string filename = "transactions_" + account_number + ".txt";

        ifstream ifile;
        ifile.open(filename);
        if (!ifile)
        {
            cout << endl
                 << "No Previous Transactions!" << endl;
        }
        else
        {
            string account_num;
            short action;
            double amount, balance;

            cout << "__________________________________________________________________________________________________________ " << endl;
            cout << "\t\t\t\tTransactions of " << account_number << endl;
            cout << "__________________________________________________________________________________________________________ " << endl;
            while (!ifile.eof())
            {
                ifile >> action >> amount >> account_num >> balance;
                if (action == 1)
                {
                    cout << "Deposited " << amount << " Rs. in the account." << endl;
                    cout << "\tBalance : " << balance << " Rs. \n\n";
                }
                else if (action == 2)
                {
                    cout << "Withdraw " << amount << " Rs. from the account." << endl;
                    cout << "\tBalance : " << balance << " Rs. \n\n";
                }
                else if (action == 3)
                {
                    cout << "Transfered " << amount << " Rs. to " << account_num << " ."
                         << endl;
                    cout << "\tBalance : " << balance << " Rs. \n\n";
                }
                else if (action == 4)
                {
                    cout << "Received " << amount << " Rs. from " << account_num << " ."
                         << endl;
                    cout << "\tBalance : " << balance << " Rs. \n\n";
                }
                else if (action == 5)
                {
                    cout << "Bought " << amount << " stocks at a price " << account_num << " per stock. \nTotal Cost : " << (amount * stod(account_num)) << endl;
                    cout << "\tBalance : " << balance << " Rs. \n\n";
                }
                else if (action == 6)
                {
                    cout << "Sold " << amount << " stocks at a price " << account_num << " per stock. \nTotal Cost : " << (amount * stod(account_num)) << endl;
                    cout << "\tBalance : " << balance << " Rs. \n\n";
                }

                else if (action == 7)
                {
                    cout << "Took a trade of " << amount << " Rs and ";
                    double account_num_double = stod(account_num);

                    if (account_num_double > amount)
                    {
                        cout << "made a profit of " << account_num_double - amount << "." << endl;
                    }
                    else
                    {
                        cout << "made a loss of " << amount - account_num_double << "." << endl;
                    }
                    cout << "\tBalance : " << balance << " Rs. \n\n";
                }
            }
            cout << "__________________________________________________________________________________________________________ " << endl;
            ifile.close();
        }
    }
    // To View the details of the Account
    void view(string account_number)
    {
        ifstream ifile;
        ifile.open("Accounts.txt");

        Account account;

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number == account.account_number)
            {
                cout << endl;
                cout << "______________________________________________________________________________________________________________ " << endl;
                cout << account;
                cout << "______________________________________________________________________________________________________________ " << endl;
            }
        }
        ifile.close();
    }
    // To update the details of the account
    void update(string account_number, Account *acc)
    {
        ifstream ifile;
        ifile.open("Accounts.txt");
        ofstream ofile;
        ofile.open("temp.txt");

        Account account;

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number == account.account_number)
            {
                string pass;
                char character;
                int check = 0;
                int choice;
                while (check == 0)
                {
                    cout << endl
                         << "1. Name" << endl;
                    cout << "2. CNIC" << endl;
                    cout << "3. Mobile Number" << endl;
                    cout << "4. Pin" << endl;
                    cout << "5. Full record" << endl;
                    cout << endl
                         << "What do you want to update : ";
                    cin >> choice;
                    if (choice == 1)
                    {
                        cout << "Enter name : ";
                        cin >> account.name;
                        acc->name = account.name;
                        check = 1;
                    }
                    else if (choice == 2)
                    {
                        cout << "Enter CNIC:";
                        cin >> account.cnic;
                        acc->cnic = account.cnic;
                        check = 1;
                    }
                    else if (choice == 3)
                    {
                        cout << "Enter Mobile Number: ";
                        cin >> account.mobile_number;
                        acc->mobile_number = account.mobile_number;
                        check = 1;
                    }
                    else if (choice == 4)
                    {
                        cout << "Enter Pin: ";
                        for (int i = 0; i < PIN_LENGTH; i++)
                        {
                            while (true)
                            {
                                cin >> character;
                                if (character >= '0' && character <= '9')
                                {
                                    break;
                                }
                                cout << "Enter digits from 0-9: ";
                            }
                            pass += character;
                        }
                        acc->set_pin(pass);
                        account.pin = pass;
                        check = 1;
                    }
                    else if (choice == 5)
                    {
                        cout << "Enter new details : " << endl;
                        cout << "Name : ";
                        cin >> account.name;
                        acc->name = account.name;
                        cout << "CNIC: ";
                        cin >> account.cnic;
                        acc->cnic = account.cnic;
                        cout << "Mobile Number: ";
                        cin >> account.mobile_number;
                        acc->mobile_number = account.mobile_number;
                        cout << "Enter Pin: ";
                        for (int i = 0; i < PIN_LENGTH; i++)
                        {
                            while (true)
                            {
                                cin >> character;
                                if (character >= '0' && character <= '9')
                                {
                                    break;
                                }
                                cout << "Enter digits from 0-9: ";
                            }
                            pass += character;
                        }
                        acc->set_pin(pass);
                        account.pin = pass;
                        check = 1;
                    }
                    else
                    {
                        cout << "Invalid Choice" << endl;
                    }
                }
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
            else
            {
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
        }
        ofile.close();
        ifile.close();
        remove("Accounts.txt");
        rename("temp.txt", "Accounts.txt");
    }
    // To delete the account
    void delete_(string account_number)
    {
        ifstream ifile;
        ifile.open("Accounts.txt");
        ofstream ofile;
        ofile.open("temp.txt");

        Account account;

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number == account.account_number)
            {
                cout << "Account deleted successfully!" << endl;
            }
            else
            {
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
        }
        ofile.close();
        ifile.close();
        // Delete the original file
        remove("Accounts.txt");
        // Rename the temporary file to the original filename
        rename("temp.txt", "Accounts.txt");

        ifile.open("accountNumbers.txt");
        ofile.open("temp.txt");

        string account_num;

        while (!ifile.eof())
        {
            ifile >> account_num;
            if (account_num == account_number)
            {}
            else
            {
                ofile << endl << account_num;
            }
        }

        ofile.close();
        ifile.close();

        remove("accountNumbers.txt");
        rename("temp.txt", "accountNumbers.txt");
    }

    void purchase_stocks_or_crypto(string account_number, Account *acc)
    {
        string filename = "transactions_" + account_number + ".txt";
        create_file(filename);

        ifstream ifile;
        ifile.open("Accounts.txt");
        ofstream ofile;
        ofile.open("temp.txt");
        ofstream tfile;
        tfile.open(filename, ios::app);

        Account account;

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number == account.account_number)
            {
                double quantity;
                int check = 0;
                while (check == 0)
                {
                    cout << "How many Stocks/Crypto to buy: ";
                    cin >> quantity;
                    while (quantity < 0)
                    {
                        cout << "Quantity can not be negative or zero, enter a positive value! " << endl;
                        cin >> quantity;
                    }
                    double price = stod(StocksOrCryptoTrading::get_price());
                    double buy_price = price * quantity;
                    if (acc->balance >= buy_price)
                    {
                        account.stocks_or_crypto += quantity;
                        account.balance -= buy_price;
                        acc->balance -= buy_price;
                        acc->stocks_or_crypto += quantity;
                        ofile << endl
                              << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
                        check = 1;
                        tfile << endl
                              << 5 << " " << quantity << " " << price << " " << account.balance;
                        cout << "Purchase Successful!" << endl;
                    }
                    else
                    {
                        cout << "Insufficient Balance!" << endl;
                    }
                }
            }
            else
            {
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
        }

        tfile.close();
        ofile.close();
        ifile.close();

        remove("Accounts.txt");
        rename("temp.txt", "Accounts.txt");
    }

    void sell_stocks_or_crypto(string account_number, Account *acc)
    {
        string filename = "transactions_" + account_number + ".txt";
        create_file(filename);

        ifstream ifile;
        ifile.open("Accounts.txt");
        ofstream ofile;
        ofile.open("temp.txt");
        ofstream tfile;
        tfile.open(filename, ios::app);

        Account account;

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number == account.account_number)
            {
                double quantity;
                int check = 0;
                while (check == 0)
                {
                    cout << "How many Stocks/Crypto to sell: ";
                    cin >> quantity;
                    while (quantity < 0)
                    {
                        cout << "Quantity can not be negative or zero, enter a positive value! " << endl;
                        cin >> quantity;
                    }
                    double price = stod(StocksOrCryptoTrading::get_price());
                    double sell_price = price * quantity;
                    if (acc->get_stocks_or_crypto() >= quantity)
                    {
                        account.stocks_or_crypto -= quantity;
                        account.balance += sell_price;
                        acc->balance += sell_price;
                        acc->stocks_or_crypto -= quantity;
                        ofile << endl
                              << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
                        check = 1;
                        tfile << endl
                              << 6 << " " << quantity << " " << price << " " << account.balance;
                        cout << "Sold Successfully!" << endl;
                    }
                    else
                    {
                        cout << "Insufficient Stocks/Crypto!" << endl;
                    }
                }
            }
            else
            {
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
        }

        tfile.close();
        ofile.close();
        ifile.close();

        remove("Accounts.txt");
        rename("temp.txt", "Accounts.txt");
    }

    void updatePIN(string account_number, Account *acc)
    {
        ifstream ifile;
        ifile.open("Accounts.txt");
        ofstream ofile;
        ofile.open("temp.txt");

        Account account;

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number == account.account_number)
            {
                string pass;
                char character;
                cout << "Enter New Pin: ";
                for (int i = 0; i < PIN_LENGTH; i++)
                {
                    while (true)
                    {
                        cin >> character;
                        if (character >= '0' && character <= '9')
                        {
                            break;
                        }
                        cout << "Enter digits from 0-9: ";
                    }
                    pass += character;
                }
                acc->set_pin(pass);
                account.pin = pass;

                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
                cout << endl
                     << "Pin Changed Successfully" << endl;
            }
            else
            {
                ofile << endl
                      << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
        }
        ofile.close();
        ifile.close();
        remove("Accounts.txt");
        rename("temp.txt", "Accounts.txt");
    }

    void trade(string account_number, Account *acc)
    {
        ifstream ifile;
        ifile.open("Accounts.txt");
        ofstream ofile;
        ofile.open("temp.txt");

        double invested_amount, remaining_amount;
        double quantity_crypto;
        int hold = 0;
        Account account;

        string filename = "transactions_" + account_number + ".txt";
        create_file(filename);
        ofstream tfile;
        tfile.open(filename, ios::app);

        while (!ifile.eof())
        {
            ifile >> account.account_number >> account.name >> account.cnic >> account.mobile_number >> account.balance >> account.pin >> account.status >> account.stocks_or_crypto;
            if (account_number == account.account_number)
            {
                cout << "How much do you want to invest : ";
                cin >> invested_amount;

                if (invested_amount > 0)
                {
                    if (acc->balance >= invested_amount)
                    {
                        acc->balance -= invested_amount;
                        account.balance -= invested_amount;

                        quantity_crypto = (invested_amount/stod(StocksOrCryptoTrading::get_price()));
                        cout<<"Price at buying time  : "<<stod(StocksOrCryptoTrading::get_price());
                        
                        double before_price = stod(StocksOrCryptoTrading::get_price());
                        StocksOrCryptoTrading::update_price();
                        double after_price = stod(StocksOrCryptoTrading::get_price());
                        remaining_amount = StocksOrCryptoTrading::trade_graph_display(invested_amount, before_price, after_price);
                        do
                        {
                            Sleep(500);
                            cout<<"\n\nCurrent Price : "<<stod(StocksOrCryptoTrading::get_price());
                            cout << "\n\nSelect on option : \n";
                            cout << "1. Hold trade" << endl;
                            cout << "2. Sell " << endl;
                            cout << endl << "Enter Choice: " << endl;
                            cin >> hold;
                            if (hold == 1)
                            {
                                before_price= after_price;      //the after price now becomes the before price
                                StocksOrCryptoTrading::update_price();
                                after_price = stod(StocksOrCryptoTrading::get_price());
                                remaining_amount = StocksOrCryptoTrading::trade_graph_display(quantity_crypto, before_price, after_price);
                            }
                        } while ((hold == 1));
                        cout<<"Price at selling time : "<<stod(StocksOrCryptoTrading::get_price())<<endl;
                        cout << "Amount invested : " << invested_amount << "\n";
                        if (remaining_amount > invested_amount)
                        {
                            cout << endl << "Profit: " << (remaining_amount - invested_amount) << endl;
                            cout << "Amount including profit : ";
                        }
                        else
                        {
                            cout << endl << "Loss: " << (remaining_amount - invested_amount) << endl;
                            cout << "Amount after loss : ";
                        }
                        cout << remaining_amount << endl;

                        acc->balance += remaining_amount;
                        account.balance += remaining_amount;

                        ofile << endl << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;

                        tfile << endl << 7 << " " << invested_amount << " " << remaining_amount << " " << acc->balance;
                        tfile.close();
                    }
                    else
                    {
                        cout << "InSufficient balance!" << endl;
                    }
                }
                else
                {
                    cout << "\nInvested amount can not be 0 or negative!\n\n";
                }
            }
            else
            {
                ofile << endl << account.account_number << " " << account.name << " " << account.cnic << " " << account.mobile_number << " " << account.balance << " " << account.pin << " " << account.status << " " << account.stocks_or_crypto;
            }
        }
        ofile.close();
        ifile.close();

        remove("Accounts.txt");
        rename("temp.txt", "Accounts.txt");
    }
};
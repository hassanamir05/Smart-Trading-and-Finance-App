#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Account.h"
#include "Stack.h"
using namespace std;

class TreeNode
{
public:
    Account account;
    TreeNode *left;
    TreeNode *right;

    TreeNode(const Account &acc)
    {
        account = acc;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree
{
private:
    TreeNode *root;

    void makeTree(BinarySearchTree *tree)
    {
        ifstream ifile;
        ifile.open("Accounts.txt");

        Account account;
        string account_number;
        string name;
        long cnic;
        long mobile_number;
        double balance;
        string status;
        double stocks_or_crypto;
        string pin;

        while (!ifile.eof())
        {
            ifile >> account_number >> name >> cnic >> mobile_number >> balance >> pin >> status >> stocks_or_crypto;

            account.set_account_number(account_number);
            account.set_name(name);
            account.set_cnic(cnic);
            account.set_mobile_number(mobile_number);
            account.set_balance(balance);
            account.set_pin(pin);
            account.set_status(status);
            account.set_stocks_or_crypto(stocks_or_crypto);

            tree->root = tree->insert(tree->root, account);
        }
        ifile.close();
    }

    TreeNode *insert(TreeNode *node, Account account)
    {
        if (node == NULL)
        {
            return new TreeNode(account);
        }

        if (account.get_account_number() < node->account.get_account_number())
        {
            node->left = insert(node->left, account);
        }
        else
        {
            node->right = insert(node->right, account);
        }

        return node;
    }

    Account *search(TreeNode *node, string account_number)
    {
        if (node == NULL || account_number == node->account.get_account_number())
        {
            return &(node->account);
        }
        else if (account_number < node->account.get_account_number())
        {
            return search(node->left, account_number);
        }
        else
        {
            return search(node->right, account_number);
        }
    }

    void view(Account *acc)
    {
        StocksOrCryptoTrading::update_price();
        char choice;

        do
        {
            cout << endl
                 << endl
                 << "MENU" << endl
                 << endl;
            cout << endl
                 << "1. Balance" << endl;
            cout << "2. All Details" << endl;
            cout << "3. Back" << endl;
            cout << endl
                 << "Enter Choice: ";
            cin >> choice;
            if (choice == '1')
            {
                cout << endl
                     << "Balance:" << acc->get_balance() << endl;
            }
            else if (choice == '2')
            {
                acc->view(acc->get_account_number());
            }
            else if (choice == '3')
            {
                cout << endl
                     << "BACK" << endl;
                break;
            }
            else
            {
                cout << endl
                     << "Invalid Choice" << endl;
            }
        } while (1);
    }

    void deposit(Account *acc)
    {
        StocksOrCryptoTrading::update_price();
        acc->deposit(acc->get_account_number(), acc);
    }

    void withdraw(Account *acc)
    {
        StocksOrCryptoTrading::update_price();
        acc->withdraw(acc->get_account_number(), acc);
    }

    void transfer(Account *acc_from, string account_number_to)
    {
        StocksOrCryptoTrading::update_price();
        Account *acc_to = search(root, account_number_to);
        if (acc_to == NULL)
        {
            cout << endl
                 << "Account Doesn't Exist!" << endl;
            return;
        }
        acc_from->transfer(acc_from->get_account_number(), account_number_to, acc_from, acc_to);
    }

    void transactions(Account *acc)
    {
        StocksOrCryptoTrading::update_price();
        acc->transactions(acc->get_account_number());
    }

    void trading(Account *acc)
    {
        StocksOrCryptoTrading::update_price();
        char choice;
        float amount;

        do
        {
            cout << endl
                 << endl
                 << "MENU" << endl
                 << endl;
            cout << "1. Graph" << endl;
            cout << "2. Buy" << endl;
            cout << "3. Sell" << endl;
            cout << "4. Trade" << endl;
            cout << "5. Back" << endl;
            cout << endl
                 << "Enter Choice: ";
            cin >> choice;
            if (choice == '1')
            {
                StocksOrCryptoTrading::update_price();
                StocksOrCryptoTrading::graph_display();
            }
            else if (choice == '2')
            {
                cout << endl
                     << "Stock/Crypto Price: " << StocksOrCryptoTrading::get_price() << endl;
                cout << endl
                     << "Balance: " << acc->get_balance() << endl;
                cout << endl
                     << "Stocks/Crypto Owned: " << acc->get_stocks_or_crypto() << endl;
                acc->purchase_stocks_or_crypto(acc->get_account_number(), acc);
                cout << endl
                     << "Balance: " << acc->get_balance() << endl;
                cout << endl
                     << "Stocks/Crypto Owned: " << acc->get_stocks_or_crypto() << endl;
                StocksOrCryptoTrading::update_price();
            }
            else if (choice == '3')
            {
                cout << endl
                     << "Stock/Crypto Price: " << StocksOrCryptoTrading::get_price() << endl;
                cout << endl
                     << "Balance: " << acc->get_balance() << endl;
                cout << endl
                     << "Stocks/Crypto Owned: " << acc->get_stocks_or_crypto() << endl;
                acc->sell_stocks_or_crypto(acc->get_account_number(), acc);
                cout << endl
                     << "Balance: " << acc->get_balance() << endl;
                cout << endl
                     << "Stocks/Crypto Owned: " << acc->get_stocks_or_crypto() << endl;
                StocksOrCryptoTrading::update_price();
            }
            else if (choice == '4')
            {
                StocksOrCryptoTrading::update_price();
                acc->trade(acc->get_account_number(), acc);
            }
            else if (choice == '5')
            {
                cout << endl
                     << "BACK" << endl;
                break;
            }
            else
            {
                cout << endl
                     << "Invalid Choice" << endl;
            }
        } while (1);
    }

    void update(Account *acc)
    {
        StocksOrCryptoTrading::update_price();
        acc->update(acc->get_account_number(), acc);
    }

    void delete_(Account *acc, BinarySearchTree *tree)
    {
        StocksOrCryptoTrading::update_price();
        acc->delete_files(acc->get_account_number());
        acc->delete_(acc->get_account_number());
        tree->root = NULL;
        tree->makeTree();
    }

    string get_otp(Account *acc)
    {
        StocksOrCryptoTrading::update_price();
        string otp = acc->generate_otp(acc->get_account_number());
        return otp;
    }

    void updatePIN(Account *acc)
    {
        StocksOrCryptoTrading::update_price();
        acc->updatePIN(acc->get_account_number(), acc);
    }

public:
    BinarySearchTree() : root(NULL)
    {
    }

    void lock_account(string account_number)
    {
        Account *acc;
        acc->create_needed_files();
        acc = search(root, account_number);
        if (acc == NULL)
        {
            cout << endl
                 << "Account Doesn't Exist!" << endl;
            return;
        }

        char character;
        Queue<char> pass;
        Queue<char> otp;
        char *char_arr;
        string s_otp = get_otp(acc);
        char_arr = new char[s_otp.length()];
        strcpy(char_arr, s_otp.c_str());
        for (int i = 0; i < PIN_LENGTH; i++)
        {
            otp.enqueue(char_arr[i]);
        }
        delete[] char_arr;
        cout << endl
             << "An OTP has been sent to you!" << endl;
        cout << "Enter OTP: ";
        for (int i = 0; i < OTP_LENGTH; i++)
        {
            cin >> character;
            pass.enqueue(character);
        }
        for (int i = 0; i < OTP_LENGTH; i++)
        {
            if (otp.dequeue() != pass.dequeue())
            {
                cout << endl
                     << "OTP Doesnt Match!" << endl;
                return;
            }
        }
        acc->set_status("locked");
        acc->lock_unlock_account(acc->get_account_number(), "locked");
        cout << endl
             << "Account has been locked!" << endl;
    }

    void forgot_pin(string account_number)
    {
        Account *acc;
        acc->create_needed_files();
        acc = search(root, account_number);
        if (acc == NULL)
        {
            cout << endl
                 << "Account Doesn't Exist!" << endl;
            return;
        }

        char character;
        Queue<char> pass;
        Queue<char> otp;
        char *char_arr;
        string s_otp = get_otp(acc);
        char_arr = new char[s_otp.length()];
        strcpy(char_arr, s_otp.c_str());
        for (int i = 0; i < PIN_LENGTH; i++)
        {
            otp.enqueue(char_arr[i]);
        }
        delete[] char_arr;
        cout << endl
             << "An OTP has been sent to you!" << endl;
        cout << "Enter OTP: ";
        for (int i = 0; i < OTP_LENGTH; i++)
        {
            cin >> character;
            pass.enqueue(character);
        }
        for (int i = 0; i < OTP_LENGTH; i++)
        {
            if (otp.dequeue() != pass.dequeue())
            {
                cout << endl
                     << "OTP Doesnt Match!" << endl;
                return;
            }
        }
        acc->set_status("unlocked");
        acc->lock_unlock_account(acc->get_account_number(), "unlocked");
        updatePIN(acc);
    }

    void makeTree()
    {
        Account acc;
        acc.create_needed_files();
        makeTree(this);
    }

    void create_account()
    {
        Account acc;
        acc.create_needed_files();
        acc = acc.create_account();
        root = insert(root, acc);
        cout << endl
             << "Account Number is: " << acc.get_account_number() << endl;
    }

    void login(string account_number)
    {
        Account *acc;
        acc->create_needed_files();
        acc = search(root, account_number);
        if (acc == NULL)
        {
            cout << endl
                 << "Account Doesn't Exist!" << endl;
            return;
        }
        if (acc->get_status() == "locked")
        {
            cout << endl
                 << "Account is locked!" << endl;
            forgot_pin(account_number);
        }
        Stack tries;
        char character;
        bool check;
        Queue<char> password;
        Queue<char> pin;
        string s_pin;
        char *char_arr;

        while (tries.pop())
        {
            check = true;
            s_pin = acc->get_pin();

            char_arr = new char[s_pin.length()];
            strcpy(char_arr, s_pin.c_str());
            for (int i = 0; i < PIN_LENGTH; i++)
            {
                pin.enqueue(char_arr[i]);
            }
            delete[] char_arr;

            cout << endl
                 << "Enter Pin: ";
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
                password.enqueue(character);
            }
            for (int i = 0; i < PIN_LENGTH; i++)
            {
                if (pin.dequeue() != password.dequeue())
                {
                    check = false;
                }
            }
            if (check)
            {
                cout << endl
                     << "Login Successful" << endl;
                char choice;
                char loop = 'Y';
                do
                {
                    cout << endl
                         << endl
                         << "MENU" << endl
                         << endl;
                    cout << "1. View" << endl;
                    cout << "2. Deposit" << endl;
                    cout << "3. Withdraw" << endl;
                    cout << "4. Transfer" << endl;
                    cout << "5. Previous Transactions" << endl;
                    cout << "6. Stocks/Crypto Trading" << endl;
                    cout << "7. Update Account" << endl;
                    cout << "8. Delete Account" << endl;
                    cout << "9. Logout" << endl;
                    cout << endl
                         << "Enter choice: ";
                    cin >> choice;
                    if (choice == '1')
                    {
                        view(acc);
                    }
                    else if (choice == '2')
                    {
                        deposit(acc);
                    }
                    else if (choice == '3')
                    {
                        withdraw(acc);
                    }
                    else if (choice == '4')
                    {
                        string acc_num;
                        cout << endl
                             << "Enter Account Number to Transfer Money to: ";
                        cin >> acc_num;
                        transfer(acc, acc_num);
                    }
                    else if (choice == '5')
                    {
                        transactions(acc);
                    }
                    else if (choice == '6')
                    {
                        trading(acc);
                    }
                    else if (choice == '7')
                    {
                        update(acc);
                    }
                    else if (choice == '8')
                    {
                        delete_(acc, this);
                        break;
                    }
                    else if (choice == '9')
                    {
                        cout << endl
                             << "Logout Successful" << endl;
                        break;
                    }
                    else
                    {
                        cout << endl
                             << "Invalid Action" << endl;
                    }

                } while (1);
                return;
            }
        }
        acc->set_status("locked");
        acc->lock_unlock_account(acc->get_account_number(), "locked");
    }
};
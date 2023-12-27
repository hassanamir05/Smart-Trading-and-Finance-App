#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>

using namespace std;

void srand(int seed);

class StocksOrCryptoTrading
{
private:
    static string price;
    int count = 0;

public:
    //  Constructor

    StocksOrCryptoTrading() // default constructor
    {
        // seeding
        static bool seeded = false;
        if (!seeded)
        {
            srand(static_cast<unsigned>(time(0)));
            seeded = true;
        }
        count = 0;
        StocksOrCryptoTrading::update_price();
    }

    // Accessors/ getter function
    static string get_price()
    {
        return price;
    }

    int get_count()
    {
        return count;
    }

    void set_count(int val)
    {
        count = val;
    }

    static void update_price()
    {
        // Generate a random string in the format "____.__"
        for (int i = 0; i < 4; ++i)
        {
            int random_index = rand() % 10; // generate a random index from 0 to 9
            price[i] = '0' + random_index;  // concatenate the character at the random index
        }
        price[4] = '.'; // place the dot at index 4
        for (int i = 5; i < 8; ++i)
        {
            int random_index = rand() % 10; // generate a random index from 0 to 9
            price[i] = '0' + random_index;  // concatenate the character at the random index
        }
    }

    static void graph_display()
    {
        ifstream infile;
        int characters_per_line = 53, counter = 0;

        int random_number = ((rand() % 2) + 1);
        if (random_number == 1)
        {
            random_number = ((rand() % 3) + 1);
            if (random_number == 1)
            {
                infile.open("smallIncrease.txt");
            }
            else if (random_number == 2)
            {
                infile.open("mediumIncrease.txt");
            }
            else
            {
                infile.open("largeIncrease.txt");
            }
        }
        else
        {
            random_number = ((rand() % 3) + 1);
            if (random_number == 1)
            {
                infile.open("smallDecrease.txt");
            }
            else if (random_number == 2)
            {
                infile.open("mediumDecrease.txt");
            }
            else
            {
                infile.open("largeDecrease.txt");
            }
        }
        char ch;
        while (infile >> ch)
        {
            if (counter == characters_per_line || counter == 0)
            {
                cout << "\t\t\t\t\t";
                cout << endl;
                counter = 0;
            }
            cout << ch;
            counter++;
        }
        infile.close();
    }

    static double trade_graph_display(double quantity, double before_trade, double after_trade)
    {
        ifstream infile;
        bool hold = true;
        int characters_per_line = 53, counter = 0;

        double remaining_amount;

        if (before_trade < after_trade)
        {
            if (after_trade >= (before_trade * 1.1) && after_trade <= (before_trade * 1.3))
            {
                infile.open("smallIncrease.txt");
            }
            else if (after_trade > (before_trade * 1.298) && after_trade <= (before_trade * 1.7))
            {
                infile.open("mediumIncrease.txt");
            }
            else
            {
                infile.open("largeIncrease.txt");
            }
        }
        else
        {
            if (after_trade >= (before_trade * 0.7) && after_trade < (before_trade * 1.0))
            {
                infile.open("smallDecrease.txt");
            }
            else if (after_trade >= (before_trade * 0.3) && after_trade < (before_trade * 0.7))
            {
                infile.open("mediumDecrease.txt");
            }
            else
            {
                infile.open("largeDecrease.txt");
            }
        }

        remaining_amount = quantity * stod(get_price());

        char ch;
        while (infile >> ch)
        {
            if (counter == characters_per_line || counter == 0)
            {
                Sleep(20);
                cout << endl;
                cout << "\t\t\t";
                counter = 0;
            }
            cout << ch;
            counter++;
        }
        infile.close();
        cout << endl;

        return remaining_amount;
    }
};

string StocksOrCryptoTrading::price = "0000.00";

StocksOrCryptoTrading s;
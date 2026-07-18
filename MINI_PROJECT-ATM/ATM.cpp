#include <conio.h> //we are using the library for a C library function from conio.h which is => getch() so that it holds the screen until user pressed something on the keyboard
#include <iostream>
#include <string>
using namespace std;



class atm
{
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public:
    //setData function is setting the Data into the private 
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a)
    {
        account_No = account_No_a; //assigning these formal argument to private member variable

        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }


    //getAccountNo function is returning the user account no

    long int getAccountNo()
    {
        return account_No;
    }

    //getName function is returning the user's Name

    string getName()
    {
        return name;
    }


    //getPIN function is returning the user's PIN
    int getPIN()
    {
        return PIN;
    }


    //getBalance is returning user bank Balance

    double getBalance()
    {
        return balance;
    }


    string getMobileNo()
    {
        return mobile_No;
    }


    //setMobile function is for update the mobile no of users

    void setMobile(string mob_prev, string mob_new)
    {
        if(mob_prev == mobile_No)
        {
            //update with new if old matches
            mobile_No = mob_new;

            cout << endl << "Successfully Update Mobile No";
            _getch(); //getch is used to hold the screen until user presses and key
        }
        else
        {
            cout << endl << "Incorrect!!! Old Mobile No";
            _getch();
        }
    }


//withdraw money with cashWithDraw function
    void cashWithDraw(int amount_a)
    {
        if(amount_a > 0 && amount_a <= balance) //checking entered amount validity
        {
            balance -= amount_a;
            cout << endl << "Please Collect Your Cash";
            cout << endl << "Avaialble Balance :" << balance;
            _getch();
        }
        else
        {
            cout << "Insufficient Balance";
            _getch();
        }
    }

};


/////////////////////////////////////////////////////////////////

int main()
{
    //creating enterPIN and enterAccountNo for user authentication
    int choice = 0, enterPIN;
    long int enterAccountNo;

    system("cls");


    //creating user {object}

    atm user1;

    user1.setData(1234567,"Tim", 1111, 45000.90, "9087654321");


    do
    {
        system("cls");

        cout << "Welcome to ATM" << endl;
        cout << endl << "Enter Your Account No ";
        cin >> enterAccountNo;


        cout << endl << "Enter PIN";
        cin >> enterPIN;

        if((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");

                //user Interface

                cout << endl << "**** Welcome To ATM *****" << endl;
                cout << endl << "Select Option ";
                cout << endl << "1 Check balance";
                cout << endl << "2 Cash Withdraw";
                cout << endl << "3 Show User Details";
                cout << endl << "4 Update Mobile No";
                cout << endl << "5 Exit" << endl;
                cin >> choice;



                switch(choice)
                {
                    case 1:
                        cout << endl << "Your Bank Balance is: " << user1.getBalance();

                        _getch();
                        break;
                    case 2:
                        cout << endl << "Enter Amount ";
                        cin >> amount;
                        user1.cashWithDraw(amount);
                        break;
                    case 3:
                        cout << endl << "*** User Details are :- ";
                        cout << endl << "-> Account No: " << user1.getAccountNo();
                        cout << endl << "-> Name: " << user1.getName();
                        cout << endl << "-> Balance: " << user1.getBalance();
                        cout << endl << "-> Mobile No: " << user1.getMobileNo();

                        _getch();
                        break;
                    case 4:
                        cout << endl << "Enter Old Mobile No ";
                        cin >> oldMobileNo;

                        cout << endl << "Enter New Mobile No ";
                        cin >> newMobileNo;

                        user1.setMobile(oldMobileNo, newMobileNo);
                        break;
                    case 5:
                        exit(0);
                        break;
                    default:
                        cout << endl << "Enter Valid Data !!!";
                        _getch();
                    }
            }
            while(1);
        }
        else
        {
            cout << endl << "Incorrect Account No or PIN !!!" << endl;
            cout << endl << "Press any key to try again or ESC to exit";
            int ch = _getch();
            if(ch == 27)
                exit(0);
        }
    }
    while(1);
}
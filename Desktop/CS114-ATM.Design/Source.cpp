#include<iostream>
#include<cstring>
#include"atm.h"
using namespace std;
int main()
{
	ATM User;
	while (1)
	{
		string name, pass;


		cout << "Welcome!" << endl << endl;
		cout << "Please enter your account number: ";
		cin >> name;
		cout << endl << "Enter your PIN: ";
		cin >> pass;
		cout << endl;

		User.user(name, pass);

		if (User.signin())
		{
			while (1)
			{
				int choice = 0;
				string input;
				cout << "Main menu: " << endl;
				cout << "1 - View my balance" << endl;
				cout << "2 - Withdraw cash" << endl;
				cout << "3 - Deposit funds" << endl;
				cout << "4 - Exit" << endl << endl;
				cout << "Enter a choice: ";
				cin >> input;
				cout << endl;
				choice = atoi(input.c_str());

				if (choice == 4)
				{
					cout << "Exiting the system..." << endl << endl;
					cout << "Thank you! Goodbye!" << endl << endl;
					break;
				}
				else
				{
					switch (choice)
					{
					case 1:
						User.ViewMyBalance();
						break;
					case 2:
						User.WithdrawCash();
						break;
					case 3:
						User.DepositFund();
						break;
					default:
						break;
					}
				}
			}
		}
	}
}
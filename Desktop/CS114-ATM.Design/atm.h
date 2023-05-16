#include<iostream>
#include<string>#pragma once
using namespace std;
class ATM
{
public:
	ATM();
	void user(string Account, string PIN);
	bool signin();
	void ViewMyBalance();
	void WithdrawCash();
	void DepositFund();

private:
	string account;
	string password;
	double availble[2], total[2];
	int ch;
};

ATM::ATM()
{
		availble[0] = 1000.0;
		total[0] = 1200.0;
		availble[1] = 200.0;
		total[1] = 200.0;
	
}
void ATM::user(string Account, string PIN)
{
	account = Account;
	password = PIN;
}
bool ATM::signin()
{
	if (account == "12345")
	{
		if (password == "54321")
		{
			ch = 0;
			return true;
		}
		else
			return false;
	}
	else if (account == "98765")
	{
		if (password == "56789")
		{
			ch = 1;
			return true;
		}
		else
			return false;
	}
}
void ATM::ViewMyBalance()
{
	cout << "Balance Information:" << endl;
	cout << "- Available balance: $" << availble[ch] << endl;
	cout << "- Total balance: $" << total[ch] << endl << endl;
}
void ATM::WithdrawCash()
{
	int choice = 0;
	cout << "Withdrawal options:" << endl;
	cout << "1 - $20" << endl;
	cout << "2 - $40" << endl;
	cout << "3 - $60" << endl;
	cout << "4 - $100" << endl;
	cout << "5 - $200" << endl;
	cout << "6 - Cancel transaction" << endl << endl;
	cout << "Choose a withdrawal option (1-6): ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		if ((availble[ch] - 20) >= 0 && (total[ch] - 20) >=0)
		{
			availble[ch] -= 20;
			total[ch] -= 20;
		}
		break;
	case 2:
		if ((availble[ch] - 40) >= 0 && (total[ch] - 40) >= 0)
		{
			availble[ch] -= 40;
			total[ch] -= 40;
		}
		break;
	case 3:
		if ((availble[ch] - 60) >= 0 && (total[ch] -60) >= 0)
		{
			availble[ch] -= 60;
			total[ch] -= 60;
		}
		break;
	case 4:
		if ((availble[ch] - 100) >= 0 && (total[ch] - 100) >= 0)
		{
			availble[ch] -= 100;
			total[ch] -= 100;

		}
		
		break;
	case 5:
		if ((availble[ch] - 200) >= 0 && (total[ch] - 200) >= 0)
		{
			availble[ch] -= 200;
			total[ch] -= 200;
		}
		break;
	default:
		break;
	}
	cout << "Please take your cash from the cash dispenser." << endl << endl;
}
void ATM::DepositFund()
{
	int deposit = 0;
	float t = 0;
	cout << "Please enter a deposit amount in CENTS (or 0 to cancel): ";
	cin >> deposit;
	cout << endl;
	cout << "Please insert a deposit envelope containing $10.00 in the deposit slot." << endl << endl;
	t = deposit % 100;
	deposit /= 100;
	total[ch] += deposit + t * 0.01;
	cout << "NOTE: The money deposited will not be available until we verify the amount of any enclosed cash, and any enclosed checks clear." << endl << endl;
}
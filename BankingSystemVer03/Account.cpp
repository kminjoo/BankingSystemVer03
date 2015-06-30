/*
* Name: Minjoo Kwon
* Project: BankingSystemVer03
* Account.cpp
*/

/*
깊은 복사를 원칙으로 한다면, 클래스의 생성자만 봐도 복사 생성자의 필요성을 판단할 수 있다. 실제 복사 생성자의 호출여부는 중요하지 않다.
클래스는 그 자체로 완성품이 되어야 하기 때문에, 당장 필요한것만으로 채우지 않는다.
Account 클래스에 깊은 복사를 진행하는 복사 생성자를 정의한다.
비록 복사생성자가 호출되지는 않지만, 깊은 복사를 우너칙으로정하고 이를 위해서 복사생성자를 추가하기로 하겠다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(char *name_in, int ID_in, int balance_in)
{
	const int LEN = strlen(name_in) + 1;
	cusName = new char[LEN];
	strcpy(cusName, name_in);

	accountID = ID_in;
	balance = balance_in;
}

Account::Account(const Account& copy)
	:accountID(copy.accountID), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}


char* Account::GetName() const
{
	return cusName;
}

int Account::GetID() const
{
	return accountID;
}

int Account::GetBalance() const
{
	return balance;
}

void Account::AddBalance(int balance_in)
{
	balance += balance_in;
}

void Account::Withdrawl(int withdrawl_in)
{
	balance -= withdrawl_in;
}

void Account::ShowInfos(int numPeople_in) const
{
	cout << "Account ID: " << accountID << endl;
	cout << "Name: " << cusName << endl;
	cout << "Balance: $" << balance << endl;
}
Account::~Account()
{
	delete[]cusName;
}
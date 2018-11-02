#pragma once
#include<vector>
#include "Konto.h"

using namespace std;
class Bank
{
public:
	Bank();
	~Bank();

private:
	vector <Konto*> accounts;
	Konto* getAccount(int nummer);
	void addAccount();
	void deleteAccount();
	void manipulate();

public:
	void showMenu();

};


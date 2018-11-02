#pragma once
#include<vector>

using namespace std;
class Konto
{
public:
	Konto();
	~Konto();

private:
	int id;
	int balance=0;
	vector <int> history;


public:
	void withdraw();
	Konto(int id);
	void deposite();
	int getBalance();
	vector<int> getHistory();
	int getID();




};


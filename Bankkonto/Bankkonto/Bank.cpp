#include "pch.h"
#include "Bank.h"
#include<iostream>


Bank::Bank()
{
}


Bank::~Bank()
{
}

Konto * Bank::getAccount(int nummer)
{
	
	for (Konto* a : this->accounts)
	{
		if (a->getID() == nummer)
			return a;
	}
	cout << "Kontonummer existiert nicht\n"; // wenn nie in die if schleife nie true existiert die Kontonr. nicht
	return nullptr;
}

void Bank::addAccount()
{
	if (accounts.size() == 0)
	{
		Konto *neuesKonto = new  Konto(1);
		this->accounts.push_back(neuesKonto);
		cout << "Ihr Konto mit der Nr.:" << neuesKonto->getID() << " wurde erstellt\n";
	}
	else
	{
		Konto *neuesKonto = new  Konto(this->accounts.back()->getID() + 1);
		this->accounts.push_back(neuesKonto);
		cout << "Ihr Konto mit der Nr.:" << neuesKonto->getID() << " wurde erstellt\n";
	}
}

void Bank::deleteAccount()
{
	int nummer;
	cout << "Bitte geben Sie die Kontonummer ein\n";
	cin >> nummer;
	vector<Konto*> ::iterator it;
	for (it = this->accounts.begin(); !(it == this->accounts.end()); it++)
		if ((*it)->getID() == nummer)
		{
			accounts.erase(it);
			return;
		}
			

}

void Bank::manipulate()
{
	int temp;
	Konto *kont;
	cout << "Geben Sie die Kontonummer ein\n";
	cin >> temp;
	if((kont = getAccount(temp)) == NULL)
		return;
	else
	{
		while (1)
		{
			cout << " 1) Einzahlen\n 2) Abheben\n 3) Kontostand\n 4) History\n 99) zurueck\n\n";
			cin >> temp;
			switch (temp)
			{
			case 1: kont->deposite(); break;
			case 2: kont->withdraw(); break;
			case 3: cout << "Ihr Kontostand betraegt:" << kont->getBalance() << "Euro\n"; break;
			case 4: for (int a : kont->getHistory()) cout << a << "Euro\n"; cout << "Kontostand:" << kont->getBalance() << "Euro\n";  break;
			case 99: return;
			default: cout << "Falsche Eingabe\n";

			}
		}
	}
		


}

void Bank::showMenu()
{
	cout << " 1) Konto erstellen\n 2) Konto loeschen\n 3) Konto manipulieren\n 99) beenden\n\n";
	int temp;
	cin >> temp;

	if (temp == 1)
		addAccount();
	else if (temp == 2)
		deleteAccount();
	else if (temp == 3)
		manipulate();
	else if (temp == 99)
		exit(0);
	else
		cout << "Falsche Eingabe\n";
}
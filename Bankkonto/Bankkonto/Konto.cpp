#include "pch.h"
#include "Konto.h"
#include<iostream>

Konto::Konto()
{
}


Konto::~Konto()
{
}

void Konto::withdraw()
{
	int abheben;
	cout << "Wieviel wollen Sie abheben?\n";
	cin >> abheben;
	if (abheben > 0)			//nur positive werte groesser 0 sinnvoll
	{
		this->balance -= abheben;
		this->history.push_back(abheben*-1);

	}
	else
		cout << "Nur positive Betraege groesser 0 moeglich\n";
}

void Konto::callwithdraw()
{
	withdraw();
}

Konto::Konto(int id)
{
	this->id = id;
}

void Konto::deposite()
{
	int einzahlen;
	cout << "Wie viel wollen Sie einzahlen?\n";
	cin >> einzahlen;
	if (einzahlen > 0)
	{
		this->balance += einzahlen;
		this->history.push_back(einzahlen);
	}
	else
		cout << "Nur positive Betraege groesser 0 moeglich\n";
}

int Konto::getBalance()
{
	return this->balance;
}

vector<int> Konto::getHistory()
{
	return vector<int>(this->history);
}

int Konto::getID()
{
	return this->id;
}

#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include "OrderedList.h"
#include "UnoCard.h"
using namespace std;

class UnoPlayer
{
public:
	OrderedList<UnoCard, IsLess> hand;
	friend std::ostream& operator<<(std::ostream& os, const UnoCard &c);
	string getName();
	void setName(string name);
	int isMatch(UnoCard topOfDeck);
private:
	string Name;
};


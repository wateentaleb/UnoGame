
#include <iostream>
#include "UnoPlayer.h"
#pragma warning(disable: 4996)
using namespace std;

int UnoPlayer::isMatch(UnoCard topOfDeck)
{
	Number tempnumber = topOfDeck.getNumber();
	Color tempcolor = topOfDeck.getColor();

	//Check to see if the player has a card in their hand with the same number as the card on top of the face up pile
	for (int i = 1; i <= hand.getLength(); i++)
	{
		if ((hand.retrieve(i).getNumber()) == tempnumber)
		{
			return i;
		}
	}

	//Check to see if the player has a card in their hand with the same number as the card on top of the face up pile
	for (int i = 1; i <= hand.getLength(); i++)
	{
		if ((hand.retrieve(i).getColor()) == tempcolor)
		{
			return i;
		}
	}

	//If there is no Number or color match, return -1
	return -1;
}
string UnoPlayer::getName()
{
	return Name;
}

void UnoPlayer::setName(string name)
{
	Name = name; 
}

//Overload the << operator to write a print function for UnoPlayer
ostream& operator<<(std::ostream& os, UnoPlayer &player)
{
	os << player.getName();

	return os;
}

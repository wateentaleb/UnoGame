#include "UnoCard.h"
#include <iostream>
using namespace std;

UnoCard::UnoCard()
{

}

UnoCard::UnoCard(Color color, Number number): x_color(color), x_number(number)
{

}

// destructor
UnoCard::~UnoCard()
{

}

char UnoCard::toCharColor()
{
	if (x_color == RED)   return 'R';
	else if (x_color == BLUE)    return 'B';
	else if (x_color == GREEN)   return 'G';
	else                       return 'Y';
}

char UnoCard::toCharNumber()
{
	if (x_number == N1)	
		return '1';
	else if (x_number == N2)	
		return '2';
	else if (x_number == N3)	
		return '3';
	else if (x_number == N4)	
		return '4';
	else if (x_number == N5)	
		return '5';
}

std::ostream& operator<<(std::ostream& os, const UnoCard &c) 
{
	Color colorx= c.getColor();
	Number num = c.getNumber();

	switch (colorx) 
	{
	case RED:
		os << "A Red";
		break;
	case BLUE:
		os << "A Blue";
		break;
	case GREEN:
		os << "A Green";
		break;
	case YELLOW:
		os << "A Yellow";
		break;
	}
	
	switch (num) 
	{
	case 1:
		os << " 1";
		break;
	case 2:
		os << " 2";
		break;
	case 3:
		os << " 3";
		break;
	case 4:
		os << " 4";
		break;
	case 5:
		os << " 5";
		break;
	}
	
	return os;
}
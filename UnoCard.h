#pragma once
#pragma once
#include <iostream>
// User defined Color and Number types (user-defined integers) 
enum Color { RED = 11, BLUE = 12, GREEN = 13, YELLOW = 14 };
enum Number { N1 = 1, N2 = 2, N3 = 3, N4 = 4, N5 = 5 };

class UnoCard
{
public:
	UnoCard();
	UnoCard(Color color, Number number = N5); // constructor with some default values
	~UnoCard(); // destructor
	inline Color getColor() const 
	{ 
		return x_color; 
	}
	inline Number getNumber() const 
	{ 
		return x_number; 
	}
	char toCharColor(void); // returns a char that "describes" UnoCard's Color
	char toCharNumber(void); // returns a char that "describes" UnoCard's Number

public:
	Color x_color; // private storage of Color
	Number x_number; // private storage of Number
	friend std::ostream& operator<<(std::ostream& os, const UnoCard &c);
};

//ARE THESE EXTRA FUNCTIONS?

// checks equality of suits and Numbers for two cards
inline bool operator==(UnoCard& a, UnoCard& b)
{
	return (a.getNumber() == b.getNumber() && a.getColor() == b.getColor());
}

// global operator functions comparing Numbers of two cards
// The cards a and b are passed by reference
inline bool operator<(const UnoCard& a, const UnoCard& b) {
	if (a.getColor() == b.getColor()) return (a.getNumber()<b.getNumber());
	else                            return (a.getColor()<b.getColor());
}
inline bool operator>(const UnoCard& a, const UnoCard& b) {
	if (a.getColor() == b.getColor()) return (a.getNumber()>b.getNumber());
	else                            return (a.getColor()>b.getColor());
}


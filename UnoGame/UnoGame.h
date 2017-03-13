#pragma once
#pragma warning(disable: 4996)
#define NUMBER_OF_PLAYERS = 3
#include <iostream>
#include "Stack.h"
#include "UnoCard.h"
#include "LinkedList.h"
#include "UnoPlayer.h"
#include "Queue.h"
#include "Bag.h"
#include <string>
using namespace std;

// codes are explained below 
class UnoGame
{
public:
	UnoGame(unsigned int num);
	void make_a_hand(unsigned int num_player);
	void firstcard();
	void Game_Deck();
	void emptyDeck();
	void players(unsigned int num_player);
	void game(unsigned int new_player);
	int Winner(unsigned int new_players);
	Stack<UnoCard> facingUp;
	UnoPlayer * container;
	Queue<UnoCard> deck;
};
// gives all the function the number of players in main 

UnoGame::UnoGame(unsigned int numPlayers)
{
	Game_Deck();
	players(numPlayers);
	make_a_hand(numPlayers);
	firstcard();
	game(numPlayers);
}

// creates the deck for the game, 2 cards of each, 4 colors, 5 numbers 

void UnoGame::Game_Deck()
{
	Bag<UnoCard> bag;
	//First create cards and put them into a bag
	Color c[] = { RED, BLUE, GREEN, YELLOW };
	Number n[] = { N1, N2, N3, N4, N5 };

	//We are creating 2 of every type of UnoCard
	for (int a = 1; a < 3; a++)
	{
		//4 suits
		for (int b = 0; b <= 3; b++)
		{
			//5 denominations
			for (int z = 0; z <= 4; z++)
			{
				bag.add(UnoCard(c[b], n[z]));
			}
		}
	}

	//Next, draw cards from bag and place them into the deck
	for (int i = 1; i <= 40; i++)
	{
		deck.enqueue(bag.getOne());
	}
}

// pulls up the first card 

void UnoGame::firstcard()
{
	UnoCard temp = deck.dequeue();
	facingUp.push(temp);
}

// this checks if the any of the players have won after matching a card, checks the hand length of each player 
int UnoGame::Winner (unsigned int new_player)
{
	for (int i = 0; i < new_player; i++)
	{
		if (container[i].hand.isEmpty() == true)
			return i;
	}
	return -1;
}

// this empties the deck, useful to not waste computer memory
void UnoGame::emptyDeck()
{
	if (deck.isEmpty() == true)
	{
		//Pop the top UnoCard off the face up pile
		UnoCard temp = facingUp.pop();
		Bag<UnoCard> shuffleBag;

		//Now, throw the cards into the bag
		while (facingUp.isEmpty() == false)
		{
			shuffleBag.add(facingUp.pop());
		}

		//Add the the temporary UnoCard to the top of the face up pile
		facingUp.push(temp);

		//Take the cards out of the bag and put them back into the deck
		for (int i = 0; i < shuffleBag.currentSize(); i++)
		{
			deck.enqueue(shuffleBag.getOne());
		}
	}
}

// the majority of this project is in this function, a while loop that make sure to keep looping while no one has won 
void UnoGame::game(unsigned int new_player)
{
	cout << "Username: twateen" << endl; 
	cout << "Student Number: 250 841 825" << endl; 
	cout << "Course: 1037 Comp Sci (lit course" << endl; 
	cout << "Welcome to UNO!, My name is Wateen, Good Luck!!" << endl;
	// setting the game as not won yet 
	int isGameWon = -1;
	// while the game isnt won
	while (isGameWon == -1)
	{
		for (int i = 0; i < new_player; i++)
		{




			int cardIndex = container[i].isMatch(facingUp.peek());
			cout << endl;
			cout << "The card to match is: " << facingUp.peek() << endl; 
			
			

		// if the card the player has matched the card facing up, remove it from hand, put it in the pile 
			if (cardIndex != -1)
			{
				// creating a temporary card 

				// removing it fromt the hand 
				UnoCard temp = container[i].hand.remove(cardIndex);
				cout << "Card Match!!!!" << endl; 
				cout << "The Card" << temp << "Was matched by Player" << (i + 1) << endl; 
				facingUp.push(temp);
			}



		// if no card is matched, (which sucks), they have to take from the pile. 

			if (cardIndex == -1)
			{
				cout << "No Card Matched by Player" << (i + 1) << endl; 
			
				UnoCard temp = deck.dequeue();

				cout << "Card taken from teh Pile: " << temp << endl;

				container[i].hand.insert(temp);




				// double check if the card taken matches with the face up pile 
				cardIndex = container[i].isMatch(facingUp.peek());


				//remove if matches
				if (cardIndex != -1)
				{
					UnoCard temp = container[i].hand.remove(cardIndex);
					cout << "Card Match!, Player"<<(i+1)<<" matched card: " << temp; 
					facingUp.push(temp);
				}
			}
			if (container[i].hand.getLength() > 1 || container[i].hand.getLength() == 0) {
				cout << "Player: " << (i + 1) << " has: " << container[i].hand.getLength() << " cards left" << endl;
			
			}
			else if (container[i].hand.getLength() == 1) {
				cout << "UNOOOOOOOOO yells Player: " << (i + 1) << endl;
				
			}
			
			emptyDeck();

			
			
		}

		int winner = Winner(3);
		cout << "WE HAVE A WINNER, Congrats to PLAYER:  " << (winner+1) << endl;
		

		cout << endl;
		isGameWon = Winner(new_player);
	}

	
}


// sets up the players
void UnoGame::players(unsigned int new_player)
{
	for (int i = 0; i < new_player; i++)
	{
		container = new UnoPlayer[new_player];
	}
}


// distributes the cards amoungts the players 

void UnoGame::make_a_hand(unsigned int new_player)
{
	for (int i = 0; i < new_player; i++)
	{
		// dont forget to change j as a 7, leaving it 5 to test if it still works 
		for (unsigned int j = 0; j < 5; j++)
		{
			UnoCard temp = deck.dequeue();
			container[i].hand.insert(temp);
		}
	}
}
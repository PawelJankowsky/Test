#pragma once
#include "Card.h"
#include "Player.h"
#include <iostream>
#include <ctime>

class Player;
class Deck 
{
private:
	int length;
	static const int MAXSIZE = 108; //108 cards in UNO
	

public:
	Deck();
	
	void createDeck();
	void shuffle();
	void pop();
	int top();
	bool isEmpty();
	bool isFull();
	void toString(Card::Color color); //converts enum to string.
	void valueToString(int value);
	void dealCard(Player &player);
	Card getCard();
	Card* deck;

	~Deck();
};
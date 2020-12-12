#pragma once

#include <vector>
#include <iostream>
#include "Deck.h"
#include "Card.h"


using namespace std;
class Card;
class Deck;
class Game;

class Player 
{
private:
	string username; //can indicate whos turn / wins
	static const int HANDSIZE = 7;
	vector<Card> hand;

public:
	Player();
	void pushHand(Card deck); 
	void deleteHand(int position);
	void printHand(Deck deck);
	void setHand(Deck &deck, Player& player); 
	Card getHandCard(Player& player, int position);
	int getHANDSIZE();
	string getUserName();
	void setUserName(std::string name);
	bool isEmpty(Player& player); //hand is empty
	bool isOne(Player& player);

	~Player();
};


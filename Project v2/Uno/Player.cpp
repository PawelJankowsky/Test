#include "Player.h"
class Player;
using namespace std;

Player::Player()
{
	
}

void Player::pushHand(Card deck)
{
	this->hand.push_back(deck);
	
}

void Player::deleteHand(int position)
{
	for (int i = 0; unsigned(i) < unsigned(hand.size()); i++)
	{
		if (i == position-1)
		{
			hand.erase(hand.begin()+i);
		}
	}
}

void Player::printHand(Deck deck)
{
	for (int i = 0; unsigned(i) < unsigned(hand.size()); i++)
	{
		cout << i+1 << ". ";
		cout << "Color: ";
		deck.toString(hand[i].color);
		cout << " | " << "Value: ";
		deck.valueToString(hand[i].value);
		cout << endl;
		
	}
}

void Player::setHand(Deck &deck, Player& player) //used only for setting hand at beginning of game
{
	for (int i = 0; i < getHANDSIZE(); i++)
	{
		deck.dealCard(player);
	}
}

Card Player::getHandCard(Player& player, int position)
{
	return this->hand[position - 1];

}

int Player::getHANDSIZE()
{
	return 7; //7 cards in hand to start
}

string Player::getUserName()
{
	return username;
}

void Player::setUserName(string name)
{
	username = name;
}

bool Player::isEmpty(Player& player)
{
	if (hand.size() == 0)
	{
		return true;
	}

	return false;
}

bool Player::isOne(Player& player)
{
	if (hand.size() == 1)
	{
		return true;
	}

	return false;
}
Player::~Player()
{
	
}

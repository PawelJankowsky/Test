#pragma once
#include "vector"
#include "Player.h"

class Card
{
private:


public:
	
	enum class Color { BLUE, GREEN, RED, YELLOW, WILD };
	Card();
	//int skip(Player& player, Deck& deck, int& playerIndex, const vector<Player*> playerVector);
	Color color{};
	int value{};
	Card(Color color, int value);
	

	~Card();
};


class specialskip : public Card {
public:
	specialskip();
	int skip(Player& player, Deck& deck, int& playerIndex, const vector<Player*> playerVector)
	{
		//skip
		playerIndex = (playerIndex + 2) % playerVector.size();
		return playerIndex;
	}

	~specialskip();

};


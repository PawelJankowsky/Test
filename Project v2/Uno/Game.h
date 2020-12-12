#pragma once
#include "Player.h"
#include "algorithm"

#include <string>
#include <vector>

class Global;
using namespace std;


class Game : protected Player, protected Deck
{
private:
	int amountOfPlayers;
	vector<Player*> playerVector;
	vector<Card> inPlay; //cards in play

public:
	Game();

	void createPlayerVector(Deck& deck);
	void menu(Deck &deck, Player &player, Game game);
	void iterateTurn(Player& player, Deck& deck);
	void drawOrPlay(Player& player, Deck& deck, int i);
	bool chooseCard(Player& player, Deck& deck, int chooseOrDraw, int playerIndex);
	bool validate(Player& player, int playerIndex, int chooseOrDraw);
	bool win(Player& player);
	void playGame(Player& player, Game game, Deck& deck);
	void ifSpecialCard(Player& player, Deck& deck, int chooseOrDrawint,int &playerIndex);
	void reverse(Player& player, Deck& deck, int chooseOrDrawint, int playerIndex);
	
	void drawTwo(Player& player, Deck& deck, int chooseOrDraw, int playerIndex); 
	void wildDrawFour(Player& player, Deck& deck, int chooseOrDraw, int playerIndex);
	
	~Game();
};

class Exception :public exception {

public:
	const char* what() const throw()
	{
		return "Exception caught: Unable to open file";
	}
};


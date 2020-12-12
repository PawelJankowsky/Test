#include "Game.h"
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Global.h"
//#include <vld.h>

using namespace std;



int main()
{
	
	Game game;
	Deck deck;
	Player player;
	Global global;
	Card card;

	
	//system("mode 650");
	//global.intro();
	
	try {
		
		game.menu(deck, player, game);
		throw Exception();
		system("pause");
	}
	catch (Exception& g)
	{
		cout << g.what() << endl;
	}
	
	

	return 0;
}

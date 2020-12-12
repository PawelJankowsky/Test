#include "Game.h"
#include "card.h"
#include <fstream>
#include "Card.h"
using namespace std;
specialskip drawn;
bool reverseCard = false;
bool skipCard = false;
int skip;
Game::Game()
{
	Deck deck;
}

void Game::createPlayerVector(Deck &deck)//function for assigning number of players
{
	
	string userName;
	cout << "Please enter the amount of players: ";
	cin >> amountOfPlayers;//inputing number of players

	if (amountOfPlayers < 2 || amountOfPlayers>10)
	{
		if (amountOfPlayers < 2)
		{
			cout << "Sorry! Not enough players." << endl;
			return Game::createPlayerVector(deck);//at least two players are needed
		}

		if (amountOfPlayers > 10)
		{
			cout << "Sorry! Too many players." << endl;//you can't play with too many people
		}
	}

	else
	{
		cout << "Please enter the names of each player." << endl;//We need to differentiate players somehow
		cin.ignore();

		for (int i = 0; i < amountOfPlayers; i++)//iterating players so everyone can have a name
		{
			Player* player = new Player;
			playerVector.push_back(player);
		
			cout << "Player " << i+1 << ": ";

			getline(cin, userName);

			playerVector[i]->setUserName(userName);
			playerVector[i]->setHand(deck, *player);//every player needs his set of cards
			
		}
		
	}
	
	system("PAUSE");
	system("CLS");

return;
}

void Game::menu(Deck& deck, Player& player, Game game)
{

	int choice;
	ifstream myfile("Rules.txt");
	//The Menu
	cout << "UNO" << endl;
	cout << "1. Play Game" << endl;
	cout << "2. Read Rules" << endl;
	cout << "3. Quit" << endl;

	
	do
	{
		
		cin >> choice;
		string line;
		switch (choice)//what do we want to do?
		{
		case 1:
			cout << "Play Game" << endl;//I thnk it is self-explanatory
			game.playGame(player, game, deck);//what every game needs, which is players, gameplay and assets
			
			break;

		case 2:
			cout << "Read Rules" << endl;//some people may not know the rules and internet connection may not be available, so we incldue the rules file
			try
			{
				if (myfile.is_open())
				{
					while (getline(myfile, line))
					{
						cout << line << '\n';
					}


					myfile.close();
				}
				else throw Exception(); 
				system("pause");
			}
			catch (Exception& g)
			{
				cout << g.what() << endl;
			}
			system("CLS");
			return Game::menu(deck,player,game);//we go back to the menu so we are not stuck on the rules
			
			break;
		case 3:
			
			break;//if we change our mind and don't want to play this option is the best choice for us
		
		default:
			cout << "Invalid choice. Please choose again." << endl;//we can't have our program not know what to do if someone misclicks a button
		}
		
	} while (choice < 1 || choice >3);
	myfile.close();
	
	
}

void Game::iterateTurn(Player& player, Deck& deck)//here we change the turns for the players
{
	while (win(player) == false)
	{
		for (int playerIndex = 0; unsigned(playerIndex) < playerVector.size(); playerIndex++)
		{
			if (skipCard == true)//if someone got skip card played he loses his turn 
			{
				
				playerIndex--;
				playerIndex = drawn.skip(player, deck, playerIndex, playerVector);
			}

			if (reverseCard == true)//here we change the direction of the game with the use of reverse card
			{
				
			}

			skipCard = false;


			drawOrPlay(player, deck, playerIndex);

		}
	}
}


void Game::drawOrPlay(Player& player, Deck& deck, int playerIndex)//the turn proceedings
{
	int option, chooseOrDraw;
	bool proceed = false;//here we make sure we don;t skip a turn
	
	do
	{
		
		cout << "It is currently " << playerVector[playerIndex]->getUserName() << "'s" << " turn." << endl << endl;//so we know whos turn it is
		cout << "The card you must match is: " << endl;//so we know what card we need to match

		//the presented card
		deck.toString(inPlay.front().color);//the color we need to match
		cout << " ";
		deck.valueToString(inPlay.front().value);// the value we need to match
		cout << endl << endl;

		cout << "Cards currently in your hand:" << endl;//here is the hand of the player
		playerVector[playerIndex]->printHand(deck);
		cout << endl;
		cout << "[1] Draw Card " << endl;//here are his options
		cout << "[2] Play Card" << endl;
		cout << "Pick an option. " << endl;
		
		cin >> option;

		switch (option)
		{
	

		case 1://this case is if we don't have a matching card and need to draw one

			cout << "You have taken:" << endl;
			cout << "Color: ";
			deck.toString(deck.getCard().color);
			cout << " | " << "Value: ";
			deck.valueToString(deck.getCard().value);

			deck.dealCard(*playerVector[playerIndex]);
			cout << endl;
			proceed = true;

			break;

		case 2:
			cout << "Please choose a card or press 0 to draw a card. " << endl;
			
			cin >> chooseOrDraw;

			if (chooseOrDraw == 0)
			{
				//here is an option if we changed our mind and want to keep the card we wanted to play previously, so we draw a new one
				cout << "You have taken:" << endl;
				cout << "Color: ";
				deck.toString(deck.getCard().color);
				cout << " | " << "Value: ";
				deck.valueToString(deck.getCard().value);

				deck.dealCard(*playerVector[playerIndex]);
				cout << endl;
				proceed = true;
			}

			else
			{
				proceed = chooseCard(player, deck, chooseOrDraw, playerIndex);
			}

			break;
		}

		system("PAUSE");
		system("CLS");

	} while (proceed == false);
}

bool Game::chooseCard(Player& player, Deck& deck, int chooseOrDraw, int playerIndex)
{
	bool specialCard = false;
	
	//here we check if the card is a valid one
	if (validate(player, playerIndex, chooseOrDraw) == true)
	{

		//checks if it is some special card
		{
			if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value >= 10 && playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value <= 14)
			{
				specialCard = true;
			}
		}


		//checks which special card it is
		if (specialCard == true)
		{
			ifSpecialCard(player, deck, chooseOrDraw, playerIndex);
		}

		else
		{
			inPlay.insert(inPlay.begin(), playerVector[playerIndex]->getHandCard(player, chooseOrDraw));
		}

			playerVector[playerIndex]->deleteHand(chooseOrDraw);
		
		return true;
	}

	else//actions with undefined cards prompt form here
	{
		cout << "You cannot play this card!" << endl;
	}

	return false;
}


bool Game::validate(Player& player, int playerIndex, int chooseOrDraw)//the validation action occurs here
{
	if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == inPlay.front().value || playerVector[playerIndex]->getHandCard(player, chooseOrDraw).color == inPlay.front().color)
	{
		return true;
	}

	if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 13 || playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 14)
	{
		return true;
	}


	else
	{
		return false;
	}
}


bool Game::win(Player& player)// here we check if someone has won
{

	if (player.isOne(player) == true)
	{
		cout << "You have no more cards in your hand, You win!" << endl;
		delete& player;
		system("pause");
		exit(0);
	}

	return false;
}

void Game::playGame(Player& player, Game game, Deck& deck)
{
	//here we prompt to initialise the deck and shuffle it
	deck.createDeck();
	deck.shuffle();

	createPlayerVector(deck);

	//here we start the game by placing a single card
	inPlay.push_back(deck.getCard());
	deck.pop();


	//if no one wins the game continues
	while (win(player) == false)
	{
		iterateTurn(player, deck);
	}

}

void Game::ifSpecialCard(Player& player, Deck& deck, int chooseOrDraw, int &playerIndex)//our choices for special cards
{
	if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 13)
	{
		//wild card - change color
		int choice;

		cout << "What color would you like to choose?" << endl;
		cout << "[1] BLUE" << endl;
		cout << "[2] GREEN" << endl;
		cout << "[3] RED" << endl;
		cout << "[4] YELLOW" << endl;

		cin >> choice;

		//and the acton happens
		inPlay.insert(inPlay.begin(), playerVector[playerIndex]->getHandCard(player, chooseOrDraw));
		inPlay.front().color = static_cast<Card::Color>(choice - 1);
	}

	
	//all the initialisations for diffrent special cards
	else if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 10) //draw2
	{
		drawTwo(player, deck, chooseOrDraw, playerIndex);
	}

	else if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 11) //skip
	{
		
		playerIndex = drawn.skip(player, deck, playerIndex, playerVector); 
		skipCard = true;
	}

	else if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 12) //reverse
	{
		reverseCard = true;

	}

	else if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 14) //draw4
	{
		wildDrawFour(player, deck, chooseOrDraw, playerIndex);
	}
}


//and the functions for the special cards
void Game::reverse(Player& player, Deck& deck, int chooseOrDrawint, int playerIndex)//reverse
{
	for ((playerVector.size()-1); int i = 0; i--)
	{
		drawOrPlay(player, deck, i);
		win(player);
	}
}


//the function for drawing two
void Game::drawTwo(Player& player, Deck& deck, int chooseOrDraw, int playerIndex)
{
	if (playerIndex != (playerVector.size() - 1))
	{
		for (int i = 0; i < 2; i++)
		{
			deck.dealCard(*playerVector[playerIndex + 1]);
		}

		cout << playerVector[playerIndex + 1]->getUserName() << " has received two cards." << endl;
	}



	else if (playerIndex == (playerVector.size() - 1))
	{
		
		for (int i = 0; i < 2; i++)
		{
			deck.dealCard(*playerVector[0]);
		}
		cout << playerVector[0]->getUserName() << " has received two cards." << endl;
	}
}

void Game::wildDrawFour(Player& player, Deck& deck, int chooseOrDraw, int playerIndex)
{
	//wild draw4

	//prompt for color change
	int choice;

	cout << "What color would you like to choose?" << endl;
	cout << "[1] BLUE" << endl;
	cout << "[2] GREEN" << endl;
	cout << "[3] RED" << endl;
	cout << "[4] YELLOW" << endl;

	cin >> choice;

	//change color
	inPlay.insert(inPlay.begin(), playerVector[playerIndex]->getHandCard(player, chooseOrDraw));
	inPlay.front().color = static_cast<Card::Color>(choice - 1);

	if (playerIndex != (playerVector.size() - 1))
	{
		for (int i = 0; i < 4; i++)
		{
			deck.dealCard(*playerVector[playerIndex + 1]);
		}

		cout << playerVector[playerIndex + 1]->getUserName() << " has received four cards." << endl;
	}

	else if (playerIndex == (playerVector.size() - 1))
	{
		//at end of vector
		for (int i = 0; i < 4; i++)
		{
			deck.dealCard(*playerVector[0]);
		}

		cout << playerVector[0]->getUserName() << " has received four cards." << endl;
	}
}


Game::~Game()
{

}

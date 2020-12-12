#pragma once
//#include "vector"
//#include "Player.h"

class Card
{
private:


public:
	
	enum class Color { BLUE, GREEN, RED, YELLOW, WILD };
	Card();
	
	Color color{};
	int value{};
	Card(Color color, int value);
	

	~Card();
};

/*
class specialskip : protected Card {
public:
	specialskip();
	

	~specialskip();

};

*/
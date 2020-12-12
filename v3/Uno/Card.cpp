#include "Card.h"
#pragma warning(disable : 26812)

using namespace std;

Card::Card()
{	
}
Card::Card(Color color, int value)
{
	color = this->color;
	value = this->value;
}
Card::~Card()
{
}

#pragma once
#include "Card.h"
class Player {
private:
	std::string name;
	int num_of_cards;
	std::vector<Card *> vector_cards;
	//private members

public:
	//public members
	bool play(Card&);
	~Player();
	Player(std::string name, int num_of_cards);
};

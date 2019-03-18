#pragma once
#include "Card.h"
class Player {
private:
	std::string name;
	int num_of_cards;
	std::vector<Card *> vector_cards;
	//private members
	void clean();
public:
	//public members
	bool play(Card&);
	~Player();
	Player(const Player& other);
	Player(std::string name, int num_of_cards);
	Player& operator=(const Player& other);
};

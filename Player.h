#pragma once
#include "Card.h"
class Player {
private:
	std::string name;
	int num_of_cards;
	std::vector<Card *> vector_cards;
	//private members
	void clean();
	void takeCard();
	void putCard(int index);
	bool getInt(int& value);
public:
	//public members
	bool play(Card&);
	~Player();
	Player(const Player& other);
	Player(std::string name, int num_of_cards);
	Player& operator=(const Player& other);
	bool isEmpty();
};

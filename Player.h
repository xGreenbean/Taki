/* Ehud Plaksin 314095605 */
/* Saimon Lankri 209025907 */
#pragma once
#include <vector>

#include "Card.h"

class Player {
public:
	//public members
	bool play(Card&);
	~Player();
	std::string getName() const;
	Player(const Player& other);
	Player(std::string name, int num_of_cards);
	Player& operator=(const Player& other);
	bool isEmpty();
private:
	std::string name;
	int num_of_cards;
	std::vector<Card *> vector_cards;
	//private members
	void clean();
	void takeCard();
	void putCard(const int index);
	bool getInt(int& value);

};

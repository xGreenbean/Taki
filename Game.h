#pragma once
#include "Player.h"
#include "Card.h"
#include <deque>
class Game {
private:
	Card * _currCard;
	std::deque<Player *> deque_playes;
	Player * curr_player;
	bool direction;
public:
	//public members and functions
	void start();
};

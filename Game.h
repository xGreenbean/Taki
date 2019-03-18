#pragma once
#include "Player.h"
#include "Card.h"
#include <deque>
#include <exception>
class Game {
private:
	int num_players;
	Card * currCard;
	int num_of_cards;
	std::deque<Player *> deque_playes;
	Player * curr_player;
	bool direction;

	Game& operator=(const Game& other);
	Game(const Game& other);
	void init();
	bool getInt(int& value);
public:
	//public members and functions
	void start();
	~Game();
	Game();
};

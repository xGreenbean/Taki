/* Ehud Plaksin 314095605 */
/* Saimon Lankri 209025907 */
#pragma once
#include <deque>
#include <exception>

#include "Player.h"
#include "Card.h"

class Game {
public:
	//public members and functions
	void start();
	~Game();
	Game();
private:
	int num_players;
	Card * curr_card;
	int num_of_cards;
	std::deque<Player *> deque_playes;
	Player * curr_player;
	//deque in/out direction 1 for front 0 for back.
	bool direction;

	Game& operator=(const Game& other);
	Game(const Game& other);
	void init();
	bool getInt(int& value);
	void nextPlayer();
	bool gameOver();
	void nextTurn();
};

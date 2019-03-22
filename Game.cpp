/* Ehud Plaksin 314095605 */
/* Saimon Lankri 209025907 */
#include "Game.h"
#define PLAYERS "How many players?"
#define CARDS "How many cards?"

Game::~Game() {
	auto it = deque_playes.begin();
	Player * temp;
	while (it != deque_playes.end()) {
		temp = (*it);
		delete temp;
		temp = NULL;
		it = deque_playes.erase(it);
	}
	if (curr_card != NULL)
		delete curr_card;
	curr_card = NULL;
	if (curr_player != NULL)
		delete curr_player;
	curr_player = NULL;
}

Game::Game() {
	direction = true;
	//NULL init to avoid double free in destructor,
	//some times memory has garbage
	curr_card = NULL;
	curr_player = NULL;
}

void Game::start(){
  try{
    init();
  }catch(std::string& s){
    std::cout << s << '\n';
    return;
  }
  
  curr_player = deque_playes.front();
  deque_playes.pop_front();

  while(true){
    try{
      if((*curr_player).play((*curr_card))){
		  if (gameOver()) {
			  std::cout << (*curr_player).getName() << " wins!" << std::endl;
			  return;
		}else {
			  nextPlayer();
		  }
        continue;
        }
		//player took card from stack, game moves on.
        nextTurn();
    }catch(std::string s){
      std::cout << s << '\n';
      return;
    }
  }

}
//sets the game, gets number of players, and cards.
void Game::init(){
  std::cout << PLAYERS << '\n';
  if(getInt(num_players) || num_players <= 0)
    throw std::string("num players value ilegal");

  std::cout << CARDS << '\n';
  if(getInt(num_of_cards) || num_of_cards <= 0)
    throw std::string("num cards value ilegal");

  for (size_t i = 1; i <= num_players; i++) {
    std::string name;
    std::cout << "player number " << i << " name?" << '\n';
    std::cin >> name;
    deque_playes.push_back(new Player(name, num_of_cards));
  }
  //first card has to be generated.
  curr_card = new Card;
  (*curr_card) = Card::generate_card();
}

bool Game::getInt(int& value){
  std::cin >> value;
  return (std::cin.fail());
}

void Game::nextPlayer(){
  sign card_sign = (*curr_card).get_sign();

  switch(card_sign){
    case sign::CD:
      direction = !direction;
	  nextTurn();
      break;
    case sign::STOP:
      nextTurn();
      nextTurn();
      break;
    case sign::PLUS:
      break;
    default:
      nextTurn();
      break;
  }
}

bool Game::gameOver(){
  return ((*curr_player).isEmpty());
}

void Game::nextTurn(){
  Player * temp = curr_player;
  if(direction){
    curr_player = deque_playes.front();
    deque_playes.pop_front();
    deque_playes.push_back(temp);
  }
  else{
    curr_player = deque_playes.back();
    deque_playes.pop_back();
    deque_playes.push_front(temp);
  }
}

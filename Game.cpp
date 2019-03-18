#include "Game.h"
#define PLAYERS "how many players?"
#define CARDS "how many cards?"
void Game::start(){

};
void Game::init(){
  std::cout << PLAYERS << '\n';
  if(getInt(num_players))
    throw std::string("num players value ilegal");

  std::cout << CARDS << '\n';
  if(getInt(num_of_cards))
    throw std::string("num cards value ilegal");

  for (size_t i = 0; i < num_players; i++) {
    std::string name;
    std::cout << "Player number " << i << " name?" << '\n';
    std::cin >> name;
    deque_playes.push_back(new Player(name, num_of_cards));
  }
  (*currCard) = Card::generate_card();
}

bool Game::getInt(int& value){
  std::cin >> value;
  return (std::cin.fail());
}
Game::~Game(){
  auto it = deque_playes.begin();
  Player * temp;
  while(it != deque_playes.end()){
    temp = (*it);
    delete temp;
    temp = nullptr;
    it = deque_playes.erase(it);
  }
}
Game::Game(){
  
}

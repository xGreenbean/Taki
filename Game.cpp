#include "Game.h"
#define PLAYERS "how many players?"
#define CARDS "how many cards?"
void Game::start(){
  init();
  curr_player = deque_playes.front();
  deque_playes.pop_front();

  while(true){

    if((*curr_player).play((*curr_card))){

      if((*curr_player).isEmpty()){
        std::cout << "we have a winner" << '\n';
        return;
      }
      else{
        nextPlayer();
      }

    }else{
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
  }
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
  curr_card = new Card;
  (*curr_card) = Card::generate_card();
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
  delete curr_card;
  curr_card = nullptr;
}
Game::Game(){
  direction = true;
}
void Game::nextPlayer(){
  Player * temp;
  switch((*curr_card).get_sign()){
    case sign::CD:
      direction = !direction;
      temp = curr_player;
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

      break;
    case sign::STOP:
      temp = curr_player;
      if(direction){
        deque_playes.push_back(curr_player);
        curr_player = deque_playes.front();
        deque_playes.pop_front();
        deque_playes.push_back(curr_player);
        curr_player = deque_playes.front();
        deque_playes.pop_front();
      }
      else{
        deque_playes.push_front(curr_player);
        curr_player = deque_playes.back();
        deque_playes.pop_back();
        deque_playes.push_front(curr_player);
        curr_player = deque_playes.back();
        deque_playes.pop_back();
      }
      break;
    case sign::PLUS:
      break;

    default:
      temp = curr_player;
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
      break;
  }
}

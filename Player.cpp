#include "Player.h"
Player::Player(std::string name, int num_of_cards){
  this->name = name;
  this->num_of_cards = num_of_cards;
  for (size_t i = 0; i < num_of_cards; i++) {
    Card * temp_card = new Card;
    *(temp_card) = (Card::generate_card());
    vector_cards.push_back((temp_card));
  }
}
Player::~Player(){
  clean();
}
void Player::clean(){
  for (size_t i = 0; i < num_of_cards; i++) {
    Card * temp = vector_cards.front();
    delete temp;
    vector_cards.pop_back();
  }
}
//no operator = for Card!!
Player& Player::operator=(const Player& other){
  if(this != &other )
  {
    clean();
    this->name = other.name;
    this->num_of_cards = other.num_of_cards;
    for (size_t i = 0; i < num_of_cards; i++) {
      Card * temp = new Card();
      (*temp) = other.vector_cards.at(i);
      vector_cards.push_back(temp);
    }
  }
  return *this;

}
//might be better to implement copy & swap idiom.
Player::Player(const Player& other){
  (*this) = other;
}

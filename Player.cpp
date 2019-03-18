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
  for (size_t i = 0; i < num_of_cards; i++) {
    Card * temp = vector_cards.front();
    delete temp;
    vector_cards.pop_back();
  }
}

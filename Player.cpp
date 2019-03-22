/* Ehud Plaksin 314095605 */
/* Saimon Lankri 209025907 */
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

std::string Player::getName() const
{
	return name;
}

void Player::clean(){
  auto it = vector_cards.begin();
  while(it != vector_cards.end()){
    Card * temp = (*it);
    delete temp;
    temp = NULL;
    it = vector_cards.erase(it);
  }
}


Player& Player::operator=(const Player& other){
  if(this != &other )
  {
    clean();
    this->name = other.name;
    this->num_of_cards = other.num_of_cards;
    for (size_t i = 0; i < num_of_cards; i++) {
      Card * temp = new Card();
      (*temp) = (*other.vector_cards.at(i));
      vector_cards.push_back(temp);
    }
  }
  return *this;

}

//might be better to implement copy & swap idiom.
Player::Player(const Player& other){
  (*this) = other;
}

bool Player::play(Card& curr_card){
	//print current round info
	std::cout << "current: " << curr_card << '\n';
	std::cout << name << ", your turn -" << '\n';
	std::cout << "Your cards: ";

	for (size_t i = 0; i < num_of_cards; i++) {
		std::cout << "(" << i + 1 << ")" << (*vector_cards.at(i)) << ' ';
	}
	std::cout << '\n';

  do {
    int choice;
	//here we do allow non positive values,
	//they will cause taking card from stack.
    if(getInt(choice))
      throw std::string("Card choice ilegal");

    if(choice <= 0 || choice > num_of_cards){
      takeCard();
      return false;
    }
	//we showed card indexes that start at 1,
	//we access arrays from 0. so decrementing.
    choice--;

    if(curr_card.is_legal(*vector_cards.at(choice))){
      curr_card = (*vector_cards.at(choice));
      putCard(choice);
      return true;
    }
    std::cout << "You can't put " << (*vector_cards.at(choice)) << " on "
    << (curr_card)  << '\n';
  } while(true);

}
void Player::takeCard(){
  Card * temp = new Card;
  (*temp) = Card::generate_card();
  vector_cards.push_back(temp);
  num_of_cards++;
}

void Player::putCard(const int index){
  Card * temp = vector_cards.at(index);
  delete temp;
  vector_cards.erase(vector_cards.begin() + index);
  num_of_cards--;
}

bool Player::getInt(int& value){
  std::cin >> value;
  //we want integer input!
  return (std::cin.fail());
}

bool Player::isEmpty(){
  return num_of_cards == 0;
}

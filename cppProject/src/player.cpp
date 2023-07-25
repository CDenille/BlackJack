#include "player.h"
#include <iostream>

void Player::clearHand() {
  hand.clear();
}
void Player::PlayerHandTotal() {
  std::cout<< "Your hand total is "<<handTotal << std::endl;
}
void setChips(Player& player, Player &secondHand) {
  secondHand.chips += player.chips;
  secondHand.bet += player.bet;
}
void Player::displayChips() {
  std::cout << "You have $" << chips
            << " left";
      }

void Player::PrintHand() {
  std::cout<< "Your hand: ";
  for (Card* card : hand) {
    card->Print();
    std::cout<< " "; 
  }
  std::cout<< std::endl;
}

void Player::addCard(Card* card) {
  // checks if the card is an Ace. The Ace has a value of
  // 11 or 1 depending on the handTotal
  if (card->getValue() == 11 && handTotal >= 11) {
    hand.push_back(card);
    handTotal += 1;
  }
  else {
  hand.push_back(card);
  handTotal += card->getValue();
  }
}
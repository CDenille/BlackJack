#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "card.h"

class Player {
//  protected:
//   std::vector<Card*> hand;

 public:
  std::vector<Card*> hand;
  int chips = 0;
  int handTotal = 0;
  int wins = 0;
  int losses = 0;
  int draws = 0;
  int bet = 0;
  void PlayerHandTotal();
  void PrintHand();
  void addCard(Card* card);
  void clearHand();
  void printStats();
  // void setChips(Player &player, Player &secondHand);
  void displayChips();
};
void setChips(Player &player, Player &secondHand);
#endif
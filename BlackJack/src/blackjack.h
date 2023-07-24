#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "card.h"
#include "deck.h"
#include "player.h"
#include "dealer.h"

class BlackJack {
 private:
  Deck deck;
  Dealer dealer;
  Player player;
  char response;
  char hit;
  public:
  void mainMenu();
  void playGame();
  void dealPlayer();
  void dealDealer();
  void checkWinner(Player& player, Dealer& dealer, int doubleBet);
  bool isBlackJack(Player player);
  bool isBust(Player player);
  void Split();
  void PlayHand(Player& player);
};
#endif

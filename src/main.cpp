# include <iostream>
# include <ostream>
#include <ctime>
#include "blackjack.h"
#include <vector>

int main() {
  // std::vector<int> numbers(3, 100);
  // std::vector<int>::iterator i= numbers.begin();
  // numbers.insert(i+1,400);
  // for (i = numbers.begin(); i < numbers.end(); i++) {
  //   std::cout << *i << " \n";
  // };

//   Player player;
//   Player secondHand;
//   Deck deck;
//   srand(time(nullptr));
//   deck.shuffle();
//   deck.print();
//   player.addCard(deck.Hit());
//   deck.returnCard();
//   player.addCard(deck.Hit());
//   deck.returnCard();
//   player.PrintHand();
//   deck.print();

//   secondHand.addCard(player.hand[1]);
//   player.handTotal -= player.hand[1]->getValue();
//   player.hand.pop_back();
//   player.addCard(deck.Hit());
//   deck.returnCard();
//  secondHand.addCard(deck.Hit());
//   deck.returnCard();
//   deck.print();
//   // std::vector<Card*>::iterator c = player.hand.begin();
//   // player.hand.insert(c + 1, deck.Hit());
//   // deck.returnCard();
//   // player.addCard(deck.Hit());
//   // deck.returnCard();
//   player.PrintHand();
//   player.PlayerHandTotal();
//   secondHand.PrintHand();
//   secondHand.PlayerHandTotal();
  // int firstHandTotal = player.hand[0]->getValue() + player.hand[1]->getValue();
  // int secondHandTotal = player.hand[2]->getValue() + player.hand[3]->getValue();
  // std::cout << "Your first hand totals " << firstHandTotal;
  // std::cout << std::endl;
  // std::cout<< "Your second hand totals "<<secondHandTotal; std::cout<<std::endl;
  
  BlackJack blackjack;
  blackjack.playGame();
return 0;
};
#include "dealer.h"
#include <iostream>

void Dealer::PrintFirstCard() {
  std::cout<< "Dealer's hand: ";
  hand[0]->Print();
  std::cout<< std::endl;
}

void Dealer::PrintDealerHand() {
   std::cout<< "Dealer's hand: ";
  for (Card* card : hand) {
    card->Print();
    std::cout<< " "; 
  }
  std::cout<< std::endl;
};

void Dealer::FirstCardTotal() {
  std::cout << "The dealer's hand totals " << hand[0]->getValue();
  std::cout<< std::endl;
}

void Dealer::DealerHandTotal() {
  std::cout<< "The dealer's total is "<<handTotal << std::endl;
}
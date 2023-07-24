#include <iostream>
#include "deck.h"
#include <algorithm>

Deck::Deck() {
    for (Card::Value v = Card::Two; v <= Card::Ace; v = static_cast<Card::Value>(static_cast<int>(v)+1)) {
        for (Card::Suit s = Card::hearts; s <= Card::clubs; s = static_cast<Card::Suit>(static_cast<int>(s)+1)) {
            deck.push_back(new Card(v, s));
        }
    }
}

Deck::~Deck() {
    for (Card *card: deck) {
        delete card;
    }
    deck.clear();
}

void Deck::shuffle() { std::random_shuffle(deck.begin(), deck.end()); }

Card* Deck::Hit() { return deck.front(); }

// Once the player takes a hit, the card is returned
// to the bottom of the deck and removed from the front
void Deck::returnCard() {
  deck.push_back(deck.front());
  deck.erase(deck.begin());
}

void Deck::print() {
  for (Card* card : deck) {
    card->Print();
    std::cout<<" ";
  }
  std::cout<< std::endl;
}
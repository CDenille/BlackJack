#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck {
    private:
        std::vector<Card*> deck;
    public:
        Deck();
        ~Deck();
        void shuffle();
        void print();
        Card* Hit();
        void returnCard();
};

#endif
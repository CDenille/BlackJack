# include <ostream>

#ifndef CARD_H
#define CARD_H
class Card {
    public:
    enum Value{

        Two = 2,
        Three = 3,
        Four = 4,
        Five = 5,
        Six = 6,
        Seven = 7,
        Eight = 8,
        Nine = 9,
        Ten = 10,
        Jack = 11,
        Queen = 12,
        King = 13,
        Ace = 14,
    };
    enum Suit{
        hearts,
        spades,
        diamonds,
        clubs,
    };
    Card(Value value, Suit suit);

    // friend std::ostream &operator<<(std::ostream &out, const Card &card);

    void Print();

    int getValue();

private:
    Value value;
    Suit suit;

};

#endif
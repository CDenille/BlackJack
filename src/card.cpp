# include <iostream>
# include "card.h"
# include <iomanip>

Card::Card(Value value, Suit suit) {
        this->value = value;
        this->suit = suit;
    }

// std::ostream& operator<<(std::ostream& out, const Card& card) {
//         out << "Card value is " << card.value << "\n"
//             << "Card suit is " << card.suit << "\n";
//         return out;
// }
    int Card::getValue() {
      //number cards retains its value
      if (this->value <= 10) {
        return value;
        //face cards have a value of 10
      } else if (value <= 13) {
        return 10;
        //Ace has an inital value of 11
      } else {
        return 11;
      }
    }
    //make a switch statement - intergal type
    void Card::Print() {
    if (value <= Ten) {
        std::cout << value;
    }
    else if (value == Jack) {   
        std::cout << "J";
    }    
    else if (value == Queen) {
        std::cout <<  "Q";
    }
    else if (Card::value == King) {
        std::cout << "K";
    }
    else {
        std::cout << "A";
    }
    switch (suit) {
        case hearts:
          std::cout << "H";
          break;
        case spades:
          std::cout << "S";
          break;
        case diamonds:
          std::cout << "D";
          break;
        case clubs:
          std::cout << "C";
          break;
    }
    // if (suit == hearts) {
    //     std::cout << "H";
    // }
    // else if (suit == spades) {
    //     std::cout << "S";
    // }
    // else if (suit == diamonds) {
    //     std::cout << "D";
    // }
    // else {
    //     std::cout << "C";
    // }
};

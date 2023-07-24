#include "blackjack.h"
#include <cstddef>
#include <iostream>
#include <ctime>

void BlackJack::mainMenu() {
  char response;
  std::cout << "Welcome to BlackJack \n"
            << "Would you like to start a new game? \n"
            << "Enter 'y' for Yes or 'n' for No \n";
  std::cin >> response;
  if (response == 'y') {
    playGame();
  }
  else {
    return;
  }
}
void BlackJack::dealDealer() {
  dealer.addCard(deck.Hit());
  deck.returnCard();
  dealer.addCard(deck.Hit());
  deck.returnCard();
  std::cout << "____________________"
      << std::endl;
  dealer.PrintFirstCard();
  dealer.FirstCardTotal();
};

void BlackJack::dealPlayer(){
  player.addCard(deck.Hit());
  deck.returnCard();
  player.addCard(deck.Hit());
  deck.returnCard();
  std::cout << "____________________"
      << std::endl;
  player.PrintHand();
  player.PlayerHandTotal();
}
void BlackJack::checkWinner(Player& player, Dealer& dealer, int bet) {
  if (player.handTotal > 21) {
    std::cout << "Bust!";
    std::cout<<std::endl;
    player.chips -= player.bet * bet;
      player.displayChips();
      std::cout << std::endl;
      player.losses++;
  }
  else if (dealer.handTotal > 21) {
    std::cout << "The dealer Bust! Congratulations, you won!";
    std::cout<<std::endl;
    player.chips += player.bet * bet;
      player.displayChips();
      std::cout << std::endl;
      player.wins++;
  }
  else if (dealer.handTotal == player.handTotal) {
    std::cout << "It's a draw" << std::endl;
    player.displayChips();
    std::cout << std::endl;
    player.draws++;
  }else if (dealer.handTotal > player.handTotal) {
    std::cout << "Sorry, the dealer won";
    std::cout<<std::endl;
      player.chips -= player.bet * bet;
      player.displayChips();
      player.losses ++;
      std::cout << std::endl;
  } else {
    std::cout << "Congratulations, you won!";
    std::cout<<std::endl;
    player.chips += player.bet * bet;
    player.displayChips();
    player.wins ++;
    std::cout << std::endl;
  }
}

bool BlackJack::isBust(Player player){
  if (player.handTotal > 21) {
    std::cout << "It's a bust! \n";
    return true;
  }
  return false;
}

bool BlackJack::isBlackJack(Player player) {
  if (player.handTotal == 21) {
    return true;
  } 
    return false;  
}

void BlackJack::Split() {
  Player secondHand;
  // adds the player's second card to a new hand(secondHand)
  secondHand.addCard(player.hand[1]);
  //if first card is an Ace, the handtotal is 10
  if (player.hand[1]->getValue() == 11) {
    player.handTotal --;
  } else {
    player.handTotal -= player.hand[1]->getValue();
  }
  //erase player's second card
  player.hand.pop_back();

  //add a card to both hands
  player.addCard(deck.Hit());
  deck.returnCard();
  secondHand.addCard(deck.Hit());
  deck.returnCard();

  player.PrintHand();
  player.PlayerHandTotal();
  secondHand.PrintHand();
  secondHand.PlayerHandTotal();

  while (player.handTotal < 21 && hit != 's') {
    std::cout<<"First hand: "<<player.handTotal;std::cout<<std::endl;;
    std::cout << "Enter 'h' if you would you like to Hit \n"
              << "or 's' if you would like to Stand \n";
    std::cin >> hit;
    if (hit == 'h') {
      player.addCard(deck.Hit());
      deck.returnCard();
      std::cout << "____________________"<< std::endl;
      player.PrintHand();
      player.PlayerHandTotal();
    } else {
      std::cout << "First hand: You stand on " << player.handTotal << std::endl;
      std::cout << "____________________"<< std::endl;
    }
  }
  if (hit == 's') {
    hit = 'h';
  }
  while (secondHand.handTotal < 21 && hit != 's') {
    std::cout<<"Second hand: "<<secondHand.handTotal;std::cout<<std::endl;
    std::cout << "Enter 'h' if you would you like to Hit \n"
              << "or 's' if you would like to Stand \n";
    std::cin >> hit;
    if (hit == 'h') {
      secondHand.addCard(deck.Hit());
      deck.returnCard();
      std::cout << "____________________"<< std::endl;
      secondHand.PrintHand();
      secondHand.PlayerHandTotal();
    } else {
      std::cout << "Second hand: You stand on " << secondHand.handTotal << std::endl;
    }
  }
  std::cout << "____________________"
              << std::endl;
  dealer.PrintDealerHand();
  dealer.DealerHandTotal();
  if (dealer.handTotal < 17) {
    dealer.addCard(deck.Hit());
    deck.returnCard();
    std::cout << "____________________"
              << std::endl;
    dealer.PrintDealerHand();
    dealer.DealerHandTotal();
  }
  std::cout << "____________________" << std::endl;
  checkWinner(player, dealer, 1);
  setChips(player, secondHand);
  checkWinner(secondHand, dealer, 1);
}
void BlackJack::PlayHand(Player& player) {
  std::cout << "Enter 'h' if you would you like to Hit \n"
            << "or 's' if you would like to Stand \n";
        std::cin >> hit;
        if (hit == 'h') {
          player.addCard(deck.Hit());
          deck.returnCard();
          std::cout << "____________________"
          << std::endl;
          player.PrintHand();
          player.PlayerHandTotal();
          if (player.handTotal >= 21) {
            checkWinner(player, dealer, 1);
          }
        }
        else {  
          std::cout << "You stand on " << player.handTotal << std::endl;
          std::cout << "____________________"
          << std::endl;
          dealer.PrintDealerHand();
          dealer.DealerHandTotal();
          if (dealer.handTotal >= 17) {
            checkWinner(player, dealer, 1);
          } else {
            dealer.addCard(deck.Hit());
            deck.returnCard();
            std::cout << "____________________"
                << std::endl; 
            dealer.PrintDealerHand();
            dealer.DealerHandTotal();
            checkWinner(player, dealer, 1);
          }
      }
  
}

void BlackJack::playGame() {
  std::cout << "Welcome to BlackJack! \n"
            << "How much would you like to buy in for? \n";
  std::cin >> player.chips;
  std::cout<< "You bought in for "<<player.chips << " dollars \n \n";
  do {
    std::cout << "\nYour stats: Wins: "<< player.wins
              << " Losses: "<< player.losses
              << " Draws: " << player.draws << std::endl;     
    std::cout << "_____________________________ \n"
            << "Would you like to start a new game? \n"
            << "Enter 'y' for Yes or 'n' for No \n";
    std::cin >> response;
      if (response == 'y') {
        goto play;
      }
      else {
        break;
      }
  play:
    //reset player/dealer variables 
    hit = {};
    player.bet = 0;
    player.clearHand();
    dealer.clearHand();
    player.handTotal = 0;
    dealer.handTotal = 0;

    //shuffle deck
    srand(time(nullptr));
    deck.shuffle();
   
    //ask for the bet
    std::cout << "_____________________ \n"
        << "How much would you like to bet? \n"
              << "The minimum bet is $5. \n";
    std::cin >> player.bet;
    std::cout << std::endl;

    //start play
    dealDealer();
    dealPlayer();

    if (player.hand[0]->getValue() == player.hand[1]->getValue()) {
      std::cout << "_____________________ \n"
      << "Would you like to split?";
      std::cout<<std::endl;
          char split;
      std::cin >> split;
      if(split == 'y') {
        Split();
        continue;
      } else {
        PlayHand(player);
      } 
    }
    else if (isBlackJack(dealer)) {
      dealer.PrintDealerHand();
      std::cout << "Sorry the dealer has BlackJack.";
      std::cout<<std::endl;
      player.chips -= player.bet;
      player.displayChips();
      player.losses ++;
      std::cout<<std::endl;
    }
    else if (isBlackJack(player)) {
      std::cout << "Congratulations, you have BlackJack!!!";
      std::cout<<std::endl;
      player.chips += player.bet;
      player.displayChips();
      player.wins ++;
      std::cout<<std::endl;
    } else {
      std::cout << "Would you like to Surrender? \n"
                << "Enter 'y' for Yes or 'n' for No \n";
      char surrender;
      std::cin >> surrender;
      if (surrender == 'y') {
          player.bet = player.bet / 2;
          player.chips -= player.bet;
          player.losses ++;
          std::cout << "You surrendered. \n";
          player.displayChips();
          std::cout << std::endl;
          continue;
      } else {
          std::cout << "Would you like to Double Down? \n"
                << "Enter 'y' for Yes or 'n' for No \n";
          char doubleDown;
          std::cin >> doubleDown;
          if (doubleDown == 'y') {
            player.addCard(deck.Hit());
            deck.returnCard();
            player.PrintHand();
            player.PlayerHandTotal();
            if (isBlackJack(player) || player.handTotal > 21) {
              checkWinner(player, dealer, 2);
              continue; 
            } else {
                std::cout << "____________________"
                << std::endl;
                dealer.PrintDealerHand();
                dealer.DealerHandTotal();
                std::cout << "____________________"
                << std::endl;
                if (dealer.handTotal <= 17) {
                  dealer.addCard(deck.Hit());
                  deck.returnCard();
                  dealer.PrintDealerHand();
                  dealer.DealerHandTotal();
                } else { 
                  checkWinner(player,dealer, 2);
                }
            }
          } else {
              while (!(isBlackJack(player)) && player.handTotal <21 && hit != 's') {
                PlayHand(player);
              }
          }
      }    
    }
  } while (response == 'y' && player.chips >= 5);
}
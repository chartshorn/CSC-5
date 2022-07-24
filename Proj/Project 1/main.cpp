/*
 * file: main.cpp
 * author: caden hartshorn
 * date: July 22 2022 @ 1216
 * purpose: blackjack game
 */

// System libraries
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

// User libraries

// Global Constants - Math/Physics/Conversions Constants

// Function Prototypes

// Execution begins here
int main(int argc, char **argv) {
  // seed for the random number generator
  srand(pow(time(0), 2));

  // Declare Variables
  unsigned short numPlys,
      cCard,               // current card up in deck
      p1scr,               // player 1 score
      p2scr,               // player 2 score
      dlrscr;              // dealer score
  const short nCards = 52; // number of cards in the deck
  string face[13] = {"Ace", "2", "3",  "4",    "5",     "6",   "7",
                     "8",   "9", "10", "Jack", "Queen", "King"};
  string suit[4] = {"Clubs", "Spades", "Hearts", "Diamonds"};
  string p1c1, p1c2, p1c3, p2c1, p2c2, p2c3, dc1, dc2, dc3;

  // file stream decl
  fstream cards;
  string fileNm;

  // Init Variables & Seek User Input
  // card init
  cCard = 0;

  // file stream init
  fileNm = "card.dat";
  cards.open(fileNm, ios::out);

  // user vars init
  numPlys = 3; // 3 players including dealer

  // Generate Deck Of Cards
  for (unsigned char i = 0; i < nCards; i++) {
    string cardStr;
    cardStr = face[i % 13] + "_";
    cardStr += suit[i / 13];
    cards << cardStr << endl;
  }

  cards.close();

  // Map inputs to outputs -> the process
  // Load cards from file
  cards.open(fileNm, ios::in);
  vector<string> shfArr;
  string cLine;
  while (getline(cards, cLine)) {
    shfArr.push_back(cLine);
  }

  // Shuffle cards
  for (short i = 0; i < nCards * 14; i++) {
    short rand1 = rand() % nCards;
    short rand2 = rand() % nCards + 1;

    string swap1 = shfArr[rand1];
    string swap2 = shfArr[rand2];

    shfArr[rand1] = swap2;
    shfArr[rand2] = swap1;
  }
  cards.close();

  // Generate Game Output
  cout << right << setw(32) << "BLACKJACK" << endl;
  cout << right << setw(32) << "2 Player + 1 Dealer Blackjack" << endl;
  cout << right << setw(32) << "Care to test your odds?" << endl;
  cout << "********************************" << endl;

  cout << "Enter Any Letter To Continue!" << endl;
  getchar();
  cin.ignore();
  cout << endl;

  // Deal Cards
  for (short i = 0; i < numPlys * 2; i++) {
    switch (i) {
    case 0: {
      p1c1 = shfArr[cCard];
    } break;
    case 1: {
      p2c1 = shfArr[cCard];
    } break;
    case 2: {
      dc1 = shfArr[cCard];
    } break;
    case 3: {
      p1c2 = shfArr[cCard];
      cCard++;
    } break;
    case 4: {
      p2c2 = shfArr[cCard];
    } break;
    case 5: {
      dc2 = shfArr[cCard];
    } break;
    }
    cCard++;
  }

  cout << "The dealer shows card: " << dc2 << endl;
  cout << "-======-" << endl;

  // Player Turns
  for (short i = 0; i < numPlys; i++) {
    bool cntTrn = true;

    // Individual player turn logic
    do {
      // var declaration
      string scrng;
      char plyrMv;
      short score;
      unsigned char aces;

      // hand cards
      string hCard1, hCard2, hCard3;

      // var init
      score = 0;
      aces = 0;

      if (i == 0 || i == 1) {
        cout << "Hello Player " << i + 1 << endl;
        cout << "It is your turn" << endl;
        cout << "Your hand is:" << endl;
        if (i == 0) {
          hCard1 = p1c1;
          hCard2 = p1c2;
          cout << "-" << p1c1 << endl;
          cout << "-" << p1c2 << endl;
        } else if (i == 1) {
          hCard1 = p2c1;
          hCard2 = p2c2;
          cout << "-" << p2c1 << endl;
          cout << "-" << p2c2 << endl;
        }

        // Player Input
        while (plyrMv != 'H' && plyrMv != 'S') {
          cout << "Enter H to Hit and S to Stand" << endl;
          cin >> plyrMv;

          if (plyrMv == 'H') {
            // hit logic
            cout << "Player " << i + 1 << " Hits!" << endl;
            if (i == 0) {
              p1c3 = shfArr[cCard];
              hCard3 = p1c3;
              cout << "Your 3rd card is: " << endl << p1c3 << endl;
            } else if (i == 1) {
              p2c3 = shfArr[cCard];
              hCard3 = p2c3;
              cout << "Your 3rd card is: " << endl << p2c3 << endl;
            }
            cCard++;
          } else if (plyrMv == 'S') {
            // stand logic
            cout << "Player " << i + 1 << " Stands!" << endl;
            // Player Input Validation
          } else {
            cout << "Invalid Input!" << endl;
          }
        }
        plyrMv = ' ';
      } else {
        //Dealer (Computer) Choices
        //decision making var declaration
        string cardv1,
        cardv2;
        short pos;

        //Output code and variable init
        cout << "Dealer Flips Second Card To Reveal:" << endl;
        hCard1 = dc1;
        hCard2 = dc2;
        cout << "-" << hCard1 << endl;
        cout << "-" << hCard2 << endl;

        //Automated choices
        pos = hCard1.find("_");
        cardv1 = hCard1.substr(0, pos);
        pos = hCard2.find("_");
        cardv2 = hCard2.substr(0, pos);
        //Determine if either card has a value of 10
        //If neither card has a value of 10, hit
        if ( cardv1 != "10" && cardv1 != "Jack" && cardv1 != "Queen" && cardv1 != "King" 
          && cardv2 != "10" && cardv2 != "Jack" && cardv2 != "Queen" && cardv2 != "King") {
          dc3 = shfArr[cCard];
          hCard3 = dc3;
          cout << "Your 3rd card is: " << endl << hCard3 << endl;
        }
      }

      // Scoring logic
      // Separate Individual Card Identifiers
      for (short c = 0; c < 3; c++) {
        short pos;
        if (c == 0) {
          pos = hCard1.find("_");
          scrng = hCard1.substr(0, pos);
        } else if (c == 1) {
          pos = hCard2.find("_");
          scrng = hCard2.substr(0, pos);
        } else if (c == 2) {
          if (hCard3.length() > 0) {
            pos = hCard3.find("_");
            scrng = hCard3.substr(0, pos);
          }
        }

        //calculate card values and add to turn score
        if (scrng == "2")
          score += 2;
        else if (scrng == "3")
          score += 3;
        else if (scrng == "4")
          score += 4;
        else if (scrng == "5")
          score += 5;
        else if (scrng == "6")
          score += 6;
        else if (scrng == "7")
          score += 7;
        else if (scrng == "8")
          score += 8;
        else if (scrng == "9")
          score += 9;
        else if (scrng == "10" || scrng == "Jack" || scrng == "Queen" ||
                 scrng == "King")
          score += 10;
        else if (scrng == "Ace")
          aces++;
        scrng = "";
      }

      // logic to determine highest value of ace(s)
      for (short a = 0; a < aces; a++) {
        if (score + 11 <= 21) {
          score += 11;
        } else {
          if (aces > 1) {
            score -= 11;
            score++;
          }
          score++;
        }
      }

      // Determine blackjack
      if (score == 21 && (i == 0 || i == 1)) {
        cout << "Player " << i + 1 << " Blackjack!" << endl;
      }

      //Output hand results
      if (i == 0 || i == 1)
        cout << "Player " << i + 1;
      else
        cout << "Dealer";
      if (score > 21) {
        cout << " Busted! (" << score << ")" << endl;
      } else {
        cout << " Has a Score of " << score << endl;
      }

      //Set high level tracking of score
      if (i == 0) {
        p1scr = score;
      } else if (i == 1) {
        p2scr = score;
      } else if (i == 2) {
        dlrscr = score;
      }

      //Reset score
      score = 0;

      cout << "-======-" << endl;
      cntTrn = false;
    } while (cntTrn);
  }

  // Determine Winner
  if (p1scr > 21) p1scr = 0;
  if (p2scr > 21) p2scr = 0;
  if (dlrscr > 21) dlrscr = 0;
  
  if (dlrscr > p1scr && dlrscr > p2scr) {
    //dealer wins
    cout << "The house always wins! Congratulations to the dealer for winning.";
  } else if (p1scr > p2scr) {
    //p1 wins
    cout << "Congratulations to our lucky winner, Player 1!";
  } else if (p2scr > p1scr) {
    //p2 wins
    cout << "Ding Ding Ding! Player 2 wins it all!";
  } else if (p1scr == p2scr && p2scr == dlrscr) {
    cout << "Push!" << endl;
  }

  // Exit stage right!
  return 0;
}
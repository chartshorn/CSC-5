/*
 * file: main.cpp
 * author: caden hartshorn
 * date: July 22 2022 @ 1216
 * purpose: blackjack game
 */

// System libraries
#include <cmath>
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
  srand(time(0));

  // Declare Variables
  unsigned short numPlys,
      cCard;               // current card up in deck
  const short nCards = 52; // number of cards in the deck
  string face[13] = {"Ace", "2", "3",  "4",    "5",     "6",   "7",
                     "8",   "9", "10", "Jack", "Queen", "King"};
  string suit[4] = {"Clubs", "Spades", "Hearts", "Diamonds"};
  vector<short> p1hand = {};
  vector<short> p2hand = {};
  vector<short> dealerhand = {};

  // file stream decl
  fstream cards;
  string fileNm;

  // Init Variables & Seek User Input
  //card init
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
    cards << setw(14) << cardStr << endl;
  }

  cards.close();

  // Map inputs to outputs -> the process
  // Shuffle Cards
  cards.open(fileNm, ios::in);
  vector<string> shfArr;
  string cLine;
  while (getline(cards, cLine)) {
    shfArr.push_back(cLine);
  }
  for (short i = 0; i < nCards; i++) {
    short rand1 = rand() % nCards + 1;
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
  cout << "******************************" << endl;

  cout << "Enter Any Letter To Continue!" << endl;
  getchar();
  cout << endl;

  // Player Turns
  for (short i = 0; i < numPlys; i++) {
    bool cntTrn = true;

    // Individual player turn logic
    do {
      string hCard1 = shfArr[cCard];
      cCard++;
      string hCard2 = shfArr[cCard];
      cCard++;
      string hCard3;
      
      char plyrMv;

      if (i == 0 || i == 1) {
        cout << "Hello Player " << i + 1 << endl;
        cout << "It is your turn" << endl;
        cout << "Your hand is:" << endl;
        cout << hCard1 << endl;
        cout << hCard2 << endl;
        cout << "Enter H to Hit and S to Stand" << endl;
        plyrMv = getchar();
        cin.ignore();

        if (plyrMv == 'H') {
          hCard3 = shfArr[cCard];
          cCard++;
          cout << "Your 3rd card is " << hCard3 << endl;
        } else if (plyrMv == 'S') {
          // stand logic
        }
      } else {
        cout << "Hello Dealer";
      }

      cntTrn = false;
    } while (cntTrn);
  }

  // Exit stage right!
  return 0;
}
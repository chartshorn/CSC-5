/*
* file: main.cpp
* author: caden hartshorn
* date: July 22 2022 @ 1216
* purpose: blackjack game
*/

//System libraries
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>
#include <time.h>
#include <string>
using namespace std;

//User libraries

//Global Constants - Math/Physics/Conversions Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //seed for the random number generator
    srand(time(0));
  
    //Declare Variables
    unsigned short numPlys;
    const short nCards = 52; // number of cards in the deck
    string face [13] = {"Ace", "2", "3", "4", "5", "6", "7", "8",
    "9", "10", "Jack", "Queen", "King"};
    string suit [4] = {"Clubs", "Spades", "Hearts", "Diamonds"};
    vector<short> p1hand = {};
    vector<short> p2hand = {};
    vector <short> dealerhand = {};

    //file stream decl
    fstream cards;
    string fileNm;
  
    //Init Variables & Seek User Input
    //file stream init
    fileNm="card.dat";
    cards.open(fileNm, ios::out);

    //user vars init
    numPlys = 3; // 3 players including dealer
    
    //Generate Deck Of Cards
    for (unsigned char i = 0; i < nCards; i++) {
      string cardStr;
      cardStr = face[i%13] + "_";
      cardStr += suit[i/13];
      cards <<setw(14)<<cardStr<<endl;
    }
  
    //Map inputs to outputs -> the process
    //Shuffle Cards
    ifstream rdCrds;
    rdCrds.open(fileNm);
    vector <string> shfArr;
    string cLine;
    while (getline(cards, cLine)) {
      shfArr.push_back(cLine);
    }
    for (short i = 0; i < nCards; i++) {
      cout << shfArr[4];
      
      short rand1 = rand()%nCards+1;
      short rand2 = rand()%nCards+1;
      
      //string swap1 = ;
      //string swap2= ;
      
    }
    rdCrds.close();

    //Deal Cards
    for (short i = 0; i < numPlys; i++) {
      bool cntTrn = true;
      
      //Shuffling of Cards
      do {
        //generate random card # and see if it has been used in this deck

        cntTrn = false;
      } while (cntTrn);
    }

    //Output Data
    cout << "Hello world!";

    //Exit stage right!
    cards.close();
    return 0;
}
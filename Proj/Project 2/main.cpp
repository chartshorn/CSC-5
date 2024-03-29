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
#include <algorithm>
using namespace std;

// User libraries

// Global Constants - Math/Physics/Conversions Constants

// Function Prototypes
// Generates a file of cards
// of length nCards
string dlCrdH(vector<string> &); // helper - deal an individual card; returns card dealt
void dlCrd(vector<string> &, string[][6], short); // deal a card
void sortS(unsigned short [], unsigned short [], short); // sort scores
void genDeck(string, const short, const string[13],
             const string[4]); // file name, nCards, faces, suits
void shfDeck(vector<string> &, string, short,
             short = 52); // output vector, file name, nCards, # of loops
void dlCrds(vector<string> &, string[][6], short); // deck, hands, numPlys
short score(string [][6], short); // plyHnds, playerid
void printH(string [][6], short); // plyHnds, playerid
void printS(unsigned short [], short); // print 1d array of scores
bool plyrChc(vector<string> &, string[][6], short); // give player choice to hit / stand
bool dlrDc(vector<string> &, string[][6], short); // automatic dealer decision 
void scoreGm(unsigned short [], short); // score the game

// Execution begins here
int main(int argc, char **argv) {
  // seed for the random number generator
  srand(static_cast<unsigned int>(pow(time(0), 2)));

  // Declare Variables
  const short stdW = 64, maxPlys = 7; // standard width of header output, max players
  unsigned short numPlys; // number of players in a game
  const short nCards = 52; // number of cards in the deck
  // arrays
  const string face[13] =
      {"Ace", "2", "3",  "4",    "5",     "6",   "7",
       "8",   "9", "10", "Jack", "Queen", "King"}, // all possible card faces
      suit[4] = {"Clubs", "Spades", "Hearts",
                 "Diamonds"}; // all possible card suits

  string plyHnds[maxPlys][6] = {}; // where each player hand will be stored
  unsigned short scores[maxPlys]; // player scores array

  // dynamic memory
  vector<string> deck; // shuffled deck

  // file stream decl
  string fileNm; // name of the file to read/write to

  // Init Variables & Seek User Input
  // file stream init
  fileNm = "card.dat"; // generated deck will be loaded and written to this file

  // generate deck of cards
  genDeck(fileNm, nCards, face, suit);

  // Map inputs to outputs -> the process
  // Load cards from file
  // shuffle deck 14 times
  shfDeck(deck, fileNm, 14);

  // Generate Game Information Output
  cout << right << setw(stdW) << "BLACKJACK" << endl;
  cout << right << setw(stdW) << "Care to test your odds?" << endl;
  cout << "****************************************************************"
       << endl;

  cout << "How many players (excluding the dealer) would you like?" << endl;
  cin >> numPlys;

  //input validation
  while (numPlys < 2 || numPlys > 5) {
    cout << "Invalid number of players! Please enter a range between 2 and 6."
         << endl;
    cin >> numPlys;
  }

  cout << endl;

  // Deal cards
  dlCrds(deck, plyHnds, numPlys);

  //announce dealers public card
  cout << "The dealer shows card: " << plyHnds[numPlys][1] << endl;
  cout << "-======-" << endl;

  // Player Turns - While I is less than the number of players, create a turn
  for (short i = 0; i < numPlys + 1; i++) {
    bool cntTrn = false; // whether to continue the players turn
    //announce current turn
    cout << (i != numPlys ? "Player " + to_string(i+1) + " " : "Dealer's ") << "Turn";

    //determine blackjack
    if (score(plyHnds, i) == 21) {
      //blackjack
      cout << "Blackjack! ";
    } else {
      cntTrn = true;
    }
    
    // Individual player turn logic
    do {
      short tScore; //turn score
  
      //calculate initial score
      tScore = score(plyHnds, i);
      if (i != numPlys) cout << "Your";
      else cout << "Dealer\'s";
      cout << " hand is:" << endl;
      printH(plyHnds, i);
      cout << "For a score of: " << tScore << endl;

      //check if player has busted
      if (tScore < 22) {
        //if player has not busted, allow them to make a decision
        if (i != numPlys) {
          //Player turn
          cntTrn = plyrChc(deck, plyHnds, i);
        } else {
          //dealer turn
          cntTrn = dlrDc(deck, plyHnds, i);
        }
      } else if (tScore > 21) {
        cout << "Busted!" << endl;
        cntTrn = false;
      } else {
        cout << "Critical Error! (if.tscore)";  
      }
      
    } while (cntTrn);
    //update global score
    scores[i] = score(plyHnds, i);
    
    cout << "-======-" << endl;
  }

  cout << "Total Scores:" << endl;
  printS(scores, numPlys); // print list of scores

  scoreGm(scores, numPlys); // score the game
  
  // Exit stage right!
  return 0;
}

string dlCrdH(vector<string>&deck) {
  string dltCrd = deck[0];
  deck.erase(deck.begin());
  return dltCrd;
}

void swap(int *v1, int *v2) 
{ 
    int temp = *v1; 
    *v1 = *v2; 
    *v2 = temp; 
}

void dlCrd(vector<string> &deck, string plyHnds[][6], short player) {
  bool dealt = false;
  for (short i = 2; i < 6; i++) {
    if (plyHnds[player][i] == "" && dealt == false) {
      dealt = true;
      plyHnds[player][i] = dlCrdH(deck);
    }
  }
}

void sortS(unsigned short scores[], unsigned short plyOrdr[], short numPlys) { // sort scores
  for (short i = 0; i < numPlys; i++) {
    short minIndx = i;
    for (short c = i+1; c < numPlys; c++) {
      if (scores[c] < scores[minIndx]) {
        minIndx = c;
      }
    }
    swap(scores[minIndx], scores[i]);
    swap(plyOrdr[minIndx], plyOrdr[i]);
  }
}

void genDeck(string fileNm, const short nCards, const string face[13], const string suit[4]) {
  fstream cards;

  cards.open(fileNm, ios::out); // open write stream

  // Generate Deck Of Cards - Write to file
  for (unsigned char i = 0; i < nCards; i++) {
    string cardStr;               // Blank string to write to
    cardStr = face[i % 13] + "_"; // set string equal to card face
    cardStr += suit[i / 13];      // append the suit
    cards << cardStr << endl;     // write to file
  }

  cards.close(); // close write stream
}

void shfDeck(vector<string> &shfArr, string fileNm, short loops, short nCards) {
  fstream cards;

  cards.open(fileNm, ios::in);

  string cLine; // current line of the file
  while (getline(cards, cLine)) {
    shfArr.push_back(
        cLine); // for each line of the file, add it to the shuffled deck array
  }

  // Shuffle cards
  for (short i = 0; i < loops * 14; i++) {
    short rand1 = rand() % nCards;     // random card from the deck
    short rand2 = rand() % nCards + 1; // random card from the deck

    string swap1 = shfArr[rand1]; // store first card in memory
    string swap2 = shfArr[rand2]; // store second card in memory

    shfArr[rand1] = swap2; // swap card 1 with card 2
    shfArr[rand2] = swap1; // vice versa
  }

  cards.close(); // close read stream
}

void dlCrds(vector<string> &deck, string plyHnds[][6], short numPlys) {
  // first pass of table, give each player a card
  for (short i = 0; i < numPlys + 1; i++) {
    plyHnds[i][0] = dlCrdH(deck);
  }
  //second pass of table, give each player a card
  for (short i = 0; i < numPlys + 1; i++) {
    plyHnds[i][1] = dlCrdH(deck);
  }
}

short score(string hands[][6], short player) {
  // Scoring logic
  //var decl and init
  short cScore = 0;
  short aces = 0;
  
  // Separate Individual Card Identifiers
  for (short c = 0; c < 6; c++) {
    short pos;
    string scrng;
    pos = hands[player][c].find("_"); // find where the _ in string is
    scrng =  hands[player][c].substr(0, pos); // split string and store first half

    // calculate card values and add to turn score
    if (scrng == "2")
      cScore += 2;
    else if (scrng == "3")
      cScore += 3;
    else if (scrng == "4")
      cScore += 4;
    else if (scrng == "5")
      cScore += 5;
    else if (scrng == "6")
      cScore += 6;
    else if (scrng == "7")
      cScore += 7;
    else if (scrng == "8")
      cScore += 8;
    else if (scrng == "9")
      cScore += 9;
    else if (scrng == "10" || scrng == "Jack" || scrng == "Queen" ||
             scrng == "King")
      cScore += 10;
    else if (scrng == "Ace")
      aces++;
    scrng = "";
  }

  // logic to determine highest value of ace(s)
  for (short a = 0; a < aces; a++) {
    if (cScore + 11 <= 21) {
      cScore += 11;
    } else {
      if (aces > 1) {
        cScore -= 11;
        cScore++;
      }
      cScore++;
    }
  }

  return cScore;
}

void printH(string plyHnds[][6], short player) {  
  //for each row in array, print each column
  for (short i = 0; i < 6; i++) {
    if (plyHnds[player][i] != "") {
      cout << "-" << plyHnds[player][i] << endl;
    }
  }
}

void printS(unsigned short scores[], short numPlys) {
  //declare variables
  unsigned short plyOrdr[numPlys+1];
  //init variables
  for (short i = 0; i < numPlys+1; i++) {
    plyOrdr[i] = i;
  }

  //sort the scores
  sortS(scores, plyOrdr, numPlys);

  //loop through each player and display their score
  for (short i = 0; i < numPlys + 1; i++) {
    if (i != numPlys) {
      //Player output
      cout << "Player " << plyOrdr[i] + 1 << " has a score of: ";
    } else {
      //dealer output
      cout << "Dealer has a score of: ";
    }
    cout <<  scores[i] << endl;
  }
}

bool plyrChc(vector <string> &deck, string plyHnds[][6], short i) {
    char plyrMv; // player input variable
    //prompt user for input
    cout << "Would you like to hit (H) or stand (S)?" << endl;
    cin >> plyrMv;
    //standardize input
    plyrMv = toupper(plyrMv);

    //input validation
    while (plyrMv != 'H' && plyrMv != 'S') {
      cout << "Invalid input! Please enter H for hit or S for stand." << endl;
      cin >> plyrMv;
    }

    //the process
    //evalulate player move
    switch (plyrMv) {
      case 'H': {
        //player hits
        cout << "Player hits!" << endl;
        dlCrd(deck, plyHnds, i); // deal player addtl card
        return true;
      }
      break;
      case 'S': {
        //player stands
        cout << "Player stands!" << endl;
        return false;
      }
      break;
      default: {
        //error handling
        cout << "Critical error (switch.plyrMv)";
        exit(1);
        return false;
      }
      break;
    }
}

bool dlrDc(vector<string> &deck, string plyHnds[][6], short i) {
  //var decl & init
  short cScore = score(plyHnds, i); // find current score
  if (cScore < 17) {
    //if dealer has score of less than 17, hit
    cout << "Dealer hits per house rules." << endl;
    dlCrd(deck, plyHnds, i);
    return true;
  } else {
    //else (score >= 17) stand
    cout << "Dealer stands per house rules." << endl;
    return false;
  }
}

void scoreGm(unsigned short scores[], short numPlys) {
  //var decl
  unsigned short maxScr = 0, //max score
  cWinner = 0,//current winner
  pshSc; // push score
  vector<short> pushers; //how many people are tied
  
  //var init
  bool pshEval = false; //by default noone is pushing

  //the process
  //loop through every score
  for (short i = 0; i < numPlys + 1; i++) {
    if (scores[i] >= maxScr && scores[i] <= 21) {
      //if score is valid and greater than or equal to the previously known max score,
      if (maxScr == scores[i]) {
        //if current score element equasl the max score element, players are pushing
        pshEval = true;
        pshSc = scores[i];
      }
      //set max score equal to current element
      maxScr = scores[i];
      cWinner = i;
    } 
  }

  if (maxScr == 0) {
    //everyone busted
    cout << "All players pushed! (Game tie)" << endl;
  } else if (pshEval == true && pshSc == maxScr) {
      //some players pushed
      cout << "Players:" << endl;
      for (short i = 0; i < numPlys + 1; i++) {
        if (scores[i] == maxScr) {
          if (i == numPlys) {
            //dealer
            cout << "Dealer" << endl;
          } else {
            cout << "Player " << i+1 << endl;
          }
        }
      }
      cout << "Pushed! All players not listed lose." << endl;
  } else if (cWinner != numPlys) {
    //specific player won
    cout << "Congratulations Player " << cWinner+1 << "!" << endl;
    cout << "They won with a score of " << maxScr << "." << endl;
  } else {
    //dealer won
    cout << "The house always wins!" << endl;
    cout << "The dealer wins with a score of " << maxScr << "." << endl;
  }
}
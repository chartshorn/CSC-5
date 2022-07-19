/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 10 2022 @ 1955
 * Purpose:  Calculate outcome of rock paper scissors
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void r_s (); // rock beats scissors
void p_r (); // paper beats rock
void p_s (); // scissors beats paper
void tie (); // tie

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(time(0));
    
    //Declare Variables
    char p1, p2; // player 1, player 2
    
    //Initialize or input i.e. set variable values
    cout << "Rock Paper Scissors Game" << endl;
    cout << "Input Player 1 and Player 2 Choices" << endl;
    cin >> p1 >> p2;
    
    //Map inputs -> outputs
    //ensure inputs are uppercase
    p1 = toupper(p1);
    p2 = toupper(p2);
    
    //p1 is paper
    if (p1 == 'P') {
        if (p2 == 'R') {
            cout << "Paper covers rock."; // paper beats rock
        } else if (p2 == 'S') {
            cout << "Scissors cuts paper."; //scissors loses to paper
        } else {
            cout << "Tie";
        }
    //p1 is rock
    } else if (p1 == 'R') {
        if (p2 == 'P') {
            cout << "Paper covers rock."; // paper beats rock
        } else if (p2 == 'S') {
            cout << "Rock breaks scissors."; // rock beats scissors
        } else {
            cout << "Tie";
        }
    //p1 is scissors    
    } else if (p1 == 'S') {
        if (p2 == 'R') {
            cout << "Rock breaks scissors."; // rock beats scissors
        } else if (p2 == 'P') {
            cout << "Scissors cuts paper."; // paper loses to scissors
        } else {
            cout << "Tie";
        }
    }
    
    //Display the outputs
    //called above

    //Exit stage right or left!
    return 0;
}

// rock beats scissors
void r_s() {
    cout << "Rock breaks scissors.";
}

// paper beats rock
void p_r() {
    cout << "Paper covers rock.";
}

// scissors beat paper
void p_s() {
    cout << "Scissors cuts paper.";
}

// tie!
void tie() {
    cout <<"Tie!";
}
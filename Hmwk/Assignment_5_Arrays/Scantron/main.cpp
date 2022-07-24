/* 
 * File:   main.cpp
 * Author:Caden Hartshorn
 * Created on: July 23 2022 @ 1430
 * Purpose: Compare the answer sheet to the key
 *          and grade
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>   //File I/O
#include <string.h>    //String Library
#include <algorithm>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
//Purpose: Print a string of characters and add spaces
//Args: (const string& -- string to print)
void print(const string &);
//Purpose: Read a line of input and strip spaces
//Arg: (string & -- string to assign value of line to);
void read(string &);

//Purpose: Compare two strings, assign C/W (C if characters match, W if they don't)
//Args: (const string & string1, const string & string2 -- strings to compare)
//Args: (string & output -- string to output comparison C/W to)
//Returns: int pRight -- Number of comparison cases that match
int  compare(const string &,const string &,string &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    string key,answers,score; // answer key, chosen answers, C/W score
    float pRight; // number of chosen answers that match the answer key
    
    //Initialize or input i.e. set variable values
    score = ""; // empty string for later concatenation 
    //Get User Input
    read(key); // read first line of input - answer key
    read(answers); // read second line of input - chosen answers
    
    //Map Inpts to Outputs -> The Process
    
    //Score the exam
    pRight=compare(key,answers,score);
    
    //Display the outputs
    cout<<"C/W     ";print(score);
    cout<<"Percentage Correct = "<<pRight/score.size()*100<<"%"<<endl;
    
    //Exit stage right or left!
    return 0;
}

void print(const string &input) {
    string output = ""; // console output string for later concatenation 
    // loop through provided string; for each character that isn't a space concatenate that character plus a space
    // to the output string
    for (short i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
           output += input[i];
           output += ' ';
        }
    }
    cout << output << endl;
}

void read (string &outStr) {
    //get the input line from console
    getline(cin, outStr);
    //remove identifier
    outStr.erase(0,8);
    //remove spaces
    outStr.erase(remove_if(outStr.begin(), outStr.end(), ::isspace), outStr.end());
}

int compare(const string &key,const string &answers,string &score) {
    int pRight = 0; // number of correct answers
    //loop through the key and answer string;
    for (short i = 0; i < key.length(); i++) {
        //for each answer that matches the key, add a C (correct) to the score string and increase the number of correct questions
        if (key[i] == answers[i]) {
            score += "C";
            pRight++;
        //else if for each answer that doesn't match the key, add a W (wrong) to the score string
        } else if (key[i] != answers[i]) {
            score += "W";
        }
    }
    //return number of correct answers
    return pRight;
}
/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created: 23 July 2022 @ 1212
 * Purpose: Create a 6x6 2d Table
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int COLS=6; // number of clumns in the table

//Function Prototypes
//Fill a table with added values
void fillTbl(int [][COLS],int);
//Print a table (2d array)
void prntTbl(const int [][COLS],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int ROWS=6; //number of rows in the table
    int tablSum[ROWS][COLS]; // table array
    
    //Initialize or input i.e. set variable values
    fillTbl(tablSum,ROWS);
    
    //Display the outputs
    prntTbl(tablSum,ROWS);

    //Exit stage right or left!
    return 0;
}

void fillTbl (int array[][COLS], int rows) {
    //loop thru rows
    for (short i = 0; i < rows; i++) {
        //for each row, loop throug columns
        for (short c = 0; c < COLS; c++) {
            //for each column, set value to the sumn of the row and column
            array[i][c] = (1+i) + (1+c);
        }
    }
}

void prntTbl (const int array[][COLS], int rows) {
    //Output header per problem specs
    cout << "Think of this as the Sum of Dice Table" << endl;
    cout << "           C o l u m n s" << endl;
    cout << "     |   1   2   3   4   5   6" << endl;
    cout << "----------------------------------" << endl;
    //loop through rows
    for (short i = 0; i < rows; i++) {
        //Output R O W S in rows 2-5 per problem specs
        char rowId = ' '; 
        if (i==1) rowId = 'R';
        else if (i==2) rowId = 'O';
        else if (i==3) rowId = 'W';
        else if (i==4) rowId = 'S';
        cout << rowId << "  " << i+1 << " |";
        //Loop through columns
        for (short c = 0; c < COLS; c++) {
            //output the value found at the intersection of current row and column 
            cout << setw(4) << right << array[i][c];
        }
        cout << endl;
    }
}
/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on July 14 2022 @ 2256
 * Purpose:  Basic Menu for HW 4
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip> // Set precision, fixed, etc
#include <cmath> // pow() and addtl math fns
#include <string.h> // strings lib
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
const int COLS=6; // number of clumns in the table

//Function Prototypes
void fillTbl_0(int [][COLS],int);
void prntTbl_0(const int [][COLS],int);
//Fill a table with multiplied values
void fillTbl_1(int [][COLS],int);
//Print a table (2d array)
void prntTbl_1(const int [][COLS],int);
void  init_2(int [],int);//Initialize the array
void  print_2(int [],int,int);//Print the array
void  revrse_2(int [],int);;//Reverse the array
void  init_3(float [],int);//Initialize the array
float avgX_3(float [],int);//Calculate the Average
float stdX_3(float [],int);//Calculate the standard deviation
//Purpose: Print a string of characters and add spaces
//Args: (const string& -- string to print)
void print_4(const string &);
//Purpose: Read a line of input and strip spaces
//Arg: (string & -- string to assign value of line to);
void read_4(string &);
//Purpose: Compare two strings, assign C/W (C if characters match, W if they don't)
//Args: (const string & string1, const string & string2 -- strings to compare)
//Args: (string & output -- string to output comparison C/W to)
//Returns: int pRight -- Number of comparison cases that match
int  compare_4(const string &,const string &,string &);
//Function Prototypes
//Purpose: Fill a provided array with user Input
//Args: (int [] array - array to populate)
//Args: (int arrSz - size of the array)
void fillAry_5(int [], int);

//Purpose: Linearly search an array for provided values
//Args: (int [] array - array to search)
//Args: (int arrSz - size of the array)
//Args: (int val - value to search for)
//Args: (int &indx - index of the found value)
//Returns: (bool - if true, value was found, if false, value was not found)
bool linSrch_5(int [], int, int, int&);
void fillAry_6(int [],int);
void prntAry_6(int [],int,int);
void selSrt_6(int [],int);
bool binSrch_6(int [],int,int,int&);
void fillAry_7(int [],int);
void prntAry_7(int [],int,int);
void bublSrt_7(int [],int);
bool binSrch_7(int [],int,int,int&);


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int choose;//Choose a problem
    
    //Initialize variables here
    do{
        //List of Problems which can be run by the program
        cout<<"Choose from the following Menu Items"<<endl;
        cout<<"Problem 0"<<endl;
        cout<<"Problem 1"<<endl;
        cout<<"Problem 2"<<endl;
        cout<<"Etc......"<<endl;
        cout<<"10 or greater, all negatives to exit"<<endl;
        cin>>choose;
        
        switch(choose){
            case 0: {
                //Declare Variables
                const int ROWS=6; //number of rows in the table
                int tablSum[ROWS][COLS]; // table array

                //Initialize or input i.e. set variable values
                fillTbl_0(tablSum,ROWS);

                //Display the outputs
                prntTbl_0(tablSum,ROWS);

                //Exit stage right or left!
            }
            break;
            case 1: {
                //Declare Variables
                const int ROWS=6; //number of rows in the table
                int tablSum[ROWS][COLS]; // table array

                //Initialize or input i.e. set variable values
                fillTbl_1(tablSum,ROWS);

                //Display the outputs
                prntTbl_1(tablSum,ROWS);

                //Exit stage right or left!
            }
            break;
            case 2: {
                //Set the random number seed
                srand(static_cast<unsigned>(time(0)));

                //Declare Variables
                const int SIZE=50; //size of the array
                int test[SIZE]; // input array

                //Initialize or input i.e. set variable values
                init_2(test,SIZE); 

                //Reverse the Values
                revrse_2(test,SIZE);

                //Display the outputs
                print_2(test,SIZE,10);

                //Exit stage right or left!
                return 0;
            }
            break;
            case 3:
            {
                //Set the random number seed
                srand(static_cast<unsigned> (time(0)));

                //Declare Variables
                const int SIZE = 20; // size of the array
                float test[SIZE]; // array for the problem

                //Initialize or input i.e. set variable values
                init_3(test, SIZE);

                //Display the outputs
                cout << setprecision(7) << fixed;
                cout << "The average            = " << avgX_3(test, SIZE) << endl;
                cout << "The standard deviation = " << stdX_3(test, SIZE) << endl;

                //Exit stage right or left!
            }
            break;
            case 4: {
                //Set the random number seed
                //Declare Variables
                string key,answers,score; // answer key, chosen answers, C/W score
                float pRight; // number of chosen answers that match the answer key

                //Initialize or input i.e. set variable values
                score = ""; // empty string for later concatenation 
                //Get User Input
                read_4(key); // read first line of input - answer key
                read_4(answers); // read second line of input - chosen answers

                //Map Inpts to Outputs -> The Process

                //Score the exam
                pRight=compare_4(key,answers,score);

                //Display the outputs
                cout<<"C/W     ";print_4(score);
                cout<<"Percentage Correct = "<<pRight/score.size()*100<<"%"<<endl;

                //Exit stage right or left!
            }
            break;
            case 5: {
                //Set the random number seed
                srand(static_cast<unsigned int>(time(0)));

                //Declare Variables
                const int SIZE=100; // size of the array
                int array[SIZE]; // generate the array of provided size
                int indx,val; // index of search element, value to search for

                //Initialize or input i.e. set variable values
                val=50; // value to search for is 50
                fillAry_5(array,SIZE); // populate the array with user input

                //Display the outputs
                //Search the array for provided value
                if(linSrch_5(array,SIZE,val,indx))
                    cout<<val<<" was found at indx = "<<indx<<endl;

                //Exit stage right or left!
            }
            break;
            case 6: {
               //Set the random number seed
                srand(static_cast<unsigned int>(time(0)));

                //Declare Variables
                const int SIZE=100;
                int array[SIZE];
                int indx,val;

                //Initialize or input i.e. set variable values
                fillAry_6(array,SIZE);

                //Sorted List
                selSrt_6(array,SIZE);

                //Display the outputs
                prntAry_6(array,SIZE,10);
                cout << endl;
                cout<<"Input the value to find in the array"<<endl;
                cin>>val;
                if(binSrch_6(array,SIZE,val,indx))
                    cout<<val<<" was found at indx = "<<indx<<endl;

                //Exit stage right or left!
            }
            break;
            case 7: {
               //Set the random number seed
                srand(static_cast<unsigned int>(time(0)));

                //Declare Variables
                const int SIZE=100;
                int array[SIZE];
                int indx,val;

                //Initialize or input i.e. set variable values
                fillAry_7(array,SIZE);

                //Sorted List
                bublSrt_7(array,SIZE);

                //Display the outputs
                prntAry_7(array,SIZE,10);
                cout << endl;
                cout<<"Input the value to find in the array"<<endl;
                cin>>val;
                if(binSrch_7(array,SIZE,val,indx))
                    cout<<val<<" was found at indx = "<<indx<<endl;

                //Exit stage right or left!
            }
            break;
          
            default:cout<<"Exiting the Menu"<<endl;
        }
    }while(choose>=0 && choose<=9);

    return 0;
}

void fillTbl_0 (int array[][COLS], int rows) {
    //loop thru rows
    for (short i = 0; i < rows; i++) {
        //for each row, loop throug columns
        for (short c = 0; c < COLS; c++) {
            //for each column, set value to the sumn of the row and column
            array[i][c] = (1+i) + (1+c);
        }
    }
}

void prntTbl_0 (const int array[][COLS], int rows) {
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

void fillTbl_1 (int array[][COLS], int rows) {
    //loop thru rows
    for (short i = 0; i < rows; i++) {
        //for each row, loop throug columns
        for (short c = 0; c < COLS; c++) {
            //for each column, set value to the product of the row and column
            array[i][c] = (1+i) * (1+c);
        }
    }
}

void prntTbl_1 (const int array[][COLS], int rows) {
    //Output header per problem specs
    cout << "Think of this as a Product/Muliplication Table" << endl;
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

void init_2(int array[], int size) {
    // for each element in array, accept input
    for (short i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void print_2 (int array[], int size, int rowSize) {
    //for each element in array, print it plus a space to console
    for (short i = 0; i < size; i++) {
        cout << array[i] << " ";
        //output new line per problem specs
        if ((i+1) % rowSize == 0) cout << endl;
    }
}

void revrse_2(int array[], int size) {
    int rArray[size]; // reversed array
    //Loop through input array and assign reversed values to reverse array
    for (short i = 0; i < size; i++) {
        rArray[size-1-i] = array[i];
    }
    //Override normal order values in input array with reversed values
    for (short i = 0; i < size; i++) {
        array[i] = rArray[i];
    }
}

void init_3 (float array[], int size) {
    // for each element in array, accept input
    for (short i = 0; i < size; i++) {
        cin >> array[i];
    }
}

float avgX_3 (float array[], int size) {
    float mean; // average of all elements
    float sum = 0; // sum of all array elements
    
    //loop thru array; add each element to the sum
    for (short i =0; i < size; i++) {
        sum += array[i];
    }
    //calculate average by dividing sum by the number of terms 
    mean = sum/size;
    
    return mean;
}

float stdX_3 (float array[], int size) {
    //init variables
    float sqSum = 0; // sum of the squares of all terms
    float mean = avgX_3(array, size); // average of all terms
    
    //loop through all array elements; add the the square sum the square of the element value minus the average
    //sum((x[i]-mean)^2/(n-1))
    for (short i = 0; i < size; i++) {
        sqSum += pow((array[i]-mean), 2);
    }

    return sqrt(sqSum / (size  - 1));
}

void print_4(const string &input) {
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

void read_4(string &outStr) {
    //get the input line from console
    getline(cin, outStr);
    //remove identifier
    outStr.erase(0,8);
    //remove spaces
    outStr.erase(remove_if(outStr.begin(), outStr.end(), ::isspace), outStr.end());
}

int compare_4(const string &key,const string &answers,string &score) {
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

//Purpose: Fill a provided array with user Input
void fillAry_5(int array[], int arrSz) {
    //loop thru the array; for each element, assign the user provided value
    for (short i = 0; i < arrSz; i++) {
        cin >> array[i];
    }
}

//Purpose: Linearly search an array for provided values
bool linSrch_5(int array[], int arrSz, int val, int &indx) {
    //loop thru the array starting at 0; if the value is found,
    //assign the index to the reference variable and return true
    //if the value is not found, return false
    for (short i = 0; i < arrSz; i++) {
        if (array[i] == val) {
            indx = i;
            return true;
        }
    }
    return false;
}

void fillAry_6(int array[], int size) {
    //loop thru the array; for each element, assign the user provided value
    for (short i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void prntAry_6 (int array[], int size, int rowSize) {
    //for each element in array, print it plus a space to console
    for (short i = 0; i < size; i++) {
        cout << array[i] << " ";
        //output new line per problem specs
        if ((i+1) % rowSize == 0) cout << endl;
    }
}

void selSrt_6(int array[], int size) {
    int minIndx; // index of the lowest number
    //loop through array
    for (short i = 0; i < size; i++) {
        //placeholder index of -1
        minIndx = -1;
        //loop through array again;
        for (short c = i; c < size; c++) {
            //if the value of the inner loop is less than the value of the outer loop,
            //assign the minimum index to the element from the inner loop
            if (array[c] < array[minIndx]) minIndx = c;
        }
        //swap elements
        short tmp = array[i];
        array[i] = array[minIndx];
        array[minIndx] = tmp;
    }
}

bool binSrch_6(int array[], int size, int val, int &indx) {
    int low = 0; //low end of the range
    int hi = size-1; //high end of the range
    int mid; // midpoint of the range
    //while the range is greater than 1 (the high and low are not the same)
    //execute loop
    while (hi-low > 1) {
        mid = (hi + low) / 2; // searchpoint is equal to the center of the range
        // if the value is found greater than the midpoint,
        //assign a new lowpoint of the midpoing
        if (array[mid] < val) {
            low = mid + 1;
        //else if the value is found at a point lower than the midpoint,
        //assign the high end of the range to the current midpoint
        } else {
            hi = mid;
        }
    }
    //check for match of high or lowpoint,
    //return true and assign appropriate index if so
    if (array[low] == val) {
        indx = low;
        return true;
    } else if (array[hi] == val) {
        indx = hi;
        return true;
    } else {
        return false;
    }
}

void fillAry_7(int array[], int size) {
    //loop thru the array; for each element, assign the user provided value
    for (short i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void prntAry_7 (int array[], int size, int rowSize) {
    //for each element in array, print it plus a space to console
    for (short i = 0; i < size; i++) {
        cout << array[i] << " ";
        //output new line per problem specs
        if ((i+1) % rowSize == 0) cout << endl;
    }
}

void bublSrt_7(int array[], int size) {
    int a = size, // assign a 1equal to size of array
    temp; // temp variable for swapping
    bool done; // continue sorting

    do {
        done = false; // stop sorting array

        //loops through all remaining sort elements in array
        for(int n = 0; n < a; n++ ) {
            if(array[n] > array[n+1]) { // if an array element is greater than the element after it,
                temp = array[n];        // swaps the two elements
                array[n] = array[n+1];
                array[n+1] = temp;

                done = true; // continue sorting array
            }
        }

        a--;
    } while(done);
}

bool binSrch_7(int array[], int size, int val, int &indx) {
    int low = 0; //low end of the range
    int hi = size-1; //high end of the range
    int mid; // midpoint of the range
    //while the range is greater than 1 (the high and low are not the same)
    //execute loop
    while (hi-low > 1) {
        mid = (hi + low) / 2; // searchpoint is equal to the center of the range
        // if the value is found greater than the midpoint,
        //assign a new lowpoint of the midpoing
        if (array[mid] < val) {
            low = mid + 1;
        //else if the value is found at a point lower than the midpoint,
        //assign the high end of the range to the current midpoint
        } else {
            hi = mid;
        }
    }
    //check for match of high or lowpoint,
    //return true and assign appropriate index if so
    if (array[low] == val) {
        indx = low;
        return true;
    } else if (array[hi] == val) {
        indx = hi;
        return true;
    } else {
        return false;
    }
}
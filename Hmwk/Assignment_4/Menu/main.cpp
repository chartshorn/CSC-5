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
#include <vector> // vector datatype lib
#include <string> // strings lib

using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
const float lToG = .264179; // factor to multiply liters by for gallons

//Function Prototypes
// Purpose: Calculate mpg of a car and output associated data
// Inputs: ( character - id - id of the car to output )
// Returns: Float - Average MPG
float calcMpg(char); 

//Purpose: Calculate inflation rate
//Input: (Float curPrc - Current price in USD) (Float oldPrc - Price from one year ago in usd)
//Returns: float rate - percentage rate of inflation
float calcInf ( float, float );

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
                //Gaddis_9thEd_Chap5_Prob1_Sum
                // Purpose: Calculate the sum of all numbers
                //Declare Variables
                short input, // usr input
                total; // sum

                //Initialize or input i.e. set variable values
                total = 0; // baseline for total
                cin >> input; // gather input

                //Map inputs -> outputs
                //loop starting at zero to input number, add every number in the process.
                for (short i = 1; i < input+1; i++) {
                    total += i;
                }

                //Display the outputs
                cout << "Sum = " << total;

                //Exit stage right or left
            }
            break;
            case 1: {
                //Gaddis_9thEd_Chap5_Prob7_PayInPennies
                //Determine salary in pennies
                //Declare Variables
                short days; // number of days employee worked
                double pay; // pay based on days, must be double due to exponential nature

                //Initialize or input i.e. set variable values
                pay = 0; // init pay
                cin >> days;

                //input validation
                if (days < 1) {
                    cout << "*** ERROR: INVALID DAYS ***";
                    return 1;
                }

                //Map inputs -> outputs
                //loop through days, calculate pay per problem specs
                for (short i = 1; i < days+1; i++) {
                    pay += i == 1 ? .01 : pow(2,i-1) * .01;
                }



                //Display the outputs
                cout << "Pay = $" << setprecision(2) << fixed << pay;
                
            }
            break;
            case 2: {
                //Gaddis_9thEd_Chap5_Prob13_MinMax
                // Purpose:  Determine Min and Max of a set of #s
                //Declare Variables
                short lowest, // lowest number
                highest; // highest number
                bool wntInpt; // want input - boolean for if user has entered -99 yet
                vector < short > nums; // due to nonpreset size, vector used over array

                //Initialize or input i.e. set variable values
                wntInpt = true; // want input 

                while (wntInpt) {
                    short inpt; // termporary var for input
                    cin >> inpt; // seek user input
                    if (inpt != -99) nums.push_back(inpt); // if input isn't 99, add the inpt to the array
                    else wntInpt = false; // stop seeking input
                }

                //Map inputs -> outputs
                //loop thru nums
                for (short i = 0; i < 5; i++) {
                    // element needs to be sorted up
                    if (nums[i] > nums[i+1]) {
                        // swap num elements
                        short tmpNm = nums[i];
                        nums[i] = nums[i+1];
                        nums[i+1] = tmpNm;

                        //restart loop
                        i = -1;
                    }
                }

                //Display the outputs
                cout << "Smallest number in the series is " << nums.front() << endl;
                cout << "Largest  number in the series is " << nums.back();
                
            }
            break;
            case 3: {
                //Gaddis_9thEd_Chap5_Prob22_Rectangle
                //Purpose: generate a rectangle
                //Declare Variables
                short size; // size of rectangle
                char symbol; // symbol to make up rectangle

                //Initialize or input i.e. set variable values
                cin >> size >> symbol;

                //input validation per problem specs
                if (size > 15 || size <= 0) {
                    cout << "*** ERROR: Invalid Size ***" << endl;
                    return 1;
                }

                //Map inputs -> outputs
                for (short i = 0; i < size; i++) {
                    // output a row of the desired symbol
                    for (short i = 0; i < size; i++) {
                        cout << symbol; // output a column of the desire symbol
                    }
                    if (i != size-1) cout << endl; // do not include endl on last loop per problem specs
                }
            }
            break;
            case 4: {
                // Gaddis_9thEd_Chap5_Prob23_Pattern
                // Purpose: Generate a pattern given an input
                //Declare Variables
                short inpt; // input var

                //Initialize or input i.e. set variable values
                cin >> inpt;

                //Map inputs -> outputs
                // loop through every number below one, generate row
                for (short i = 1; i < inpt+1; i++) {
                    //loop through row, generate columns
                    for (short w = 1; w < i+1; w++) {
                        cout << "+";
                    }

                    // generate endls
                    cout << endl;
                    cout << endl;
                }

                //starting at the max, loop through every number until zero, generate row
                for (short i = inpt; i > 0; i--) {
                    //loop through row, generate columns
                    for (short w = 1; w < i+1; w++) {
                        cout << "+";
                    }

                    //format new line per problem specs
                    if (i != 1) {
                        cout << endl;
                        cout << endl;
                    }
                }
            }
            break;
            case 5: {
                //Savitch_9thEd_Chap4_Prob1_MPG
                //Purpose: calculate mpg of a car
                // loop controlling variable
                bool cnt = true;

                while (cnt) {
                    //Declare Variables
                    short ltrsCsm, // liters consumed 
                    mlsTrvl; // miles travelled
                    float glns, // gallons consumd
                    mpg; // avg mpg
                    char yesNo; //usr input for yes no


                    //Initialize or input i.e. set variable values
                    cout << "Enter number of liters of gasoline:" << endl;
                    cin >> ltrsCsm;
                    cout << endl;
                    cout << "Enter number of miles traveled:" << endl;
                    cin >> mlsTrvl;
                    cout << endl;

                    //Map inputs -> outputs
                    glns = ltrsCsm * lToG; // gallons = liters * liters to gallons factor
                    mpg = mlsTrvl / glns; // mpg = miles travelled / gallons

                    //Display the outputs
                    cout << "miles per gallon:" << endl;
                    cout << setprecision(2) << fixed << mpg;
                    cout << endl;

                    cout << "Again:" << endl;
                    cin >> yesNo;

                    //restart loop dependent on user input
                    if (yesNo == 'y') {
                        cout << endl;
                    } else {
                        cnt = false;
                    }
                }
            }
            break;
            case 6: {
                //Savitch_9Ed_Chap4_Prob2_FuelEff
                //Purpose: calculate mpg of a car
                // loop controlling variable
                bool cnt = true;

                while (cnt) {
                    //Declare Variables
                    char yesNo; //usr input for yes no
                    float mpg1, // mpg of car 1
                    mpg2; // mpg of car 2

                    mpg1 = calcMpg('1'); // calc mpg of car 1
                    mpg2 = calcMpg('2'); // calc mpg of car 2

                    //determine which car is more gas efficient
                    if (mpg1 > mpg2) cout << "Car 1 is more fuel efficient" << endl;
                    else if (mpg2 > mpg1) cout << "Car 2 is more fuel efficient" << endl;
                    else cout << "MPG Error";
                    cout << endl;

                    //prompt user for second loop
                    cout << "Again:" << endl;
                    cin >> yesNo;

                    //restart loop dependent on user input
                    if (yesNo == 'y') {
                        cout << endl;
                    } else {
                        cnt = false;
                    }
                }
            }
            break;
            case 7: {
                //Savitch_9Ed_Chap4_Prob4_Inflation
                //Purpose:  Calculate inflation rate
                //loop Variables
                bool wntLoop;
                wntLoop = true;

                while (wntLoop) {
                    //Declare Variables
                    float oldPrc, // old price
                    curPrc, // current price
                    infRate; // inflation rate
                    char yesNo; // user input - y/n continue the loop

                    //Initialize or input i.e. set variable values
                    cout << "Enter current price:" << endl;
                    cin >> curPrc;
                    cout << "Enter year-ago price:" << endl;
                    cin >> oldPrc;

                    //Map inputs -> outputs
                    //inflation rate is equal to current price / old price - 1, converted to percentage
                    infRate = (( curPrc / oldPrc ) - 1.0f) * 100;

                    //Display the outputs
                    cout << "Inflation rate: " << setprecision(2) << fixed << infRate << "%" << endl << endl;

                    cout << "Again:" << endl;
                    cin >> yesNo;

                    if (yesNo == 'y') {
                         cout << endl;
                    } else {
                        wntLoop = false;
                    }
                }
            }
            break;
            case 8: {
                //Savitch_9Ed_Chap4_Prob5_EstCost
                //loop Variables
                bool wntLoop;
                wntLoop = true;

                while (wntLoop) {
                    //Declare Variables
                    float oldPrc, // old price
                    curPrc, // current price
                    yr1Prc, // price in 1 year
                    yr2Prc, // price in 2 years
                    infRate; // inflation rate
                    char yesNo; // user input - y/n continue the loop

                    //Initialize or input i.e. set variable values
                    cout << "Enter current price:" << endl;
                    cin >> curPrc;
                    cout << "Enter year-ago price:" << endl;
                    cin >> oldPrc;

                    //Map inputs -> outputs
                    infRate = calcInf(curPrc, oldPrc); // calculate inflation rate
                    yr1Prc = curPrc + curPrc * infRate * .01; // calculate the price one year from now assuming current price and constant inflation rate
                    yr2Prc = yr1Prc + yr1Prc * infRate * .01; // calculate the price two years from now assuming yr1 price and constant inflation rate

                    //Display the outputs
                    cout << "Inflation rate: " << setprecision(2) << fixed << infRate << "%" << endl << endl;
                    cout << "Price in one year: $" << yr1Prc << endl;
                    cout << "Price in two year: $" << yr2Prc << endl << endl;

                    cout << "Again:" << endl;
                    cin >> yesNo;

                    //determine whether user wants to run the scenario again
                    if (yesNo == 'y') {
                         cout << endl;
                    } else {
                        wntLoop = false;
                    }
                }
            }
            break;
            case 9: {
                //Savitch_9Ed_Chap4_Prob9_2or3Max
                //Purpose:  Determine two highpoints of a set of floats
                //Declare Variables
                float high2, high3; // highpoint of first two, highpoint of first 3
                float nums [3] = {}; // input numbers

                //Initialize or input i.e. set variable values
                cout << "Enter first number:" << endl << endl;
                cin >> nums[0];
                cout << "Enter Second number:" << endl << endl;
                cin >> nums[1];
                cout << "Enter third number:" << endl << endl;
                cin >> nums[2];

                //Map inputs -> outputs
                // determine if two point is the highest
                if (nums[0] > nums[1]) high2 = nums[0]; // number 0 is highpoint of first 2 params
                else if (nums[1] > nums[0]) high2 = nums[1]; // number 1 is the highpoint of first 2 params
                else cout << "*** Error ***";

                //determine highpoint of series
                if (high2 > nums[2]) high3 = high2; // the highpoint of the first 2 params is the highest of the entire set
                else if (nums[2] > high2) high3 = nums[2]; // the highpoint of the set is the last param
                else cout << "*** Error ***";


                //Display the output
                cout << setprecision(1) << fixed;
                cout << "Largest number from two parameter function:" << endl;
                cout << high2 << endl << endl;
                cout << "Largest number from three parameter function:" << endl;
                cout << high3 << endl;
            }
            break;
            default:cout<<"Exiting the Menu"<<endl;
        }
    }while(choose>=0 && choose<=9);

    return 0;
}

// Purpose: Calculate mpg of a car and output associated data
float calcMpg(char id) {
    short ltsCsm, // liters consumed 
    mlsTrv; // miles travelled
    float glns, // gallons consumed
    mpg; // avg mpg
    
    cout << "Car " << id << endl;
    cout << "Enter number of liters of gasoline:" << endl;
    cin >> ltsCsm;
    cout << "Enter number of miles traveled:" << endl;
    cin >> mlsTrv;
    
    //car 1 conversion
    glns = ltsCsm * lToG; // gallons = liters * liters to gallons factor
    mpg = mlsTrv / glns; // mpg = miles travelled / gallons
        
    //Display the outputs
    cout << "miles per gallon: ";
    cout << setprecision(2) << fixed << mpg;
    cout << endl << endl;
    
    return mpg; // return mpg for later comparison
}

//Purpose: Calculate inflation rate
float calcInf(float curPrc, float oldPrc) {
    return (( curPrc / oldPrc ) - 1.0f) * 100; //inflation rate is equal to current price / old price - 1, converted to percentage
}


/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on: July 23 2022 @ 1904
 * Purpose:  Binary Search
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Functions
#include <ctime>     //Time Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
void bublSrt(int [],int);
bool binSrch(int [],int,int,int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int array[SIZE];
    int indx,val;
    
    //Initialize or input i.e. set variable values
    fillAry(array,SIZE);

    //Sorted List
    bublSrt(array,SIZE);
    
    //Display the outputs
    prntAry(array,SIZE,10);
    cout << endl;
    cout<<"Input the value to find in the array"<<endl;
    cin>>val;
    if(binSrch(array,SIZE,val,indx))
        cout<<val<<" was found at indx = "<<indx<<endl;

    //Exit stage right or left!
    return 0;
}

void fillAry(int array[], int size) {
    //loop thru the array; for each element, assign the user provided value
    for (short i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void prntAry (int array[], int size, int rowSize) {
    //for each element in array, print it plus a space to console
    for (short i = 0; i < size; i++) {
        cout << array[i] << " ";
        //output new line per problem specs
        if ((i+1) % rowSize == 0) cout << endl;
    }
}

void bublSrt(int array[], int size) {
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

bool binSrch(int array[], int size, int val, int &indx) {
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
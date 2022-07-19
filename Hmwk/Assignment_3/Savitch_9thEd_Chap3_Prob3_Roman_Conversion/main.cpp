/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on Jul 10 2022 @ 2016
 * Purpose: Roman Numeral Conversion
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  

//User Libraries

//Global Constants not Variables

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    short alg;
    string rom="";
    char n1000s,n100s,n10s,n1s;
    
    //Initialize variables here
    cout<<"Arabic to Roman numeral conversion."<<endl;
    cout<<"Input the integer to convert."<<endl;
    cin>>alg;
    
    //Input validation
    if(alg<0 || alg<=999 || alg >= 3001){
        if(alg<=999 || alg >= 3001)cout<<alg<<" is Out of Range!";
        else cout<<"Negative number"<<endl;
        exit(1);
    }
    
    //Calculate the number of powers of 10
    n1000s=alg/1000;    //Strip 1000's
    n100s=alg%1000/100; //Strip the 100's place
    n10s=alg%100/10;    //Strip the 10's place
    n1s=alg%10;         //Strip the 1's place
    
    //Output Roman Numerals 1000s
    rom+=n1000s==3?"MMM" :
        n1000s==2?"MM" :
        n1000s==1?"M" : "";
    
    //Output Roman Numerals 100s
    rom+=n100s==9?"CM":
       n100s==8?"DCCC":
       n100s==7?"DCC":
       n100s==6?"DC":
       n100s==5?"D":
       n100s==4?"CD":
       n100s==3?"CCC":
       n100s==2?"CC":
       n100s==1?"C":"";
            
    //Output Roman Numerals 10s
    rom+=n10s==9?"XC":
       n10s==8?"LXXX":
       n10s==7?"LXX":
       n10s==6?"LX":
       n10s==5?"L":
       n10s==4?"XL":
       n10s==3?"XXX":
       n10s==2?"XX":
       n10s==1?"X":"";
       
    //Output Roman Numerals 10s
    rom+=n10s==9?"IX":
       n1s==8?"VIII":
       n1s==7?"VII":
       n1s==6?"VI":
       n1s==5?"V":
       n1s==4?"IV":
       n1s==3?"III":
       n1s==2?"II":
       n1s==1?"I":"";

    
    //Display the results
    cout<<alg<<" is equal to "<<rom;

    return 0;
}
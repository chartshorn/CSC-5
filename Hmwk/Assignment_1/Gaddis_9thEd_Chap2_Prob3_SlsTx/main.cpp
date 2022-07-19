/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 8:02 PM
 * Purpose: To calculate sales tax on a purchase
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float stTx, //state tax amount 
        cntyTx, //county tax amount
        txTtl, //total tax amount 
        stTxRt, //state tax rate (%)
        cntyTxRt, //county tax rate (%)
        sbttl, //purchase price pretax
        ttl; //purchase price post-tax
    
    //Initialize Variables
    //Set tax rates
    stTxRt = 0.04f; //4% state tax rate
    cntyTxRt = 0.02f; //2% state tax rate
    //Set pretax price
    sbttl = 95.0f; //$95 usd
    
    //Map inputs to outputs -> The Process
    //Multiply tax rates by subtotal to gain 
    stTx = stTxRt * sbttl; // state tax amount
    cntyTx = cntyTxRt * sbttl; // & county tax amount!
    
    //Calculate total tax on transaction
    txTtl = stTx + cntyTx; // tax total = state tax + county tax
    
    //Calculate purchase total
    ttl = sbttl + txTtl; // total = subtotal + tax
    
    //Display Results
    //Display tax amount
    cout<<"Your tax is: $";
    cout<<txTtl<<endl;
    
    //Display purchase total
    cout<<"Your total is: $";
    cout<<ttl<<endl;
    
    //Exit stage right 
    return 0;
}


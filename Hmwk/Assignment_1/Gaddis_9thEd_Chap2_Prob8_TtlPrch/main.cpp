/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 8:02 PM
 * Purpose: calculate a purchase subtotal, tax amount, and total
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
    float sbttl, //sum of all the prices
        prc1, // item 1 price ($)
        prc2, // item 2 price ($)
        prc3, // item 3 price ($)
        prc4, // item 4 price ($)
        prc5, // item 5 price ($)
        txRt, // tax rate (%)
        txAmnt, // tax amount ($)
        ttl; // sum of all prices and tax ($)
    
    //Initialize Variables
    txRt = .07f; // 7% tax rate
    prc1 = 15.95f; // $15.95 price of item 1
    prc2 = 24.95f; // ^ $24.95 2
    prc3 = 6.95f; // ^ $6.95 3
    prc4 = 12.95f; // ^ $12.95 4
    prc5 = 3.95f; // ^ $3.95 5
    
    //Map inputs to outputs -> The Process;
    sbttl += prc1;
    sbttl += prc2;
    sbttl += prc3;
    sbttl += prc4;
    sbttl += prc5;
    
    txAmnt = sbttl * txRt; // tax amount = subtotal * tax rate
    
    ttl = sbttl + txAmnt; // total = sub total + tax amount
    
    //Display Results
    cout<<"Item 1: $"<<prc1<<endl;
    cout<<"Item 2: $"<<prc2<<endl;
    cout<<"Item 3: $"<<prc3<<endl;
    cout<<"Item 4: $"<<prc4<<endl;
    cout<<"Item 5: $"<<prc5<<endl;
    cout<<"-Your Subtotal Is: $"<<sbttl<<"-"<<endl;
    cout<<"-Your Tax Is: $"<<txAmnt<<"-"<<endl;
    cout<<"-=Your Total Is: $"<<ttl<<"=-"<<endl;
    
    //Exit stage right 
    return 0;
}

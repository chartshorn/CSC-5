/* 
 * File:   main.cpp
 * Author: Caden Hartshorn
 * Created on June 22, 2022, 8:02 PM
 * Purpose: Determine cos / sin / tan of a given angle
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//User Libraries

//Global Constants
const float pi = 3.14159265359f;

//Function Prototypes
//converts degrees to radians
//arg: angle to convert
//returns: float radians of angle
float cnvrtRd(float);

//sets the formatting of console per problem specs
void stFrmt ();

//resets the formatting of console
void rstFrmt();

//prints an output statement per problem specs
//ex : sin(45) = 0.7071
//args: trigonometric value, angle, which trigonometric function, and if it's the last
void outTrg (float, float, string, bool);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float anglX, // user provided angle (x)
        radX, // anglX in rads
        sinX, // sine of x
        cosX, // cosine of x
        tanX; // tangent of x
    
    //Initialize Variables 
    //gather user input
    cout << "Calculate trig functions" << endl;
    cout << "Input the angle in degrees." << endl;
    cin >> anglX;
    
    //Map inputs to outputs -> The Process
    // convert angle to rads
    radX = cnvrtRd(anglX);
    
    sinX = sinf(radX); // sineX = sine of angle x via cmath lib
    cosX = cosf(radX); // cosineX = cosine of angle x via cmath lib
    tanX = tanf(radX); // tangentX = tangent of angle x via cmath lib
    
    //Display Results
    outTrg(sinX, anglX, "sin", false);
    outTrg(cosX, anglX, "cos", false);
    outTrg(tanX, anglX, "tan", true);
    
    //Exit stage right 
    return 0;
}

float cnvrtRd(float angl) {
    return (angl * (pi / 180));
}

//sets format per problem specs
void stFrmt() {
    cout << setprecision(4) << fixed << showpoint; // formatting per problem instructions
}

//resets console formatting
void rstFrmt() {
    cout << noshowpoint << defaultfloat;
}

//prints an output statement per problem specs
//args: trigonometric value, angle, which trigonometric function, and if it's the last
void outTrg(float trg, float angl, string trgId, bool isLast) {
    //Output the ID (cos, sin, tan) followed by the angle
    cout << trgId << "(" << angl << ") = ";
    //set the format per problem specs
    stFrmt();
    //output the sin cos or tan
    cout << trg;
    //reset formatting
    rstFrmt();
    //ternary that places a \n if this is not the last line of output
    cout << (isLast ? "" : "\n");
}

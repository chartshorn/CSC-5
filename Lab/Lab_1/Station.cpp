/* 
 * File:   Station.cpp
 * Author: cadenhartshorn
 * 
 * Created on June 23, 2022, 9:07 PM
 */

#include <iostream>
#include "Station.h"

Station::Station(
    unsigned short _dstnc, //Input Distance to Station (Miles)
    float _glnCst, //Input Gallon Cost at Station ($) , 
    float _glnNd, // Input Gallons Needed to Fuel
    float _crMpg, // Input car MPG,
    unsigned char _stnId //id of this station
    ) {
        stnId = _stnId; //station ID for print
    
        dstnc = _dstnc; //distance to gas station (miles)
        trp = dstnc*2; //calculate round trip miles by doubling distance
        
        glnCst = _glnCst; // set cost of gas / gallon
        flPrc = glnCst * _glnNd; // calculate cost of filling up the tank to full
        
        trvlPrc = trp / _crMpg * glnCst; // cost to drive to gas station and back
        
        ttl = trvlPrc + flPrc; // total price to fill tank and drive to gas station
        
        ppgAdj = ttl / _glnNd; // price / gallon factoring in travel cost
    }

//Function to print off all relevant details of the object
void Station::printDetails () {
    std::cout<<"***STATION "<<stnId<<"***"<<std::endl;
    std::cout<<"Distance To Station (Miles): "<<dstnc<<std::endl;
    std::cout<<"Cost To Fill Up: $"<<flPrc<<std::endl;
    std::cout<<"Total Trip (Miles): "<<trp<<std::endl;
    std::cout<<"Cost To Drive To and From: $"<<trvlPrc<<std::endl;
    std::cout<<"Total Cost W/ Mileage To Station: $"<<ttl<<std::endl;
    std::cout<<"Price Per Gallon W/ Mileage: $"<<ppgAdj<<std::endl;
}
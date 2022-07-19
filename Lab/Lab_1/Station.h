/* 
 * File:   Station.h
 * Author: cadenhartshorn
 *
 * Created on June 23, 2022, 9:07 PM
 */

#ifndef STATION_H
#define STATION_H
#include <iostream>

class Station {
public:
    Station( unsigned short, float, float, float, unsigned char);
    void printDetails();
private:
    unsigned short dstnc, // distance to station in miles
    trp; // Round trip distance to station in miles
    float glnCst, // Cost per gallon at this station ($)
    flPrc, // Cost to fill tank at this station ($)
    trvlPrc, // Cost to travel to station ($)
    ttl, // Total to fuel car, travel adjusted ($)
    ppgAdj; // Price per gallon adjusted ($)
    unsigned char stnId; //Id of the gas station
};

#endif /* CLASS_STATION_H */


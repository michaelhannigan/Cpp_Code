//
//  Distance.hpp
//  Lab7b
//
//  Created by Michael Hannigan on 10/13/20.
//

#ifndef Distance_hpp
#define Distance_hpp

#include <iostream>
#include <stdio.h>
using namespace std;

class Distance //English Distance class
{
private:
    int feet;
    float inches;
public: //constructor (no args)
    Distance();
    Distance(int ft, float in);
    Distance operator +(const Distance & d2) const;
    friend Distance operator -(const Distance & d1, const Distance & d2);
    friend ostream& operator << (ostream& s, const Distance d);
    friend istream& operator >> (istream& s, Distance& d);
};

#endif /* Distance_hpp */

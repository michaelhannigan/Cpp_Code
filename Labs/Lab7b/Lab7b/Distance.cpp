//
//  Distance.cpp
//  Lab7b
//
//  Created by Michael Hannigan on 10/13/20.
//

#include "Distance.hpp"

Distance::Distance(){
    feet = 0;
    inches = 0.0;
}

Distance::Distance(int ft, float in){
    feet = ft;
    inches = in;
}

Distance Distance::operator+(const Distance & d2) const{
    int totalFeet = feet + d2.feet;
    float totalInches = inches + d2.inches;
    return Distance(totalFeet, totalInches);
}

Distance operator-(const Distance & d1, const Distance & d2){
    int totalFeet = d1.feet - d2.feet;
    float totalInches = d1.inches - d2.inches;
    return Distance(totalFeet, totalInches);
}

ostream& operator << (ostream& o, const Distance d){
    o<<d.feet<<"feet "<<d.inches<<"inches"<<endl;
    return o;
}

istream& operator >> (istream& i, Distance& d){
    i>>d.feet;
    i>>d.inches;
    return i;
}

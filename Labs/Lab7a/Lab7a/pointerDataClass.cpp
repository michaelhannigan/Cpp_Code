//
//  pointerDataClass.cpp
//  Lab7a
//
//  Created by Michael Hannigan on 10/12/20.
//

#include <stdio.h>
#include <iostream>
#include "pointerDataClass.hpp"
using namespace std;


pointerDataClass::pointerDataClass(int size){
    maxSize = size;
    length = maxSize-1;
    if(size<=maxSize)
        p = new int[size];
    else
        cout<<"The size is too big";
}

pointerDataClass::~pointerDataClass(){
    
}

void pointerDataClass::insertAt(int index, int num){
    if(index <= length)
        *(p+index) = num;
    else
        cout<<"Index is out of bounds";
}

void pointerDataClass::displayData(){
    for(int i = 0; i<maxSize; i++)
    cout<<*(p+i)<<endl;
}

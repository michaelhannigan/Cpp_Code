//
//  main.cpp
//  Lab5a
//
//  Created by Michael Hannigan on 10/5/20.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
   
    long value1 = 200000;
    long value2;
    
    long *longPtr;
    
    longPtr = &value1;
    
    cout<<*longPtr<<endl;
    
    value2 = *longPtr;
    
    cout<<value2<<endl;
    
    cout<<&value1<<endl;
    
    cout<<&longPtr<<endl;
    
    
    
    
    
}

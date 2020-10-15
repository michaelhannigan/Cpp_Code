//
//  main.cpp
//  Lab7a
//
//  Created by Michael Hannigan on 10/13/20.
//

#include "pointerDataClass.hpp"
#include <stdio.h>
#include <iostream>

int main(){
    pointerDataClass list11 = pointerDataClass(10);
    for(int i = 0; i<10; i++){
        list11.insertAt(i, i);
    }
    
    list11.displayData();
    cout<<endl;
    
    return 0;
}

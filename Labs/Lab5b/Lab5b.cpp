//
//  Main.cpp
//  Lab 5b
//
//  Created by Michael Hannigan on 9/28/20.
//

#include <stdio.h>
#include <iostream>
using namespace std;



int main(int argc, const char * argv[]) {
    int size;
    cout<<"Enter how many numbers your array wil be:"<<endl;
    cin>>size;
    
    int * ptr;
    
    ptr = new int[size];
   
    //sets the array
    for(int i = 0; i<size;i++){
        cout<<"Enter number:"<<endl;
        cin>>*(ptr+i);
    }
    
    //gets the largest int
    int largest = ptr[0];
    cout<<"The array displayed is: ";
    for(int i = 0; i<size; i++){
        cout<<*(ptr + i);
        if(ptr[i]>largest)
            largest = ptr[i];
    }
    
    cout<<endl;
    cout<<"The largest number is:"<<largest<<endl;
    

}

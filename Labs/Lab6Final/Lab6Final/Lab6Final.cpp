//
//  main.cpp
//  Lab6
//
//  Created by Michael Hannigan on 10/5/20.
//

#include <iostream>
#include <fstream>
using namespace std;

//Reads data from a text file into an array
int readData(int * &arr) {
// Open the file to get the data
int size;
ifstream inputFile;
inputFile.open("data.txt");
// The first line of the file is the size of the array
inputFile >> size;

//Allocate the memory for pointer arr
    arr =  new int[size];
// Read the rest of the data into the array
for (int i = 0; i < size; i++) {
    inputFile>>*(arr +i);
    cout<<*(arr+i);
} // End for loop
inputFile.close();
return size;
} // End readData

void bsort(int * arr, int size) {
    int i,j;
    int temp;
    
    for(i = 1; i<size; i++){
        
        for(j = 0; j<size-i; j++){
        
            if(*(arr + j)< *(arr + j + 1)){
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void writeToConsole(int * arr, int size) {
cout << "Contents of array:" << endl;
for (int i = 0; i < size; i++) {
cout << *(arr + i) << " ";
} // End for loop
} // End writeToConsole
    
    
int main() {
    int * arr;
    int size = readData(arr);
  cout << "Before bubble sort" << endl;
  writeToConsole(arr, size);
  cout<<endl;
  bsort(arr, size);
  cout << "After bubble sort" << endl;
  writeToConsole(arr, size);

      return 0;
}

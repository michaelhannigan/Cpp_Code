//  Michael Hannigan
//  Class(CeCS 282-04)
//  Project Name(Prog 2 - myDate)
//  Due Date(23/09/2020)
//  I certify that this program is my own original work. I did not copy any part of
//  this program from any other source. I further certify that I typed each and
//  every line of code in this program.



#ifndef myDate_H
#define myDate_H

#include <string>
using namespace std;
class myDate{
    private:
        int month = 5;
        int day = 11;
        int year = 1959;
    public:
        myDate();
        myDate(int,int, int);
        void display();
        void increaseDate(int);
        void decreaseDate(int);
        int daysBetween(myDate);
        int getMonth();
        int getDay();
        int getYear();
        int dayOfYear();
        string dayName();
};



#endif

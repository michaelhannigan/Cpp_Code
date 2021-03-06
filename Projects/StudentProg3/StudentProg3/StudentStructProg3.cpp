//
//  StudentStructProg3.cpp
//  myDate
//
//  Created by Michael Hannigan on 10/4/20.
//  Copyright © 2020 Michael Hannigan. All rights reserved.
//
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

#ifndef myDate_H
#define myDate_H

using namespace std;
class myDate{
    private:
        int month = 5;
        int day = 11;
        int year = 1959;
    public:
        myDate();
        myDate(int,int, int);
        string display();
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

int Greg2Julian(int month, int day, int year){
    return   day-32075+1461*(year+4800+(month-14)/12)/4+367*(month-2-(month-14)/12*12)
    /12-3*((year+4900+(month-14)/12)/100)/4  ;
}

void Julian2Greg(int JD, int & month, int & day, int & year){
    int I, J, K, L,  N;
    L= JD+68569;
    N= 4*L/146097;
    L= L-(146097*N+3)/4;
    I= 4000*(L+1)/1461001;
    L= L-1461*I/4+31;
    J= 80*L/2447;
    K= L-2447*J/80;
    L= J/11;
    J= J+2-12*L;
    I= 100*(N-49)+I+L;
    
    year = I;
    month = J;
    day = K;
    
}

myDate::myDate(){
    month = 5;
    day = 11;
    year = 1959;
}

myDate::myDate(int m, int d, int y){
    if(m<1||m>12){
        m = 5;
        d = 11;
        y = 1959;
    }

    if(d<1||(d>31&&m==1)||(d>28&&m==2&&y%4==0&&y%400!=0&&y%100==0)||(d>28&&m==2&&y%4!=0)
    ||(d>31&&m==3)||(d>30&&m==4)||(d>31&&m==5)||(d>30&&m==6)||(d>31&&m==7)
    ||(d>31&&m==8)||(d>30&&m==9)||(d>31&&m==10)||(d>30&&m==11)||(d>31&&m==12)){
    m = 5;
    d = 11;
    y = 1959;
    }
        month = m;
        day = d;
        year = y;
    
    

}

string myDate::display(){
    string monthName;
    if(month == 1){
        monthName = "January";
    }if(month == 2){
        monthName = "February";
    }if(month == 3){
        monthName = "March";
    }if(month == 4){
        monthName = "April";
    }if(month == 5){
        monthName = "May";
    }if(month == 6){
        monthName = "June";
    }if(month == 7){
        monthName = "July";
    }if(month == 8){
        monthName = "August";
    }if(month == 9){
        monthName = "September";
    }if(month == 10){
        monthName = "October";
    }if(month == 11){
        monthName = "Novemeber";
    }if(month == 12){
        monthName = "December";
    }
    
    string stringDate = monthName + " " + to_string(day) + ", " + to_string(year);
    return stringDate;
}

void myDate::increaseDate(int num){
    int jd = Greg2Julian(month, day, year);
    jd+=num;
    Julian2Greg(jd, month, day, year);
        
}

void myDate::decreaseDate(int num){
    int jd = Greg2Julian(month, day, year);
    jd-=num;
    Julian2Greg(jd, month, day, year);
    

}
int myDate::daysBetween(myDate md){
    int date1 = Greg2Julian(md.getMonth(), md.getDay(), md.getYear());
    int date2 = Greg2Julian(month, day, year);
    
    int total = date1-date2;
    return total;
}
int myDate::getMonth(){
    return month;
}

int myDate::getDay(){
    return day;
}

int myDate::getYear(){
    return year;
}

int myDate::dayOfYear(){
//    int date1 = Greg2Julian(month, day, year);
//    int date2 = Greg2Julian(month, day, year-1);
//    int doy = date1-date2;
//    return doy;
    if(month == 1){
        return day;
    }
    if(month == 2){
        return day+31;
    }
    if(year%4==0 && year%400!=0){
    }

    if(month == 3){
            if((year%4==0 && year%100!=0)||(year%4==0 & year%400==0)){
                return 60+day;
            }else{
                return 59+day;
            }
    }
    if(month == 4){
        if((year%4==0 && year%100!=0)||(year%4==0 & year%400==0)){
            return 91+day;
        }else{
            return 90+day;
        }
    }
    if(month == 5){
        if((year%4==0 && year%100!=0)||(year%4==0 & year%400==0)){
            return 121+day;
        }else{
            return 120+day;
        }
    }
    if(month == 6){
        if((year%4==0 && year%100!=0)||(year%4==0 & year%400==0)){
            return 152+day;
        }else{
            return 151+day;
        }
    }
        if(month == 7){
            if((year%4==0 && year%100!=0)||(year%4==0 & year%400==0)){
            return 182+day;
            }else{
            return 181+day;
            }
    }
    if(month == 8){
        if((year%4==0 && year%100!=0)||(year%4==0 & year%400==0)){
            return 213+day;
        }else{
            return 212+day;
        }
    }
    if(month == 9){
        if((year%4==0 && year%100!=0)||(year%4==0 & year%400==0)){
            return 244+day;
        }else{
            return 243+day;
        }
    }
    if(month == 10){
        if((year%4==0 && year%100!=0)||(year%4==0 & year%400==0)){
            return 274+day;
        }else{
        return 273 + day;
        }
        }
    if(month == 11){
        if((year%4==0 && year%100!=0)||(year%4==0 & year%400==0)){
            return 385+day;
        }else{
            return 304 + day;
        }
    }
    if(month == 12){
        if((year%4==0 && year%100!=0)||(year%4==0 & year%400==0)){
            return 335 + day;
        }else{
            return 334 + day;
        }
    }
    else{return 0;}
}

string myDate::dayName(){
    int num = Greg2Julian(month, day, year);
    if(num%7==0){
        return "Monday";
    }
    if(num%7 == 1){
        return "Tuesday";
    }
    if(num%7==2){
        return "Wednesday";
    }
    if(num%7==3){
        return "Thursday";
    }
    if(num%7==4){
        return "Friday";
    }
    if(num%7==5){
        return "Saturday";
    }
    else{
        return "Sunday";
    }
}

struct Student{
    int SID;
    char grade;
    myDate birthDay;
    string homeTown;
    char name[100]; //cstring
};

void populate(Student *s[]){
    for(int i = 0; i<10; i++)
    {
        s[i] = new Student;     //allocate students
    }
    
    char grade[] = {'A', 'B', 'C', 'D', 'F'};
    srand(time(0));
    int randGrade = rand()%5;
    int randSID = rand()%9000 + 1000;   //in the range 1000-9999
    int randMonth = rand()%12 + 1;  //in the range 1-12
    int randDay = rand()%31 + 1;    //in the range 1-31
    int randYear = rand()%6;//in the range 0-6
    randYear+=2000;
    

    myDate randDate(randMonth, randDay, randYear);
    

    s[0]->SID = randSID;
    s[0]->grade = grade[randGrade];
    s[0]->birthDay = randDate;
    s[0]->homeTown = "Oakly";
    strcpy(s[0]->name,"Steve Gold");
    
    //-----------Student 2-------------------//
    randGrade = rand()%5;
    randSID = rand()%9000 + 1000;   //in the range 1000-9999
    randMonth = rand()%12 + 1;  //in the range 1-12
    randDay = rand()%31 + 1;    //in the range 1-31
    randYear = rand()%6;//in the range 0-6
    randYear+=2000;


    myDate randDate2(randMonth, randDay, randYear);


    s[1]->SID = randSID;
    s[1]->grade = grade[randGrade];
    s[1]->birthDay = randDate2;
    s[1]->homeTown = "San Jose";
    strcpy(s[1]->name,"Michael Hannigan");
    

    //-----------Student 3-------------------//
    randGrade = rand()%5;
    randSID = rand()%9000 + 1000;   //in the range 1000-9999
    randMonth = rand()%12 + 1;  //in the range 1-12
    randDay = rand()%31 + 1;    //in the range 1-31
    randYear = rand()%6;//in the range 0-6
    randYear+=2000;


    myDate randDate3(randMonth, randDay, randYear);


    s[2]->SID = randSID;
    s[2]->grade = grade[randGrade];
    s[2]->birthDay = randDate3;
    s[2]->homeTown = "Los Angeles";
    strcpy(s[2]->name,"Chuck Norris");

    //-----------Student 4-------------------//
    randGrade = rand()%5;
    randSID = rand()%9000 + 1000;   //in the range 1000-9999
    randMonth = rand()%12 + 1;  //in the range 1-12
    randDay = rand()%31 + 1;    //in the range 1-31
    randYear = rand()%6;//in the range 0-6
    randYear+=2000;


    myDate randDate4(randMonth, randDay, randYear);


    s[3]->SID = randSID;
    s[3]->grade = grade[randGrade];
    s[3]->birthDay = randDate4;
    s[3]->homeTown = "San Francisco";
    strcpy(s[3]->name,"Steve Jobs");

    //-----------Student 5-------------------//
    randGrade = rand()%5;
    randSID = rand()%9000 + 1000;   //in the range 1000-9999
    randMonth = rand()%12 + 1;  //in the range 1-12
    randDay = rand()%31 + 1;    //in the range 1-31
    randYear = rand()%6;//in the range 0-6
    randYear+=2000;


    myDate randDate5(randMonth, randDay, randYear);


    s[4]->SID = randSID;
    s[4]->grade = grade[randGrade];
    s[4]->birthDay = randDate5;
    s[4]->homeTown = "Queens";
    strcpy(s[4]->name,"Donald Trump");

    //-----------Student 6-------------------//
    randGrade = rand()%5;
    randSID = rand()%9000 + 1000;   //in the range 1000-9999
    randMonth = rand()%12 + 1;  //in the range 1-12
    randDay = rand()%31 + 1;    //in the range 1-31
    randYear = rand()%6;//in the range 0-6
    randYear+=2000;


    myDate randDate6(randMonth, randDay, randYear);


    s[5]->SID = randSID;
    s[5]->grade = grade[randGrade];
    s[5]->birthDay = randDate6;
    s[5]->homeTown = "Can't Remember";
    strcpy(s[5]->name,"Joe Biden");

    //-----------Student 7-------------------//
    randGrade = rand()%5;
    randSID = rand()%9000 + 1000;   //in the range 1000-9999
    randMonth = rand()%12 + 1;  //in the range 1-12
    randDay = rand()%31 + 1;    //in the range 1-31
    randYear = rand()%6;//in the range 0-6
    randYear+=2000;


    myDate randDate7(randMonth, randDay, randYear);


    s[6]->SID = randSID;
    s[6]->grade = grade[randGrade];
    s[6]->birthDay = randDate7;
    s[6]->homeTown = "Chicago";
    strcpy(s[6]->name,"Kanye West");

    //-----------Student 8-------------------//
    randGrade = rand()%5;
    randSID = rand()%9000 + 1000;   //in the range 1000-9999
    randMonth = rand()%12 + 1;  //in the range 1-12
    randDay = rand()%31 + 1;    //in the range 1-31
    randYear = rand()%6;//in the range 0-6
    randYear+=2000;


    myDate randDate8(randMonth, randDay, randYear);


    s[7]->SID = randSID;
    s[7]->grade = grade[randGrade];
    s[7]->birthDay = randDate8;
    s[7]->homeTown = "Akron";
    strcpy(s[7]->name,"LeBron James");

    //-----------Student 9-------------------//
    randGrade = rand()%5;
    randSID = rand()%9000 + 1000;   //in the range 1000-9999
    randMonth = rand()%12 + 1;  //in the range 1-12
    randDay = rand()%31 + 1;    //in the range 1-31
    randYear = rand()%6;//in the range 0-6
    randYear+=2000;


    myDate randDate9(randMonth, randDay, randYear);


    s[8]->SID = randSID;
    s[8]->grade = grade[randGrade];
    s[8]->birthDay = randDate9;
    s[8]->homeTown = "Baltimore";
    strcpy(s[8]->name,"Michael Phelps");

    //-----------Student 10-------------------//
    randGrade = rand()%5;
    randSID = rand()%9000 + 1000;   //in the range 1000-9999
    randMonth = rand()%12 + 1;  //in the range 1-12
    randDay = rand()%31 + 1;    //in the range 1-31
    randYear = rand()%6;//in the range 0-6
    randYear+=2000;


    myDate randDate10(randMonth, randDay, randYear);


    s[9]->SID = randSID;
    s[9]->grade = grade[randGrade];
    s[9]->birthDay = randDate10;
    s[9]->homeTown = "Pamona";
    strcpy(s[9]->name,"Robert Tarjan");
    
}

void display(Student *s[], int size)
{
    const char separator = ' ';
    const int namewidth = 20;
    const int idwidth = 20;
    const int gradewidth = 10;
    const int datewidth = 25;
    cout<< left << setw(namewidth)<< setfill(separator)<<"Name";
    cout<< left << setw(idwidth)<< setfill(separator)<< "Student ID";
    cout << left << setw(gradewidth)<< setfill(separator)<< "Grade";
    cout << left << setw(datewidth)<< setfill(separator)<< "Birthday";
    cout << left << setw(namewidth)<< setfill(separator) << "Home Town";
    cout << endl;
    
    cout<< left << setw(namewidth)<< setfill(separator)<<"----";
    cout<< left << setw(idwidth)<< setfill(separator)<< "----------";
    cout << left << setw(gradewidth)<< setfill(separator)<< "-----";
    cout << left << setw(datewidth)<< setfill(separator)<< "--------";
    cout << left << setw(namewidth)<< setfill(separator) << "---------";
    cout << endl;
    
    
    for(int i = 0; i<size; i++)
    {
        cout<< left << setw(namewidth)<< setfill(separator)<<s[i]->name;
        cout<< left << setw(idwidth)<< setfill(separator)<< s[i]->SID;
        cout << left << setw(gradewidth)<< setfill(separator)<< s[i]->grade;
        cout << left << setw(datewidth)<< setfill(separator)<< s[i]->birthDay.display();
        cout << left << setw(namewidth)<< setfill(separator) << s[i]->homeTown;
        cout << endl;
    }
    cout << endl;
}


void sortByHomeTown(Student *s[]){
    int i,j, size;
    Student * temp;
    
    size = 10;
    
    for(i = 1; i<size; i++){
        
        for(j = 0; j<size-i; j++){
            //cout<<i<<","<<j<<endl;
            if(s[j]->homeTown.compare(s[j+1]->homeTown) > 0){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void sortByBirthday(Student *s[]){
    int i,j, size;
    Student * temp;
    
    size = 10;
    for(i = 1; i<size; i++){
        
        for(j = 0; j<size-i; j++){
        
            if(s[j]->birthDay.daysBetween(s[j+1]->birthDay) < 0){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void sortByGrade(Student *s[]){
    int i,j, size;
    Student * temp;
    
    size = 10;
    for(i = 1; i<size; i++){
        
        for(j = 0; j<size-i; j++){
        
            if(s[j]->grade<s[j+1]->grade){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void sortBySID(Student *s[]){
    int i,j, size;
    Student * temp;
    
    size = 10;
    for(i = 1; i<size; i++){
        
        for(j = 0; j<size-i; j++){
        
            if(s[j]->SID>s[j+1]->SID){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void sortByName(Student *s[]){
    int i,j, size;
    Student * temp;
    
    size = 10;
    for(i = 1; i<size; i++){
        
        for(j = 0; j<size-i; j++){
        
            if(strcmp(s[j]->name,s[j+1]->name)>0){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void displayMenu(){
    cout<<"1) Display list sorted by Name"<<endl;
    cout<<"2) Display list sorted by Student ID"<<endl;
    cout<<"3) Display list sorted by Grade"<<endl;
    cout<<"4) Display list sorted by Birthday"<<endl;
    cout<<"5) Display list sorted by Home Town"<<endl;
    cout<<"6) Exit"<<endl;
}


int main()
{
    const int size = 10;
    Student *myClass[size];
    populate(myClass);
    int input;
    
    for(;;){
        displayMenu();
        cin>>input;
        
        if(input == 1){
            sortByName(myClass);
            display(myClass, size);
            continue;
        }
        
        if(input == 2){
            sortBySID(myClass);
            display(myClass, size);
            continue;
        }
        
        if(input ==3){
            sortByGrade(myClass);
            display(myClass, size);
            continue;
        }
        
        if(input ==4){
            sortByBirthday(myClass);
            display(myClass, size);
            continue;
        }
        
        if(input == 5){
            sortByHomeTown(myClass);
            display(myClass, size);
            continue;
        }
        
        if(input == 6)
            break;
    }
}


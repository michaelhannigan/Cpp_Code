//  Michael Hannigan
//  Class(CeCS 282-04)
//  Project Name(Prog 2 - myDate)
//  Due Date(23/09/2020)
//  I certify that this program is my own original work. I did not copy any part of
//  this program from any other source. I further certify that I typed each and
//  every line of code in this program.
//

#include <math.h>
#include "myDate.hpp"
#include <string>
#include <iostream>
using namespace std;

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

void myDate::display(){
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
    
    cout<<monthName<<" "<<day<<", "<<year;
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

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date{
    string day;
    string month;
    string year;

   public:
   
    // Constructor
    Date(string d = "", string da = "", string y = "")
    {
        setDate(d, da, y);
    }
   
    // Setter
    void setDate(string d = "", string da = "", string y = "")
    {
        day = d;
        month = da;
        year = y;

    }
   
    // Getters
    string getDay()
    {
        return day;
    }
    string getMon()
    {
        return month;
    }
    string getYear()
    {
        return year;
    }
    
    // Insertion Operator
    friend ostream& operator << (ostream& out, const Date& d)
    {
        cout << "(" << d.day << '/' << d.month << '/' << d.year << ')' << endl;
        return out;
    }
    
    // Extraction Operator
    friend istream& operator >> (istream& in, Date& d)
    {
        in >>  d.day >> d.month >> d.year;
        return in;
    }
    
    // Equal Operator for Timelines (true if it is the same day or 1 day before)
    bool operator == (Date d)
    {
        if((day == d.day || stoi(day) - 1 == stoi(d.day)) && month == d.month && year == d.year)
            return true;
        return false;
    }
};

#endif
#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include <string>

using namespace std;

class Activity{
   protected:
    int type;
    string name;

   public:
    
    // Constructor
    Activity(int t = 1, string n = "")
    {
        name = n;
    }  
    
    // Setters
    void setType(int t)
    {
        type = t;
    }  
    void setName(string n = "")
    {
        name = n;
    }
    
    // Getters
    int getType()
    {
        return type;
    }
    string getName()
    {
        return name;
    }

    // Abstract display function
    virtual void display() = 0;

};

// Child classes of Activity (Feeling(1), Thinking(2), Making(3), Celebrating(4))

class Feeling : public Activity{
   
   public:
   
    // Constructor
    Feeling(int t = 1, string n = "") : Activity(t, n){}

    // Insertion Operator
    friend ostream& operator << (ostream& out, const Feeling& f)
    {
        out << "is feeling " << f.name << endl;
        return out;
    }

    // Display function override
    void display()
    {
        cout << *this << endl;
    }
};

class Thinking : public Activity{

   public:

    // Constructor
    Thinking(int t = 1, string n = "") : Activity(t, n){}

    // Insertion Operator
    friend ostream& operator << (ostream& out, const Thinking& f)
    {
        out << "Waiting for " << f.name << endl;
        return out;
    }
    
    // Display function override
    void display()
    {
        cout << *this << endl;
    }
};

class Making : public Activity{

   public:

    // Constructor
    Making(int t = 1, string n = "") : Activity(t, n){}

    // Insertion Operator
    friend ostream& operator << (ostream& out, const Making& f)
    {
        out << "is making " << f.name << endl;
        return out;
    }
    
    // Display function override
    void display()
    {
        cout << *this << endl;
    }
};

class Celebrating : public Activity{

   public:
   
    // Constructor
    Celebrating(int t = 1, string n = "") : Activity(t, n){}

    // Insertion Operator
    friend ostream& operator << (ostream& out, const Celebrating& f)
    {
        out << "is celebrating " << f.name << endl;
        return out;
    }
    
    // Display function override
    void display()
    {
        cout << *this << endl;
    }
};

#endif

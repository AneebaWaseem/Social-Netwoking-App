#ifndef IDENTITY_H
#define IDENTITY_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

class Identity{
   
   protected:
    string id;
    string name;

   public:
   
    // Constructor
    Identity(string id = "", string name = "")
    {
        this->id = id;
        this->name = name;
    }
   
    // Getters
    string getID()
    {
        return id;
    }
    string getName()
    {
        return name;
    }

    // Setters
    void setID(string i)
    {
        id = i;
    }
    void setName(string n)
    {
        name = n;
    }

    // Insertion Operator
    friend ostream& operator << (ostream& out, const Identity& i)
    {
        out << i.id << "\t" << i.name;
    }

    // Extraction Operator
    friend istream& operator >> (istream& in, Identity& i)
    {
        in >> i.id;
        if(i.id[0] == 'u')
        {
            string name1, name2;
            in >> name1 >> name2;
            i.name = name1 + " " + name2;
        }
        else
            getline(in, i.name);
     
        return in;
    }  
};

// Global function to get user and page if ID is given
Identity getUserbyID(string i)
{
    if(i[0] == 'u')
    {
        ifstream in("Users.txt");
        while(!in.eof())
        {
            Identity temp;
            in >> temp;

            string extra;
            int k = 20;
            while(k--)
            {
                in >> extra;
            }
            if(temp.getID() == i)
            {
                in.close();
                return temp;
            }
        }
    }
    else
    {
        ifstream in("Pages.txt");
        while(!in.eof())
        {
            Identity temp;
            in >> temp;
            if(temp.getID() == i)
            {
                in.close();
                return temp;
            }
        }
    }
    
}

#endif
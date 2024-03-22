#ifndef COMMENT_H
#define COMMENT_H

#include "Identity.h"

using namespace std;

class Comment : public Identity{
    string post;
    string description;

   public:
    
    // Constructor
    Comment(string i = "", string n = "", string st = "") : Identity(i, n)
    {
        description = st;
    }

    // Insertion Operator
    friend ostream& operator << (ostream& out, const Comment& c)
    {
        out << c.name << " wrote: \"" << c.description << "\"" << endl;
        return out;
    }

    // Extraction Operator
    friend istream& operator >> (istream& in, Comment& c)
    {
        in >> c.post;
        in >> static_cast<Identity&>(c);
        in.ignore();
        getline(in, c.description);
        return in;
    }

    // Getters
    string getPost()
    {
        return post;
    }
    string getDes()
    {
        return description;
    }
    void setPost(string p)
    {
        post = p;
    }
    void setDes(string d)
    {
        description = d;
    }

};

#endif
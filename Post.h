#ifndef POST_H
#define POST_H

#include "Identity.h"
#include "Activity.h"
#include "Comment.h"
#include "Date.h"

using namespace std;

class Post : public Identity{

    int noOfLikes;
    vector<Identity> likes;
    Identity sharedBy;
    Activity* a;
    Date date;
    vector<Comment> comments;

   public:
    
    // Constructor
    Post(string i = "", string n = "", int no = 0, vector<Identity> l = vector<Identity>(), Identity s = Identity(), string day = "", string month = "", string year = "", vector<Comment> c = vector<Comment>()) : Identity(i, n), date(day, month, year)
    {
        noOfLikes = no;
        likes = l;
        comments = c;
        a = NULL;
    }
    
    // Getters
    Identity getSharedBy()
    {
        return sharedBy;
    }
    vector<Identity> getLiked()
    {
        return likes;
    }
    Date getDate()
    {
        return date;
    }
    Activity* getActivity()
    {
        return a;
    }
    vector<Comment> getComment()
    {
        return comments;
    }

    // Setters
    void setComment(vector<Comment>& c)
    {
        comments = c;
    }
    
    // Insertion Operator
    friend ostream& operator << (ostream& out, Post& p)
    {
        cout << p.sharedBy.getName() << " ";
        if(p.a != NULL)
            p.a->display();
        out << "\"" << p.name << "\"\t" << p.date << endl;

        for(int i=0; i<p.comments.size(); i++)
            out << '\t' << p.comments[i];
        return out;
    }
    
    // Extraction Operator
    friend istream& operator >> (istream& in, Post& p)
    {
        in >> static_cast<Identity&> (p);
        int n;
        in >> p.date;
        in >> n;
        string st;
        if(n)
            getline(in, st);
        if(n == 1)
            p.a = new Feeling(n, st);
        else if(n == 2)
            p.a = new Thinking(n, st);
        else if(n == 3)
            p.a = new Making(n, st);
        else if(n == 4)
            p.a = new Celebrating(n, st);
        string i;
        in >> i;
        Identity s(getUserbyID(i));
        p.sharedBy = s;

        // Getting the likes on post
        string temp;
        in >> temp;
        while(temp != "-1")
        {
            Identity likedPerson;
            likedPerson = getUserbyID(temp);
            p.likes.push_back(likedPerson);
            in >> temp;
        }
        // Getting the comments on post
        ifstream out("Comments.txt");
        while(!out.eof())
        {
            Comment c;
            out >> c;
            if(c.getPost() == p.getID())
                p.comments.push_back(c);
        }
        out.close();
        
        return in;
    }
    
};

#endif
#ifndef USER_H
#define USER_H

#include "Post.h"
#include "Identity.h"

using namespace std;


class User : public Identity{
   
    vector<Identity> friends;
    vector<Identity> pages;
    vector<Post> list;

   public:
    
    // Constructor
    User(string i = "", string n = "", vector<Identity> f = vector<Identity>(), vector<Identity> p = vector<Identity>(), vector<Post> po = vector<Post>()) : Identity(i, n)
    {
        setFriends(f);
        setPages(p);
        list = po;
    }
    
    // Setters
    void setFriends(vector<Identity> f){
        friends = f;
    }
    void setPages(vector<Identity> p){
        pages = p;
    }
    
    // Getters
    vector<Identity> getFriends()
    {
        return friends;
    }
    vector<Identity> getPages()
    {
        return pages;
    }
    vector<Post> getPosts()
    {
        return list;
    }

    // Insertion Operator
    friend ostream& operator << (ostream& out, User& u)
    {
        out << (Identity)u << endl;
        out << "Friend List: " << endl;
        for(int i=0; i<u.friends.size(); i++)
        {
            out << u.friends[i] << endl;
        }
        out << endl;
        out << "Liked Pages: " << endl;
        for(int i=0; i<u.pages.size(); i++)
        {
            out << u.pages[i] << endl;
        }
        out << endl;
        out << "Posts Shared: " << endl;
        for(int i=0; i<u.list.size(); i++)
            out << u.list[i] << endl;
    }

    // Extraction Operator
    friend istream& operator >> (istream& in, User& u)
    {
        in >> static_cast<Identity&>(u);
        string i;

        // Getting friends
        int k = 0;
        while(k < 10)
        {
            in >> i;
            if(i != "-1")
            {
                Identity temp(getUserbyID(i));
                u.friends.push_back(temp);
            }
            k++;
        }

        // Getting Liked Pages
        k = 0;
        while(k < 10)
        {
            in >> i;
            if(i != "-1")
            {
                Identity temporary(getUserbyID(i));
                u.pages.push_back(temporary);
            }
            k++;
        }

        // Getting Posts
        ifstream input("SocialNetworkPosts.txt");
        while(!input.eof())
        {
            Post temp;
            input >> temp;
            string t = (temp.getSharedBy()).getID();
            if(t == u.id)
            {
                u.list.push_back(temp);
            }
        }
        input.close();

        return in;
    }
};

#endif
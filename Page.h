#ifndef PAGE_H
#define PAGE_H

#include "Identity.h"
#include "Post.h"

using namespace std;

class Page : public Identity{

    vector<Post> list;
    vector<Identity> peopleLiked;

   public:
    
    // Constructor
    Page(string i = "", string n = "", vector<Post> l = vector<Post>(), vector<Identity> p = vector<Identity>()) : Identity(i, n)
    {
        list = l;
        peopleLiked = p;
    }

    // Getters
    vector<Post> getPosts()
    {
        return list;
    }
    vector<Identity> getLiked()
    {
        return peopleLiked;
    }
    
    // Setter
    void setLiked(vector<Identity> l)
    {
        peopleLiked = l;
    }
    
    // Insertion Operator
    friend ostream& operator << (ostream& out, Page& p)
    {
        // cout << static_cast<Identity&>(p) << endl;
        cout << (Identity)p << endl;
        cout << "Posts: " << endl;
        for(int i=0; i<p.list.size(); i++)
            out << p.list[i] << endl;
        
        cout << "Liked By: " << endl;
        for(int i=0; i<p.peopleLiked.size(); i++)
            out << p.peopleLiked[i] << endl;
    }

    // Extraction Operator
    friend istream& operator >> (istream& in, Page& p)
    {
        in >> static_cast<Identity&>(p);
 
        // Getting the Posts shared by the Page
        ifstream input("SocialNetworkPosts.txt");
        while(!input.eof())
        {
            Post temp;
            input >> temp;
            string t = (temp.getSharedBy()).getID();
            if(t == p.id)
                p.list.push_back(temp);
        }
        input.close();

        // Getting the users who liked the Page
        ifstream input2("Users.txt");
        while(!input2.eof())
        {
            User u;
            input2 >> u;
            vector<Identity> i = u.getPages();
            for(int x=0; x<i.size(); x++)
            {
                if(i[x].getID() == p.id)
                {
                    p.peopleLiked.push_back((Identity)u);
                    break;
                }
            }
        }
        input2.close();        
        return in;
    }

};

// Show all the Pages
void showPages()
{
    ifstream in("Pages.txt");
    while(!in.eof())
    {
        Identity i;
        in >> i;
        cout << i << endl;
    }
    in.close();
}


#endif 
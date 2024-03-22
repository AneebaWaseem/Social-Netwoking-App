#ifndef POSTMANAGER_H
#define POSTMANAGER_H

#include "Post.h"

class PostManager{
    
    Post *manager;

   public:
   
    // Constructor
    PostManager()
    {
        manager  = NULL;
    }
   
    // Set Post
    void setPost(string id)
    {
        ifstream in("SocialNetworkPosts.txt");
        while(!in.eof())
        {
            Post u;
            in >> u;
            if(u.getID() == id)
            {
                manager = new Post(u);
                break;
            }
        }
        in.close();
    }
    
    // View Post
    void viewPost(string id)
    {
        setPost(id);
        if(manager == NULL)
        {
            cout << "No post found!" << endl;
            return;
        }
        cout << endl;
        cout << *manager << endl;

        free();
    }

    // View List Of Liked People
    void viewLikedList(string id)
    {
        setPost(id);
        if(manager == NULL)
        {
            cout << "No post found!" << endl;
            return;
        }
        cout << id << " - Liked by" << endl;
        vector<Identity>liked = manager->getLiked();
        if(liked.size() == 0)
            cout << "\tNo Likes yet!" << endl;
        for(int i=0; i<liked.size(); i++)
            cout << liked[i] << endl;
        
        free();
    }
    
    void free()
    {
        delete manager;
    }

    // Destructor
    ~PostManager()
    {
        free();
    }
    
};


#endif
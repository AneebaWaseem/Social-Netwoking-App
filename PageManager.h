#ifndef PAGEMANAGER_H
#define PAGEMANAGER_H

#include "Page.h"

class PageManager{
    
    Page *manager;

   public:
   
    // Constructor
    PageManager()
    {
        manager  = NULL;
    }
   
    // Set Page
    void setPage(string id)
    {
        ifstream in("Pages.txt");
        while(!in.eof())
        {
            Page u;
            in >> u;
            if(u.getID() == id)
            {
                manager = new Page(u);
                break;
            }
        }
        in.close();
    }
    
    // View Page
    void viewPage(string id)
    {
        setPage(id);
        if(manager == NULL)
        {
            cout << "No page found!" << endl;
            return;
        }
        cout << endl;
        cout << manager->getName() << " - Timeline" << endl;
        vector<Post>posts = manager->getPosts();
        if(posts.size() == 0)
            cout << "\tNo Posts yet!" << endl;
        for(int i=0; i<posts.size(); i++)
            cout << posts[i] << endl;
        
        free();
    }
   
    // View List Of Liked People
    void viewLikedList(string id)
    {
        setPage(id);
        if(manager == NULL)
        {
            cout << "\tNo page found!" << endl;
            return;
        }
        cout << endl;
        cout << manager->getName() << " - Liked by" << endl;
        vector<Identity>liked(manager->getLiked());
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
    ~PageManager()
    {
        free();
    }
};


#endif
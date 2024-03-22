#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"

class UserManager{
    
    User *manager;

   public:

    // Constructor
    UserManager()
    {
        manager = NULL;
    }
   
    // Set User
    void setUser(string id)
    {
        ifstream in("Users.txt");
        while(!in.eof())
        {
            User u;
            in >> u;
            if(u.getID() == id)
            {
                manager = new User(u);
                break;
            }
        }
        in.close();
        cout << endl << manager->getName() << " is successfully set as Current user" << endl;
    }
    
    // Friend List
    void viewListOfFriends()
    {
        if(manager == NULL)
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
        cout << endl;
        cout << "\t" << manager->getName() << " - Friends List" << endl;
        vector<Identity>friends = manager->getFriends();
        if(friends.size() == 0)
            cout << "\tNo Friends yet!" << endl;
        for(int i=0; i<friends.size(); i++)
            cout << "\t" << friends[i] << endl;
    }
    
    // Liked Pages
    void viewListOfLikedPages()
    {
        if(manager == NULL)
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
        cout << endl;
        cout << "\t" << manager->getName() << " - List of Liked Pages" << endl;
        vector<Identity>pages = manager->getPages();
        if(pages.size() == 0)
            cout << "\tNo Liked Pages yet!" << endl;
        for(int i=0; i<pages.size(); i++)
            cout << "\t" << pages[i] << endl;
    }
    
    // Timeline
    void viewTimeline()
    {
        if(manager == NULL)
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
        
        cout << endl;
        cout << "\t" << manager->getName() << " - Timeline" << endl;
        vector<Post> posts = manager->getPosts();
        if(posts.size() == 0)
            cout << "\tNo Posts yet!" << endl;
        for(int i=0; i<posts.size(); i++)
            cout << posts[i] << endl;
    }

    // Homepage
    void HomePage(Date& date)
    {
        if(manager == NULL)
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
        cout << endl;
        cout << "\t" << manager->getName() << " - Home Page" << endl;
        vector<Identity>friends = manager->getFriends();

        for(int i=0; i<friends.size(); i++)
        {
            ifstream in("SocialNetworkPosts.txt");
            while(!in.eof())
            {
                Post p;
                in >> p;
                if((p.getSharedBy()).getID() == friends[i].getID() && date == p.getDate())
                    cout << p;
            }
            in.close();
        }
    }

    // Add a Friend
    void addFriend(string f)
    {
        if(manager == NULL)
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
        vector<Identity>r =manager->getFriends(); 
        // vector<Identity>f (manager->getFriends());
        if(r.size() < 0)
        {
            fstream in("Users.txt", ios::in | ios::out);
            string i;
            while(!in.eof())
            {
                Identity temp;
                in >> temp;

                string extra;
                if(temp.getID() == manager->getID())
                {
                    streampos p = in.tellg();
                    in >> extra;
                    while(extra != "-1")
                    {
                        p = in.tellg();
                        in >> extra;
                    }
                    in.seekp(p);
                    in << setw(5) << f;
                    cout << "User " << f << " has been successfully added to your friendlist!" << endl;
                    in.close();
                    return;
                }
                else
                {
                    int k = 20;
                    while(k--)
                        in >> extra;
                }
            }
        }
        else
        {
            cout << "You have reached the limit to add a friend!" << endl;
        }
    }

    // Like a Page
    void addPage(string f)
    {
        if(manager == NULL)
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
        
        vector<Identity> p(manager->getPages());
        if(p.size() < 10)
        {
            fstream in("Users.txt", ios::in | ios::out);
            string i;
            while(!in.eof())
            {
                Identity temp;
                in >> temp;

                string extra;
                if(temp.getID() == manager->getID())
                {
                    int t = 10;
                    while(t--)
                        in >> extra;
                    
                    streampos p = in.tellg();
                    in >> extra;
                    while(extra != "-1")
                    {
                        p = in.tellg();
                        in >> extra;
                    }
                    in.seekp(p);
                    in << setw(5) << f;
                    cout << "Page " << f << " has been liked  successfully!" << endl;
                    in.close();
                    return;
                }
                else
                {
                    int k = 20;
                    while(k--)
                        in >> extra;
                }
            }
        }
        else
        {
            cout << "You have reached the limit to like a page!" << endl;
        }
    }

    // Setting post to add comment
    Post SetPost(string id)
    {
        ifstream input("SocialNetworkPosts.txt");
    
        while(!input.eof())
        {
            Post post;
            input >> post;
            
            if(post.getID() == id)
            {
                input.close();
                return post;
            }
        }
    }

    // Add comment
    void addComment(string postID)
    {
        if(manager == NULL)
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
        
        Comment comment;
        string des;

        comment.setID(manager->getID());
        comment.setName(manager->getName());

        cout << "Write your thoughts on the post: ";
        cin.ignore();
        getline(cin , des);
        comment.setPost(postID);
        comment.setDes(des);
        
        Post temp;
        temp = SetPost(postID);
        vector <Comment> com(temp.getComment());

        if(com.size() < 10)
        {
            fstream input("Comments.txt", ios::app);

            input << setw(7) << postID << " ";
            input << setw(5) <<  manager->getID() << "\t";
            input << setw(12) << manager->getName() <<"\t"; 
            input << comment.getDes() << endl;

            cout << "Your comment has been posted successfully!" << endl;
            input.close();
        } 
        else
        {
            cout << "You can't add anymore comments!" << endl;
        }
    }
    
    // Add a post
    void AddPost(Date& d)
    {
        if(manager == NULL)
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
        
        int count = 0;
        ifstream in("SocialNetworkPosts.txt");
        while(!in.eof())
        {
            Post p;
            in >> p;
            count++;
        }
        in.close();

        count++;
        fstream out("SocialNetworkPosts.txt", ios::app);
        char a = (count/10) + '0';
        char b = (count%10) + '0';
        string st = "post";
        out << endl << st << a << b << '\t';

        cout << "Write your thoughts:\t";
        cin.ignore();
        getline(cin, st);
        out << st << endl;
        out << d.getDay() << "\t" << d.getMon() << "\t" << d.getYear() << endl;

        int type;        
        cout << "Enter Activity type: (1 for feeling, 2 for thinking, 3 for making, 4 for celebrating, -1 for no activity)\t";
        cin >> type;
        out << type << '\t';

        if(type != -1)
        {
            cout << "Activity:\t";
            cin.ignore();
            getline(cin, st);
            out << st;
        }
        out << endl;
        
        out << manager->getID() << endl;
        out << "-1";

        out.close();
        cout << "Your post has been added successfully!" << endl;
    }

    // Destructor
    ~UserManager()
    {
        delete manager;
    }
};

#endif
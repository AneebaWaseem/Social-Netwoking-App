#include "Date.h"
#include "UserManager.h"
#include "PageManager.h"
#include "PostManager.h"

using namespace std;

void setDate(Date& date)
{
    // Get the current time
    time_t t = time(nullptr);
    // Convert the current time to a tm structure
    tm* now = localtime(&t);
    // Extract the components of the date
    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;  // Month is 0-based
    int day = now->tm_mday;
    
    date.setDate(to_string(day), to_string(month), to_string(year));
}

void menu ()
{
    cout << endl << endl;
    cout << "-------------------  SOCIAL NETWORKING SYSTEM  -------------------" << endl << endl;
    cout << "\t\t1.\tSet User" << endl << endl;
    cout << "\t\t2.\tMy Friends" << endl << endl;
    cout << "\t\t3.\tMy Liked Pages" << endl << endl;
    cout << "\t\t4.\tMy Timelime" << endl << endl;
    cout << "\t\t5.\tMy Home" << endl << endl;
    cout << "\t\t6.\tAdd Friend" << endl << endl;
    cout << "\t\t7.\tLike a Page" << endl << endl;
    cout << "\t\t8.\tView Post" << endl << endl;
    cout << "\t\t9.\tLikes on Post" << endl << endl;
    cout << "\t\t10.\tAdd Comment" << endl << endl;
    cout << "\t\t11.\tAdd Post" << endl << endl;
    cout << "\t\t12.\tView Page" << endl << endl;
    cout << "\t\t13.\tLikes on Page" << endl << endl;
    cout << "\t\t14.\tExit" << endl << endl;
    cout << "------------------------------------------------------------------" << endl << endl;
    cout << "\tEnter Command No:\t";
}

int main()
{
    int choice;
    Date d;
    setDate(d);
    UserManager user;
    PostManager post;
    PageManager page;
    while(1)
    {
        menu();
        cin >> choice;
        cout << endl;
        if(choice == 1)
        {
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            user.setUser(id);
        }
        else if(choice == 2)
        {
            user.viewListOfFriends();
        }
        else if(choice == 3)
        {
            user.viewListOfLikedPages();
        }
        else if(choice == 4)
        {
            user.viewTimeline();
        }
        else if(choice == 5)
        {
            user.HomePage(d);
        }
        else if(choice == 6)
        {
            cout << "Enter user ID (u1, u2, ... , u20) you want to be friends with:\t";
            string id;
            cin >> id;
            user.addFriend(id);
        }
        else if(choice == 7)
        {
            showPages();
            cout << "Enter page ID (u1, u2, ... , u20) you want to like:\t";
            string id;
            cin >> id;
            user.addPage(id);
        }
        else if(choice == 8)
        {
            cout << "Enter Post ID (post1, post2, ...): ";
            string id;
            cin >> id;
            post.viewPost(id);
        }
        else if(choice == 9)
        {
            cout << "Enter Post ID (post1, post2, ...): ";
            string id;
            cin >> id;
            post.viewLikedList(id);
        }
        else if(choice == 10)
        {
            cout << "Enter Post ID (post1, post2, ...): ";
            string id;
            cin >> id;
            user.addComment(id);
        }
        else if(choice == 11)
        {
            user.AddPost(d);
        }
        else if(choice == 12)
        {
            showPages();
            cout << "Enter the page ID you want to view: ";
            string id;
            cin >> id;
            page.viewPage(id);
        }
        else if(choice == 13)
        {
            cout << "Enter the page ID (p1, p2, ...) you want to view the likes on: ";
            string id;
            cin >> id;
            page.viewLikedList(id);
        }
        else if(choice == 14)
        {
            cout << "Are you sure you want to exit?\t";
            string st;
            cin >> st;
            cout << endl;
            transform(st.begin(), st.end(), st.begin(), ::tolower);
            if(st == "yes")
            {
                cout << "Thanks for using the app! Bye!" << endl << endl;
                break;
            }
        }
    }

    return 0;
}
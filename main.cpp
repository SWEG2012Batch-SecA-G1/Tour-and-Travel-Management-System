#include <iostream>
using namespace std;

const int nums = 100;                   // Max number for the arrays
string admin[2] = {"admin", "admin"};   // admin authentication username and password

struct User
{
    int user_id;        // use the index of the array
    string name;
    string user_name;   // must be unique
    string password;
    int phone_num;
    int point;
}users[100];

struct Place
{
    int place_id;       // is equal to the index of the array
    string name;
    string distance;    //distance from Addis Ababa Review
    string discription; //brief description of the place
    int rating[nums];
    int availability;
}places[nums];

void add_user();            // receives input from user and add the registered user to the array
void display_user();        // displays all the registered users with detail in tabular format
void add_place() // receives input and add the registered place to the array
{
    for (int i=0; i<nums; i++){
        places[i].place_id=i+1;
        cout<<"Location Name: ";
        getline(cin>>ws,places[i].name);
        cout<<"Distance From Addis Ababa: ";
        cin>>places[i].distance;
        cout<<"Location description: ";
        getline(cin>>ws, places[i].discription);
        cout<<"availability: ";
        cin>>places[i].availability;
    }
}

void display_place()    // displays all the registered places with detail in tabular format
{
        cout<<"Location Name \t Distance From Addis Ababa \t Location description \tAvailability \t Rating \n";
    for (int i=0; i<nums; i++){
        cout<<places[i].name<<"\t\t\t"<<places[i].distance<<"\t\t\t\t";
        for(int j=0; j<8; j++){
        cout<<places[i].discription[j];
        }
        if(places[i].discription.length()>8)
        cout<<"...";
        cout<<"\t\t"<<places[i].availability<<endl;
    }
}
void rate_place();          // allows the user to rate a place
void available_place();     // displays all the the available places that have an availability number > 0
int login_user();           // asks the user for login authentication and if it is correct match returns 1 other wise -1
int login_admin();          // asks for admin authentication and if it is correct returns 1 otherwise -1


// asks the user for login authentication and if it is correct match returns 1 other wise -1
int login_user(User *users, const int  nums)
{
    int loginAttempt = 0;
    string userName, userPassword;
    while (loginAttempt < 3)
    {
        cout << "Please enter your user name: "; //user enters user name.
        cin >> userName;
        cout << "Please enter your user password: ";//user enters password.
        cin >> userPassword;

        for (int i; i < nums; i++)//for loop authenticates user names and passwords.
        {
            if (userName == users[i].user_name && userPassword == users[i].password)
            {
                return 1;
                break;
            }
        }
        cout << "Invalid login attempt. Please try again.\n";
        loginAttempt++;

        if (loginAttempt == 3)
        {
                cout << "Too many login attempts!";
                return -1;
                break;
        }
    }
}

// asks for admin authentication and if it is correct returns 1 otherwise -1
int login_admin()
{
    int loginAttempt = 0;
    string adminName, adminPassword;
    while (loginAttempt < 3)
    {
        cout << "Please enter Admin name: "; //admin enters user name.
        cin >> adminName;
        cout << "Please enter Admin password: ";//admin enters password.
        cin >> adminPassword;

        if (adminName == admin[0] && adminPassword == admin[1])
        {
                return 1;
                break;
        }
        cout << "Invalid login attempt. Please try again.\n";
        loginAttempt++;

        if (loginAttempt == 3)
        {
                cout << "Too many login attempts!";
                return -1;
                break;
        }
    }
}

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
void add_place();           // receives input and add the registered place to the array
void display_place();       // displays all the registered places with detail in tabular format
void rate_place();          // allows the user to rate a place
void available_place();     // displays all the the available places that have an availability number > 0
int login_user();           // asks the user for login authentication and if it is correct match returns 1 other wise -1
int login_admin();          // asks for admin authentication and if it is correct returns 1 otherwise -1


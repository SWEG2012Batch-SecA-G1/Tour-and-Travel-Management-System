#include <iostream>
#include<string.h>
#include<conio.h>
#include<Windows.h>
using namespace std;

const int nums = 100;                               // Max number for the arrays
string admin[2] = {"admin", "admin"};               // admin authentication username and password
int loged_in = 0;                                   // the id of the user who logged in
float rates[4] = {0.001, 0.1, 2};                   // discount rates per points, number of people, and cost per distance,
int package_discounts[4] = {0,0.01,0.05,0.1};       // discount for single, couple, family and event packages

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
    float distance;    //distance from Addis Ababa Review
    string discription; //brief description of the place
    int rating[nums];
    int availability;
}places[nums];

void add_user();                        // receives input from user and add the registered user to the array
void display_user();                    // displays all the registered users with detail in tabular format
void add_place();                       // receives input and add the registered place to the array
void display_place(int);                // displays all the registered places with detail in tabular format
void rate_place();                      // allows the user to rate a place
void available_place();                 // displays all the tIhe available places that have an availability number > 0
int login_user();                       // asks the user for login authentication and if it is correct match returns 1 other wise -1
int login_admin();                      // asks for admin authentication and if it is correct returns 1 otherwise -1
int home();                             // home page options
void user_option();                     // options for user after login
void admin_option();                    // options for admin after login
void tour_reservation(Register [nums]); // reserves a tour for the logged in user
void tour_history();                    // filters history of tour registration for the logged in user used the variable loged_in to gets the id of the loged_in user
void profile_of_user();                 // displays a profile of the logged in user
void refill_availability();             // with an option to refill all the places or a given place

int main()
{
    home();
    return (0);
}


int home()
{
    int login = 0;
    int choose;
    cout << "1. register\n";
    cout << "2. login\n";
    cout << "3. admin\n";
    cout << "4. exit\n";
    cout << "choose: ";
    cin >> choose;
    switch(choose)
    {
        case 1:
            system("cls");
            add_user();
            break;
        case 2:
            system("cls");
            login = login_user();
            if (login == 1)
                user_option();
            cout << "closing the app";
            break;
        case 3:
            system("cls");
            login = login_admin();
            if (login == 1)
                admin_option();
        case 4:
            return 0;
            break;
        default:
            cout << "ERROR: input is out of bound";
    }
    return 0;
}

void user_option()
{
    int choose;
    cout << "1. Broucher\n";
    cout << "2. Open spot for each place\n";
    cout << "3. rate place\n";
    cout << "4. back to home\n";
    cout << "choose: ";
    cin >> choose;
    switch(choose)
    {
        case 1:
            system("cls");
            display_place(1);
            break;
        case 2:
            system("cls");
            available_place();
            break;
        case 3:
            system("cls");
            rate_place();
            break;
        case 4:
            system("cls");
            home();
            loged_in = 0;
            break;
        default:
            cout << "ERROR: input is out of bound";
    }

}


void admin_option()
{
    int s=4;
    int choose;
    cout << "1. List all users info\n";
    cout << "2. List all places\n";
    cout << "3. Add place\n";
    cout << "4. home\n";
    cout << "choose: ";
    cin >> choose;
    switch(choose)
    {
        case 1:
            system("cls");
            display_user();
            break;
        case 2:
            system("cls");
            display_place(4);
            break;
        case 3:
            system("cls");
            add_place();
            break;
        case 4:
            system("cls");
            home();
            loged_in = 0;
            break;
        default:
            cout << "ERROR: input is out of bound";
    }

}

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

 void rate_place()
{
    int n, rate;
    string ns;
    display_place(0);
    cout << "choose which country you want to rate: ";
    cin >> n;
    a:cout << "rate from 10 to 1";
    cin >> rate;
    if (rate > 10 && rate < 0)
        goto a;
    if (places[n - 1].rating = 0)
        places[n - 1].rating = rate;
    places[n - 1].rating = (places[n - 1].rating + rate) / 2;
    cout << "press any key to go back";
    getline(cin >> ws, ns);
    system("cls");
    user_option();
}

void available_place()    // displays all the registered places with detail in tabular format
{
    string n;
    int number_of_place;
    for (number_of_place = 0; places[number_of_place].place_id != 0;number_of_place++);
    number_of_place--;
    cout<<"Location Name \t Distance From Addis Ababa \t Location description \tAvailability \t Rating \n";
    for (int i=0; i<number_of_place; i++){
        if (places[i].availability > 0)
        {
            cout<<places[i].name<<"\t\t\t"<<places[i].distance<<"\t\t\t\t";
            for(int j=0; j<8; j++){
            cout<<places[i].discription[j];
            }
            if(places[i].discription.length()>8)
            cout<<"...";
            cout<<"\t\t"<<places[i].availability<<endl;
        }
    }
    cout << "press any key to go back";
    getline(cin >> ws, n);
    system("cls");
    user_option();
}
void add_user()
{
    int i;
    for (i = 0; users[i].user_id != 0;i++);
    cout << "\nEnter your personal information: \n";
    cout << "\nEnter name: ";
    getline(cin >> ws, users[i].name);
    cout << "\nEnter user name: ";
    getline(cin >> ws, users[i].user_name);
    cout << "\nEnter password: ";
    getline (cin >> ws, users[i].password);
    cout<< "\nEnter phone number: ";
    cin >> users[i].phone_num;
    users[i].user_id = i + 1;

    cout << "\n-------------------You are now registered-------------------------\n\n";
    system("cls");
    home();
}

void display_user()
{
    int number_of_user;
    for (number_of_user = 0; users[number_of_user].user_id != 0;number_of_user++);
    number_of_user--;
    string n;
    cout << "Name" << "\t\t|\t" << "User name" << "\t" << "Phone number" << endl;
    cout << "-------------------------------------------------------------------------"<< endl;
    for(int i = 0; i <= number_of_user; i++){
            cout << users[i].name << "\t\t|\t" << users[i].user_name << "\t" << users[i].phone_num << endl;
    }
    cout << "press any key to go back";
    getline(cin >> ws, n);
    system("cls");
    user_option();




#include <iostream>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include <iomanip>
using namespace std;

const int nums = 100;                                     // Max number for the arrays
string admin[2] = {"admin", "admin"};                     // admin authentication username and password
int loged_in = 0;                                         // the id of the user who logged in
float rates[4] = {0.0001, 0.01, 5, 0.1};                  // discount rates per points, number of people, and cost per distance, point per distance
float package_discounts[4] = {0,0.01,0.05,0.1};           // discount for single, couple, family and event packages
string package_names[4] = {"for Single", "for Couple",
                           "for Family", "for Event"};    // Package names;
string times[3] = {"12:00", "3:00", "6:00"};
int monthly[12] = {0};
string months[12] = {"sep", "oct", "nov", "dec", "jan", "feb", "march", "april","may","jun","jul","aug"};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct User
{
    int user_id;        // use the index of the array
    string name;
    string user_name;   // must be unique
    string password;
    char phone_num[10];
    int point=10;
}users[nums];

struct Date
{
    int dd,mm,yy;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Place
{
    int place_id;       // is equal to the index of the array
    string name;
    int distance;       //distance from Addis Ababa Review
    string discription; //location description
    float rating = 0;
    int availability;
    int reg = 0;
}places[nums];
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Register
{
    int book_id;
    int user_id;
    int place_id;
    int package;            // index of the array package_name + 1
    int num_people = 1;     // number of people to travel
    Date date;
    int times;               // index of the time array times_avail + 1
    float cost;
    float discount;
    float final_cost;

}reserved[nums];
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void add_user();                        // receives input from user and add the registered user to the array
void display_user();                    // displays all the registered users with detail in tabular format
void add_place();                       // receives input and add the registered place to the array
void display_place(int);                // displays all the registered places with detail in tabular format
void rate_place();                      // allows the user to rate a place
void available_place();                 // displays all the tIhe available places that have an availability number > 0
int login_user();                       // asks the user for login authentication and if it is correct match returns 1 other wise -1
int login_admin();                      // asks for admin authentication and if it is correct returns 1 otherwise -1
int home();                             // home options
void user_option();                     // options for user after login
void admin_option();                    // options for admin after login
void tour_reservation();                // reserves a tour for the logged in user
int tour_history(int);                  // filters history of tour registration for the logged in user
void profile_of_user();                 // displays a profile of the logged in user
void refill_availability();             // with an option to refill all the places or a given place
void place_filter();                    // gives report of places registration
void total_sales();                     // gives detail of total sales until now
void month_users();                     // gives report of total registration per month
void filter_option();                   // displays an option of reports
void admin_auth();                      // change the password and username of the admin
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    home();
    return (0);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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
            else
            {
                system("cls");
                home();
            }
            break;
        case 3:
            system("cls");
            login = login_admin();
            if (login == 1)
                admin_option();
            else
            {
                system("cls");
                home();
            }
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "ERROR: input is out of bound";
    }
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void user_option()
{
    int choose;
    cout << "1. Broucher\n";
    cout << "2. Open spot for each place\n";
    cout << "3. rate place\n";
    cout << "4. register\n";
    cout << "5. history\n";
    cout << "6. profile\n";
    cout << "7. back to home\n";
    cout << "choose: ";
    cin >> choose;
    switch(choose)
    {
        int a;
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
            tour_reservation();
            break;
        case 5:
            system("cls");
            a = tour_history(0);
            break;
        case 6:
            system("cls");
            profile_of_user();
            break;
        case 7:
            system("cls");
            home();
            loged_in = 0;
            break;
        default:
            cout << "ERROR: input is out of bound";
    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void admin_option()
{
    int s=4;
    int choose;
    cout << "1. List all users info\n";
    cout << "2. List all places\n";
    cout << "3. Add place\n";
    cout << "4. Report\n";
    cout << "5. Change admin authentication\n";
    cout << "6. home\n";
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
            filter_option();
            break;
        case 5:
            system("cls");
            admin_auth();
            break;
        case 6:
            system("cls");
            home();
            loged_in = 0;
            break;
        default:
            cout << "ERROR: input is out of bound";
    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void filter_option()
{
    int login = 0;
    int choose;
    cout << "1. Each month egistration\n";
    cout << "2. Each place registration\n";
    cout << "3. Total sales\n";
    cout << "4. admin\n";
    cout << "choose: ";
    cin >> choose;
    switch(choose)
    {
        case 1:
            system("cls");
            month_users();
            break;
        case 2:
            system("cls");
            place_filter();
            cout << "closing the app";
            break;
        case 3:
            system("cls");
            total_sales();
            break;
        case 4:
            system("cls");
            admin_option();
            break;
        default:
            cout << "ERROR: input is out of bound";
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void add_place() // receives input and add the registered place to the array
{
    int i, num_places, origin;
    for (i = 0; places[i].place_id != 0;i++);
    origin = i;
    cout << "how many places do you want to add: ";
    cin >> num_places;
    while (i < origin + num_places)
    {
        places[i].place_id=i+1;
        F:cout<<"Location Name: ";
        getline(cin>>ws,places[i].name);
        for (int j = 0; j < nums; j++)
        {
        if (places[i].name == places[i - 1].name)
        {
            cout << "The place is already registered." << endl;
            goto F;
        }
        }
        cout<<"Distance From Addis Ababa: ";
        cin>>places[i].distance;
        cout<<"Location description: ";
        getline(cin>>ws, places[i].discription);
        cout<<"availability: ";
        cin>>places[i].availability;
        i++;
    }
    cout << "\n-------------------place have been successfully added-------------------------\n\n";
    system("cls");
    admin_option();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display_place(int n)    // displays all the registered places with detail in tabular format
{
    int number_of_place;
    string ns;
    for (number_of_place = 0; places[number_of_place].place_id != 0;number_of_place++);
    number_of_place--;
    cout << " ---------------------------------------------------------------------------------------------------------------\n";
    cout << "| "
         << left << setw(7) << "ID" << "| "
         << left << setw(18)<< "Location Name" << "| "
         << left << setw(22)<< "Distance from Addis" << "| "
         << left << setw(23)<< "Location Description" << "| "
         << left << setw(17) << "Availability" << "| "
         << left << setw(12) << "Ratings" << " | " << endl;
    cout << " ---------------------------------------------------------------------------------------------------------------\n";
    for (int i=0; i<=number_of_place; i++)
    {
        cout<< "| "
            <<left << setw(7)  << places[i].place_id << "| "
            <<left << setw(18) <<places[i].name << "| "
            <<left << setw(22) <<places[i].distance << "| ";
        cout<<left << setw(23) << places[i].discription << "| ";
//        if(places[i].discription.length()>8)
//            cout<<"...";
        cout<<left<< setw(17)<< places[i].availability << "| "
            << left << setw(12)  << places[i].rating  << " | " <<endl;
    }
    cout << " ---------------------------------------------------------------------------------------------------------------\n";
    if (n == 0)
        return;
    else if (n == 1)
    {
        cout << "press any key to go back";
        getline(cin >> ws, ns);
        system("cls");
        user_option();
    }
    else
    {
        cout << "press any key to go back";
        getline(cin >> ws, ns);
        system("cls");
        admin_option();
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void available_place()    // displays all the registered places with detail in tabular format
{
    int number_of_place;
    string n;
    for (number_of_place = 0; places[number_of_place].place_id != 0;number_of_place++);
    number_of_place--;
    cout << "\t\t\t\t\t\t Available places\n";
    cout << " ---------------------------------------------------------------------------------------------------------------\n";
    cout << "| "
         << left << setw(7) << "ID" << "| "
         << left << setw(18)<< "Location Name" << "| "
         << left << setw(22)<< "Distance from Addis" << "| "
         << left << setw(23)<< "Location Description" << "| "
         << left << setw(17) << "Availability" << "| "
         << left << setw(12) << "Ratings" << " | " << endl;
    cout << " ---------------------------------------------------------------------------------------------------------------\n";
    for (int i=0; i<=number_of_place; i++)
    {
        if (places[i].availability > 0)
        {
            cout<< "| "
                <<left << setw(7)  << places[i].place_id << "| "
                <<left << setw(18) <<places[i].name << "| "
                <<left << setw(22) <<places[i].distance << "| ";
            cout<<left << setw(23) << places[i].discription << "| ";
            cout<<left<< setw(17)<< places[i].availability << "| "
                << left << setw(12)  << places[i].rating  << " | " <<endl;
        }
    }
    cout << " ---------------------------------------------------------------------------------------------------------------\n";
    cout << "press any key to go back";
    getline(cin >> ws, n);
    system("cls");
    user_option();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tour_reservation()
{
    int i, pack, index, place_index;
    for (i = 0; reserved[i].user_id != 0;i++);
    reserved[i].user_id = loged_in;
    display_place(0);
    E:cout << "\n\nWhere do you want to go? " << endl;
    cout << "Enter the place id: ";
    cin >> place_index;
    place_index--;
    places[place_index].reg += 1;
    system("cls");
    if(places[place_index].availability < 1){
        int ch;
        cout << "Sorry we have no seats available please choose another place" << endl;
        G:cout << "if you want to return back to home press 1, else if you want to choose another place press 2: ";
        cin >> ch;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void profile_of_user()
{
    string n;
    for (int i = 0; i < 85; i++)
    {   cout << "-";
    }
    cout<<endl;
    cout << "|" << left << setw(25) << "Name" << "|"
         << left << setw(28) << "Username" << "|"
         << left << setw(17) << "Phone Number" << "|"
         << left << setw(10) << "Point" << "|" << endl;
    for (int i = 0; i < 85; i++)
    {   cout << "-";
    }
    cout << endl;
    cout << "|" << left << setw(25) << users[loged_in-1].name << "|"
         << left << setw(28) << users[loged_in-1].user_name << "|"
         << left << setw(17) << users[loged_in-1].phone_num << "|"
         << left << setw(10) << users[loged_in-1].point << "|" << endl;
    for (int i = 0; i < 85; i++)
    {   cout << "-";
    }
    cout << "\npress any key to go back";
    getline(cin >> ws, n);
    system("cls");
    user_option();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int tour_history(int d=0)
{
    int reserves, counts = 0;
    string n;
    for (int i = 0; i < 117; i++)
    {   cout << "-";
    }
    cout << endl;
    cout << "|" << left << setw(15) << "Place" << "|"
         << left << setw(12) << "Package" << "|"
         << left << setw(21) << "Number of People" << "|"
         << left << setw(13) << "Date" << "|"
         << left << setw(14) << "Time" << "|"
         << left << setw(9) << "Cost"<< "|"
         << left << setw(13) << "Discount" << "|"
         << left << setw(11) << "Final Cost" << "|" << endl;
    for (int i = 0; i < 117; i++)
    {   cout << "-";
    }
    cout << endl;
    for (reserves = 0; reserved[reserves].user_id != 0; reserves++);
    reserves--;

    for(int i=0; i<=reserves; i++){
        if(reserved[i].user_id==loged_in)
        {
            counts++;
            int place_id = reserved[i].place_id - 1;
            cout << "|" << left << setw(15) << places[place_id].name << "|"
                 << left<< setw(12) << package_names[reserved[i].package] << "|"
                 << left << setw(21) << reserved[i].num_people << "|"
                 << left << setw (2) << reserved[i].date.mm<<"/"<< setw(2) << reserved[i].date.dd<<"/"<< setw(7) << reserved[i].date.yy << "|"
                 << left << setw(14) << times[reserved[i].times] << "|"
                 << left << setw(9) << reserved[i].cost << "|"
                 << left << setw(13) << reserved[i].discount << "|"
                 << left << setw(11) << reserved[i].final_cost << "|" << endl;
        }
    }
    for (int i = 0; i < 117; i++)
    {
        cout << "-";
    }
    cout << endl;
    if (d == 1)
        return counts;
    else
    {
        cout << "press any key to go back";
        getline(cin >> ws, n);
        system("cls");
        user_option();
        return counts;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void place_filter()
{
    string n;
    cout << endl << "Place Name" << "\t\t\t" <<  "reserved seats" << endl;
    cout << "------------------------------------------------------------------------"<< endl;
    int number_of_place;
    for (number_of_place = 0; places[number_of_place].place_id != 0;number_of_place++);
    number_of_place--;
    for (int i=0; i<=number_of_place; i++)
    {
        cout<<places[i].name<<"\t\t\t"<<places[i].reg<<endl;
    }
    cout << "press any key to go back";
    getline(cin >> ws, n);
    system("cls");
    filter_option();
}

void month_users(){
    string n;
    for(int i=0; i<100; i++){
            int index;
            index = reserved[i].date.mm;
            if (index != 0)
                monthly[index - 1]++;
    }
    cout << endl << "month" << "\t\t\t" << "total travels" <<endl;
    cout << "------------------------------------------------------------------"<< endl;
    for(int i=0; i<12; i++){
        cout << months[i] << "\t\t\t" << monthly[i] << endl;
    }
        cout << "press any key to go back";
    getline(cin >> ws, n);
    system("cls");
    filter_option();
}

void total_sales()
{
    int reserves;
    for (reserves = 0; reserved[reserves].user_id != 0; reserves++);
    string n;
    float cost = 0;
    cout << endl << "month" << "\t\t\t" << "total travels" <<endl;
    cout << "------------------------------------------------------------------"<< endl;

    for(int i=0; i<100; i++){
        cost += reserved[i].final_cost;
    }
    cout << " Total number of sales: " << reserves;
    cout << "\n The income from sales: " << cost << endl;
    cout << " The profit is: " << cost * 0.2 << endl << endl << endl;
    cout << "press any key to go back";
    getline(cin >> ws, n);
    system("cls");
    filter_option();
}


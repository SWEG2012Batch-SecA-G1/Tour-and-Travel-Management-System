#include <iostream>
#include<string.h>
#include<Windows.h>
#include <iomanip>
#include <fstream>

using namespace std;



const int nums = 100;                                               // Max number for the arrays
string admin[2] = {"admin", "admin"};                               // admin authentication username and password
int loged_in = 0;                                                   // the id of the user who logged in
float rates[4] = {0.000001, 0.001, 5, 0.01};                        // discount rates per points, number of people, and cost per distance, point per distance
float package_discounts[4] = {0,0.001,0.005,0.01};                  // discount for single, couple, family and event packages
//int ranked[100] = {0};
string package_names[4] = {"for Single", "for Couple",
                           "for Family", "for Event"};              // Package names;
string times[3] = {"12:00", "3:00", "6:00"};                        // available time per day
int monthly[12] = {0};                                              // an Array to save monthly records
string months[12] = {"sep", "oct", "nov", "dec", "jan", "feb",      // an array of months name form 0-11 index
                     "march", "april","may","jun","jul","aug"};

// Sturctrure user
struct User
{
    int user_id;            // use the index of the array
    string name;
    string user_name;       // must be unique
    string password;
    char phone_num[10];
    int point=10;
}users[nums];


// Structure for Date
struct Date
{
    int dd,mm,yy;
};



// Structure for Place
struct Place
{
    int place_id;          // is equal to the index of the array
    string name;
    int distance;          //distance from Addis Ababa Review
    string discription;    //location description
    float rating = 0;
    int availability;
    int reg = 0;
}places[nums];



// Structure for Register
struct Register
{
    int book_id;
    int user_id;
    int place_id;
    int package;             // index of the array package_name + 1
    int num_people = 1;      // number of people to travel
    Date date;
    int times;               // index of the time array times_avail + 1
    float cost;
    float discount;
    float final_cost;

}reserved[nums];



void add_user();                        // receives input from user and add the registered user to the array
void display_user();                    // displays all the registered users with detail in tabular format
void add_place();                       // receives input and add the registered place to the array
void display_place(int);                // displays all the registered places with detail in tabular format
void rate_place();                      // allows the user to rate a place
void available_place();                 // displays all the the available places that have an availability number > 0
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
void rank_place();                      // arranges places according to their rankin
void display_ranked();                  // displays ranked places based on rating
void read_place();                      // reads places from a file and save on a structure
void save_place();                      // saves the place to a file place.txt
void save_user();                       // saves the user to a file user.txt
void read_user();                       // reads users from a file and save on a structure
void save_reg();                        // saves the registrations to a file registrations.txt
void read_reg();                        // reads registrations from a file and save on a structure
void search_user();                     // searches user from the available list
void search_place();                    // searches place from the available list
void edit_user();                       // edits user details
void edit_place();                      // edits place details
void delete_user();                     // delete user and its all related data's
int all_tour();                         // displays all related data's
void delete_reg();                      // delete a reserved regestration
template <typename T>
void Tswap(T &var1, T &var2);            // A template function to swap any type of variable



template <typename T>
void Tswap(T &var1, T &var2)
{
    T temp = var1;
    var1 = var2;
    var2 = temp;
}

// the main function to be run
int main()
{
    read_reg();
    read_place();
    read_user();
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

void user_option()
{
    int choose;
    cout << "1. Broucher\n";
    cout << "2. Ranked by rating\n";
    cout << "3. Open spot for each place\n";
    cout << "4. rate place\n";
    cout << "5. register\n";
    cout << "6. delete registeration\n";
    cout << "7. history\n";
    cout << "8. profile\n";
    cout << "9. Delete your profile\n";
    cout << "10. Search place by name\n";
    cout << "11. Edit your profile\n";
    cout << "12. back to home\n";
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
            display_ranked();
            break;
        case 3:
            system("cls");
            available_place();
            break;
        case 4:
            system("cls");
            rate_place();
            break;
        case 5:
            system("cls");
            tour_reservation();
            break;
        case 6:
            system("cls");
            delete_reg();
            break;
        case 7:
            system("cls");
            a = tour_history(0);
            break;
        case 8:
            system("cls");
            profile_of_user();
            break;
        case 9:
            system("cls");
            delete_user();
            break;
        case 10:
            system("cls");
            search_place();
            break;
        case 11:
            system("cls");
            edit_user();
            break;
        case 12:
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
    cout << "4. Edit places\n";
    cout << "5. All reserved tours list\n";
    cout << "6. Search user\n";
    cout << "7. Report\n";
    cout << "8. Change admin authentication\n";
    cout << "9. home\n";
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
            edit_place();
            break;
        case 5:
            system("cls");
            all_tour();
            break;
        case 6:
            system("cls");
            search_user();
            break;
        case 7:
            system("cls");
            filter_option();
            break;
        case 8:
            system("cls");
            admin_auth();
            break;
        case 9:
            system("cls");
            home();
            loged_in = 0;
            break;
        default:
            cout << "ERROR: input is out of bound";
    }
}

void rate_place()
{
    int n, rate, counts;
    string ns;
    counts = tour_history(1);
    if (counts == 0)
    {
        system("cls");
        cout << " you haven't visited any place yet \n";
        cout << "going back....";
        Sleep(1000);
        system("cls");
        user_option();
    }
    cout << "choose which country you want to rate: ";
    cin >> n;
    a:cout << "rate from 1 to 5";
    cin >> rate;
    if (rate > 5 && rate < 0)
        goto a;
    if (places[n - 1].rating == 0)
        places[n - 1].rating = rate;
    else
        places[n - 1].rating = (places[n - 1].rating + rate) / 2;
    cout << "press any key to go back";
    getline(cin >> ws, ns);
    system("cls");
    save_place();
    user_option();
}


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

void add_user()
{
    int i;
    for (i = 0; users[i].user_id != 0;i++);
    cout << "\nEnter your personal information: \n";
    cout << "\nEnter name: ";
    getline(cin >> ws, users[i].name);
    c:cout << "\nEnter user name: ";
    getline(cin >> ws, users[i].user_name);
    for (int j = 0; j < nums; j++)
    {
        if (users[i].user_name == users[i - 1].user_name)
        {
            cout<< "This username is taken please choose another one? ";
            goto c;
        }
    }
    cout << "\nEnter password: ";
    getline (cin >> ws, users[i].password);
    X: cout<< "\nEnter phone number: ";
    cin >> users[i].phone_num;
    for (int j = 0; j < 10; j++)
    {
        if(!(isdigit(users[i].phone_num[j])) || users[i].phone_num[10])
        {
            cout << "Invalid phone number please try again!" << endl;
            goto X;
        }

    }
    users[i].user_id = i + 1;
    save_user();
    read_user();
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
    cout << " ------------------------------------------------------------- "<< endl;
    cout << "| "
         << left << setw(20) << "Name" << "| "
         << left << setw(20) << "User name" << "| "
         << left << setw(15) << "Phone number" << "| " << endl;
    cout << " ------------------------------------------------------------- "<< endl;
    for(int i = 0; i <= number_of_user; i++){
            cout << "| "
                 << left << setw(20) << users[i].name << "| "
                 << left << setw(20) << users[i].user_name << "| "
                 << left << setw(15) << users[i].phone_num << "| " << endl;
    }
    cout << " ------------------------------------------------------------- "<< endl;

    cout << "press any key to go back";
    getline(cin >> ws, n);
    system("cls");
    admin_option();
}


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
    save_place();
    read_place();
    cout << "\n-------------------place have been successfully added-------------------------\n\n";
    system("cls");
    admin_option();
}

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


int login_user()
{
    int loginAttempt = 0;
    string userName, userPassword;
    while (loginAttempt < 3)
    {
        cout << "Please enter your user name: "; //user enters user name.
        cin >> userName;
        cout << "Please enter your user password: ";//user enters password.
        cin >> userPassword;

        for (int i = 0; i < nums; i++)//for loop authenticates user names and passwords.
        {
            if (userName == users[i].user_name && userPassword == users[i].password)
            {
                system("cls");
                loged_in = users[i].user_id;
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
    return 0;
}

// asks for admin authentication and if it is correct returns 1 otherwise -1
int login_admin()
{
    int loginAttempt = 0;
    string adminName, adminPassword;
    while (loginAttempt < 3)
    {
        cout << "Please enter Admin username (default = admin): "; //admin enters user name.
        cin >> adminName;
        cout << "Please enter Admin password (default = admin): ";//admin enters password.
        cin >> adminPassword;

        if (adminName == admin[0] && adminPassword == admin[1])
        {
                system("cls");
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
    return -1;
}


void tour_reservation()
{
    int i, pack, index, place_index;
    for (i = 0; reserved[i].user_id != 0;i++);
    reserved[i].user_id = loged_in;
    display_place(0);
    reserved[i].book_id = i+1;
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
        switch(ch)
        {
        case 1:
            user_option();
            break;
        case 2:
            goto E;
            break;
        default:
            cout << "Invalid input please try again" << endl;
            goto G;
        }
    }
    reserved[i].place_id = places[place_index].place_id;
    cout << " you chose " << places[place_index].name <<endl;
    reserved[i].cost = 2 * places[place_index].distance;
    places[place_index].availability--;

    cout << "Packages" << endl;
    B:cout << "1. One Person only (No discount)\n";
    cout <<"2. Couples package (0.1% discount) \n3. Family package (0.5% discount)(three and above) \n4. Event or Organizational package (1% discount)(10 and above)" << endl;
    cout <<"Choose package: ";
    cin >> pack;
    if (!(pack >= 1 && pack <= 4))
    {
        cout << "Invalid input please try again";
        goto B;
    }
    reserved[i].package = pack;
    index = reserved[i].package - 1;
    if (index != 0)
    {
        if (index == 1)
            reserved[i].num_people = 2;
        else
        {
            system("cls");
            cout << "how many people are with you: ";
            cin >> reserved[i].num_people;
        }
    }
    reserved[i].cost = (rates[2] * places[place_index].distance) * reserved[i].num_people;
    reserved[i].discount = (reserved[i].cost * (rates[1] * users[loged_in - 1].point)) +        //discount by the point of the user
                            (reserved[i].cost * package_discounts[reserved[i].package] )+       //discount by the package they chose
                            (reserved[i].cost * (reserved[i].num_people * rates[0]));           //discount by the the number of people they are bringing

    reserved[i].final_cost = reserved[i].cost - reserved[i].discount;
    system("cls");
    s:cout << "choose a day in Ethiopian calendar (dd mm yy) use this format: ";
    cin >> reserved[i].date.dd>> reserved[i].date.mm >> reserved[i].date.yy;
    if (!(reserved[i].date.mm > 0 && reserved[i].date.mm < 14))
    {
        if (reserved[i].date.mm == 13 && !(reserved[i].date.dd > 0 && reserved[i].date.dd < 6))
        {
            cout << "\n!!! ERROR: puagme have only five days\n";
            goto s;
        }
        if (!(reserved[i].date.dd > 0 && reserved[i].date.dd < 31))
        {
            if (!(reserved[i].date.yy < 2012 && reserved[i].date.yy > 2015))
            {
                cout << "\n!!! ERROR: year out of range\n";
                goto s;
            }
            cout << "\n!!! ERROR: month is out of range\n";
            goto s;
        }
        cout << "\n!!! ERROR: out of bound month\n";
        goto s;
    }
    system("cls");

    A:cout << "Time" << endl;
    cout << "1. for 6 am (12:00 local time) \n2. for 9 am (3:00 local time)" ;
    cout << "\n3. for 12pm (6:00 local time) \n" << endl;
    cout << "Choose at what time you want to go: ";
    cin >> reserved[i].times;
    users[loged_in - 1].point += (places[place_index].distance * rates[3]);
    if (!(reserved[i].times < 4 && reserved[i].times > 0))
    {
        cout << "Invalid input please try again!";
        goto A;
    }
    reserved[i].times--;
    system("cls");
    cout << "\n Your choices \n";
    cout << "Place: " << places[place_index].name << endl
         << "Package: " << reserved[i].package << endl
         << "Date: " << reserved[i].date.dd << "\\" << reserved[i].date.mm  << "\\" << reserved[i].date.yy << endl
         << "Time: " << times[reserved[i].times] << endl
         << "Cost: " << reserved[i].cost << endl
         << "Discount in package, point of user, number of people: " << reserved[i].discount << endl
         << "Final cost: " << reserved[i].final_cost << endl;
    cout << "\n\n Are you sure you want to continue(Y/N): ";
    char chois;
    cin >> chois;
    if (chois == 'Y' || chois == 'y')
    {
    save_reg();
    read_reg();
    save_place();
    save_user();
    cout << "-------------------------- You have successfully reserved your seat----------------------------";
    Sleep(700);
    system("cls");
    user_option();
    }
    else
    {
            reserved[i].user_id = 0;
            places[place_index].reg -= 1;
            places[place_index].availability++;
            reserved[i].cost = 0;
            cout << "-------------------------- Rolled back: Thanks for being here ----------------------------";
            Sleep(1200);
            system("cls");
            user_option();

    }


    cout << "\n-------------------Reservation have been successfully added-------------------------\n\n";
    system("cls");
    admin_option();

}

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
    int year = 0, s;
    cout << "1. all registrations until now\n";
    cout << "2. specific year\n";
    cout << "choose: ";
    cin >> s;
    if (s == 2){
    cout << "\nEnter the year you want to get report too: ";
    cin >> year;
    }
    for(int i=0; i<100; i++){

            if (year == reserved[i].date.yy || s == 1)
            {
                int index;
                index = reserved[i].date.mm;
                if (index != 0)
                    monthly[index - 1]++;
            }
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

int tour_history(int d=0)
{
    int reserves, counts = 0;
    string n;
    for (int i = 0; i < 117; i++)
    {   cout << "-";
    }
    cout << endl;
    cout << "|" << left << setw(7) << "Book_Id" << "|"
         << left << setw(7) << "Place_Id" << "|"
         << left << setw(15) << "Place" << "|"
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
            cout << "|" << left << setw(7) << reserved[i].book_id << "|"
                 << left << setw(7) << reserved[i].place_id << "|"
                 << left << setw(15) << places[place_id].name << "|"
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

void admin_auth()
{
    cout << "Set Admin username: ";
    cin >> admin[0];
    cout << "Set Admin password: ";
    cin >> admin[1];
    cout << "------------------------"
         << "YOUR PASSWORD AND USERNAME"
         << "HAVE BEEN SUCCESSFULLY SET"
         << " -------------------------";
    Sleep(1000);
    system("cls");
    admin_option();
}

void rank_place()
{
    int  place_holder;
    bool flag = true;
    int number_of_place;
    string ns;
    for (number_of_place = 0; places[number_of_place].place_id != 0;number_of_place++){
//        ranked[number_of_place] = 0;
    }
    Place temp;
    number_of_place--;
    for (int i=0; i<=number_of_place; i++)
    {
        for (int j=0; j <= number_of_place - 1 - i; j++)
        {
            if (places[j].rating < places[j + 1].rating)
            {
                Tswap(places[j], places[j+1]);
            }
        }
    }
    //save_place();

}

void display_ranked()    // displays all the registered places with detail in tabular format
{
    rank_place();
    string n;
    int number_of_place;
    for (number_of_place = 0; places[number_of_place].place_id != 0;number_of_place++);
    number_of_place--;
    cout << " ----------------------------------------------\n";
    cout << "| "
         << left << setw(7) << "Rank" << "| "
         << left << setw(18)<< "Location Name" << "| "
         << left << setw(12) << "Ratings" << " | " << endl;
    cout << " --------------------------------------------------\n";
    for (int i=0; i<=number_of_place; i++)
    {

        cout<< "| "
            <<left << setw(7)  << i + 1 << "| "
            <<left << setw(18) <<places[i].name << "| "
            << left << setw(12)  << places[i].rating  << " | " <<endl;
    }
    cout << " ----------------------------------------------\n";
    cout << "\n\npress any key to go back";
    getline(cin >> ws, n);
    system("cls");
    user_option();
}


string ReplaceString(string text, const string& searchs, const string& replaces)
{
    int pos = 0;
    while ((pos = text.find(searchs, pos)) != std::string::npos)
    {
        text.replace(pos, searchs.length(), replaces);
        pos += replaces.length();
    }
    return text;
}



void save_place()
{
    cout << "-----------------------------------  Saving Places ------------------------------------";
    ofstream place("place.txt");
    int number_of_place;
    for (number_of_place = 0; places[number_of_place].place_id != 0;number_of_place++);
    number_of_place--;
    for (int i = 0; i <= number_of_place; i++)
    {
        string name = ReplaceString(places[i].name, " ", "_");
        string discr = ReplaceString(places[i].discription, " ", "_");
        place << places[i].place_id << " " << name << " " << places[i].distance << " "
              << discr << " " << places[i].availability << " " << places[i].rating << " " << places[i].reg << "\n";
    }
    place.close();
}

void read_place()
{
    cout << "-----------------------------------  Saving Places ------------------------------------\n";
    // opening a file
    ifstream read_place("place.txt");
    if (!read_place.is_open())
    {
        return;
    }
    int i = 0;
    while(!read_place.eof()){
        string name;
        string discr;
        read_place >> places[i].place_id >> name >> places[i].distance >>
                 discr >> places[i].availability >> places[i].rating >> places[i].reg;

        places[i].name = ReplaceString(name, "_", " ");
        places[i].discription = ReplaceString(discr, "_", " ");

        i++;
    }
    //closing a file
    read_place.close();

}


void save_user()
{
    cout << "-----------------------------------  Saving Places ------------------------------------";
    // opening a file
    ofstream save_user("user.txt");
    if(save_user.is_open())
    {

    int us;

    for (us = 0; users[us].user_id != 0;us++);
    us--;
        for (int i = 0; i <= us; i++)
    {
        string name = ReplaceString(users[i].name, " ", "_");
        string username = ReplaceString(users[i].user_name, " ", "_");
        string password = ReplaceString(users[i].password, " ", "_");
        save_user << users[i].user_id << " " << name << " " << username <<  " " << password << " " << users[i].phone_num << " "
              << users[i].point << "\n";
    }
    } else {
    cout<<"ERROR!!!!!";
    }
    //closing a file
    save_user.close();
}

void read_user()
{
    // opening a file
    ifstream read_user("user.txt");
    if (!read_user.is_open())
    {
        return;
    }
    int i = 0;

    while(!read_user.eof()){
        string name;
        string username;
        string password;
        read_user >> users[i].user_id >> name >> username >> password >> users[i].phone_num >>
              users[i].point;
        users[i].name = ReplaceString(name, "_", " ");
        users[i].user_name = ReplaceString(username, "_", " ");
        users[i].password = ReplaceString(password, "_", " ");
        i++;
    }
    //closing a file
    read_user.close();
}


void delete_user()
{
    int id, line;
    id = loged_in;
    ifstream iread_user("user.txt");
    if (!iread_user.is_open())
    {
        return;
    }
    ofstream oread_user("n_user.txt");
    int i = 0;
    while(!iread_user.eof()){

                string name = ReplaceString(users[i].name, " ", "_");
        string username = ReplaceString(users[i].user_name, " ", "_");
        string password = ReplaceString(users[i].password, " ", "_");

              iread_user >> users[i].user_id >> name >> username >> password >> users[i].phone_num >>
              users[i].point;

        if(users[i].user_id != id){



            oread_user << users[i].user_id << " " << name << " " << username << " " << password <<" " << users[i].phone_num << " " <<
              users[i].point<< "\n";


        }
        i++;
    }
    //closing a file
    iread_user.close();
    oread_user.close();

remove("user.txt");

rename("n_user.txt", "user.txt");
    string n;
    cout << " -------------------------  YOUR ACCOUNT HAVE BEEN SUCCESSFULLY DELETED ---------------------\n";
    cout << "\n\npress any key to go back: ";
    getline(cin >> ws, n);
    system("cls");
    home();
}



void save_reg()
{
    cout << "-----------------------------------  Saving Reservation ------------------------------------";
    // opening a file
    ofstream save_reg("reservation.txt");
    if(save_reg.is_open())
    {

    int us;

    for (us = 0; reserved[us].user_id != 0;us++);
    us--;
        for (int i = 0; i <= us; i++)
    {

        save_reg << reserved[i].book_id << " " << reserved[i].user_id << " " << reserved[i].place_id << " " << reserved[i].package << " " << reserved[i].num_people << " "
        << reserved[i].date.dd <<" "<< reserved[i].date.mm <<" "<< reserved[i].date.yy << " " << reserved[i].times << " " << reserved[i].cost << " " << reserved[i].discount << " " << reserved[i].final_cost << "\n";

    }
    } else {
    cout<<"ERROR!!!!!";
    }
    //closing a file
    save_reg.close();
}


void read_reg()
{
    // opening a file
    ifstream read_reg("reservation.txt");
    if (!read_reg.is_open())
    {
        return;
    }
    int i = 0;

    while(!read_reg.eof()){

        read_reg >> reserved[i].book_id >> reserved[i].user_id >> reserved[i].place_id >> reserved[i].package >> reserved[i].num_people
        >>reserved[i].date.dd >> reserved[i].date.mm >> reserved[i].date.yy >> reserved[i].times >> reserved[i].cost >> reserved[i].discount >> reserved[i].final_cost;

        i++;
    }
    //closing a file
    read_reg.close();

}

void delete_reg()
{
    int id, line;
    cout<<"Delete by ID: ";
    cin>>id;
    ifstream iread_reg("reservation.txt");
    if (!iread_reg.is_open())
    {
        return;
    }
    ofstream oread_reg("n_reservation.txt");
    int i = 0;

    while(!iread_reg.eof()){
        iread_reg >> reserved[i].book_id >> reserved[i].user_id >> reserved[i].place_id >> reserved[i].package >> reserved[i].num_people
        >>reserved[i].date.dd >> reserved[i].date.mm >> reserved[i].date.yy >> reserved[i].times >> reserved[i].cost >> reserved[i].discount >> reserved[i].final_cost;

        if(reserved[i].book_id != id){
        oread_reg << reserved[i].book_id << " " << reserved[i].user_id << " " << reserved[i].place_id << " " << reserved[i].package << " " << reserved[i].num_people << " "
        << reserved[i].date.dd <<" "<< reserved[i].date.mm <<" "<< reserved[i].date.yy << " " << reserved[i].times << " " << reserved[i].cost << " " << reserved[i].discount << " " << reserved[i].final_cost << "\n";
        }
        i++;
    }
    //closing a file
    iread_reg.close();
    oread_reg.close();

remove("reservation.txt");

rename("n_reservation.txt", "reservation.txt");
    string n;
    cout << " -------------------------  YOUR REGISTRATION HAVE BEEN SUCCESSFULLY DELETED ---------------------\n";
    cout << "\n\npress any key to go back: ";
    getline(cin >> ws, n);
    system("cls");
    user_option();
}



void search_user()
{
    int user_id, i, j;
    for (i = 0; users[i].user_id != 0;i++);
    cout << "Enter the User Id you want to search: ";
    cin >> user_id;
    for (int j = 0; j < i; j++)
    {
        if (users[j].user_id == user_id)
        {
            cout << " ------------------------------------------------------------- "<< endl;
            cout << "| "
                    << left << setw(20) << "Name" << "| "
                    << left << setw(20) << "User name" << "| "
                    << left << setw(15) << "Phone number" << "| " << endl;
            cout << " ------------------------------------------------------------- "<< endl;
            cout << "| "
                 << left << setw(20) << users[j].name << "| "
                 << left << setw(20) << users[j].user_name << "| "
                 << left << setw(15) << users[j].phone_num << "| " << endl;
            cout << " ------------------------------------------------------------- "<< endl;
            admin_option();
        }
    }
    cout << "user was not found!";
    Sleep(500);
    admin_option();
}

void edit_user()
{
    int index, i, j;
    for (i = 0; users[i].user_id != 0;i++);
    for (int j = 0; j < i; j++)
    {
        if (users[j].user_id == loged_in)
        {
            index = j;
            break;
        }
    }

    cout << "\nEdit your personal information: \n";
    cout << "\nEdit name: ";
    getline(cin >> ws, users[index].name);
    c:cout << "\nEdit user name: ";
    string userName;
    getline(cin >> ws, userName);
    for (int f = 0; f < nums; f++)
    {
        if (users[f].user_name == userName)
        {
            cout<< "This username is taken please choose another one? ";
            goto c;
        }
    }
    users[index].user_name = userName;
    cout << "\nchange password: ";
    getline (cin >> ws, users[index].password);
    X: cout<< "\nedit phone number: ";
    cin >> users[index].phone_num;
    for (int j = 0; j < 10; j++)
    {
        if(!(isdigit(users[index].phone_num[j])) || users[index].phone_num[10])
        {
            cout << "Invalid phone number please try again!" << endl;
            goto X;
        }
    }
    cout << "-------------------------------- YOU HAVE SUCCESSFULLY EDITED YOUR PROFILE -------------------------------------"<<endl;
    save_user();
    read_user();
    Sleep(500);
    user_option();
}

void search_place()
{
    int number_of_place;
    string place_id;
    string ns;
    cout << "Enter the name of the place you want to search: ";
    getline(cin>>ws, place_id);
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
        if (place_id == places[i].name)
        {
            cout<< "| "
                <<left << setw(7)  << places[i].place_id << "| "
                <<left << setw(18) <<places[i].name << "| "
                <<left << setw(22) <<places[i].distance << "| ";
            cout<<left << setw(23) << places[i].discription << "| ";
            cout<<left<< setw(17)<< places[i].availability << "| "
                << left << setw(12)  << places[i].rating  << " | " <<endl;
            break;
            return;
        }
    }
    cout << " ---------------------------------------------------------------------------------------------------------------\n";
    user_option();
}

void edit_place()
{
    int i, num_places, origin;
    for (i = 0; places[i].place_id != 0;i++);

    origin = i;
    cout << "Enter the Id of place you want to edit: ";
    cin >> num_places;
        num_places--;
        F:cout<<"Location Name: ";
        getline(cin>>ws,places[num_places].name);
        for (int j = 0; j < nums; j++)
        {
            if (places[i].name == places[i - 1].name)
            {
                cout << "The place is already registered." << endl;
                goto F;
            }
        }
        cout<<"Distance From Addis Ababa: ";
        cin>>places[num_places].distance;
        cout<<"Location description: ";
        getline(cin>>ws, places[num_places].discription);
        cout<<"availability: ";
        cin>>places[num_places].availability;
        i++;
    save_place();
    read_place();
    cout << "\n-------------------PLACE HAVE BEEN EDITED SUCCESSFULLY --------------------------------------------\n\n";
    system("cls");
    admin_option();
}
//void delete_user()
//{
//
//}

int all_tour()
{
    int reserves;
    string n;
    for (int i = 0; i < 117; i++)
    {   cout << "-";
    }
    cout << endl;
    cout << "|" << left << setw(7) << "Place_Id" << "|"
         << left << setw(15) << "Place" << "|"
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
            int place_id = reserved[i].place_id - 1;
            cout << "|" << left << setw(7) << reserved[i].place_id << "|"
                 << left << setw(15) << places[place_id].name << "|"
                 << left<< setw(12) << package_names[reserved[i].package] << "|"
                 << left << setw(21) << reserved[i].num_people << "|"
                 << left << setw (2) << reserved[i].date.mm<<"/"<< setw(2) << reserved[i].date.dd<<"/"<< setw(7) << reserved[i].date.yy << "|"
                 << left << setw(14) << times[reserved[i].times] << "|"
                 << left << setw(9) << reserved[i].cost << "|"
                 << left << setw(13) << reserved[i].discount << "|"
                 << left << setw(11) << reserved[i].final_cost << "|" << endl;
    }
    for (int i = 0; i < 117; i++)
    {
        cout << "-";
    }
    cout << "press any key to go back";
    getline(cin >> ws, n);
    system("cls");
    admin_option();
}



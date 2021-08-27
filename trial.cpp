#include <iostream>
#include <iomanip>
using namespace std;
const int nums =2;
struct Place
{
    int place_id;       // is equal to the index of the array
    string name;
    string distance;    //distance from Addis Ababa Review
    string discription; //brief description of the place
    int rating[nums];
    int availability;
}places[nums];

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

int main(){
Place places[nums];
add_place();
display_place();
return 0;
}

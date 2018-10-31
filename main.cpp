//Main.cpp for connecting both Sys.cpp and Sys.hpp
//Code starts here

#include"Sys.hpp"
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    int Choise;
    cout.width(150);
    cout.fill('-');
    cout<<"\n\t\t**** Student Record System ****"<<endl;
    cout<<"\n\t1-->Write Record to File. "<<endl;
    cout<<"\t2-->Read all the Records of the File."<<endl;
    cout<<"\t3-->Read Single Student Record of the File. "<<endl;
    cout<<"\t2-->Exit The Program."<<endl;
    cout<<"\n\n\t\tEnter Your Choise: ";
    cin>>Choise;
    switch(Choise)
    {
        case 1:
            writeTofile();
            break;
        case 2:
            readFromfile();
            break;
        case 3:
            readOnerecord();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout<<"\n\tChoise not Available....";
            exit(0);

    }
}

//Sys.cpp for defining functions and class
#include"Sys.hpp"   //Including Sys.hpp header file
#include<iostream>
#include<fstream>
#include<cstring>
#define M 30
using namespace std;
// Creating class
class Student
{
private:
    char name[M];
    int age;
    long int num;
public:
    void getData()
    {
        cin.ignore();   //cin.ignore is used to remove the new line
        cout<<"Enter Your Name: ";
        gets(name);
        cout<<"Enter Your Age: ";
        cin>>age;
        cout<<"Enter Your Number: ";
        cin>>num;
    }
    void showData()
    {
        cout<<"\n\tName = "<<name;
        cout<<"\n\tAge = "<<age;
        cout<<"\n\tNumber = "<<num;
        cout<<"\n\n";
    }
};
void readFromfile()    //function for reading data from file and its prototype is already initialized in Sys header file
{
    Student st;
    ifstream infile("Record.dat",ios::binary);
    while(!infile.eof())
    {
        infile.read(reinterpret_cast<char*>(&st),sizeof(st));
        st.showData();
    }


}
void writeTofile()
{
    Student st;
    int Count;
    ofstream outfile("Record.dat",ios::binary|ios::app);
    cout<<"Number of students: ";
    cin>>Count;
    for(int i=0;i<Count;i++)
    {
        st.getData();
        cin.ignore();
        outfile.write(reinterpret_cast<char*>(&st),sizeof(st));
    }
}
void readOnerecord()
{
    Student st;
    int n;
    cout<<"Enter The Record Number: ";
    cin>>n;
    ifstream infile("Record.dat",ios::binary);
    infile.seekg((n-1)*sizeof(st));     //n-1 is done to get exact position
    infile.read(reinterpret_cast<char*>(&st),sizeof(st));
    st.showData();

  /*  while(!infile.eof())
    {
        infile.read(reinterpret_cast<char*>(&st),sizeof(st));
        int n=infile.tellg();
        infile.seekg(n*sizeof(st));
        st.showData();
       if((offset = line.find(Test,0)) != string::npos)
        {
            cout<<"Ture";
            int n=infile.tellg();
            infile.seekg(n*sizeof(st));
            infile.read(reinterpret_cast<char*>(&st),sizeof(st));
            st.showData();
        }
    }
        */
}


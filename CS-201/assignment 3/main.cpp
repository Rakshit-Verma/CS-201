#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "class.h"
#include "pQueue.h"

int main()
{
    std::vector<Lab> vlabs;    //vector for labs
    vlabs.clear();
    std::ifstream in1,in2;
    std::string namein;
    float areain;
    int numofdoorsin;
    int x,y;
    int numofitemin;
    int ch;
    in1.open("lab.txt");
    while(in1.is_open())
    {
        while(!in1.eof())
        {
            if(in1 >> namein >> areain >> numofdoorsin >> x >> y >> numofitemin){
            Lab labtemp(namein,areain,numofdoorsin,x,y,numofitemin);
            vlabs.push_back(labtemp);
            }
        }
        in1.close();
    }
    std::cout<<"LABS-----------------------------\n";
    pQueue<Lab,labcomp> pqlab(vlabs);
    std::cout<<"Do you want to remove the element added last    :\n1.Yes\n0.No\n";
    std::cin>>ch;
    if(ch)
    {
        pqlab.remove();
    }
    std::cout<<"Do you want to add Labs :\n1.Yes\n0.No\n";
    std::cin>>ch;
    while(ch)
    {
        std::cout<<"Enter the data in format\nName Area Number_Of_Doors (X,Y) Number_Of_Computers\n";
        std::cin >> namein;
        std::cin >> areain;
        std::cin >> numofdoorsin;
        std::cin >> x;
        std::cin >> y;
        std::cin >> numofitemin;
        Lab labtemp(namein,areain,numofdoorsin,x,y,numofitemin);
        vlabs.push_back(labtemp);
        pqlab.insert(labtemp);
        std::cout<<"Do you want to add more :\n1.Yes\n0.No\n";
        std::cin>>ch;
    }
    std::cout<<"Do you want to remove the minimum   :\n1.Yes\n0.No\n";
    std::cin>>ch;
    if(ch)
    {
        pqlab.remove_Min();
    }
    std::cout<<"Do you want to see the list :\n1.Yes\n0.No\n";
    std::cin>>ch;
    if(ch)
    {
        pqlab.print();
    }

    std::vector<Lec> vlecs;    //vector for lecture halls
    in2.open("lec.txt");
    while(in2.is_open())
    {
        while(!in2.eof())
        {
            in2 >> namein >> areain >> numofdoorsin >> x >> y >> numofitemin;
            Lec lectemp(namein,areain,numofdoorsin,x,y,numofitemin);
            vlecs.push_back(lectemp);
        }
        in2.close();
    }
    std::cout<<"LECTURE HALLS--------------------------\n";
    pQueue<Lec,leccomp> pqlec(vlecs);
    std::cout<<"Do you want to remove the element added last    :\n1.Yes\n0.No\n";
    std::cin>>ch;
    if(ch)
    {
        pqlec.remove();
    }
    std::cout<<"Do you want to add Lecs :\n1.Yes\n0.No\n";
    std::cin>>ch;
    while(ch){
    std::cout<<"Enter the data in format\nName Area Number_Of_Doors (X,Y) Number_Of_Chairs\n";
    std::cin >> namein;
    std::cin >> areain;
    std::cin >> numofdoorsin;
    std::cin >> x;
    std::cin >> y;
    std::cin >> numofitemin;
    Lec lectemp(namein,areain,numofdoorsin,x,y,numofitemin);
    vlecs.push_back(lectemp);
    pqlec.insert(lectemp);
    std::cout<<"Do you want to add more :\n1.Yes\n0.No\n";
    std::cin>>ch;
    }
    std::cout<<"Do you want to remove the minimum   :\n1.Yes\n0.No\n";
    std::cin>>ch;
    if(ch)
    {
        pqlec.remove_Min();
    }
    std::cout<<"Do you want to see the list :\n1.Yes\n0.No\n";
    std::cin>>ch;
    if(ch)
    {
        pqlec.print();
    }
    return 0;
}
#include <iostream>
#include "class.h"

Base::Base()
{
    name = "\0";
    area = 0;
    numofdoors = 0;
    location[0] = 0;
    location[1] = 0;
}

void Base::setname(std::string namein)
{
    name = namein;
}

void Base::setarea(float areain)
{
    area = areain;
}

void Base::setnumofdoors(int numofdoorsin)
{
    numofdoors = numofdoorsin;
}

void Base::setlocation(int x, int y)
{
    location[0] = x;
    location[1] = y;
}

Lab::Lab()
{
    numofcomp = 0;
}

Lab::Lab(std::string namein, float areain, int numofdoorsin, int x, int y, int numofcompin)
{
    name = namein;
    area = areain;
    numofdoors = numofdoorsin;
    location[0] = x;
    location[1] = y;
    numofcomp = numofcompin;
}

void Lab::setnumofcomp(int numofcompin)
{
    numofcomp = numofcompin;
}

float Lab::getarea()
{
    return area;
}

void Lab::printlist()
{
    std::cout<<"Name        :   "<<name<<"\nArea        :   "<<area<<"\nNumber of doors :   "<<numofdoors<<"\nLocation(X,Y)     :   ("<<location[0]<<","<<location[1]<<")\nNumber of computers  :   "<<numofcomp<<"\n\n"<<std::endl;
}

Lec::Lec()
{
    numofchairs = 0;
}

Lec::Lec(std::string namein, float areain, int numofdoorsin, int x, int y, int numofchairsin)
{
    name = namein;
    area = areain;
    numofdoors = numofdoorsin;
    location[0] = x;
    location[1] = y;
    numofchairs = numofchairsin;
}

void Lec::setnumofchairs(int numofchairsin)
{
    numofchairs = numofchairsin;
}

int Lec::getchairs()
{
    return numofchairs;
}

void Lec::printlist()
{
    std::cout<<"Name        :   "<<name<<"\nArea        :   "<<area<<"\nNumber of doors :   "<<numofdoors<<"\nLocation(X,Y)     :   ("<<location[0]<<","<<location[1]<<")\nNumber of chairs  :   "<<numofchairs<<"\n\n"<<std::endl;
}
#pragma once
#include <iostream>

class Base
{
    private:
    std::string name;
    float area;
    int numofdoors;
    int location[2];
    public:
    Base();
    void setname(std::string namein);
    void setarea(float areain);
    void setnumofdoors(int numofdoorsin);
    void setlocation(int x, int y);
    virtual void printlist(){};
    friend class Lab;
    friend class Lec;
};

class Lab : public Base
{
    private:
    int numofcomp;
    public:
    Lab();
    Lab(std::string namein, float areain, int numofdoorsin, int x, int y, int numofcompin);
    void setnumofcomp(int numofcompin);
    float getarea();
    void printlist();
    friend class labcomp;
};

class Lec : public Base
{
    private:
    int numofchairs;
    public:
    Lec();
    Lec(std::string namein, float areain, int numofdoorsin, int x, int y, int numofchairsin);
    void setnumofchairs(int numofchairsin);
    int getchairs();
    void printlist();
};
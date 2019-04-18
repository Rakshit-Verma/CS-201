#ifndef LIST_H
#define LIST_H
#include <vector>
#include "item.h"

class List
{
    private:
    struct node
    {
        Item *list;
        node *next;
    };
    node *head, *tail;
    public:
    List();
    void insertnode(Item *p, int x);
    void areasearch(int xm,int ym, int xM, int yM);
    int typesearch(std::string typeS);
    void sell(std::string type,int number);
    void amcal(int maxcal,int pay,int b);
    void print();
};
#endif
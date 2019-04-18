#ifndef LIST_H
#define LIST_H
#include <deque>
#include "item.h"
#include "sQueue.h"

struct node
{
    Item *list;
    node *next;
    bool operator <= (const node & i)
    {
      return(this->list->retcal() <= i.list->retcal());
    }
    bool operator < (const node & i)
    {
      return(this->list->retcal() < i.list->retcal());
    }
};

class List
{
    private:
    sQueue<node> sq;
    int sizeoflist;
    node *head, *tail;
    public:
    List();
    void listsize();
    void mincalelement();
    void insertnode(Item *p);
    void deletefrontnode();
    void print();
};
#endif
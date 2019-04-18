#ifndef LIST_H
#define LIST_H
#include <deque>
#include "item.h"
// #include "sQueue.h"

struct node
{
    Item *list;
    node *next;
};
// template <typename E>
  /*class sQueue 
  {					      // an interface for a queue
    std::deque<node> dq;
    public:
    sQueue();
    void printfirst();
    int size() const;				      // number of items in queue
    bool empty() const;	
    const node& min();			      // is the queue empty?
    int frontid();
    void enqueue (const node& e);
    void dequeue();
  };*/

class List
{
    private:
    // sQueue sq;
    node *head, *tail;
    std::deque<node> dq;
    public:
    List();
    void mincalelement();
    void insertnode(Item *p);
    void deletefrontnode();
    void print();
    //template <class U>
    //friend class sQueue<U>;
};
/*void sQueue::printfirst()
    {
      std::deque<node>::iterator it = dq.begin();
      it->list->print();
    }
int sQueue::frontid()
    {
      std::deque<node>::iterator it = dq.begin();
      return it->list->retID();
    }
void sQueue::enqueue (const node& e)
    {
      std::deque<node>::iterator it = dq.end();
      it--;
      if(it->list->retcal() <= e.list->retcal())
      {
        dq.push_back(e);        
      }
      else
      {
        while(!dq.empty())
        {
          if(e.list->retcal() < it->list->retcal())
          {
            it--;
            dq.pop_back();
          }
          else
          {
            break;
          }
        }
        dq.push_back(e);
      }
    }
void sQueue::dequeue()		      // dequeue element at front
    {
      dq.pop_front();
    }*/
#endif
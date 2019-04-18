#ifndef SQUEUE_H
#define SQUEUE_H
#include "list.h"
#include "item.h"
#include <iostream>
#include <deque>
using namespace std;
template <typename E>
  class sQueue 
  {					      // an interface for a queue
    deque<E> dq;
    public:
    void printfirst()
    {
    	if(!dq.empty())
    	{
    		(dq.front()).list->print();		
    	}
      	else
      		cout<<"\nNO ELEMENT IS PRESENT!!!\n\n\n";
    }
		      // is the queue empty?
    int frontid()
    {
      return (dq.front()).list->retID();
    }
    void enqueue (E& e)
    {
      if(!dq.empty()){
      if((dq.back()) <= e)
      {
        dq.push_back(e);        
      }
      else
      {
        while(!dq.empty())
        {
          if(e < (dq.back()))
          {
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
      else
      {
        dq.push_back(e);
      }
    }
    void dequeue()		      // dequeue element at front
    {
      dq.pop_front();
    }
  };
#endif

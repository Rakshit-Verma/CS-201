#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include "class.h"
using namespace std;

class labcomp
{
  public:
  bool operator () (Lab lab1, Lab lab2)
  {
    return(lab1.getarea() < lab2.getarea());
  }
};

class leccomp
{
  public:
  bool operator () (Lec lec1, Lec lec2)
  {
    return(lec1.getchairs() < lec2.getchairs());
  }
};

class locator
{
  public:
  int index;
};

template <class E, class C>//E is element type and C is comparator
class pQueue 			// adaptable priority queue
{
  private:
  vector<E> heap;
  public:
  locator l;
  int size() const				// number of elements
  {
    return heap.size();
  }
  bool empty()				// is the queue empty?
  {
    return heap.empty();
  }

  void insert(E e)		// insert element
  {
    heap.push_back(e);
    build_minheap();
  }
  void remove()		// remove at location l
  {
    heap.erase(heap.begin()+l.index);
    build_minheap();
  }
  void replace(E e) // replace at position p
  {
    heap.remove();
    heap.insert(e);
  }
  pQueue(vector<E> &vel)   //constructor for heap
  {
    for(int i = 0; i < vel.size(); i++)
    {
      heap.push_back(vel[i]);
    }
    l.index = vel.size()-1;
    build_minheap();
  }
  void build_minheap()
  {
    for(int i = heap.size()/2-1; i >= 0; i--)
    {
      min_heapify(i);
    }
  }
  void min_heapify(int i)
  {
    C cmp;
    int smallest = i;
    int left = 2*i+1;
    int right = 2*(i+1);
    if((left< heap.size())&&cmp(heap[left] , heap[smallest]))
    {
      smallest = left;
    }
    if((right< heap.size())&&cmp(heap[right] , heap[smallest]))
    {
      smallest = right;
    }
    if(smallest != i)
    {
      if(i == l.index)
      {
        l.index = smallest;
      }
      else if(smallest == l.index)
      {
        l.index = i;
      }
      swap(heap[i],heap[smallest]);
      min_heapify(smallest);
    }
  }
  const E return_min() const
  {
    return heap[0];
  }
  void remove_Min()
  {
    heap[0].printlist();
    heap.erase(heap.begin());
    build_minheap();
  }

  void print()
  {
    for(int i = 0; i < heap.size(); i++)
    {
      this->heap[i].printlist();
      cout<<i<<endl;
    }
    // heap[heap.size()-1].printlist();
  }
};


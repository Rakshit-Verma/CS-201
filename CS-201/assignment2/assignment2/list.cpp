#include <iostream>
#include "list.h"
#include "item.h"
#include "sQueue.h"

    List::List()
    {
        head = NULL;
        tail = NULL;
        sizeoflist = 0;
    }
    void List::listsize()
    {
        std::cout<<"\nSize of the list is : "<<sizeoflist<<"\n\n";
    }
    void List::mincalelement()
    {
        sq.printfirst();
    }
    void List::insertnode(Item *p)
    {
        sizeoflist++;
        node *temp = new node;
        temp->next = NULL;
        temp->list = p;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
        node temp1;
        temp1.next = NULL;
        temp1.list = p;
        sq.enqueue(temp1);
    }
    void List::deletefrontnode()
    {
        sizeoflist--;
        if(head->list->retID() == sq.frontid())
        {
            sq.dequeue();
        }
        node *temp;
        temp = head;
        head = head->next;
        delete(temp->list);
        delete(temp);
    }
    void List::print()
    {
        node *temp;
        temp = head;
        while(temp != NULL)
        {
            temp->list->print();
            temp = temp->next;
        }
    }
    
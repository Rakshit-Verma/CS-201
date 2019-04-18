#include <iostream>
#include "list.h"
#include "item.h"

    List::List()
    {
        head = NULL;
        tail = NULL;
    }
    void List::mincalelement()
    {
        // sq.printfirst();
        std::deque<node>::iterator it = dq.begin();
        it->list->print();
    }
    void List::insertnode(Item *p)
    {
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
        //------------------
        std::deque<node>::iterator it = dq.end();
        it--;
        if(dq.empty())
        {
            dq.push_back(temp1);
        }
        else if(it->list->retcal() <= temp1.list->retcal())
        {
            dq.push_back(temp1);        
        }
        else
        {
            while(!dq.empty())
            {
                if(temp1.list->retcal() < it->list->retcal())
                {
                    it--;
                    dq.pop_back();
                }
                else
                {
                    break;
                }
            }
                dq.push_back(temp1);
        }
        //-----------------------------------------
    }
    void List::deletefrontnode()
    {
        std::deque<node>::iterator it = dq.begin();
        if(head == NULL)
        {
            return;
        }
        else if(head->next == NULL)
        {
            dq.pop_front();
            delete(head->list);
            head = NULL;
        }
        else
        {
            if(it->list->retID() == head->list->retID())
            {
                dq.pop_front();
            }
            node *temp = new node;
            temp = head;
            head = head->next;
            delete(temp->list);
            delete(temp);
        }

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
    
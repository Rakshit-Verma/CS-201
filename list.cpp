#include <iostream>
#include "list.h"
#include "item.h"

    List::List()
    {
        head = NULL;
        tail = NULL;
    }
    void List::insertnode(Item *p, int x)
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
            tail = temp;
        }
    }
    void List::areasearch(int xm,int ym, int xM, int yM)
    {
        node *temp;
        temp = head;
        int *lp;
        while (temp != NULL)
        {
            lp = temp->list->retlocation();
            if(((lp[0]<=xM)&&(lp[0]>=xm))&&((lp[1]<=yM)&&(lp[1]>=ym)))
            {
                temp->list->print();
            }
            temp = temp->next;
        }
    }
    int List::typesearch(std::string typeS)
    {
        node *temp;
        temp = head;
        int amount = 0;
        while(temp != NULL)
        {
            if(temp->list->rettype() == typeS)
            {
                amount += temp->list->retunit();
                temp->list->print();
            }
            temp = temp->next;
        }
        std::cout<<"Total amount found in store :   "<<amount<<std::endl;
        return amount;
    }
    void List::sell(std::string type,int number)
    {
        node *temp = new node;
        temp = head;
        std::vector<int> vi;
        while(temp != NULL)
        {
            if(temp->list->rettype() == type)
            {
                vi.push_back(temp->list->retID());
            }
            temp = temp->next;
        }
        std::vector<int> vc; 
        for(int i = 0; i < vi.size(); i++)
        {
            temp = head;
            while(temp != NULL)
            {
                if(temp->list->retID() == vi[i])
                {
                    vc.push_back(temp->list->cost_per_unit());
                    temp = temp->next;
                    break;
                }
                temp = temp->next;
            }
        }
        //vc is filled
        int costmin = 1000000, point = 0;
        for(int i = 0; i < vc.size(); i++)
        {
            if(vc[i] < costmin)
            {
                point = i;
                costmin = vc[i];
            }
        }
        int flag = 0;
        for(int i = 0; i < vc.size(); i++)
        {
            if(vc[i] == costmin)
            {
                flag++;
                if(flag > 1)
                {
                    break;
                }
            }
        }
        if(flag > 1)
        {
            std::vector<int> vd;
            point = 0;
            for(int i = 0; i < vc.size(); i++)
            {
                if(vc[i] == costmin)
                {
                    vd.push_back(temp->list->retdistance());
                }
                else
                {
                    vd.push_back(10000000);
                }
            }
            int distmin = 10000000;
            for(int i = 0; i < vd.size(); i++)
            {
                if(vd[i] < distmin)
                {
                    point = i;
                    distmin = vd[i];
                }
            }
        }
        temp = head;
        while(temp != NULL)
        {
            if(temp->list->retID() == vi[point])
            {
                std::cout<<"You have selected "<<number<<" units of  the following item\n(NOTE: IF the cheapest item does not fullfill desired unit then max possible units would be deducted)\n";
                temp->list->print();
                if((temp->list->retunit() - number) < 0)
                {
                    number = temp->list->retunit();
                }
                temp->list->update(number);
                std::cout<<"After deduction\n";
                temp->list->print();
                std::cout<<"\nYou have to pay\t\t:\t\t"<<number*(temp->list->cost_per_unit())<<std::endl;
                break;
            }
            temp = temp->next;
        }
        if(temp->list->retunit() == 0)
        {
            node *curr = new node;
            node *prev = new node;
            curr = head;
            for(int i = 0; i < temp->list->retID() - 1 ; i++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete(curr->list);
            delete(curr);
        }
    }
    void List::amcal(int maxcal,int pay,int b)
    {
        if(b == 1)
        {
            std::cout<<"You have to pay\t:\t"<<pay<<std::endl;
            return;
        }
        std::vector<int> vcal;
        std::vector<int> vi;
        node *temp = new node;
        temp = head;
        while(temp != NULL)
        {
            vi.push_back(temp->list->retID());
            vcal.push_back(temp->list->retcal());
            temp = temp->next;
        }
        int fincal = 0;
        int calmin = 100000,point;
        for(int i = 0; i < vcal.size(); i++)
        {
            fincal +=vcal[i];
            if(vcal[i] < calmin)
            {
                point = i;
                calmin = vcal[i];
            }
        }
        temp = head;
        while(temp->list->retID() != vi[point])
        {
            temp = temp->next;
        }
        //min calorie product point obtained
        int totunits = temp->list->retunit();
        int totprice = temp->list->cost_per_unit();
        std::cout<<fincal<<std::endl;
        if(fincal-maxcal < 0)
        {
            maxcal = fincal;
        }
        if(temp->list->retunit()*calmin - maxcal < 0)
        {
            std::cout<<"You have selected "<<temp->list->retunit()<<" units of  the following item\n";
            temp->list->print();
            //std::cout<<"You have to pay\t:\t"<<totprice*totunits<<std::endl;
            temp->list->update(temp->list->retunit());
            //deleting the node
            node *curr = new node;
            node *prev = new node;
            curr = head;
            for(int i = 0; i < temp->list->retID() - 1 ; i++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete(curr->list);
            delete(curr);
            amcal(maxcal-totunits*calmin,pay + totunits*totprice,0);
        }
        else
        {
            std::cout<<"You have selected "<<maxcal/calmin<<" units of  the following item\n";
            temp->list->print();
            //std::cout<<"You have to pay\t:\t"<<totprice*(maxcal/calmin)<<std::endl;
            temp->list->update(maxcal/calmin);
            b = 1;
            amcal(maxcal,pay + (totprice*(maxcal/calmin)),1);
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
#include <iostream>
#include <fstream>
#include "list.h"
#include "item.h"
// #include "sQueue.h"


int main()
{
    List * ll = new List;
    int ch;
        std::cout<<"How would you like to enter data through file   :\n1.Yes\n2.No\n";
    std::cin>>ch;
    std::cout<<"\n----------------------------------------------------------\n";
    if(ch == 1)
    {
        std::cout<<"Do you want to load fruits.txt  :\n1.Yes\n2.No\n";
        std::cin>>ch;
        std::cout<<"\n----------------------------------------------------------\n";
        std::ifstream file1,file2;

        if(ch == 1)
        {
            std::string typein;
            int x,y;
            float weightin;
            int pricein;
            int caloriesin;
            int unitin;
            file1.open("fruits.txt");
            if(file1.is_open())
            {
                while(!file1.eof())
                {
                    file1 >> typein >> x >> y >> weightin >> pricein >> caloriesin >> unitin;
                    Fruit *newf_fruit = new Fruit(typein,x,y,weightin,pricein,caloriesin,unitin);
                    ll->insertnode(newf_fruit);
                }
                file1.close();
            }
        }
        std::cout<<"Do you want to load vegetables.txt  :\n1.Yes\n2.No\n";
        std::cin>>ch;
        std::cout<<"\n----------------------------------------------------------\n";
        if(ch == 1)
        {
            std::string typein;
            int x,y;
            int pricein;
            int volumein;
            int caloriesin;
            int amountin;
            file2.open("vegetables.txt");
            if(file2.is_open())
            {
                while(!file2.eof())
                {
                    file2 >> typein >> x >> y >> pricein >> volumein >> caloriesin >> amountin;
                    Vegetable *newf_vegetable = new Vegetable(typein,x,y,pricein,volumein,caloriesin,amountin);
                    ll->insertnode(newf_vegetable);
                }
                file2.close();
            }
        }
    }
    int t = 1;
    while(t)
    {
            std::cout<<"1.Add using console\n";
            std::cout<<"2.See the stock\n";
            std::cout<<"3.Mincalorie element\n";
            std::cout<<"4.Deque\n";
            std::cout<<"5.Size of the list\n";
            std::cout<<"6.End\n-->>";
        
        std::cin>>ch;
        if(ch == 5)
        {
            ll->listsize();
        }
        if(ch == 3)
        {
            ll->mincalelement();
        }
        if(ch == 4)
        {
            ll->deletefrontnode();
            std::cout<<"\n\nFirst node deleted--------\n\n";
        }
        if(ch == 1)
        {
            
            while(ch)
            {
                std::cout<<"Please provide the type of element you want to insert   :\n1.Fruit\n2.Vegetable\n0.Back\n";
                std::string str;
                int val,x,y;
                float fval;
                std::cin>>ch;
                std::cout<<"\n----------------------------------------------------------\n";
                if(ch == 1)
                {
                    Item *new_fruit = new Fruit;
                    std::cout<<"Please provide further details\n";
                    std::cout<<"What is the type of fruit   :";
                    std::cin>>str;
                    new_fruit->gettype(str);
                    std::cout<<"Where do you want to place them. Please provide the coordinates\nX,Y  :";
                    std::cin>>x>>y;
                    new_fruit->getlocation(x,y);
                    std::cout<<"What is the weight of each unit :";
                    std::cin>>fval;
                    new_fruit->getweight_per_unit(fval);
                    std::cout<<"What is the price of each unit  :";
                    std::cin>>val;
                    new_fruit->getprice_per_unit(val);
                    std::cout<<"What is the calorie intake  :";
                    std::cin>>val;
                    new_fruit->getcalories(val);
                    std::cout<<"How many of these do you want to add    :";
                    std::cin>>val;
                    new_fruit->getunits_to_add(val);
                    ll->insertnode(new_fruit);
                    ch = 100;
                }
                else if(ch == 2)
                {
                    Item *new_vegetable = new Vegetable;
                    std::cout<<"Please provide further details\n";
                    std::cout<<"What is the type of vegetable   :";
                    std::cin>>str;
                    new_vegetable->gettype(str);
                    std::cout<<"Where do you want to place them. Please provide the coordinates\nX,Y  :";
                    std::cin>>x>>y;
                    new_vegetable->getlocation(x,y);
                    std::cout<<"What is the price of one kg :";
                    std::cin>>val;
                    new_vegetable->getprice_per_kg(val);
                    std::cout<<"What is the volume of each kg   :";
                    std::cin>>val;
                    new_vegetable->getvolume_per_kg(val);
                    std::cout<<"What is the calorie intake  :";
                    std::cin>>val;
                    new_vegetable->getcalories(val);
                    std::cout<<"How many of these do you want to add    :";
                    std::cin>>val;
                    new_vegetable->getamount_to_add(val);
                    ll->insertnode(new_vegetable);
                    ch = 100;
                }   
            }
        }
        if(ch == 2)
        {
            std::cout<<"\tSTORE\n----------------------------------------------------------\n";
            ll->print();
            std::cout<<"\n----------------------------------------------------------\n";
        }
        if(ch == 6)
        {
            t = 0;
            break;
        }
    }
    return 0;
}
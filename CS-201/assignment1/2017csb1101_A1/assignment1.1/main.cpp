#include <iostream>
#include <fstream>
#include "list.h"

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
                    ll->insertnode(newf_fruit,1);
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
                    ll->insertnode(newf_vegetable,2);
                }
                file2.close();
            }
        }
    }
    int t = 1;
    int total_present = 0;
    while(t)
    {
            std::cout<<"1.Add using console\n";
            std::cout<<"2.See the stock\n";
            std::cout<<"3.Search for any item using name\n";
            std::cout<<"4.Search using area\n";
            std::cout<<"7.Terminate the loop (If you want to purchase something)\n";
        
        std::cin>>ch;
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
                    ll->insertnode(new_fruit,ch);
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
                    ll->insertnode(new_vegetable,ch);
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
        if(ch == 3)
        {
            std::string typeS;
            std::cout<<"Please provide the desired item's name  :";
            std::cin>>typeS;
            total_present = ll->typesearch(typeS);
        }
        std::cout<<"\n----------------------------------------------------------\n";
        if(ch == 4)
        {
            int xm = 0, xM = 0, ym = 0, yM = 0;
            std::cout<<"Please provide the coordinates  :\nProvide the coordinates as x-min,y-min,x-Max,y-Max\n";
            std::cin>>xm>>ym>>xM>>yM;
            ll->areasearch(xm,ym,xM,yM);
        }
        std::cout<<"\n----------------------------------------------------------\n";
        
        //Selling
        std::cout<<"\n----------------------------------------------------------\n";
        if(ch == 7)
            {
                t = 0;
            }
    }
    std::cout<<"5.Purchase based on calories intake\n";
    std::cout<<"6.Purchase based on keyword\n";
    std::cin>>ch;
    if(ch == 5)
            {
                std::cout<<"Please enter max calorie intake (max 1000)    :";
                std::cin>>ch;
                ll->amcal(ch,0,0);
                ch = 100;
            }
    else if(ch == 6)
            {
                int /*identity,*/number;
                std::string typeS;
                std::cout<<"Please provide the desired item's name  :";
                std::cin>>typeS;
                total_present = ll->typesearch(typeS);
                /*std::cout<<"Please enter the ID of the item you want to purchase    :";
                std::cin>>identity;*/
                if(total_present)
                {
                    std::cout<<"Please enter number of units you want to buy    :";
                    std::cin>>number;
                    ll->sell(typeS,number);
                }
                if(total_present == 0)
                {
                    std::cout<<"Item is not valid or present\n";
                }
            }
    return 0;
}
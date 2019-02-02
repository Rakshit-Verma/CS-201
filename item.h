#ifndef ITEM_H
#define ITEM_H
#include <iostream>

class Item
{
    private:
    static int ID;
    int purchase_Id;
    std::string purchase_time;
    int location[2];
    public:
    Item();
    virtual void print(){};
    virtual void update(int num){};
    virtual std::string rettype(){};
    virtual void gettype(std::string typein){};
    virtual void getweight_per_unit(float weightin){};
    virtual void getprice_per_unit(int pricein){};
    virtual int cost_per_unit(){};
    virtual int retcal(){};
    virtual void getcalories(int caloriesin){};
    virtual int retunit(){};
    virtual void getunits_to_add(int unitin){};
    virtual void getprice_per_kg(int pricein){};
    virtual void getvolume_per_kg(int volumein){};
    virtual void getamount_to_add(int amountin){};
    int retID();
    int * retlocation();
    int retdistance();
    void getlocation(int x, int y);
    friend class Fruit;
    friend class Vegetable;
};
class Vegetable : public Item
{
    private:
    std::string type;
    int price_per_kg;
    int volume_per_kg;
    int calories;
    int amount_to_add;  //in kg
    public:
    Vegetable();
    Vegetable(std::string typein, int x, int y, int pricein, int volumein, int caloriesin, int amountin);
    std::string rettype();
    void gettype(std::string typein);
    int cost_per_unit();
    void getprice_per_kg(int pricein);
    void getvolume_per_kg(int volumein);
    int retcal();
    void getcalories(int caloriesin);
    int retunit();
    void update(int num);
    void getamount_to_add(int amountin);
    void print();
};
class Fruit : public Item
{
    private:
    std::string type;
    float weight_per_unit;
    int price_per_unit;
    int calories;
    int units_to_add;
    public:
    Fruit();
    Fruit(std::string typein,int x, int y, float weightin, int pricein, int caloriesin, int unitin);
    std::string rettype();
    void gettype(std::string typein);
    void getweight_per_unit(float weightin);
    int cost_per_unit();
    void getprice_per_unit(int pricein);
    int retcal();
    void getcalories(int caloriesin);
    int retunit();
    void update(int num);
    void getunits_to_add(int unitin);
    void print();
};
#endif
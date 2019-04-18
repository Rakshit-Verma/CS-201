#include <iostream>
#include "item.h"


    Item::Item()
    {
        ID++;
        purchase_Id = ID;
    }
    int Item::retID()
    {
        return purchase_Id;
    }
    int * Item::retlocation()
    {
        return location;
    }
    int Item::retdistance()
    {
        return (location[0])*(location[0])+(location[1])*(location[1]);
    }
    void Item::getlocation(int x, int y)
    {
        location[0] = x;
        location[1] = y;
    }
    int Item::ID = 0;

    Vegetable::Vegetable()
    {
        type = '\0';
        location[0] = 0;
        location[1] = 0;
        price_per_kg = 0;
        volume_per_kg = 0;
        calories = 0;
        amount_to_add = 0;
    }
    Vegetable::Vegetable(std::string typein, int x, int y, int pricein, int volumein, int caloriesin, int amountin)
    {
        type = typein;
        location[0] = x;
        location[1] = y;
        price_per_kg = pricein;
        volume_per_kg = volumein;
        calories = caloriesin;
        amount_to_add = amountin;
    }
    std::string Vegetable::rettype()
    {
        return type;
    }
    void Vegetable::gettype(std::string typein)
    {
        type = typein;
    }
    int Vegetable::cost_per_unit()
    {
        return price_per_kg;
    }
    void Vegetable::getprice_per_kg(int pricein)
    {
        price_per_kg = pricein;
    }
    void Vegetable::getvolume_per_kg(int volumein)
    {
        volume_per_kg = volumein;
    }
    int Vegetable::retcal()
    {
        return calories;
    }
    void Vegetable::getcalories(int caloriesin)
    {
        calories = caloriesin;
    }
    int Vegetable::retunit()
    {
        return amount_to_add;
    }
    void Vegetable::update(int num)
    {
        amount_to_add = amount_to_add - num;
    }
    void Vegetable::getamount_to_add(int amountin)
    {
        amount_to_add = amountin;
    }
    void Vegetable::print()
    {
        std::cout<<"Type\t\t:\t"<<type<<"\nLocation(x,y)\t:\t("<<location[0]<<","<<location[1]<<")\nPrice per kg\t:\t"<<price_per_kg<<"\nVolume per kg\t:\t"<<volume_per_kg<<"\nCalories\t:\t"<<calories<<"\nUnits present\t:\t"<<amount_to_add<<"\nID\t\t:\t"<<purchase_Id<<std::endl<<std::endl;
    }
    Fruit::Fruit()
    {
        type = '\0';
        location[0] = 0;
        location[1] = 0;
        weight_per_unit = 0;
        price_per_unit = 0;
        calories = 0;
        units_to_add = 0;
    }
    Fruit::Fruit(std::string typein,int x, int y, float weightin, int pricein, int caloriesin, int unitin)
    {
        type = typein;
        location[0] = x;
        location[1] = y;
        weight_per_unit = weightin;
        price_per_unit = pricein;
        calories = caloriesin;
        units_to_add = unitin;
    }
    std::string Fruit::rettype()
    {
        return type;
    }
    void Fruit::gettype(std::string typein)
    {
        type = typein;
    }
    void Fruit::getweight_per_unit(float weightin)
    {
        weight_per_unit = weightin;
    }
    int Fruit::cost_per_unit()
    {
        return price_per_unit;
    }
    void Fruit::getprice_per_unit(int pricein)
    {
        price_per_unit = pricein;
    }
    int Fruit::retcal()
    {
        return calories;
    }
    void Fruit::getcalories(int caloriesin)
    {
        calories = caloriesin;
    }
    int Fruit::retunit()
    {
        return units_to_add;
    }
    void Fruit::update(int num)
    {
        units_to_add = units_to_add - num;
    }
    void Fruit::getunits_to_add(int unitin)
    {
        units_to_add = unitin;
    }
    void Fruit::print()
    {
        std::cout<<"Type\t\t:\t"<<type<<"\nLocation(x,y)\t:\t("<<location[0]<<","<<location[1]<<")\nWeight per unit\t:\t"<<weight_per_unit<<"\nPrice per unit\t:\t"<<price_per_unit<<"\nCalories\t:\t"<<calories<<"\nUnits present\t:\t"<<units_to_add<<"\nID\t\t:\t"<<purchase_Id<<std::endl<<std::endl;
    }
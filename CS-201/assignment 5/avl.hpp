#pragma once
#include <iostream>
#include <string>
using namespace std;

struct node
{
    string word;
    string meaning;
    node *right;
    node *left;
    int height;
};

class Avl
{
    private:
    node *root;
    node* insert(string wordin, string meaningin, node *t);
    node* singleRightRotate(node* t);
    node* singleLeftRotate(node* t);
    node* doubleLeftRotate(node* t);
    node* doubleRightRotate(node* t);
    node* deleteNode(node *t, string wordin);
    node* findMin(node *t);
    int height(node *t);
    int descendent(node *t);
    void displaytree(node *t);
    void count_in_range(node *t , string k1, string k2);
    int getBalance(node *t);
    public:
    Avl();
    void add(string wordin, string meaningin);
    void remove_node(string wordin);
    void search(string wordin);
    int size();
    void display();
    void range(string k1, string k2);
};
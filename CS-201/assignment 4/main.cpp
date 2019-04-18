#include <iostream>
#include <string>
#include <fstream>
#include "hashtable.hpp"
using namespace std;

int main()
{
    cout<<"Do you want to give size as an input?\n1.Yes\n2.No\n";
    int choice;
    cin>>choice;
    if(choice == 1)
    {
        int size;
        cin>>size;
        Hashtable<elem> dict(size);
    }
    Hashtable<elem> dict;
    ifstream ip("words.txt");
    string line;
    string word;
    string temp;
    string meaning;
    while(!ip.eof())
    {
        ip>>word;
        ip>>temp;
        getline(ip, meaning);
        meaning = temp + meaning;
        dict.add(word,meaning);
    }
    while(1)
    {
        cout<<"Please select\n1.Add a word\n2.Search a word\n3.Remove a word\n4.Spell Check\n5.Size\n0.Exit\n";
        int ch;
        cin>>ch;
        if(ch == 0)
        {
            break;
        }
        else if(ch == 1)
        {
            cout<<"Please provide the word\n";
            cin>>word;
            cout<<"Please provide the meaning\n";
            cin>>meaning;
            dict.add(word,meaning);
        }
        else if(ch == 2)
        {
            cout<<"Please provide the word\n";
            cin>>word;
            elem *t = dict.search(word);
            if(t != NULL)
            {
                cout<<"\nWORD::\n"<<t->word<<endl<<"MEANING::\n"<<t->meaning<<endl<<endl;
            }
            else if(t == NULL)
            {
                cout<<"\nNOT FOUND!!!\n\n";
            }
        }
        else if(ch == 3)
        {
            cout<<"Please provide the word\n";
            cin>>word;
            dict.remove(word);
        }
        else if(ch == 4)
        {
            cout<<"Please provide the word\n";
            cin>>word;
            dict.spellcheck(word);
        }
        else if(ch == 5)
        {
            cout<<"\n"<<dict.size()<<endl<<endl;
        }
    }
    return 0;
}
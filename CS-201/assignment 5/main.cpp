#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "avl.hpp"
using namespace std;

int main()
{
    Avl dict;
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
        cout<<"Please select\n1.Add a word\n2.Search a word\n3.Remove a word\n4.Count in range\n5.Display tree\n6.Size\n0.Exit\n";
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
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            dict.add(word,meaning);
        }
        else if(ch == 2)
        {
            cout<<"Please provide the word\n";
            cin>>word;
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            dict.search(word);        
        }
        else if(ch == 3)
        {
            cout<<"Please provide the word\n";
            cin>>word;
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            dict.remove_node(word);
            cout<<"\nNode is deleted(If present)!!!"<<endl<<endl;
        }
        else if(ch == 4)
        {
            string k1, k2;
            cout<<"Please provide the words with a space between them\n";
            cin>>k1>>k2;
            cout<<"The following keys are obtained\n****************************\n";
            dict.range(k1, k2);
            cout<<"****************************\n";
        }
        else if(ch == 5)
        {
            dict.display();
        }
        else if(ch == 6)
        {
            cout<<"\nCurrent size\t:\t"<<dict.size()<<endl<<endl;
        }
    }
    return 0;
}
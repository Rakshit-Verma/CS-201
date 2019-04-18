#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
#define max 100000
using namespace std;

struct elem
{
    string word;
    string meaning;
};

int currentsize = 0;

template <typename T>
class Hashtable
{
    private:
    T *elem0 = NULL;
    vector<T *>hashtable;
    int hash1(string str)
    {
        int hash = 5381;
        int c,i = 0;
        while (c = str[i++])
        {
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        }
        return hash;
    }

    int hash2(int k)
    {
        return k%7+1;
    }

    public:

    int size()
    {
        return currentsize;
    }

    Hashtable()
    {
        hashtable.resize(max,elem0);
    }

    Hashtable(int tablesize)
    {
        hashtable.resize(tablesize,elem0);
    }

    void add(string wordin, string meaningin)
    {
        T *item = new T;
        item->word = wordin;
        item->meaning = meaningin;
        int h1 = hash1(wordin);
        int h2 = hash2(h1);
        int i = 0;
        while(1)
        {
            int index = (h1+(i++)*h2)%hashtable.size();
            if(hashtable[index] != NULL && hashtable[index]->word == wordin)
            {
                hashtable[index]->meaning = meaningin;
                break;
            }
            else if(hashtable[index] == NULL)
            {
                hashtable[index] = item;
                currentsize++;
                break;
            }
        }
    }

    T* search(string wordin)
    {
        int h1 = hash1(wordin);
        int h2 = hash2(h1);
        int i = 0;
        T * temp = NULL;
        while(i<=currentsize)
        {
            int index = (h1+(i++)*h2)%hashtable.size();
            if((hashtable[index] != NULL) && (hashtable[index]->word != "-1") && (hashtable[index]->word == wordin))
            {
                return hashtable[index];
            }
        }
        return temp;
    }

    void remove(string wordin)
    {
        int h1 = hash1(wordin);
        int h2 = hash2(h1);
        int i = 0;
        while(i<=currentsize)
        {
            int index = (h1+(i++)*h2)%hashtable.size();
            if((hashtable[index] != NULL) && (hashtable[index]->word != "-1") && (hashtable[index]->word == wordin))
            {
                hashtable[index]->word = "-1";
                hashtable[index]->meaning = "-1";
                cout<<"\nWORD REMOVED\n\n";
                currentsize--;
                return;
            }
        }
        cout<<"\nNOT PRESENT IN DATABASE\n\n";
    }

    T* searchnew(string wordin)
    {
        int h1 = hash1(wordin);
        int h2 = hash2(h1);
        int i = 0;
        T *temp = NULL;
        while(i<=currentsize)
        {
            int index = (h1+(i++)*h2)%hashtable.size();
            if((hashtable[index] != NULL) && (hashtable[index]->word != "-1") && (hashtable[index]->word == wordin))
            {
                return hashtable[index];
            }
            return temp;
        }
    }

    void spellcheck(string w)
    {
        T *item = searchnew(w);
        if(item != NULL)
        {
            cout<<"\nMEANING::\n"<<item->meaning<<endl<<endl;
        }
        else
        {
            set<string> sug;
            long long int c = 0;
            cout << "Did you mean :";
            for (int i=0; i<=(w).size(); i++) 
            {
                for (char j='a'; j<='z'; j++) 
                {
                    string str1 = w;
                    string str2(1, j);
                    str1.insert(i, str2);
                    T *word1 = search(str1);
                    if(word1 != NULL)
                    { 
                        sug.insert(word1->word);
                        c++;
                    }
                }
            }
            for (int i=0; i<(w).size()-1; i++) 
            {
                string str = w;
                char temp = str[i];
                str [i] = str[i+1];
                str[i+1] = temp;
                T *word1 = search(str);
                if (word1 != NULL) 
                {
                    sug.insert(word1->word); 
                    c++;
                }
            }
            for (int i=0; i<(w).size(); i++) 
            {
                for (char j='a'; j<='z'; j++) 
                {
                    string str = w;
                    str[i] = j;
                    T *word1 = search (str);
                    if (word1 != NULL) 
                    {
                        sug.insert(word1->word);
                        c++;
                    }
                }
            }
            for (int i=0; i<(w.size()); i++) 
            {
                string str = w;
                str.erase(str.begin()+i);
                T *word1 = search (str);
                if (word1 != NULL) 
                {
                    sug.insert(word1->word);
                    c++;
                }
            }
            if (c == 0) 
                cout << "Error !!!! No Suggestions Found" << endl;
            cout<<endl;
            for (set<string>::iterator it = sug.begin(); it != sug.end(); it++) 
            {
                cout << *it << endl;
            }
            cout << endl;
        }
    }
};
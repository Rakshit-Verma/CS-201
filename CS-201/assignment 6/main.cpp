#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "graph.hpp"
using namespace std;

Vertex vertex;

int main()
{
    string capital1;
    string capital2;
    float dist;
    int n = 0;
    ifstream ipr("capitals.txt");
    if(ipr.is_open())
    {
        while(!ipr.eof())
        {
            ipr >> capital1 >> capital2 >> dist;
            if(vertex.searchcap(capital1) == -1)
            {
                vertex.add(capital1);
            }
        }
        ipr.close();
    }
    n = vertex.size();
    Edge map(n);
    ifstream ip("capitals.txt");
    int cap1, cap2;
    if(ip.is_open())
    {
        while(!ip.eof())
        {
            ip >> capital1 >> capital2 >> dist;
            cap1 = vertex.searchcap(capital1);
            cap2 = vertex.searchcap(capital2);
            if(cap1 != -1 && cap2 != -1)
            {
                map.add(cap1, cap2, dist);
            }
            else
            {
                cout<<"Invalid input!!!"<<endl;
            }
            cap1 = -1;
            cap2 = -1;
        }
        ip.close();
    }
    int t = 1;
    int choice;
    while(t)
    {
        cout<<"\nPlease select\n1.Shortest route between two capitals in terms of DISTANCE\n2.Shortest route between two capitals in terms of NUMBER OF HOPS\n3.City with largest area\n0.End\n\n-->";
        cin>>choice;
        if(choice == 1)
        {
            cout<<"Please provide the names of the capitals"<<endl;
            cin>>capital1>>capital2;
            cap1 = vertex.searchcap(capital1);
            cap2 = vertex.searchcap(capital2);
            if(cap1 != -1 && cap2 != -1)
            {
                map.searchdist(vertex, cap1, cap2);
            }
            else
            {
                cout<<"Places not found!!!"<<endl;
            }
        }
        else if(choice == 2)
        {
            cout<<"Please provide the names of the capitals"<<endl;
            cin>>capital1>>capital2;
            cap1 = vertex.searchcap(capital1);
            cap2 = vertex.searchcap(capital2);
            if(cap1 != -1 && cap2 != -1)
            {
                map.searchhops(vertex, cap1, cap2);
            }
            else
            {
                cout<<"Places not found!!!"<<endl;
            }
        }
        else if(choice == 3)
        {
            cout<<vertex.val_at_i(map.largeststate())<<" is the capital of the largest state"<<endl;
        }
        else
        {
            t = 0;
            break;
        }
    }
    return 0;
}
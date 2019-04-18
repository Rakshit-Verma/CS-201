#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INFINITY 1000000.0

class Vertex
{
    private:
    vector<string> vertex;
    public:
    Vertex()
    {
        vertex.clear();
    }
    void add(string cap)
    {
        vertex.push_back(cap);
    }
    int searchcap(string caps)
    {
        for(int i = 0; i < vertex.size(); i++)
        {
            if(caps == vertex[i])
                return i;
        }
        return -1;
    }
    string val_at_i(int i)
    {
        return vertex[i];
    }
    int size()
    {
        return vertex.size();
    }
    friend class Edge;
};

class Edge
{
    private:
    int n;
    float** map;
    public:
    Edge(int t);
    ~Edge();
    void add(int cap1, int cap2, float dist);
    void searchdist(Vertex ver, int cap1, int cap2);
    void searchhops(Vertex ver, int cap1, int cap2);
    int largeststate();
    friend class Vertex;
};
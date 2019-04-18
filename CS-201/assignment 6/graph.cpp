#include "graph.hpp"

Edge::Edge(int t)
{
    n = t;
    map = new float*[n];
    for (int i = 0; i < n; i++) 
    {
        map[i] = new float[n];
        for (int j = 0; j < n; j++)
            map[i][j] = INFINITY;
    }
}

Edge::~Edge()
{
    for(int i = 0; i < n; i++)
        delete[] map[i];
    delete[] map;
}

void Edge::add(int i, int j, float dist)
{
    map[i][j] = dist;
    // map[j][i] = dist;
}

void Edge::searchdist(Vertex ver, int startnode, int finaldestination)
{
    float cost[n][n],mindistance,distance[n];
    int visited[n],count,nextnode,i,j,pred[n];
    
    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(map[i][j]==INFINITY)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=map[i][j];
    
    //initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    
    while(count<n-1)
    {
        mindistance=INFINITY;
        
        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
            
            //check if a better path exists through nextnode            
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
 
    //print the path and distance of each node
    {
        cout<<"\nDistance of node "<<ver.val_at_i(finaldestination)<<" = "<<distance[finaldestination];
        cout<<"\nPath = "<<ver.val_at_i(finaldestination);
        
        j=finaldestination;
        do
        {
            j=pred[j];
            cout<<"<-"<<ver.val_at_i(j);
        }while(j!=startnode);
    }
}

void Edge::searchhops(Vertex ver, int startnode, int finaldestination)
{
    float cost[n][n],mindistance,distance[n];
    int visited[n],count,nextnode,i,j,pred[n];
    
    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(map[i][j]==INFINITY)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=1.0;
    
    //initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    
    while(count<n-1)
    {
        mindistance=INFINITY;
        
        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
            
            //check if a better path exists through nextnode            
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
 
    //print the path and distance of each node
    {
        cout<<"\nPath = "<<ver.val_at_i(finaldestination);
        
        j=finaldestination;
        do
        {
            j=pred[j];
            cout<<"<-"<<ver.val_at_i(j);
        }while(j!=startnode);
    }
}
int Edge::largeststate()
{
    int index = 0;
    int max1 = 0, max2 = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] != 1000000.0)
            {
                max2++;
            }
        }
        if(max1 < max2)
        {
            max1 = max2;
            index = i;
        }
        max2 = 0;
    }
    return index;
}
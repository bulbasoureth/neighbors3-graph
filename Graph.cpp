//
//  Question3.cpp
//  hw7
//
//  Created by Diana Chen on 4/13/16.
//  Copyright © 2016 Pocoa. All rights reserved.
//

#include "Graph.h"


using namespace std;

Graph ::Graph(){}

//add a vertex into the set
void Graph::addVertex(string vert){
    //decding the ID and where to place it
    vertices.emplace(vert);
    //output the sets
    //        for (it = vertices.begin();it != vertices.end();it++)
    //        {
    //            cout<<*it<<" ";
    //        }
    //        cout<<endl;
    //        for (itss = edges.begin();itss != edges.end();itss++)
    //        {
    //            cout<<itss->first<<" "<<itss->second<<" "<<endl;
    //        }
    //        cout<<endl;
}

//adding an edge, a pair of vertices into the set of edges
void Graph::addEdge(undirectedEdge newEdge){
    
    //checking to make sure the edge is not already in the set
    set<string>::const_iterator iter1;
    set<string>::const_iterator iter2;
    iter1 = vertices.find(newEdge.first);
    iter2 = vertices.find(newEdge.second);
    
    //add the edge
    if (iter1 != vertices.end() && iter2 != vertices.end())
        edges.insert(newEdge);
}


// looks for the edges in set
bool Graph::isEdge(undirectedEdge newEdge){
    for (set<undirectedEdge>::iterator itss = edges.begin(); itss != edges.end(); itss++) {
        
        //checking if there is an edge, still counts if it's inverted ex. (1,7) == (7,1)
        bool b1 = (itss->second == newEdge.second && itss->first == newEdge.first);
        bool b2 = (itss->second == newEdge.first && itss->first == newEdge.second);
        
        if (b1 || b2)
            return true;
    }
    return false;
}
vector<string> Graph::distThreeNeighbors(string vertex) {
    set<string> result;
    for (set<string>::iterator  vert2 = vertices.begin(); vert2 != vertices.end(); vert2++)
    {
        if (isEdge (undirectedEdge(vertex, *vert2)))
        {
            result.emplace(*vert2);
            for (set<string>::iterator  vert3 = vertices.begin(); vert3 != vertices.end(); vert3++)
            {
                if(isEdge(undirectedEdge(*vert2,*vert3)))
                {
                    result.emplace(*vert3);
                    for (set<string>::iterator  vert4 = vertices.begin(); vert4 != vertices.end(); vert4++)
                    {
                        if(isEdge(undirectedEdge(*vert3,*vert4)))
                        {
                            result.emplace(*vert4);
                        }
                        
                    }
                }
            }
        }
    }
    //turn it into a vector
    vector<string> resul;
    for (set<string>::iterator  x = result.begin(); x != result.end(); x++)
    {
        resul.push_back(*x);
    }
    return resul;
}

//
//  Graph.hpp
//  hw7
//
//  Created by Diana Chen on 4/13/16.
//  Copyright © 2016 Pocoa. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

typedef pair<string, string> undirectedEdge;
typedef set<string>::iterator it;


class Graph {
    
private:
  
    set<undirectedEdge> edges;
    map< int,string > colors;

public:
    
    Graph();
    
    void addVertex(string vert);
    
    void addEdge(undirectedEdge newEdge);


    bool isEdge(undirectedEdge newEdge);
    vector<string> distThreeNeighbors(string vertex);
    set<string> vertices;
};
#endif /* Graph_h */

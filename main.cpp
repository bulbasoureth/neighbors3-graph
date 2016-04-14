//
//  main.cpp
//  hw7
//
//  Created by Diana Chen on 4/13/16.
//  Copyright © 2016 Pocoa. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include "Graph.h"


Graph graphy;

int main(int argc, const char * argv[]) {

    string filen = argv[1];
    string lines;
    string s(argv[2]);
    int vlength = s.length();
    string first, ev, ee;
    string isspace = "\"\"";
    int dist, num1, num2;
    ifstream afile;
    afile.open(filen);
    if(afile.is_open())
    {
        while(!afile.eof())
        {
            afile>>first;
            if (first == s) //the source
            {
                graphy.addVertex(first);
                //vertices.emplace(first);
                afile>>num1>>num2;
                //store into vertex
                break;
            }
            else
            {
                //dumps
                afile>>ev>>ee;
            }
        }
    }
    afile.close();
    ifstream aafile;
    aafile.open(filen);
    if(aafile.is_open())
    {
    
        
        while(!aafile.eof())
        {
            aafile>>first;
            if(first == isspace)
            {
                aafile>>ev>>ee>>dist;
                //add edge
                graphy.addEdge(undirectedEdge(ev,ee));
                //edges.emplace(undirectedEdge(ev, ee));
                
            }
            
            else if(!graphy.vertices.empty() && first != isspace && (first.length() == vlength))
            {
                graphy.addVertex(first);
                //                vertices.emplace(first);
                aafile>>num1>>num2; //dump the rest
                
            }
            else
            {
                //dumps
                aafile>>ev>>ee;
            }
        }
        aafile.close();
        
        
    }

    
        vector<string> resutl =graphy.distThreeNeighbors(s);
        sort(resutl.begin(),resutl.end());
        cout<<s<<":"<<endl;
        for (vector<string>::iterator res = resutl.begin(); res != resutl.end(); res++)
        {
            cout<<*res<<endl;
        }

    return 0;
}

/*
 * Graph.h
 *
 *  Created on: Mar 12, 2016
 *      Author: root
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include <vector>
using namespace std;
class Graph{
    protected:
    int vertexs;
    int edges;
    vector <vector<int> > adj;

    public:
    int mincolour;
    Graph(int v,int e);
    int getEdges(){
        return edges;
    }
    int getVertexs(){
        return vertexs;
    }
    vector<int> ADJ(int x){
        return adj[x];
    }
    void insert(int x,int y);
    void printGraph();
    int levelOf(int x){ return adj[x].size();}
    void greeding();
};

#endif /* GRAPH_H_ */

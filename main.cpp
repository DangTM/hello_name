/*
 * main.cpp
 *
 *  Created on: Mar 12, 2016
 *      Author: root
 */
#include <iostream>

#include "Graph.h"
using namespace std;
int main(){
	int v,e;
	cin>>v>>e;
	Graph G(v,e);
	G.printGraph();
	G.greeding();
	cout<<endl;
	cout<<G.mincolour;

}




/*
 * Graph.cpp
 *
 *  Created on: Mar 12, 2016
 *      Author: root
 */

#include "Graph.h"

Graph::Graph(int v,int e){
    vertexs=v;
    adj.resize(v);
    vertexs=v;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        insert(x,y);
    }
}
void  Graph::insert(int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
    edges++;
}
void Graph::printGraph(){
    cout<<"Graph:\n";
        for(int i=0;i<vertexs;i++){
            cout<<i<<": ";
            vector<int> gm;
            gm=ADJ(i);
            for(int i=0;i<gm.size();i++){
                cout<<gm[i];
            }
            cout<<endl;
        }

}
void Graph::greeding(){
	mincolour=0;
	vector<int> result;
	for(int i=0;i<vertexs;i++)
		result.push_back(-1);
	//Tao ra mo list ghi nhan tung diem se to mau gi, mac dinh -1 la khog to mau


	vector<bool> check;
	check.resize(vertexs);
	//tao ra mot list ghi nhan mau gi da duoc to doi vs cac o ke x

	result[0]=0;
	//to mau cho o dau tien
	mincolour++;

	for(int i=1;i<vertexs;i++){
		//DUyet tung diem i
		for(vector<int>::iterator j=adj[i].begin();j!=adj[i].end();j++){
			//Xet tung diem ke vs diem i
			if(result[*j]!=-1)
				//Neu mot trong nhug diem ke vs diem i da to mau
				check[result[*j]]=true;
				//THi ghi nhan rang mau do da dc to
		}


		int color;
		for(color=0;color<vertexs;color++){
			//TIm ra trong hop mau, mau dau tien chua dc cac o ke i to
			if(check[color]==false)
				break;
		}

		result[i]=color;
		//to diem do vs mau color

		for(vector<int>::iterator j=adj[i].begin();j!=adj[i].end();j++){
					if(result[*j]!=-1)
						check[result[*j]]=false;
				}
		//Tra ve de xet cho diem tiep theo

	}
	for(int i=0;i<vertexs;i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<vertexs;i++){
		bool flag=true;
		for(int j=0;j<i;j++){
			if(result[i]==result[j])
				flag=false;
		}
		if(flag==true)
			mincolour++;
	}
}

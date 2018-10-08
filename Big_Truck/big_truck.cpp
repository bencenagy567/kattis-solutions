#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int nodes;
	cin >> nodes;

	vector<list<pair<int,int>>> graph;
	vector<int> packages;
	
	for(int i=0; i<nodes; i++){
		//scanf("%d",packages[i]);
		int pack;
		cin >> pack;
		packages.push_back(pack);
	}

	int edges;
	cin >> edges;
	graph.resize(nodes);
	for(int i=0; i<edges; i++){
		int a, b, d;
		//scanf("%d %d %d", &a, &b, &d);
		cin >> a; cin >> b; cin >> d;
		graph[a-1].push_back(make_pair(b-1,d));
	}

	// for(int i=0; i<nodes; i++){
	// 	for(int j=0; j<nodes; j++){
	// 		printf("%d ", graph[i][j]);	
	// 	}
	// 	printf("\n");
	// }

	// pair<int, int> start = make_pair(0,0);
	queue<pair<int,int>>  Q;
	Q.push(make_pair(0,0));
	while(!Q.empty()){
		pair<int,int> curr = Q.front();

		if(){

		}
		if(){
			
		}
		if(){
			
		}
		if(){
			
		}
	}

	return 0;
}
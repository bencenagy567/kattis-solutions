#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main(){
	
	int N, M;
	scanf("%d %d",&M,&N);

	char map[N][M+1];
	vector<int> visited;

	for(int i=0; i<N; i++){
		scanf("%s", map[i]);
		//TODO: Itt mar megkeresni a P kezdopociziot
	}

	for(int i=0; i<N*M; i++) {
		visited.push_back(0);
	}

	int si, sj;
	for(int i=1; i<N-1; i++){
		for(int j=1; j<M-1; j++){
			if(map[i][j] == 'P'){
				si = i;
				sj = j;
			}
		}
	}

	int gold = 0;
	queue<pair<int,int>> Q;
	Q.push(make_pair(si,sj));

	while(!Q.empty()) {
		pair<int, int> point = Q.front();
		Q.pop();

		int dim_one_local = point.first * M + point.second;
		if(visited[dim_one_local] == 1) continue;
		visited[dim_one_local] = 1;

		if(map[point.first][point.second] == 'G') {
			gold++;
		}

		bool a = false;
		bool b = false;
		bool c = false;
		bool d = false;

		if(map[point.first-1][point.second] != '#' && visited[(point.first-1) * M + point.second] == 0){
			if(map[point.first-1][point.second] == 'T') continue;
			a = true;
		}
		if(map[point.first+1][point.second] != '#' && visited[(point.first+1) * M + point.second] == 0){
			if(map[point.first+1][point.second] == 'T') continue;
			b = true;
		}
		if(map[point.first][point.second-1] != '#' && visited[point.first * M + point.second-1] == 0){
			if(map[point.first][point.second-1] == 'T') continue;
			c = true;
		}
		if(map[point.first][point.second+1] != '#' && visited[point.first * M + point.second+1] == 0){
			if(map[point.first][point.second+1] == 'T') continue;
			d = true;
		}

		if(a) Q.push(make_pair(point.first-1,point.second));
		if(b) Q.push(make_pair(point.first+1,point.second));
		if(c) Q.push(make_pair(point.first,point.second-1));
		if(d) Q.push(make_pair(point.first,point.second+1));
	}

	printf("%d\n", gold);

	return 0;
}
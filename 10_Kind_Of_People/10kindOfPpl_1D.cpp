// Using 1D array
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main(){

	int N, M;
	scanf("%d %d",&N,&M);

	char map[N][M+1];
	vector<int> visited;
	int query = 1;

	for(int i=0; i<N; i++){
		scanf("%s", map[i]);
	}

	for(int i=0; i<N*M; i++) {
		visited.push_back(0);
	}

	int Q;
	scanf("%d",&Q);

	for(int i=0; i<Q; i++){
		int si, sj, di, dj;
		scanf("%d %d %d %d",&si,&sj,&di,&dj);
		si--, sj--, di--, dj--;

		int dim_one = si * M + sj; 
		int dim_two = di * M + dj; 

		if(map[si][sj] != map[di][dj]) {
			printf("neither\n");
		}		
		else if(dim_one == dim_two) {
			printf(map[si][sj] == '1' ? "decimal\n" : "binary\n");
		}
		else if(visited[dim_one] == 0 && visited[dim_two] == 0) {

			char kindOf = map[si][sj];
			queue<pair<int,int>> Q;

			Q.push(make_pair(si,sj));

			while(!Q.empty()) {
				pair<int, int> point = Q.front();
				Q.pop();

				int dim_one_local = point.first * M + point.second;

				if(visited[dim_one_local] != 0) continue;
				
				visited[dim_one_local] = query;

				if(point.first > 0 && map[point.first-1][point.second] == kindOf && visited[(point.first-1) * M + point.second] == 0){
					Q.push(make_pair(point.first-1,point.second));
				}
				if(point.first < N-1 && map[point.first+1][point.second] == kindOf && visited[(point.first+1) * M + point.second] == 0){
					Q.push(make_pair(point.first+1,point.second));
				}
				if(point.second > 0 && map[point.first][point.second-1] == kindOf && visited[point.first * M + point.second-1] == 0){
					Q.push(make_pair(point.first,point.second-1));
				}
				if(point.second < M-1 && map[point.first][point.second+1] == kindOf && visited[point.first * M + point.second+1] == 0){
					Q.push(make_pair(point.first,point.second+1));
				}
			}

			query++;
			printf(visited[dim_two] ? (map[si][sj] == '1' ? "decimal\n" : "binary\n") : "neither\n");
		}
		else if(visited[dim_one] == visited[dim_two]) {
			printf(map[si][sj] == '1' ? "decimal\n" : "binary\n");
		}
		else {
			printf("neither\n");
		}
	}

	return 0;
}

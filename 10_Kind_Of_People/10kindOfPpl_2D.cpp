//using 2D array

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main(){

	int N, M;
	cin >> N >> M;
	vector<vector<int>> map;
	vector<vector<int>> visited;
	int query = 1;

	map.resize(N);
	visited.resize(N);
	for(int i=0; i<N; i++){
		map[i].resize(M);
		string digits;
		cin >> digits;
		for(int j=0; j<M; j++){
			map[i][j] = digits[j] - '0'; //char to int conversion
			visited[i][j] = 0;
		}
	}

	int Q;
	cin >> Q;
	for(int i=0; i<Q; i++){
		int si, sj, di, dj;
		cin >> si >> sj >> di >> dj;
		si--, sj--, di--, dj--;

		if(map[si][sj] != map[di][dj]) {
			cout << "neither" << endl;
		}
		else if(si == di && sj == dj) {
			map[si][sj] == 1 ? cout << "decimal\n" : cout << "binary\n";
		}
		else if(visited[si][sj] == 0 && visited[di][dj] == 0) {
			int kindOf = map[si][sj];
			queue<pair<int,int>> Q;

			int N = map.size(); int M = map[0].size();

			Q.push(make_pair(si,sj));

			while(!Q.empty()) {
				pair<int, int> point = Q.front();
				Q.pop();

				if(visited[point.first][point.second] != 0) continue;
				
				visited[point.first][point.second] = query;

				if(point.first > 0 && map[point.first-1][point.second] == kindOf && visited[point.first-1][point.second] == 0){
					Q.push(make_pair(point.first-1,point.second));
				}
				if(point.first < N-1 && map[point.first+1][point.second] == kindOf && visited[point.first+1][point.second] == 0){
					Q.push(make_pair(point.first+1,point.second));
				}
				if(point.second > 0 && map[point.first][point.second-1] == kindOf && visited[point.first][point.second-1] == 0){
					Q.push(make_pair(point.first,point.second-1));
				}
				if(point.second < M-1 && map[point.first][point.second+1] == kindOf && visited[point.first][point.second+1] == 0){
					Q.push(make_pair(point.first,point.second+1));
				}
			}

			query++;
			visited[di][dj] ? (map[si][sj] == 1 ? cout << "decimal\n" : cout << "binary\n") : cout << "neither\n";
		}
		else if(visited[si][sj] == visited[di][dj]) {
			map[si][sj] == 1 ? cout << "decimal\n" : cout << "binary\n";
		}
		else {
			cout << "neither" << endl;
		}
	}

	return 0;
}
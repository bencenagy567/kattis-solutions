#include <iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;

    for(int i=0; i<test; i++){
        int milk, cats;
        cin >> milk >> cats;

        int graph[cats][cats];
        int edges = (cats * (cats-1)) / 2;

        for(int j=0; j<edges; j++){
            int x, y, dist;
            cin >> x >> y >> dist;

            graph[x][y] = graph[y][x] = dist;
        }

        int visited[cats];
        int weigth[cats];
        for(int k=0; k<cats; k++) {
            visited[k] = 0;
            weigth[k] = graph[0][k];
        }

        int cat = 1;
        int total_weight = 0;
        visited[0] = 1;

        while(cat < cats) {
            int min_dist = 3001;
            int ind = -1;

            for(int k=0; k<cats; k++){
                if(visited[k] == 0 && weigth[k] < min_dist){
                    min_dist = weigth[k];
                    ind = k;
                }
            }

            visited[ind] = 1;
            total_weight += min_dist;

            for(int k=0; k<cats; k++){
                weigth[k] = min(weigth[k], graph[ind][k]);
            }

            cat++;
        }


        cout << (milk >= cats + total_weight ? "yes\n" : "no\n");
    }




    return 0;
}
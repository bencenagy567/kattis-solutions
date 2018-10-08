#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

void Combination(vector<pair<int, int>> a, int reqLen, int start, int currLen, bool check[], int len, int &diff) 
{
	if(currLen > reqLen){
		return;
	}
	else if (currLen == reqLen) 
	{
		int total_s = 1;
		int total_b = 0;
		for (int i = 0; i < len; i++) 
		{
			if (check[i] == true) 
			{
				total_s *= a[i].first;
				total_b += a[i].second;
			}
		}
		if(abs(total_s - total_b) < diff) diff = abs(total_s - total_b);

		return;
	}
	
	if (start == len) return;
	
	check[start] = true;
	Combination(a, reqLen, start + 1, currLen + 1, check, len, diff);
	
	check[start] = false;
	Combination(a, reqLen, start + 1, currLen, check, len, diff);
}

int main(){
	
	int n;
	scanf("%d",&n);

	vector<pair<int, int>> ingredients;
	int s, b;
	
	scanf("%d %d",&s,&b);
	int diff = abs(s-b);
	ingredients.push_back(make_pair(s,b));

	bool check[n];
	for(int i=1; i<n; i++){

		scanf("%d %d",&s,&b);
		int curr_diff = abs(s-b);
		ingredients.push_back(make_pair(s,b));

		if(curr_diff < diff) diff = curr_diff;

		check[i-1] = false;
	}

	for(int i = 1; i <= n; i++)
	{
		Combination(ingredients, i, 0, 0, check, n, diff);
	}

	printf("%d\n", diff);

	return 0;
}
//Implementation with array - 0.22s
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main() {

	int n;

	while (cin >> n) {
		cin.ignore();

		int array[n];
		int elem;
		for (int i=0; i<n; i++) {
			cin >> elem;
			array[i] = elem;
		}
		
		int P[n];
		int M[n+1];
		for (int i=0; i<n; i++) {
			P[i] = 0;
		}

		for (int i=0; i<n+1; i++) {
			M[i] = 0;
		}

		int L = 0;

		for (int i=0; i<n; i++) {
			int lo = 1;
			int hi = L;

			while (lo <= hi) {
				int mid = (lo+hi)/2;
				if (array[M[mid]] < array[i]) {
					lo = mid + 1;
				}
				else {
					hi = mid - 1;
				}
			}

			int new_L = lo;
			P[i] = M[new_L-1];
			M[new_L] = i;

			if (new_L > L) {
				L = new_L;
			}
		}

		vector<int> S;
		int k = M[L];
		
		for (int i=0; i<=L-1;i++) {
			S.push_back(k);
			k = P[k];
		}

		cout << S.size() << endl;

		for (auto it = S.rbegin(); it != S.rend(); it++) {
	    	cout << *it << " ";
		}

		cout << endl;
	}
	return 0;
}
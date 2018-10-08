#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int GetCeilIndex(int arr[], vector<int> &T, int l, int r,
                 int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l)/2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }
 
    return r;
}

int main() {

	int n;
	
	while (cin >> n) {
		cin.ignore();

		if (n == 0) {
			return 0;
		}

		int array[n];
		for (int i=0; i<n; i++) {
			cin >> array[i];
		}

		vector<int> tailIndices(n, 0);
		vector<int> prevIndices(n, -1);

		int len = 1;
		for (int i=1; i<n; i++) {
			if (array[i] < array[tailIndices[0]]) {
				tailIndices[0] = -1;
			}
			else if (array[i] > array[tailIndices[len-1]]) {
				prevIndices[i] = tailIndices[len-1];
				tailIndices[len++] = i;
			}
			else {
				int pos = GetCeilIndex(array, tailIndices, -1, len-1, array[i]);
				prevIndices[i] = tailIndices[pos-1];
				tailIndices[pos] = i;
			}
		}

		cout << len << endl;
		vector<int> res;
		for (int i = tailIndices[len-1]; i >= 0; i = prevIndices[i]) {
	        res.push_back(i);
		}
		
		for(int i=len-1; i >= 0; i--) {
			cout << res[i] << " ";
		}

		cout << endl;		
	}

	return 0;
}
#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
    	int g, first, king;
    	cin >> g >> first;

    	for(int j=1; j<g; j++){
    		int curr;
    		cin >> curr;
    		if(first+1 != curr){
    			king = j;
    		}
    		first = curr;
    	}
    	cout << king << endl;

    }


	return 0;
}
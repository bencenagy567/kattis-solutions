#include <stdio.h>

using namespace std;

int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
    	int g, first, king;
    	scanf("%d", &g);
        scanf("%d", &first);

    	for(int j=1; j<g; j++){
    		int curr;
    		scanf("%d", &curr);
    		if(first+1 != curr){
    			king = j;
    		}
    		first = curr;
    	}
    	printf("%d\n", king);

    }


	return 0;
}
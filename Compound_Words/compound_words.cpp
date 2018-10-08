#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	vector<string> text;
	string word;
	while(cin >> word) {
		//for(int i=0; i<4; i++) {
		//	cin >> word;
			text.push_back(word);	
		//}	
	}

	set<string> result;
	for(int i=0; i<text.size(); i++){
		for(int j=0; j<text.size(); j++){
			if(i == j) continue;
			result.insert(text[i] + text[j]);
		}
	}
	
	for(auto it=result.begin(); it!=result.end(); it++){
		cout << *it << endl;
	}

	return 0;
}
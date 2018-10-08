#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(){
	
	int tests;
	cin >> tests;
	for(int i=0; i<tests; i++){
		int card_num;
		cin >> card_num;

		vector<int> cards;
		for(int i=0; i<card_num; i++) {
			cards.push_back(i+1);
		}

		list<int> orig_pack;
		int pos = card_num;
		int shift = card_num;
		for(int i=pos-1; i>=0; i--){
			orig_pack.push_front(cards[i]);

			for(int j=0; j<shift; j++){
				int tmp_card = orig_pack.back();
				orig_pack.pop_back();
				orig_pack.push_front(tmp_card);
			}
			shift--;
		}

		for(auto it=orig_pack.begin(); it!=orig_pack.end(); it++){
			cout << *it << " ";
		}

	}

	return 0;
}
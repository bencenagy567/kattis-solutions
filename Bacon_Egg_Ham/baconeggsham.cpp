#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, vector<string> > report;
	set<string> dishes;
	int i;

	while (cin >> i) {
		cin.ignore();

		for (int j=0; j<i; j++) {
			string name, dish, line;
			size_t index = -1;

			getline(cin, name, ' ');
			getline(cin, line);

			do {
				index++;
				dish = line.substr(index, line.find(' ', index) - (index));
				dishes.insert(dish);
				report[dish].push_back(name);
				index = line.find(' ', index + 1);
			} while (index != string::npos);
		}

		for (auto dish_name : dishes) {
			cout << dish_name << ' ';
			sort(report[dish_name].begin(), report[dish_name].end());
			for (auto item : report[dish_name]) {
				cout << item << ' ';
			}
			cout << endl;
		}

		report.clear();
		dishes.clear();

		cout << endl;
	}

	return 0;
}
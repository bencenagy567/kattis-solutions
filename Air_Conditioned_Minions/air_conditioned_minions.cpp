#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool comp(pair<int, int> r1, pair<int, int> r2){
    return (r1.second < r2.second) ? true : false;
}

int main()
{
    int n = 0;
    cin >> n;

    vector<pair<int, int>> ranges;
    
    for(int i=0; i<n; i++){
        int start, end;
        cin >> start >> end;
        ranges.push_back(make_pair(start,end));
    }

    sort(ranges.begin(),ranges.end(), comp);

    cout << endl;
    for(int i=0; i<ranges.size(); i++){
        cout << ranges[i].first << " " << ranges[i].second << endl;
    }
    cout << endl;
    
    int rooms = 1;
    int temp = ranges[0].second;

    for(int i=1; i<ranges.size(); i++){
        if(ranges[i].first > temp){
            rooms++;
            temp = ranges[i].second;
        }
    }

    cout << rooms << endl;

    return 0;
}
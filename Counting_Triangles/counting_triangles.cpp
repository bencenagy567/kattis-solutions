#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct Point{
	float x, y;
	Point(float a, float b) { this->x = a; this->y = b; }
};

bool ccw(Point A, Point B, Point C) {
	return (C.y-A.y)*(B.x-A.x) > (B.y-A.y)*(C.x-A.x);
}

bool intersect(Point A, Point B, Point C, Point D) {
	return ccw(A,C,D) != ccw(B,C,D) && ccw(A,B,C) != ccw(A,B,D);
}

bool contains(int A, int B, vector<pair<int,int> > array) {
	auto elem = make_pair(A,B);
	for(int i=0; i<array.size(); i++) {
		if(array[i] == elem){
			return true;
		}
	}
	return false;
}

int main() {

	int i;
	
	while (cin >> i) {
		cin.ignore();

		if (i == 0) {
			return 0;
		}

		vector<pair<Point,Point> > segments;
		vector<pair<int,int> > intersections;

		for(int j=0; j<i; j++) {
			float x, y;

			cin >> x >> y;
			Point start(x,y);

			cin >> x >> y;
			Point end(x,y);
			
			segments.push_back(make_pair(start,end));
		}

		int n = segments.size();
		for(int i=0; i<n-1; i++) {
			for(int j=i+1; j<n; j++) {
				if (intersect(segments[i].first, segments[i].second, segments[j].first, segments[j].second)) {
					intersections.push_back(make_pair(i,j));
				}
			}
		}

		int count = 0;
		int m = intersections.size();
		for(int i=0; i<m-1; i++) {
			for(int j=i+1; j<m; j++) {
				if(intersections[i].second == intersections[j].first && contains(intersections[i].first,intersections[j].second, intersections)) {
					count ++;
				}
			}
		}

		cout << count << endl;
	}

	return 0;
}
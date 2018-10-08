#include <iostream>
#include <string>

using namespace std;

int main(){

    string today, doctor;
	cin >> today >> doctor;
	cout << ((today.length() < doctor.length()) ? "no\n" : "go\n");


	return 0;
}
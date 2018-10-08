#include <stdio.h>
#include <string.h>

using namespace std;

int main(){

    char today[1001], doctor[1001];
	scanf("%s", today);
	scanf("%s", doctor);
	printf(strlen(today) < strlen(doctor) ? "no\n" : "go\n" );


	return 0;
}
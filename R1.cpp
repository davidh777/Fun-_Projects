#include <iostream>
using namespace std;

int num_part(int n, int m){
	if ( m == 0 || n < 0 ) {
		return 0;}
	else if ( m == 1 ){
		return 1;}
	else{
		return num_part(n - m , m) + num_part(n, m - 1);}
}

int main(){
	cout << num_part(7,4);
	return 0;
}


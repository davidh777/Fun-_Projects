#include <iostream>
using namespace std;

int grid_paths(int n, int m){
	if (n == 1 || m == 1){
		return 1;}
	else{
		return grid_paths(n - 1, m) + grid_paths(n, m - 1);}

}
int main(){
	int n,m;
	cout << "Enter number for n: ";
	cin >> n;
	cout << "Enter number for m: ";
	cin >> m;
	cout << grid_paths(n,m);
	return 0;
}

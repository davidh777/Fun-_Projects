#include <iostream>
#include <cstdlib>
using namespace std;
int get_ascii(int region){
	int num;
	if (region == 0){
		num = rand()%10+48;
	}	
	else if	(region == 1){
		num = rand()%26+65;
	}
	else{ 
		num = rand()%26+97;
		}
	return num;
}
int main(){
	int max = 93;
	int len;
	char x;
	cout << "Types the lenght of password you want: ";
	cin >> len;
	char answer;
	cout << "Are Special Characters Allowed?[y/n]: ";
	cin >> answer;
        cout << "Password: ";
	if (answer == 'y'){
		int max = 93;
		int offset = 33;
		for (int i=0; i < len; i++){
                	int random_num = rand()%max;
                	x = random_num + offset;
                	cout << x;
        	}
	}
	else if (answer == 'n'){
		for (int i=0; i < len; i++){
			int region = rand()%3;
			x = get_ascii(region);
			cout << x;
		}
	}
	else{
		cout << "Rerun the program you made a mistake";
	}
	cout << "\n";
	return 0;
}

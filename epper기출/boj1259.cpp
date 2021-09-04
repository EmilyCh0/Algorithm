#include <iostream>
#include <string>
using namespace std;

int boj1259(){
	string str;
	while (true) {
		cin >> str;
		if (str == "0") {
			break;
		}
		int s = 0, e = str.length()-1;
		bool flag = true;
		while (s < e) {
			if(str[s]!=str[e]){
				flag = false;
				break;
			}
			s++;
			e--;
		}
		if (flag) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
	}
	return 0;
}


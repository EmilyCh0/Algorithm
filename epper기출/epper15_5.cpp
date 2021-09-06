
#include <iostream>
#include <string>
using namespace std;
int epper15_5() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char input[10001];
	cin >> input;
	char flag = input[0];
	int cnt = 1;
	int i = 1;
	if (input[0] == '1') {
		cout << "1";
	}
	while (input[i] != NULL) {
		if (input[i] == flag) {
			cnt++;
		}
		else {
			cout << (char)(cnt + 'A' - 1);
			flag = input[i];
			cnt = 1;
		}
		i++;
	}
	cout << (char)(cnt + 'A' - 1);

	return 0;
}
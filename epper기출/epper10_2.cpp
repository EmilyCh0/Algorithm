#include <iostream>
#include <string>
using namespace std;
int epper10_2() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char input[100];
	cin >> input;
	int tmp = 1;
	int sum = 0;
	int i = 0;
	while (input[i] != NULL) {
		if (input[i] == 'O') {
			sum += tmp;
			tmp++;
		}
		else {
			tmp = 1;
		}
		i++;
	}
	cout << sum;

	return 0;
}
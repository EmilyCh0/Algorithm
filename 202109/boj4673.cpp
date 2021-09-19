#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	bool arr[10001];
	for (int i = 0;i < 10001;i++) {
		arr[i] = true;
	}
	
	for (int i = 1;i < 10001;i++) {
		int sum = i; int tmp = i;
		while (tmp != 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum < 10001) {
			arr[sum] = false;
		}
		
	}
	for (int i = 1;i < 10001;i++) {
		if (arr[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}

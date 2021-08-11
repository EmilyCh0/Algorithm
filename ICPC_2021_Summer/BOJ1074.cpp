#include <iostream>
#include <cmath>
using namespace std;

int BOJ1074() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, r, c;
	cin >> N >> r >> c;
	int result = 0;
	
	int num = (int)pow(2, N - 1);
	while (num != 0) {
		if (r < num&&c < num) {
			result += num*num * 0;
			num /= 2;
		}
		else if (r < num&&c >= num) {
			result += num*num * 1;
			c -= num;
			num /= 2;
		}
		else if (r >= num&&c < num) {
			result += num*num * 2;
			r -= num;
			num /= 2;
		}
		else {
			result += num*num * 3;
			r -= num;
			c -= num;
			num /= 2;
		}
		
	}
	cout << result;

	return 0;
}
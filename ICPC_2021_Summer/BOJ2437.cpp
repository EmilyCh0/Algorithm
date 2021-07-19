// 다음 수가 (누적합+1) 보다 작거나 같으면 그 수까지 모두 표현 가능하다...
// 1 2 4 8 일때 누적합이 15이니까 현재 15까지 전부 표현 가능. 즉 다음 수가 16 이하이면 ok...

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BOJ2437() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0;i < N;i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	
	if (vec[0] != 1) {
		cout << 1;
		return 0;
	}
	int sum = 1;
	for (int i = 1;i < N;i++) {
		if (vec[i] > sum + 1) {
			break;
		}
		else {
			sum += vec[i];
		}
	}
	cout << sum + 1;
	return 0;
}
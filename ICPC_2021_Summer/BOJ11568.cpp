#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> vec(N);
	vector<int> dp;
	for (int i = 0;i < N;i++) {
		cin >> vec[i];
	}
	dp.resize(N, 1);
	for (int i = 1;i < N;i++) {
		for (int j = 0;j < i;j++) {
			if (vec[i] > vec[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	sort(dp.begin(), dp.end());
	cout << dp[N - 1];	
	return 0;
}
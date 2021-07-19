#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int BOJ1448() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, comp);
	
	for (int i = 0;i < N - 2;i++) {
		int sum = arr[i + 1] + arr[i + 2];
		if (arr[i] < sum) {
			sum += arr[i];
			cout << sum;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
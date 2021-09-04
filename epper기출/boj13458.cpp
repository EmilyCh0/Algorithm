#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, B, C;
	long long sum = 0;
	vector<int> A;
	cin >> N;
	A.resize(N);
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	for (int i = 0;i < N;i++) {
		int tmp = A[i];
		tmp -= B;
		if (tmp > 0) {
			sum += ceil((double)tmp / (double)C);
		}

	}
	sum += N;
	cout << sum;

	return 0;
}
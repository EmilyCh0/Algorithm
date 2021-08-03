#include <iostream>
#include <vector>
using namespace std;
int BOJ9095() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N;
	
	cin >> T;
	for (int i = 0;i < T;i++) {
		cin >> N;
		vector<int> vec;
		vec.resize(N+1, 0);
		vec[0] = 1;
		for (int i = 1;i <= N;i++) {
			if (i - 3 >= 0) {
				vec[i] += vec[i - 3];
				vec[i] += vec[i - 2];
				vec[i] += vec[i - 1];
			}
			else if (i - 2 >= 0) {
				vec[i] += vec[i - 2];
				vec[i] += vec[i - 1];
			}
			else {
				vec[i] += vec[i - 1];
			}
		}
		cout << vec[N]<<"\n";
	}

	return 0;
}
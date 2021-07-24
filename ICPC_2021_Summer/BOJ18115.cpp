#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
int BOJ18115() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	deque<int> dq;

	int N, opt;
	cin >> N;
	vector<pair<int, int>> vec;
	for (int i = 0;i < N;i++) {
		dq.push_back(i + 1);
	}

	for (int i = 0;i < N;i++) {
		cin >> opt;
		vec.push_back(make_pair(0, 0));
		if (opt == 1) {
			vec[i].first = dq.front();
			dq.pop_front();
		}
		else if (opt == 2) {
			int tmp = dq.front();
			dq.pop_front();
			vec[i].first = dq.front();
			dq.pop_front();
			dq.push_front(tmp);
		}
		else {
			vec[i].first = dq.back();
			dq.pop_back();
		}
	}
	for (int i = 0;i < N;i++) {
		vec[i].second = N-i;
	}
	sort(vec.begin(), vec.end(), compare);

	for (int i = 0;i < N;i++) {
		cout << vec[i].second << " ";
	}	
	return 0;
}
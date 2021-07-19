#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BOJ1377() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int,int>> vec;
	for (int i = 0;i < N;i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(make_pair(tmp, i));
	}
	stable_sort(vec.begin(), vec.end());
	int ans = 0;
	for (int i = 0;i < N;i++) {
		int dist = vec[i].second - i;
		ans = max(dist, ans);
	}
	cout << ans + 1;

	return 0;
}

/*
// 시간초과
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BOJ1377() {
int N;
cin >> N;
vector<int> vec(N);
for (int i = 0;i < N;i++) {
cin >> vec[i];
}
int max = 0, tmp;
vector<int> vec2 = vec;
sort(vec2.begin(), vec2.end());
for (int i = 0;i < N;i++) {
// vector<int>::iterator it <- type
auto it = find(vec.begin(), vec.end(), vec2[i]);
int idx1 = distance(vec.begin(), it);
it = find(vec2.begin(), vec2.end(), vec2[i]);
int idx2 = distance(vec2.begin(), it);
int tmp = idx1 - idx2;
if (tmp > max) {
max = tmp;
}
}
cout << max + 1;

return 0;
}
*/
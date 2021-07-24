#include <iostream>
#include <queue>
#include <string>

using namespace std;
int BOJ3078() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, K, len;
	long long ans = 0;
	string name;
	cin >> N >> K;
	queue<int> que[21];
	for (int i = 0;i < N;i++) {
		cin >> name;
		len = name.length();

		while (!que[len].empty() && i - que[len].front() > K) {
			// �����̵� ������ ���� ����� ť���� ����
			que[len].pop();
		}
		// que[len]�� ����ִ� ����� ���� ���� ���� �� �����Ƿ� size�� �����ֱ�
		ans += que[len].size();
		que[len].push(i);
	}
	cout << ans;
	
	return 0;
}

/*
// �ð��ʰ�
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int BOJ3078() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int N, K;
long long ans = 0;
string name;
cin >> N >> K;
vector<int> vec;
for (int i = 0;i < N;i++) {
cin >> name;
vec.push_back(name.length());
}
for (int i = 0;i < K;i++) {
for (int j = i + 1;j <= K;j++) {
if (vec[i] == vec[j])
ans++;
}
}
for (int i = K + 1;i < N;i++) {
for (int j = i - K;j < i;j++) {
if (vec[i] == vec[j])
ans++;
}
}
cout << ans;
return 0;
}
*/
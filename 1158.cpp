#include "header.h"
#include <iostream>

using namespace std;

int Q3() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int idx = K - 1;
	int arr[5001];

	for (int i = 0;i < N;i++) {
		arr[i] = i + 1;
	}
	if (N == 1) {
		cout << "<" << arr[0] << ">";
		return 0;
	}
	cout << "<"<<arr[idx]<<", ";
	
	arr[idx] = 0;
	for (int i = 0;i < N-1;i++) {
		int tmp = K;
		while (tmp > 0) {
			if (arr[idx] == 0) {
				idx = (idx + 1) % N;
			}
			else {
				tmp--;
				if (tmp == 0 && arr[idx] != 0) {
					if (i == N - 2) {
						cout << arr[idx] << ">";
						break;
					}						
					cout << arr[idx] << ", ";
					arr[idx] = 0;
					break;
				}
				else if (tmp == 0 && arr[idx] == 0) {
					tmp++;
				}
				idx = (idx + 1) % N;
			}
		}
	}
	return 0;
}


/*
// queue 시간 초과
#include "header.h"
#include <iostream>
#include <queue>

using namespace std;

int Q3() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N, K;
cin >> N >> K;
queue<int> que;
for (int i = 1;i <= N;i++) {
que.push(i);
}
cout << "<";
int cnt = 1;
while (!que.empty()) {
if (cnt == K) {
cnt = 1;
cout << que.front() << ", ";
que.pop();
if (que.size() == 1)
break;
}
int tmp = que.front();
que.push(tmp);
que.pop();
cnt++;
}
cout << que.front() << ">";

return 0;
}

*/
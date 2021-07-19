#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int BOJ11582() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,K;
	cin >> N;
	vector<int> vec;
	int tmp;
	for (int i = 0;i < N;i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	cin >> K;
	int unit = N / K;	
	
	/*
	for (auto it = vec.begin();it != vec.end();it+=unit) {	// iterator it = vec.begin() / auto: 타입추론
		sort(it, it + unit);
	}
	*/

	for (int idx = 0;idx < N;idx+=unit) {
		sort(vec.begin() + idx, vec.begin() + idx + unit);
	}
	
	/*
	for (int i = 0;i < N;i++) {
		cout << vec[i] << " ";
	}
	*/
	for (int x : vec) {
		cout << x << " ";
	}
	return 0;
}

/*
// 와이 시간초과??
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int BOJ11582() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int N,K;
cin >> N;
int *arr = new int[N];

for (int i = 0;i < N;i++) {
cin >> arr[i];
}
cin >> K;
int unit = pow(2, K);
int idx = 0;
while (idx < N) {
sort(arr + idx, arr + idx + unit);
idx += unit;
}

for (int i = 0;i < N;i++) {
cout << arr[i] << " ";
}
return 0;
}
*/
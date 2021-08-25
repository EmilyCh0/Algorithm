#include <iostream>
#include <vector>
#include <cmath>
//#include <algorithm>

using namespace std;

int E() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<double> vec(N);
	for (int i = 0;i < N;i++) {
		cin >> vec[i];
	}
	double ans = vec[N-1];
	for (int i = N-2;i >=0;i--) {
		ans = ceil(ans / vec[i])*vec[i];
	}
	cout << (long long)ans;

	return 0;
}

/*
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
int N;
cin >> N;
vector<int> vec(N);
for (int i = 0;i < N;i++) {
cin >> vec[i];
}
double ans=vec[0];
reverse(vec.begin(), vec.end());
for (int i = 1;i < N;i++) {
ans = ceil(ans / vec[i])*vec[i];
}
cout << (long long)ans;

return 0;
}
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> vec[13];
	int a, b,tmp;
	for (int i = 0;i < 12;i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	int sum = 0;
	for (int i = 1;i <= 12;i++) {
		if (vec[i].size() == 3) {
			for (int j = 0;j < 3;j++) {
				sum += vec[vec[i][j]].size();
			}
		}
		else {
			continue;
		}
		
		if (sum == 6) {
			cout << i;
			break;
		}
		else {
			sum = 0;
		}
	}
	return 0;
}
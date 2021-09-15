#include <iostream>
#include <deque>
#include <string>
using namespace std;

void move(int idx, int dir);

deque<char> deq[4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string str;
	for (int i = 0;i < 4;i++) {
		cin >> str;
		for (int j = 0;j < 8;j++) {
			deq[i].push_back(str[j]);
		}
	}
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int idx, dir;
		cin >> idx >> dir;
		if (idx == 1) {
			if (deq[0][2] != deq[1][6]) {
				if (deq[1][2] != deq[2][6]) {
					if (deq[2][2] != deq[3][6]) {
						move(3, dir*-1);
					}
					move(2, dir);
				}
				move(1, dir*-1);
			}
			move(0, dir);
		}
		else if (idx == 2) {
			if (deq[0][2] != deq[1][6]) {
				move(0, dir*-1);
			}
			if (deq[1][2] != deq[2][6]) {
				if (deq[2][2] != deq[3][6]) {
					move(3, dir);
				}
				move(2, dir*-1);
			}
			move(1, dir);
		}
		else if (idx == 3) {
			if (deq[1][2] != deq[2][6]) {
				if (deq[0][2] != deq[1][6]) {
					move(0, dir);
				}
				move(1, dir*-1);
			}
			if (deq[2][2] != deq[3][6]) {
				move(3, dir*-1);
			}
			move(2, dir);
		}
		else {
			if (deq[2][2] != deq[3][6]) {
				if (deq[1][2] != deq[2][6]) {
					if (deq[0][2] != deq[1][6]) {
						move(0, dir*-1);
					}
					move(1, dir);
				}
				move(2, dir*-1);
			}
			move(3, dir);
		}
	}
	int sum = 0, tmp=1;
	for (int i = 0;i < 4;i++) {
		sum += tmp*(int)(deq[i][0]-'0');
		tmp *= 2;
	}
	cout << sum;

	return 0;
}

void move(int idx, int dir) {
	if (dir == 1) {
		deq[idx].push_front(deq[idx].back());
		deq[idx].pop_back();
	}
	else {
		deq[idx].push_back(deq[idx].front());
		deq[idx].pop_front();
	}
}
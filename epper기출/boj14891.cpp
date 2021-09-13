#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	deque<int> deq1, deq2, deq3, deq4;
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;

	for (int i = 0;i < 8;i++) {
		deq1.push_back(str1[i]);
		deq2.push_back(str2[i]);
		deq3.push_back(str3[i]);
		deq4.push_back(str4[i]);
	}
	
	
	int n,tmp;

	cin >> n;
	for (int i = 0;i < n;i++) {
		int num, dir;
		cin >> num >> dir;
		if (num == 1) {
			if (dir == 1) { 
				// 1 시계
				if (deq1[2] != deq2[6]) {
					// 2 반시계
					if (deq2[2] != deq3[6]) {
						// 3 시계
						if (deq3[2] != deq4[6]) {
							// 4 반시계
							tmp = deq4.front();deq4.pop_front();deq4.push_back(tmp);
						}
						tmp = deq3.back();deq3.pop_back();deq3.push_front(tmp);
					}
					tmp = deq2.front();deq2.pop_front();deq2.push_back(tmp);
				}
				tmp = deq1.back();deq1.pop_back();deq1.push_front(tmp);
			}
			else { 
				// 1 반시계
				if (deq1[2] != deq2[6]) {
					// 2 시계
					if (deq2[2] != deq3[6]) {
						// 3 반시계
						if (deq3[2] != deq4[6]) {
							// 4 시계
							tmp = deq4.back();deq4.pop_back();deq4.push_front(tmp);
						}
						tmp = deq3.front();deq3.pop_front();deq3.push_back(tmp);
					}
					tmp = deq2.back();deq2.pop_back();deq2.push_front(tmp);
				}
				// 1 반시계
				tmp = deq1.front();deq1.pop_front();deq1.push_back(tmp);
			}
		}
		else if (num == 2) {
			if (dir == 1) {
				// 2 시계
				if (deq1[2] != deq2[6]) {
					// 1 반시계
					tmp = deq1.front();deq1.pop_front();deq1.push_back(tmp);
				}
				if (deq2[2] != deq3[6]) {
					// 3 반시계
					if (deq3[2] != deq4[6]) {
						// 4 시계
						tmp = deq4.back();deq4.pop_back();deq4.push_front(tmp);
					}
					tmp = deq3.front();deq3.pop_front();deq3.push_back(tmp);
				}
				tmp = deq2.back();deq2.pop_back();deq2.push_front(tmp);
			}
			else {
				// 2 반시계
				if (deq1[2] != deq2[6]) {
					// 1 시계
					tmp = deq1.back();deq1.pop_back();deq1.push_front(tmp);
				}
				if (deq2[2] != deq3[6]) {
					// 3 시계
					if (deq3[2] != deq4[6]) {
						// 4 반시계
						tmp = deq4.front();deq4.pop_front();deq4.push_back(tmp);
					}
					tmp = deq3.back();deq3.pop_back();deq3.push_front(tmp);
				}
				tmp = deq2.front();deq2.pop_front();deq2.push_back(tmp);
			}
		}
		else if (num == 3) {
			if (dir == 1) {
				// 3 시계
				if (deq2[2] != deq3[6]) {
					// 2 반시계
					if (deq1[2] != deq2[6]) {
						// 1 시계
						tmp = deq1.back();deq1.pop_back();deq1.push_front(tmp);
					}
					tmp = deq2.front();deq2.pop_front();deq2.push_back(tmp);
				}
				if (deq3[2] != deq4[6]) {
					// 4 반시계
					tmp = deq4.front();deq4.pop_front();deq4.push_back(tmp);
				}
				tmp = deq3.back();deq3.pop_back();deq3.push_front(tmp);
			}
			else {
				// 3 반시계
				if (deq2[2] != deq3[6]) {
					// 2 시계
					if (deq1[2] != deq2[6]) {
						// 1 반시계
						tmp = deq1.front();deq1.pop_front();deq1.push_back(tmp);
					}
					tmp = deq2.back();deq2.pop_back();deq2.push_front(tmp);
				}
				if (deq3[2] != deq4[6]) {
					// 4 시계
					tmp = deq4.back();deq4.pop_back();deq4.push_front(tmp);
				}
				tmp = deq3.front();deq3.pop_front();deq3.push_back(tmp);
			}
		}
		else {
			if (dir == 1) {
				// 4 시계
				if (deq3[2] != deq4[6]) {
					// 3 반시계
					if (deq2[2] != deq3[6]) {
						// 2 시계
						if (deq1[2] != deq2[6]) {
							// 1 반시계
							tmp = deq1.front();deq1.pop_front();deq1.push_back(tmp);
						}
						tmp = deq2.back();deq2.pop_back();deq2.push_front(tmp);
					}
					tmp = deq3.front();deq3.pop_front();deq3.push_back(tmp);
				}
				tmp = deq4.back();deq4.pop_back();deq4.push_front(tmp);
			}
			else {
				// 4 반시계
				if (deq3[2] != deq4[6]) {
					// 3 시계
					if (deq2[2] != deq3[6]) {
						// 2 반시계
						if (deq1[2] != deq2[6]) {
							// 1 시계
							tmp = deq1.back();deq1.pop_back();deq1.push_front(tmp);
						}
						tmp = deq2.front();deq2.pop_front();deq2.push_back(tmp);
					}
					tmp = deq3.back();deq3.pop_back();deq3.push_front(tmp);
				}
				tmp = deq4.front();deq4.pop_front();deq4.push_back(tmp);
			}
		}
	}
	int sum = 0;
	if (deq1[0] == (int)'1') {
		sum += 1;
	}
	if (deq2[0] == (int)'1') {
		sum += 2;
	}
	if (deq3[0] == (int)'1') {
		sum += 4;
	}
	if (deq4[0] == (int)'1') {
		sum += 8;
	}
	
	cout << sum;
	return 0;
}
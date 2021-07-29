#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

bool checki[9][10];
bool checkj[9][10];
bool checksq[9][10];
int arr[9][9];
pair<int, int> emptypair[82];

bool flag;

void backtrack(int k, int count);

int BOJ2239() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string tmp;
	int num, count = 0;
	for (int i = 0;i < 9;i++) {
		cin >> tmp;
		for (int j = 0;j < 9;j++) {
			num = tmp.at(j) - '0';
			arr[i][j] = num;
			checki[i][num] = true;
			checkj[j][num] = true;
			checksq[(i / 3) * 3 + (j / 3)][num] = true;
			if (num == 0) {
				emptypair[count] = make_pair(i, j);
				count++;
			}
		}
	}

	flag = true;	// 답이 여러개일때 전부 출력 방지
	backtrack(0, count);

	return 0;
}

void backtrack(int k, int count) {
	if (k == count) {
		for(int i=0;i<count;i++) {
			if (arr[emptypair[i].first][emptypair[i].second] == 0) {
				return;
			}
		}
		if (flag) {
			// 결과 출력
			for (int i = 0;i < 9;i++) {
				for (int j = 0;j < 9;j++) {
					cout << arr[i][j];
				}
				cout << "\n";
			}
			flag = false;
			return;
		}
	}
	else {
		int pi = emptypair[k].first;
		int pj = emptypair[k].second;
		if (flag) {
			for (int i = 1;i <= 9;i++) {
				if (checki[pi][i] == false && checkj[pj][i] == false && checksq[(pi / 3) * 3 + pj / 3][i] == false) {
					checki[pi][i] = true;
					checkj[pj][i] = true;
					checksq[(pi / 3) * 3 + pj / 3][i] = true;
					arr[pi][pj] = i;
					backtrack(k + 1, count);

					checki[pi][i] = false;
					checkj[pj][i] = false;
					checksq[(pi / 3) * 3 + pj / 3][i] = false;
					arr[pi][pj] = 0;
				}
			}
		}
	}
}


#include "header.h"
#include <iostream>
using namespace std;

int Q8() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int arr[1000];
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}
	int idx = 0;
	int move;
	cout << idx + 1 << " ";
	move = arr[idx];
	arr[idx] = 0;
	for (int i = 0;i < N-1;i++) {		
		if (move > 0) {
			while (move != 0) {
				idx = (++idx) % N;
				if (arr[idx] == 0) {
					continue;
				}
				move--;
			}
			cout << idx + 1 << " ";
			move = arr[idx];
			arr[idx] = 0;
		}
		else {
			while (move != 0) {
				if (--idx == -1) {
					idx = N-1;
				}
				if (arr[idx] == 0) {
					continue;
				}
				move++;
			}
			cout << idx + 1 << " ";
			move = arr[idx];
			arr[idx] = 0;
		}
	}
	return 0;
}
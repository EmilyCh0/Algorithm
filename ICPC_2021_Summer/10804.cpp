#include "header.h"

#include <iostream>

using namespace std;


int Q2() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int s, e;
	for (int i = 0;i < 10;i++) {
		cin >> s >> e;
		s--; e--;
		while (s <= e) {
			int tmp = arr[s];
			arr[s++] = arr[e];
			arr[e--] = tmp;
		}
	}
	for (int i = 0;i < 20;i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
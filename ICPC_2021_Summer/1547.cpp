#include "header.h"

#include <iostream>

using namespace std;

int Q4() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int ball = 1;
	int a, b;
	for (int i = 0;i < N;i++) {
		cin >> a >> b;
		if (a == b)
			continue;
		else if (a == ball)
			ball = b;
		else if (b == ball)
			ball = a;
	}
	cout << ball;
	return 0;
}
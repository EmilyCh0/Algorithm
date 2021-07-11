#include "header.h"

#include <iostream>
using namespace std;

int Q5() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double a, b;
	cin >> a >> b;
	
	cout.precision(10);
	cout << a / b;
	return 0;
}
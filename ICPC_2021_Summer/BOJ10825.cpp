
#include "Çì´õ.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
	string name;
	int kor, eng, math;
};

bool compare(person p1, person p2) {
	if (p1.kor != p2.kor) {
		return p1.kor > p2.kor;
	}
	else if (p1.eng != p2.eng) {
		return p1.eng < p2.eng;
	}
	else if (p1.math != p2.math) {
		return p1.math > p2.math;
	}

	return p1.name < p2.name;

}

int BOJ10825() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<person> vec(N);

	for (int i = 0;i < N;i++) {
		cin >> vec[i].name >> vec[i].kor >> vec[i].eng >> vec[i].math;
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0;i < N;i++) {
		cout << vec[i].name << "\n";
	}
	return 0;
}

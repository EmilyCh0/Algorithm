#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b) {
	return a.first < b.first;
}

int BOJ2304() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<pair<int, int>> vec;
	int maxH = -1;	// 최대 높이
	int f, s;
	for (int i = 0;i < N;i++) {
		cin >> f >> s;
		if (s > maxH) {
			maxH = s;
		}
		vec.push_back(make_pair(f, s));
	}
	sort(vec.begin(), vec.end(), comp);
	int pos = vec[0].first, posb = vec[0].first;	// pos=현재위치, posb=이전위치
	int vecIdx = 0;
	int sum = 0, hb = vec[0].second, h = vec[0].second;	// h=현재높이, hb=이전높이
	// 0번 인덱스부터 최대 높이에 도달할 때까지 오른쪽으로 이동
	while (h != maxH) {	
		if (h > hb) {
			sum += (pos - posb)*hb;
			posb= vec[vecIdx].first;
			hb = vec[vecIdx].second;
		}
		pos = vec[++vecIdx].first;
		h = vec[vecIdx].second;
	}
	sum += (pos - posb)*hb;
	int posleft = pos;	// 최대 높이 중 왼쪽 위치

	// N-1에서 다시 출발
	vecIdx = N - 1;
	pos = vec[vecIdx].first; posb = vec[vecIdx].first;
	hb = vec[vecIdx].second; h = vec[vecIdx].second;
	// N-1번 인덱스부터 최대 높이에 도달할 때까지 왼쪽으로 이동
	while (h != maxH) {
		if (h > hb) {
			sum += abs(pos - posb)*hb;
			posb = vec[vecIdx].first;
			hb = vec[vecIdx].second;
		}
		pos = vec[--vecIdx].first;
		h = vec[vecIdx].second;
	}
	sum += (posb - pos)*hb;

	// 최대 높이 지점 넓이
	sum += h*abs(pos- posleft+1);

	cout << sum;

	return 0;
}
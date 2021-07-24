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
	int maxH = -1;	// �ִ� ����
	int f, s;
	for (int i = 0;i < N;i++) {
		cin >> f >> s;
		if (s > maxH) {
			maxH = s;
		}
		vec.push_back(make_pair(f, s));
	}
	sort(vec.begin(), vec.end(), comp);
	int pos = vec[0].first, posb = vec[0].first;	// pos=������ġ, posb=������ġ
	int vecIdx = 0;
	int sum = 0, hb = vec[0].second, h = vec[0].second;	// h=�������, hb=��������
	// 0�� �ε������� �ִ� ���̿� ������ ������ ���������� �̵�
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
	int posleft = pos;	// �ִ� ���� �� ���� ��ġ

	// N-1���� �ٽ� ���
	vecIdx = N - 1;
	pos = vec[vecIdx].first; posb = vec[vecIdx].first;
	hb = vec[vecIdx].second; h = vec[vecIdx].second;
	// N-1�� �ε������� �ִ� ���̿� ������ ������ �������� �̵�
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

	// �ִ� ���� ���� ����
	sum += h*abs(pos- posleft+1);

	cout << sum;

	return 0;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long num = times.size();
	sort(times.begin(), times.end());
	long long s = 1, e = (long long)times[0] * (long long)n;
	long long mid = (s + e) / 2;

	while (s<e) {
		long long sum = 0;
		for (int i = 0;i<num;i++) {
			sum += mid / (long long)times[i];
		}
		if (sum >= n) {
			e = mid;
			mid = (s + e) / 2;
		}
		else {
			s = mid + 1;
			mid = (s + e) / 2;
		}
	}
	answer = mid;

	return answer;
}
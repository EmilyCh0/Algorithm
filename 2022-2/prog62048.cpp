using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    int small = (w > h) ? h : w;
    int gcd = 1;
    for (int i = 1; i <= small; i++) {
        if (w % i == 0 && h % i == 0) {
            gcd = i;
        }
    }
    long long cnt = (w / gcd) + (h / gcd) - 1;
    answer = (long long) w * (long long) h - (long long) gcd * cnt;

    return answer;
}
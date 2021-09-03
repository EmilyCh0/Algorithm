//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> solution(int r, int c, int zr, int zc, vector<string> words) {
	vector<string> answer;
	// 코드를 작성해주세요.

	for (int i = 0;i<r;i++) {
		string ansstr = "";
		string str = words[i];
		for (int j = 0;j<c;j++) {
			for (int k = 0;k<zc;k++) {
				ansstr += str[j];
			}
		}
		for (int j = 0;j<zr;j++) {
			answer.push_back(ansstr);
		}

	}

	return answer;
}


int epper14_7() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int r, c, zr, zc;
	vector<string> answer, words;
	string temp;

	cin >> r >> c >> zr >> zc;

	for (int i = 0; i<r; i++)
	{
		cin >> temp;
		if (temp.length()>c)
		{
			cout << "입력 범위를 초과하였습니다.\n";
			exit(1);
		}
		words.push_back(temp);
	}

	answer = solution(r, c, zr, zc, words);

	for (auto i : answer)
	{
		cout << i << endl;
	}

	return 0;
}
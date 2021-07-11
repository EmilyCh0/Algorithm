#include "header.h"
#include <iostream>
#include <string>	// string, cin.getline
#include <algorithm>	// reverse

//#include <bits/stdc++.h>
using namespace std;

int Q7() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	cin.ignore();
	for (int i = 0;i < T;i++) {
		string str, ans;
		getline(cin, str);
		int s = 0, e = 0;
		int len = str.length();
		while (e<len) {
			while (str[e] != ' '&&e<len) {
				e++;
			}
			string tmp = str.substr(s, e-s);
			reverse(tmp.begin(), tmp.end());
			tmp += " ";
			ans += tmp;
			s = ++e;
		}
		cout << ans<<'\n';		
	}
	return 0;
}

/*
#pragma warning (disable: 4996)	// strtok warning ¹«½Ã
#include "header.h"
#include <iostream>
#include <string>	// string, cin.getline
#include <algorithm>	// reverse
#include <cstring>	// strtok
using namespace std;

int Q7() {

int T;
cin >> T;
cin.ignore();

for (int i = 0;i < T;i++) {
string ans = "";
char str[1000];
cin.getline(str, 1000);
char *ptr = strtok(str, " ");
while (ptr != NULL) {
string tmp = ptr;
reverse(tmp.begin(), tmp.end());
ans = ans+tmp+" ";
ptr = strtok(NULL, " ");
}
cout << ans << "\n";
}
return 0;
}
*/
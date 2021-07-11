#include "header.h"

#include <iostream>
#include <string>	// string
#include <algorithm>	// reverse
using namespace std;

int Q6() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;
	string ans = str;
	int len = str.length();
	string tmp = "", sub;

	for (int i = 0;i < len-1;i++) {
		for (int j = i+1; j < len-1;j++) {
			sub = str.substr(0, i + 1);
			reverse(sub.begin(), sub.end());
			tmp += sub;
			sub = str.substr(i + 1, j-i);
			reverse(sub.begin(), sub.end());
			tmp += sub;
			sub = str.substr(j+1);
			reverse(sub.begin(), sub.end());
			tmp += sub;
			if (ans > tmp) {
				ans = tmp;
			}
			tmp = "";
		}
	}

	cout << ans;

	return 0;
}


/*
#include <iostream>
#include <string>	// string
#include <algorithm>	// sort
using namespace std;



int Q6() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

string str;
cin >> str;

string tmp = str;
sort(tmp.begin(), tmp.end());

char ch1 = tmp[0];

int idx1 = -1; int idx2 = -1;
int len = str.length();
for (int i = 0;i < len;i++) {
if (str[i] == ch1) {
idx1 = i;
break;
}
}

if (idx1 == len - 1) {
tmp = str.substr(0,idx1);
sort(tmp.begin(), tmp.end());
char ch2 = tmp[0];
for (int i = 0;i <= idx1;i++) {
if (str[i] == ch2) {
idx2 = i;
break;
}
}
}
else {
tmp = str.substr(idx1 + 1);
sort(tmp.begin(), tmp.end());
char ch2 = tmp[0];
for (int i = idx1+1;i <= len;i++) {
if (str[i] == ch2) {
idx2 = i;
break;
}
}
}

string ans = "";
if (idx1 < idx2) {
for (int i = idx1;i >= 0;i--) {
ans += str.at(i);
}
for (int i = idx2;i > idx1;i--) {
ans += str.at(i);
}
for (int i = str.length()-1;i > idx2;i--) {
ans += str.at(i);
}
}
else {
for (int i = idx2;i >= 0;i--) {
ans += str.at(i);
}
for (int i = idx1-1;i > idx2;i--) {
ans += str.at(i);
}
for (int i = len-1;i >= idx1;i--) {
ans += str.at(i);
}
}

cout << ans;

return 0;
}
*/
#include <iostream>
#include <deque>

using namespace std;
int BOJ20923() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, a, b;
	cin >> N >> M;
	deque<int> doque, suque,dogd,sugd;
	for (int i = 0;i < N;i++) {
		cin >> a >> b;
		doque.push_back(a);
		suque.push_back(b);
	}
	int card;

	while (true) {
		// do turn
		card = doque.back();
		doque.pop_back();
		dogd.push_front(card);
		if (doque.empty()) {
			cout << "su";
			return 0;
		}
		
		if (card == 5) {
			// do win
			while (!sugd.empty()) {
				doque.push_front(sugd.back());
				sugd.pop_back();
			}
			while (!dogd.empty()) {
				doque.push_front(dogd.back());
				dogd.pop_back();
			}
		}
		if (!sugd.empty() && !dogd.empty() && card + sugd.front() == 5) {
			// su win
			while (!dogd.empty()) {
				suque.push_front(dogd.back());
				dogd.pop_back();
			}
			while (!sugd.empty()) {
				suque.push_front(sugd.back());
				sugd.pop_back();
			}
		}
		M--;
		if (M == 0) {
			break;
		}

		// su turn
		card = suque.back();
		suque.pop_back();
		if (suque.empty()) {
			cout << "do";
			return 0;
		}
		sugd.push_front(card);
		if (card == 5) {
			// do win
			while (!sugd.empty()) {
				doque.push_front(sugd.back());
				sugd.pop_back();
			}
			while (!dogd.empty()) {
				doque.push_front(dogd.back());
				dogd.pop_back();
			}
		}
		if (!sugd.empty() && !dogd.empty() && (card + dogd.front() == 5)) {
			// su win
			while (!dogd.empty()) {
				suque.push_front(dogd.back());
				dogd.pop_back();
			}
			while (!sugd.empty()) {
				suque.push_front(sugd.back());
				sugd.pop_back();
			}
		}
		M--;
		if (M == 0) {
			break;
		}
	}
	
	if (doque.size() > suque.size()) {
		cout << "do";
	}
	else if (doque.size() == suque.size()) {
		cout << "dosu";
	}
	else {
		cout << "su";
	}

	return 0;
}

/*
// Æ²¸².. why??
#include <iostream>
#include <deque>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, a, b;
	cin >> N >> M;
	deque<int> doque, suque, dogd, sugd;
	for (int i = 0;i < N;i++) {
		cin >> a >> b;
		doque.push_back(a);
		suque.push_back(b);
	}
	int card;
	bool flag = true;
	for (int i = 0;i < M;i++) {
		if (flag) { //do 
			card = doque.back();
			doque.pop_back();
			if (doque.empty()) {
				cout << "su";
				return 0;
			}
			dogd.push_front(card);
			if (card == 5) {
				// do 
				while (!sugd.empty()) {
					doque.push_front(sugd.back());
					sugd.pop_back();
				}
				while (!dogd.empty()) {
					doque.push_front(dogd.back());
					dogd.pop_back();
				}
			}
			if (!sugd.empty() && card + sugd.front() == 5) {
				// su
				while (!dogd.empty()) {
					suque.push_front(dogd.back());
					dogd.pop_back();
				}
				while (!sugd.empty()) {
					suque.push_front(sugd.back());
					sugd.pop_back();
				}
			}

			flag = false;
		}
		else {
			card = suque.back();
			suque.pop_back();
			if (suque.empty()) {
				cout << "do";
				return 0;
			}
			sugd.push_front(card);
			if (card == 5) {
				// do 
				while (!sugd.empty()) {
					doque.push_front(sugd.back());
					sugd.pop_back();
				}
				while (!dogd.empty()) {
					doque.push_front(dogd.back());
					dogd.pop_back();
				}
			}
			if (!sugd.empty() && (card + dogd.front() == 5)) {
				// su
				while (!dogd.empty()) {
					suque.push_front(dogd.back());
					dogd.pop_back();
				}
				while (!sugd.empty()) {
					suque.push_front(sugd.back());
					sugd.pop_back();
				}
			}
			flag = true;
		}

	}
	if (doque.size() > suque.size()) {
		cout << "do";
	}
	else if (doque.size() == suque.size()) {
		cout << "dosu";
	}
	else {
		cout << "su";
	}

	return 0;
}
*/
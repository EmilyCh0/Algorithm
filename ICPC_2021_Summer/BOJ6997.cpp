#include <iostream>
#include <string>

using namespace std;

int B() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	string a, b;
	cin >> N;
	
	for (int j = 0;j < N;j++) {
		bool isUseda[] = { false,false,false,false };
		bool isUsedb[] = { false,false,false,false };
		
		int cir = 0, squ = 0;
		cin >> a >> b;
		for (int i = 0;i < 4;i++) {
			if (b[i] == a[i]) {
				cir++;
				isUseda[i] = true;
				isUsedb[i] = true;
			}
		}
		for (int i = 0;i < 4;i++) {
			if (isUsedb[i] == false) {
				for (int k = 0;k < 4;k++) {
					if ((isUseda[k] == false)&&(b[i]==a[k])) {
						squ++;
						isUseda[k] = true;
						break;
					}
				}
			}
		}
		cout << "For secret = " << a << " and guess = " << b << ", " << cir << " circles and " << squ << " squares will light up." << "\n";
	}

	return 0;
}
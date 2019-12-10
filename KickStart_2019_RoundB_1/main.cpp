#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		int N, Q;
		cin >> N >> Q;

		int result = 0;

		
		string blockStr;
		cin >> blockStr;

		for (int i = 0; i < Q; i++) {
			int L, R;
			cin >> L >> R;

			int alphbet[26] = { 0, };
			bool oddflag = false;
			if (R - L + 1 % 2 > 0) oddflag = true;
			
			for (int j = L - 1; j < R; j++) {
				alphbet[blockStr[j] - 'A']++;
			}

			bool yes = true;

			for (int i = 0; i < 26; i++) {
				if (alphbet[i] % 2 > 0) {
					if (oddflag) oddflag = false;
					else {
						yes = false;
						break;
					}
				}
			}

			if (yes) result++;

		}

		cout << "Case #" << tc << ": " << result << "\n";
	}

	return 0;
}
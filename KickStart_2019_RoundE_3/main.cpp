#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		int L, R;
		cin >> L >> R;

		int cnt = 0;

		for (int i = L; i <= R; i++) {
			int twonum = 0;
			int oddnum = 1;
			int num = i;
			
			while (num % 2 == 0) {
				twonum++;
				num /= 2;
			}
			
			for (int j = 3; j*j <= num; j+=2) {
				int tmp = 0;
				while (num%j == 0) {
					tmp++;
					num /= j;
				}
				if (tmp != 0) oddnum *= (tmp + 1);
			
			}
			if (num != 1) oddnum *= 2;

			if (twonum > 0 && oddnum*(twonum - 1) <= 2) cnt++;
			else if (twonum == 0 && oddnum <= 2) cnt++;
		}

		cout << "Case #" << tc << ": " << cnt << "\n";
	}

	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case; 
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		long long N;
		cin >> N;

		int Narr[18] = { 0, };
		long long n = N;
		int index = 0;

		while (1) {
			if (n == 0) break;
			Narr[index] = n % 10;
			n /= 10;
			index++;
		}

		long long result = 0;
		long long lowerLong = 0;
		long long higherLong = 0;

		int lower[18];
		int higher[18];

		copy(Narr, Narr + 18, lower);
		copy(Narr, Narr + 18, higher);

		for (int i = 17; i >= 0; i--) {
			if (Narr[i] % 2 == 0 && i == 0) {
				result = 0;
				break;
			}
			else if (Narr[i] % 2 > 0) {
				if (Narr[i] == 1 || Narr[i] == 3 || Narr[i] == 5 || Narr[i] == 7) { // Ã¹ È¦¼ö°¡ 135
					lower[i] = lower[i] - 1;
					higher[i] = higher[i] + 1;

					for (int j = i - 1; j >= 0; j--) {
						lower[j] = 8;
						higher[j] = 0;
					}
				}
				else { // Ã¹ È¦¼ö°¡ 9
					int tmp = i + 1;
					while (Narr[tmp] == 8) {
						tmp++;
					}

					lower[i] = lower[i] - 1;
					for (int j = i - 1; j >= 0; j--) {
						lower[j] = 8;
					}

					higher[tmp] = higher[tmp] + 2;
					for (int j = tmp - 1; j >= 0; j--) {
						higher[j] = 0;
					}
				}
				long long tt = 1;

				for (int i = 0; i < 18; i++) {
					higherLong += higher[i] * tt;
					tt *= 10;
				}

				tt = 1;
				for (int i = 0; i < 18; i++) {
					lowerLong += lower[i] * tt;
					tt *= 10;
				}

				if (N - lowerLong < higherLong - N) result = N - lowerLong;
				else result = higherLong - N;

				break;
			}
		}

		cout << "Case #" << tc << ": " << result << "\n";
	}

	return 0;
}
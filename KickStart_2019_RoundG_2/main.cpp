#include <iostream>
#include <cstring>

using namespace std;

const int MAXn = 1001;


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		int N;
		long long M;
		cin >> N >> M;

		long long A;
		int ones[51];

		memset(ones, 0, sizeof(ones));

		long long pow2[51];
		pow2[0] = 1;
		for (int i = 1; i <= 50; i++) {
			pow2[i] = 2 * pow2[i - 1];
		}

		for (int i = 0; i < N; i++) {
			cin >> A;
			int position = 0;
			while (1) {
				if (A % 2 > 0) ones[position]++;
				A = A / 2;
				position++;
				if (A == 0) break;
			}
		}

		//for (int i = 50; i >= 0; i--) {
		//	cout << ones[i] << " ";
		//}

		//cout << "\n";

		//long long m = M;
		//int len = 0;

		//while (1) {
		//	m = m / 2;
		//	len++;
		//	if (m == 0) break;
		//}

		//cout << len << "\n";

		long long sum = 0;
		long long minK[51] = { 0, };

		for (int i = 0; i <= 50; i++) {
			if (ones[i] * 2 <= N) {
				sum += pow2[i] * ones[i];
			}
			else {
				sum += (pow2[i] * (N - ones[i]));
			}
			minK[i] = sum;
		}

		//for (int i = 0; i <= 50; i++) {
		//	cout << minK[i] << " ";
		//}

		//cout << "\n";

		long long result = 0;

		if (minK[50] > M) result = -1;
		else {
			for (int i = 50; i > 0; i--) {
				long long tmp = pow2[i] * (N - ones[i]) + minK[i - 1];
				if (M - tmp >= 0) {
					M -= pow2[i] * (N - ones[i]);
					result += pow2[i];
				}
				else {
					M -= pow2[i] * ones[i];
				}
			}

			// 0 은 따로 처리
			long long tmp = pow2[0] * (N - ones[0]);
			if (M - tmp >= 0) {
				result += pow2[0];
			}
		}

		cout << "Case #" << tc << ": " << result << "\n";
	}

	return 0;
}
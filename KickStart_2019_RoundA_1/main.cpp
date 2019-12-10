#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int arr[100001];
int sub[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		int N, P;
		cin >> N >> P;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + N, compare);

		int min = 0;

		for (int i = 0; i < N - P + 1; i++) {
			sub[i] = arr[i] * P;
			for (int j = 0; j < P; j++) {
				sub[i] -= arr[i + j];
			}
			if (i == 0) min = sub[i];
			else {
				if (min > sub[i]) min = sub[i];
			}
		}

		cout << "Case #" << tc << ": " << min << "\n";
	}


	return 0;
}
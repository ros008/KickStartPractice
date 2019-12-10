#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;

	for (int tc = 1; tc <= test_case; tc++) {
		int N;
		cin >> N;

		string beauty_score;
		cin >> beauty_score;

		int total_score = 0;
		int mid = (N +1) / 2;

		for (int i = 0; i < mid; i++) {
			total_score += beauty_score[i] - '0';
		}

		int max = total_score;

		for (int i = mid; i < N; i++) {
			total_score = total_score + (beauty_score[i] - '0') - (beauty_score[i - mid] - '0');
			if (max < total_score) {
				max = total_score;
			}
		}

		cout << "Case #" << tc << ": " << max << "\n";
	}

	return 0;
}
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

long long input[1000001];
long long exp_num[1000001];

const long long MOD = 1000000007;

int N, K, x, y, C, D, E1, E2, F;

long long Pow(long long a, long long b) {
	long long ret = 1;

	while (b--) ret = (ret * a);

	return ret;
}

void get_input() {
	long long cd = C + D;
	long long Esum = E1 + E2;

	input[1] = (x + y) % F;

	//cout << "input[1] : " << input[1] << "\n";

	for (int i = 2; i <= N; i++) {
		input[i] = (cd * input[i - 1] + Esum) % F;
		//cout << "input[" << i << "] : " << input[i] << "\n";
	}
}

void get_exp_sum() {
	exp_num[1] = K;
	for (int i = 2; i <= N; i++) {
		exp_num[i] = exp_num[i - 1] + (i * (Pow(i, K) - 1) / (i - 1));
	}
}

long long get_exp_i_sum() {
	long long result = 0;

	for (int i = 1; i <= N; i++) {
		result = (result + input[i] * exp_num[i] * (N - i + 1)) % MOD;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case_num;
	cin >> test_case_num;

	for (int tc = 1; tc <= test_case_num; tc++) {

		cin >> N >> K >> x >> y >> C >> D >> E1 >> E2 >> F;
		get_input();
		get_exp_sum();
		get_exp_i_sum();

		cout << "Case #" << tc << ": " << get_exp_i_sum() << "\n";
	}

	return 0;
}
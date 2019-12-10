#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long Pow(long long x, long long n) {
	if (n == 0) return 1;
	if (n == 1) return x;

	long long half = Pow(x, n / 2);
	long long ret = half * half;

	if (n % 2 == 1) ret = ret * x;

	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case;
	cin >> test_case;
	
	for (int tc = 1; tc <= test_case; tc++) {
		int N, P;
		cin >> N >> P;

		vector<string> prefixes;

		vector<string>::iterator it1;
		vector<string>::iterator it2;

		for (int i = 0; i < P; i++) {
			string input;
			cin >> input;

			prefixes.push_back(input);
		}

		sort(prefixes.begin(), prefixes.end());

		for (it1 = prefixes.begin(); it1 != prefixes.end(); ) {
			for (it2 = it1 + 1; it2 != prefixes.end(); ) {
				string tmp1 = *it1;
				string tmp2 = *it2;

				if (tmp2.find(tmp1) == 0) {
					it2 = prefixes.erase(it2);
				}
				else {
					it2++;
				}
			}
			it1++;
		}

		//for (it1 = prefixes.begin(); it1 != prefixes.end(); it1++) {
		//	cout << *it1 << " ";
		//}

		long long total = Pow(2, N);

		for (it1 = prefixes.begin(); it1 != prefixes.end(); it1++) {
			string tmp = *it1;
			int len = tmp.length();
			total -= Pow(2, N - len);
		}
		
		cout << "Case #" << tc << ": " << total << "\n";
	}

	return 0;
}
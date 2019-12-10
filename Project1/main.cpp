#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	vector<int> ans;
	int carry = 0;

	for (int i = digits.size(); i >= 0; i++) {
		int sum = digits[i] + 1 + carry;
		if (sum > 9) {
			sum = sum % 10;
			carry = 1;
		}
		else carry = 0;

		ans.push_back(sum);
	}

	if (carry) ans.push_back(1);

	reverse(ans.begin(), ans.end());

	return ans;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	vector<int> matrix = { 1, 2, 3 };

	plusOne(matrix);

	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <string.h>
#include <iomanip>

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------

string add(string a, string b) {
	while (a.size() < b.size())a = "0" + a;
	while (a.size() > b.size())b = "0" + b;

	string ans = "";
	int up = 0;
	for (int i = a.size() - 1; i >= 0; --i) {
		int num = up + a[i] - '0' + b[i] - '0';
		up = num / 10;
		ans += to_string(num % 10);
	}
	if (up)ans += to_string(up);
	reverse(ans.begin(), ans.end());

	return ans;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n;
	cin >> n;
	if (n == 0) {
		cout << 0 << '\n';
		return 0;
	}
	string one = "0", two = "1";
	for (int i = 1; i < n; ++i) {
		string r = two;
		two = add(one, two);
		one = r;
	}
	cout << two << '\n';


	return 0;

}
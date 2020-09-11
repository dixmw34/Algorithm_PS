#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>
#include <climits>

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

bool sol(int num) {
	string s = to_string(num);
	for (int i = 2; i < s.size(); ++i) {
		if (s[i] - s[i - 1] != s[1] - s[0])return false;
	}
	return true;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, ans = 0;
	cin >> n;
	if (n <= 99)cout << n << '\n';
	else {
		for (int i = 100; i <= n; ++i) {
			if (sol(i))ans++;
		}
		cout << 99 + ans << '\n';
	}

	return 0;

}
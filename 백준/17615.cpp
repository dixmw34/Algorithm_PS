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

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

//----------------------------------------------------

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, ans = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R')ans++;
	}
	ans = min(ans, n - ans);
	int test = 0;
	bool flag = false;
	for (int i = 1; i < n; ++i) {
		if (flag && s[i] == s[0])test++;
		else if (s[i] != s[0]) flag = true;
	}
	ans = min(ans, test);
	test = 0; flag = false;
	for (int i = n-2; i >= 0; --i) {
		if (flag && s[i] == s[n - 1])test++;
		else if (s[i] != s[n - 1]) flag = true;
	}
	ans = min(ans, test);

	cout << ans << '\n';
	

	return 0;

}
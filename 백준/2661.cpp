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

bool check(string s) {
	reverse(s.begin(), s.end());
	for (int i = 1; i <= s.size() / 2; ++i) {
		if (s.substr(0, i) == s.substr(i, i))return false;
	}
	return true;
}

bool dfs(int cnt, string s) {
	if (cnt == 0) {
		cout << s << '\n';
		return true;
	}
	for (char i = '1'; i <= '3'; ++i) {
		if (check(s + i) && dfs(cnt - 1, s + i))return true;
	}
	return false;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int num;
	cin >> num;
	dfs(num, "");

	return 0;

}
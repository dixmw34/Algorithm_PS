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
	cin.tie(0); cout.tie(0);

	int n, m;
	string s;
	cin >> n >> m >> s;
	s += "!!!";

	int test = 0, ans = 0;

	for (int i = 0; i < m; ++i) {
		string a = s.substr(i, 3);
		if (a == "IOI") {
			test++;
			i++;
		}
		else {
			ans += max(0, test - n + 1);
			test = 0;
		}
	}
	cout << ans << '\n';
	

	return 0;
}
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

ll sheep[123457], wolf[123457];
vector<vector<int>>arr;

ll sol(int now, int par) {
	ll result = 0;
	if (wolf[now]) {
		for (int i = 0; i < arr[now].size(); ++i) {
			result += sol(arr[now][i], now);
		}
		return max((ll)0, result - wolf[now]);
	}
	else {
		result += sheep[now];
		for (int i = 0; i < arr[now].size(); ++i) {
			result += sol(arr[now][i], now);
		}
		return result;
	}


	return result;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, a;
	ll cnt;
	char ch;
	cin >> n;
	arr = vector<vector<int>>(n + 1);

	memset(sheep, 0, sizeof(sheep));
	memset(wolf, 0, sizeof(wolf));

	for (int i = 2; i <= n; ++i) {
		cin >> ch >> cnt >> a;
		if (ch == 'S') {
			sheep[i] = cnt;
		}
		else {
			wolf[i] = cnt;
		}
		arr[a].push_back(i);
	}

	cout << sol(1, -1) << '\n';

	return 0;

}
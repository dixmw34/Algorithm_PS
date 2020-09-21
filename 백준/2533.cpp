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
#include<string.h>

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

vector<vector<int>>arr(1000001);
int cache[1000001][2];

int sol(int now, int par, bool isea) {
	if (cache[now][isea] != -1)return cache[now][isea];
	int ret = 0;
	if (isea) {
		ret = 1;
		for (int i = 0; i < arr[now].size(); ++i) {
			if (arr[now][i] == par)continue;
			ret += min(sol(arr[now][i], now, true), sol(arr[now][i], now, false));
		}
	}
	else {
		ret = 0;
		for (int i = 0; i < arr[now].size(); ++i) {
			if (arr[now][i] == par)continue;
			ret += sol(arr[now][i], now, true);
		}
	}
	return cache[now][isea] = ret;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, a, b;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i)memset(cache[i], -1, sizeof(int) * 2);

	cout << min(sol(1, 0, true), sol(1, 0, false)) << '\n';


	return 0;

}
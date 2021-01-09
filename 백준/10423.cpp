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
#include <cassert>

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

int par[1001];
int find(int x) {
	if (par[x] == x)return x;
	else return par[x] = find(par[x]);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k, ans = 0;

	cin >> n >> m >> k;
	for (int i = 0; i <= n; ++i) {
		par[i] = i;
	}

	vector<int>gen(n + 1, -1);
	int a, b, c;
	while (k--) {
		cin >> a;
		par[a] = 0;
	}
	vector<ppi>cable;
	while (m--) {
		cin >> a >> b >> c;
		cable.push_back(ppi(c, pi(a, b)));
	}
	sort(cable.begin(), cable.end());
	for(int i = 0; i<cable.size(); ++i){
		a = cable[i].second.first, b = cable[i].second.second, c = cable[i].first;
		a = find(a), b = find(b);
		if (a != b) {
			ans += c;
			par[a] = par[b] = min(a, b);
		}
	}
	cout << ans << '\n';


	return 0;
}
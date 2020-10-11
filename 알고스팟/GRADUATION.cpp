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

int n, k, m, l;
int subject[12], semester[10], cache[10][1 << 12];

int bitcount(int num) {
	int a = 0;
	while (num) {
		a += num % 2;
		num /= 2;
	}
	return a;
}

int sol(int now, int taken) {
	if (bitcount(taken) >= k)return 0;
	if (now >= m)return INF;
	if (cache[now][taken] != -1)return cache[now][taken];

	cache[now][taken] = INF;

	int will = (~taken)&semester[now];

	for (int i = 0; i < n; ++i) {
		if ((will&(1 << i)) && ((subject[i] & taken) != subject[i]))will ^= (1 << i);
	}

	for (int take = will; take > 0; take = ((take - 1)&will)) {
		if (bitcount(take) > l)continue;
		cache[now][taken] = min(cache[now][taken], sol(now + 1, taken | take) + 1);
	}
	cache[now][taken] = min(cache[now][taken], sol(now + 1, taken));
	return cache[now][taken];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		int r, a;
		cin >> n >> k >> m >> l;
		for (int i = 0; i < n; ++i) {
			cin >> r;
			subject[i] = 0;
			while (r--) {
				cin >> a;
				subject[i] |= (1 << a);
			}
		}
		for (int i = 0; i < m; ++i) {
			cin >> r;
			semester[i] = 0;
			while (r--) {
				cin >> a;
				semester[i] |= (1 << a);
			}
		}
		memset(cache, -1, sizeof(cache));

		int result = sol(0, 0);
		if (result == INF)cout << "IMPOSSIBLE\n";
		else cout << result << '\n';
	}

	return 0;

}
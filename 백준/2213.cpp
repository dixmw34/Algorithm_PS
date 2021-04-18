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

struct Ans
{
	int num;
	vector<int>arr;
};

int n;

vector<vector<int>>link(10001);
int num[10001];
Ans dp[10001][2];
bool visit[10001][2];

Ans sol(int now, int par, bool flag) {

	int cnt = (flag ? 1 : 0);
	if (visit[now][cnt])
		return dp[now][cnt];

	visit[now][cnt] = true;
	int test1 = 0, test2 = 0;
	vector<int>arr1, arr2;
	if (flag) {
		for (int i = 0; i < link[now].size(); ++i) {
			int child = link[now][i];
			if (child == par)continue;
			Ans ans = sol(child, now, false);
			test1 += ans.num;
			for (int k = 0; k < ans.arr.size(); ++k) {
				arr1.push_back(ans.arr[k]);
			}
		}
		test1 += num[now];
		arr1.push_back(now);
	}
	for (int i = 0; i < link[now].size(); ++i) {
		int child = link[now][i];
		if (child == par)continue;
		Ans ans = sol(child, now, true);
		test2 += ans.num;
		for (int k = 0; k < ans.arr.size(); ++k) {
			arr2.push_back(ans.arr[k]);
		}
	}

	if (test1 > test2) {
		return dp[now][cnt] = Ans{ test1, arr1 };
	}
	else {
		return dp[now][cnt] = Ans{ test2, arr2 };
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> num[i];

	int a, b;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		link[a].push_back(b);
		link[b].push_back(a);
	}

	memset(visit, false, sizeof(visit));
	Ans ans = sol(1, -1, true);
	
	cout << ans.num << '\n';
	sort(ans.arr.begin(), ans.arr.end());
	for (int i = 0; i < ans.arr.size(); ++i) {
		cout << ans.arr[i] << ' ';
	}
	cout << '\n';

	return 0;
}
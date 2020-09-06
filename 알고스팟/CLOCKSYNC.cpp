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

int arr[16];
int ans = 0;
vector<vector<int>>a{ vector<int>({ 3, 7, 9, 11 }), vector<int>({ 6, 7, 8, 10, 12 }), vector<int>({ 3, 4, 5, 9, 13 }) };
int b[] = { 11, 8, 13 };

vector<vector<int> > button({
	vector<int>({ 0, 1, 2 }),
	vector<int>({ 4, 10, 14, 15 }),
	vector<int>({ 0, 4, 5, 6, 7 }),
	vector<int>({ 0, 2, 14, 15 }),
	vector<int>({ 3, 14, 15 }),
	vector<int>({ 4, 5, 7, 14, 15 }),
	vector<int>({ 1, 2, 3, 4, 5 }),
	});

void dfs(int idx, int cnt) {
	if (idx == 7) {
		for (int i = 0; i < 16; i++) {
			if (arr[i])return;
		}
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i <= 3; i++) {
		for (int k = 0; k < button[idx].size(); k++) {
			arr[button[idx][k]] = (arr[button[idx][k]] + i) % 4;
		}
		dfs(idx + 1, cnt + i);
		for (int k = 0; k < button[idx].size(); k++) {
			arr[button[idx][k]] = (arr[button[idx][k]] - i + 4) % 4;
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 16; i++) {
			cin >> arr[i];
			arr[i] = ((arr[i]) / 3) % 4;
		}
		if (arr[8] != arr[12]) {
			cout << -1 << '\n';
			continue;
		}
		
		int num = 0;
		for (int i = 0; i < 3; i++) {
			if (arr[b[i]] == 0)continue;
			int t = (4 - arr[b[i]]) % 4;
			num += t;
			for (int k = 0; k < a[i].size(); k++) {
				arr[a[i][k]] = (arr[a[i][k]] + t) % 4;
			}
		}

		ans = INF;
		dfs(0, 0);
		if (ans == INF)cout << -1 << '\n';
		else cout << ans + num << '\n';

	}

	

	return 0;

}
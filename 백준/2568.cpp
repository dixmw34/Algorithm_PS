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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n;
	cin >> n;
	vector<pi>arr(n);
	vector<vector<int>>record;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());

	vector<int>ans;
	for (int i = 0; i < n; ++i) {
		if (ans.empty() || ans.back() < arr[i].second) {
			ans.push_back(arr[i].second);
			record.push_back({ i });
		}
		else {
			int idx = lower_bound(ans.begin(), ans.end(), arr[i].second) - ans.begin();
			ans[idx] = arr[i].second;
			record[idx].push_back(i);
		}
	}
	vector<bool>visit(n, false);

	int num = record[ans.size() - 1][0];
	visit[num] = true;
	for (int i = ans.size() - 2; i >= 0; --i) {
		for (int j = record[i].size() - 1; j >= 0; --j) {
			if (num > record[i][j]) {
				num = record[i][j];
				visit[num] = true;
				break;
			}
		}
	}

	cout << n - ans.size() << '\n';
	for (int i = 0; i < n; ++i)if (!visit[i])cout << arr[i].first << ' ';
	cout << '\n';
	

	return 0;

}
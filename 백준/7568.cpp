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

#define INF 987654321

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>ppi;
typedef unsigned int ui;
typedef long long ll;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };

//----------------------------------------------------



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a, b;
	vector<pi>arr;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr.push_back(pi(a, b));
	}

	for (int i = 0; i < n; i++) {
		int ans = 1;
		for (int j = 0; j < n; j++) {
			if (arr[j].first > arr[i].first && arr[j].second > arr[i].second)ans++;
		}
		cout << ans << ' ';
	}
	cout << '\n';

	return 0;

}
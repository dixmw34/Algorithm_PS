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

	int n, m, a, ans = 0;
	vector<int>arr;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	for (int i = 1; i < n-1; i++) {
		int left = i - 1, right = i + 1;
		while (left >= 0 && right < n) {
			int num = arr[left] + arr[right] + arr[i];
			if (num <= m) {
				ans = max(ans, num);
				right++;
			}
			else {
				left--;
			}
		}
	}

	cout << ans << '\n';

	return 0;

}
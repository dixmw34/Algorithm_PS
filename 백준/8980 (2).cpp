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

struct Box
{
	int start;
	int end;
	int amount;

};

bool cmp(Box a, Box b) {
	return a.end < b.end;
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, c, m;
	cin >> n >> c >> m;
	vector<Box>arr(m);
	for (int i = 0; i < m; ++i) {
		cin >> arr[i].start >> arr[i].end >> arr[i].amount;
	}
	sort(arr.begin(), arr.end(), cmp);

	vector<int>town(n + 1, c);
	int ans = 0;

	for (int i = 0; i < m; ++i) {
		int cnt = arr[i].amount;
		for (int j = arr[i].start; j < arr[i].end; ++j) {
			cnt = min(cnt, town[j]);
		}
		if (cnt) {
			ans += cnt;
			for (int j = arr[i].start; j < arr[i].end; ++j) {
				town[j] -= cnt;
			}
		}
	}

	cout << ans << '\n';

	return 0;

}
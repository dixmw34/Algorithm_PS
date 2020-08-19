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

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

//----------------------------------------------------

struct Line
{
	int start;
	int end;

};

bool cmp(Line a, Line b) {
	if (a.start == b.start)return a.end > b.end;
	else return a.start < b.start;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a, b;
	ll ans = 0;
	vector<Line>arr;
	deque<Line>dq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr.push_back(Line{ a, b });
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		if (dq.empty() || dq.back().end < arr[i].start)dq.push_back(arr[i]);
		else if (dq.back().end < arr[i].end)dq.back().end = arr[i].end;
	}

	while (!dq.empty()) {
		ans += (ll)(dq.front().end - dq.front().start);
		dq.pop_front();
	}
	cout << ans << '\n';

	return 0;

}
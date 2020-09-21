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

struct Ball
{
	int color;
	int size;
	int idx;
};

bool cmp(Ball a, Ball b) {
	if (a.size == b.size)return a.idx < b.idx;
	else return a.size < b.size;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n;
	cin >> n;

	vector<Ball>arr(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i].color >> arr[i].size;
		arr[i].idx = i;
	}

	sort(arr.begin(), arr.end(), cmp);

	vector<ll>sum(n + 1, 0);
	vector<ll>ans(n);
	ll sum_all = 0;
	queue<Ball>q;

	for (int i = 0; i < n; ++i) {
		if (i>0 && arr[i].size != arr[i-1].size) {
			while (!q.empty()) {
				sum[q.front().color] += (ll)(q.front().size);
				sum_all+= (ll)(q.front().size);
				q.pop();
			}
		}
		ans[arr[i].idx] = sum_all - sum[arr[i].color];
		q.push(arr[i]);
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << '\n';
	}
	


	return 0;

}
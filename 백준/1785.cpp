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

	priority_queue<int>pq;
	int n, num;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		pq.push(num);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int num = pq.top() - i;
		pq.pop();
		if (num > 0)ans += (ll)num;
		else break;
	}
	cout << ans << '\n';


	return 0;

}
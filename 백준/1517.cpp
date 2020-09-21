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

vector<int>a;
vector<int>temp;
ll ans = 0;

void merge(int start, int end) {
	if (start == end)return;

	int mid = (start + end) / 2;

	merge(start, mid);
	merge(mid + 1, end);

	int i = start, j = mid + 1, idx = start;

	while (i <= mid || j <= end) {
		if (i == mid + 1) {
			temp[idx++] = a[j++];
		}
		else if (j == end + 1) {
			temp[idx++] = a[i++];
		}
		else if (a[i] <= a[j]) {
			temp[idx++] = a[i++];
		}
		else {
			ans += (ll)(mid - i + 1);
			temp[idx++] = a[j++];
		}
	}

	for (int i = start; i <= end; i++) {
		a[i] = temp[i];
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n;
	cin >> n;
	a = vector<int>(n);
	for (int i = 0; i < n; ++i)cin >> a[i];
	temp = vector<int>(n);

	merge(0, n - 1);

	cout << ans << '\n';

	return 0;

}
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

int a[50000], temp[50000], ans;

void sorting(int start, int end) {
	if (start == end)return;
	int mid = (start + end) / 2;
	sorting(start, mid);
	sorting(mid + 1, end);

	int left = start, right = mid + 1, idx = start;
	while (left <= mid || right <= end) {
		if (left == mid + 1) {
			temp[idx++] = a[right++];
		}
		else if (right == end + 1) {
			temp[idx++] = a[left++];
		}
		else {
			if (a[left] <= a[right]) {
				temp[idx++] = a[left++];
			}
			else {
				ans += mid + 1 - left;
				temp[idx++] = a[right++];
			}
		}
	}
	for (int i = start; i <= end; ++i)a[i] = temp[i];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)cin >> a[i];
		ans = 0;
		sorting(0, n - 1);
		cout << ans << '\n';
	}
	

	return 0;

}
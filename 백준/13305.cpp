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


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	int N;
	ll Min = (ll)INF + (ll)INF, ans = 0;

	cin >> N;
	vector<ll>a(N-1);
	vector<ll>b(N-1);
	for (int i = 0; i < N - 1; i++)cin >> a[i];

	for (int i = 0; i < N - 1; i++) {
		cin >> b[i];
		Min = min(Min, b[i]);
		ans += a[i] * Min;
	}
	cin >> Min;

	cout << ans << '\n';

	return 0;
	

}
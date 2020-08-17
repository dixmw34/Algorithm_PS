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

vector<int>par(10001, 0);
vector<int>cost(10001, 0);

int find(int x) {
	if (par[x] == x)return x;
	return par[x] = find(par[x]);
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K, ans = 0, a, b;

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		par[i] = i;
		cin >> cost[i];
	}

	while (M--) {
		cin >> a >> b;
		a = find(a), b = find(b);
		if (a == b)continue;
		
		if (cost[a] < cost[b])par[b] = a;
		else par[a] = b;
	}
	for (int i = 1; i <= N; i++) {
		if (par[i] == i)ans += cost[i];
	}

	if (ans <= K)cout << ans << '\n';
	else cout << "Oh no\n";

	return 0;
	

}
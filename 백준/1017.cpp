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
#include <string.h>
#include <iomanip>

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

vector<int>a, b, room;
vector<bool>visit;

bool prime(int num) {
	if (num < 2)return false;
	for (int i = 2; i <= sqrt(num); ++i) {
		if (num%i == 0)return false;
	}
	return true;
}

bool sol(int now) {
	if (visit[now])return false;
	visit[now] = true;
	for (int i = 0; i < b.size(); ++i) {
		if (prime(a[now]+b[i]) && (room[i] == -1 || (room[i] != 0 && sol(room[i])))) {
			room[i] = now;
			return true;
		}
	}
	return false;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); std::cout.tie(NULL);

	int n, first, num;

	cin >> n >> first;

	a.push_back(first);

	for (int i = 1; i < n; ++i) {
		cin >> num;
		if (first % 2 == num % 2)a.push_back(num);
		else b.push_back(num);
	}

	if (a.size() != b.size()) {
		cout << -1 << '\n';
		return 0;
	}

	sort(b.begin(), b.end());

	vector<int>ans;
	for (int i = 0; i < b.size(); ++i) {
		if (!prime(first + b[i]))continue;
		bool flag = true;
		room = vector<int>(b.size(), -1);
		room[i] = 0;
		for (int j = 1; j < a.size(); ++j) {
			visit = vector<bool>(a.size(), false);
			if (!sol(j)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans.push_back(b[i]);
		}
	}

	if (ans.size() == 0)cout << -1;
	else {
		for (int i = 0; i < ans.size(); ++i)cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;

}
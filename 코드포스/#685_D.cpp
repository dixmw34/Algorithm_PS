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

bool check(int x, int y, int d) {
	if (x*x + y * y > d*d)return false;
	return true;
}

bool cmp(pi a, pi b) {
	if (a.second == b.second)return a.first > b.first;
	else return a.second > b.second;
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll d, k, x, y = 0;
		cin >> d >> k;
		vector<pair<ll, ll>>a;
		x = d / k;
		while (x > y) {
			y = sqrt((d*d - (k*x)*(k*x))/(k*k));
			if (x < y)break;
			a.push_back(make_pair(x, y));
			x--;
		}
		sort(a.begin(), a.end(), cmp);
		ll test = (a[0].first + a[0].second);
		if (test % 2 == 1)cout << "Ashish\n";
		else cout << "Utkarsh\n";



	}

	

	return 0;
}
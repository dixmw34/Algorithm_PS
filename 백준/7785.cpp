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

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	set<string>company;
	int n;
	string name, state;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> name >> state;
		if (state == "enter") {
			company.insert(name);
		}
		else {
			set<string>::iterator it = company.find(name);
			if (it != company.end())company.erase(it);
		}
	}
	vector<string>ans;
	for (set<string>::iterator it = company.begin(); it != company.end(); ++it) {
		ans.push_back(*it);
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << '\n';
	}
	
	
	return 0;
}
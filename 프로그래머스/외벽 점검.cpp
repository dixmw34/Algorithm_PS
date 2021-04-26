#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321

vector<int>arr, man;
vector<bool>visit;
int m;

int fun(int cnt, int start) {
	if (start >= arr.size())
		return 0;
	if (cnt == m)
		return INF;
	int ans = INF;
	for (int k = 0; k < m; ++k) {
		if (!visit[k]) {
			visit[k] = true;
			int end_idx = upper_bound(arr.begin(), arr.end(), arr[start] + man[k]) - arr.begin();
			ans = min(ans, 1 + fun(cnt + 1, end_idx));
			visit[k] = false;
		}
	}
	return ans;
}

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = INF;
	arr = weak;
	man = dist;
	m = man.size();
	visit = vector<bool>(m, false);

	for (int i = 0; i < arr.size(); ++i) {
		answer = min(answer, fun(0, 0));
		arr.push_back(arr[0] + n);
		arr.erase(arr.begin());
	}

	return (answer == INF ? -1 : answer);
}

//소스코드 문제의 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

//출처 : https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/
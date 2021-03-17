#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int cal(string a) {
	return stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
}

string cal(int a) {
	int hh = (a / 60);
	int mm = a % 60;
	string ret = "";
	if (hh < 10)ret += "0";
	ret += to_string(hh) + ":";
	if (mm < 10)ret += "0";
	ret += to_string(mm);
	return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "00:00";

	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < timetable.size(); ++i) {
		pq.push(cal(timetable[i]));
	}
	int bus = 9 * 60;
	queue<int>waiting;
	for (int i = 0; i < n; ++i) {
		while (!pq.empty() && pq.top() <= bus) {
			waiting.push(pq.top());
			pq.pop();
		}

		if (i == n - 1) {
			if (waiting.size() < m) {
				return cal(bus);
			}
			else {
				for (int k = 0; k < m-1; ++k) {
					waiting.pop();
				}
				int last = waiting.front() - 1;
				return cal(last);
			}
		}

		for (int k = 0; k < m; ++k) {
			if (waiting.empty())break;
			waiting.pop();
		}
		bus += t;
	}


	return answer;
}
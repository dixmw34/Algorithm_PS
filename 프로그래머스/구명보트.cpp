#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = 0;

    deque<int>dq;
    for (int i = 0; i < people.size(); i++) {
        dq.push_back(people[i]);
    }
    sort(dq.begin(), dq.end());

    while (!dq.empty()) {
        if (dq.front() == limit)return answer + dq.size();
        int a = limit;
        answer++;
        a -= dq.back();
        dq.pop_back();
        if (!dq.empty() && dq.front() <= a)dq.pop_front();
    }

    return answer;
}
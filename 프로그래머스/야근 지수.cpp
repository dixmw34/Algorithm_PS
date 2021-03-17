#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<ll>pq;
    pq.push(0);
    for (int i = 0; i < works.size(); ++i) {
        pq.push(works[i]);
    }
    while (n && !pq.empty()) {
        int num = pq.top(); pq.pop();
        if (num == 0)
            continue;
        if (num == pq.top()) {
            n--;
            num--;
            pq.push(num);
        }
        else {
            ll cnt = min((ll)n, num - pq.top());
            if (num > cnt)pq.push(num - cnt);
            n -= cnt;
        }
    }

    while (!pq.empty()) {
        answer += pq.top()*pq.top();
        pq.pop();
    }

    return answer;
}
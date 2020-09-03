#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end());

    int Min = -500000;

    for (int i = 0; i < routes.size(); i++) {
        if (Min < routes[i][0]) {
            answer++;
            Min = routes[i][1];
        }
        else {
            Min = min(Min, routes[i][1]);
        }
    }


    return answer;
}

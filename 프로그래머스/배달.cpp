#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

typedef pair<int, int>pi;

int solution(int N, vector<vector<int> > road, int K) {

    vector<int>end(N, INF);
    end[0] = 0;
    vector<vector<pi>>edge(N);
    for(int i = 0; i<road.size(); ++i){
        edge[road[i][0]-1].push_back(pi(road[i][1]-1, road[i][2]));
        edge[road[i][1]-1].push_back(pi(road[i][0]-1, road[i][2]));
    }

    priority_queue<pi>pq;
    pq.push(pi(0, 0));
    while(!pq.empty()){
        int now = pq.top().second, cost = -pq.top().first;
        pq.pop();
        for(int i = 0; i<edge[now].size(); ++i){
            int next = edge[now][i].first, new_cost = end[now] + edge[now][i].second;
            if(new_cost<end[next]){
                end[next] = new_cost;
                if(new_cost<K)
                    pq.push(pi(-new_cost, next));
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i<N; ++i){
        if(end[i]<=K)
            answer++;
    }

    return answer;
}

int solution2(int N, vector<vector<int> > road, int K) {

    vector<int>end(N, INF);
    end[0] = 0;
    vector<vector<pi>>edge(N);
    for(int i = 0; i<road.size(); ++i){
        edge[road[i][0]-1].push_back(pi(road[i][1]-1, road[i][2]));
        edge[road[i][1]-1].push_back(pi(road[i][0]-1, road[i][2]));
    }

    for(int k = 0; k<N; ++k){
        for(int i = 0; i<N; ++i){
            if(end[i] == INF)continue;
            for(int j = 0; j<edge[i].size(); ++j){
                int next = edge[i][j].first, new_cost = end[i]+edge[i][j].second;
                if(new_cost<end[next])
                    end[next] = new_cost;
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i<N; ++i){
        if(end[i]<=K)
            answer++;
    }

    return answer;
}

//소스코드 문제의 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
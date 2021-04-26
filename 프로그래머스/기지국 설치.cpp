#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int ans = 0;
    
    stations.insert(stations.begin(), -w);
    stations.push_back(n+w+1);
    
    for(int i = 1; i<stations.size(); ++i){
        int left = stations[i-1]+w+1;
        int right = stations[i]-(w+1);
        if(left<=right)
            ans+=((right-left+1+2*w)/(2*w+1));
    }
    
    return ans;
}

//소스코드 문제의 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
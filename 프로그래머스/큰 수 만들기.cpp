#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string name) {
    int answer = 0;

    for(int i = 0; i<name.size(); i++){
        if(name[i] == 'A')continue;
        else{
            answer+=min(name[i]-'A', 'Z'-name[i]+1);
        }
    }


    return answer;
}
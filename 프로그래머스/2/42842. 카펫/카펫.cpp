#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int>answer;
    vector<pair<int, int>>possible;
    for(int i = 1; i*i <= yellow; i++){
        if(yellow%i == 0){
            possible.push_back({i, yellow/i});
        }
    }
    for(auto p : possible){
        if(2*p.first + 2*p.second + 4 == brown){
            answer.push_back(p.first+2);
            answer.push_back(p.second+2);
            break;
        }
    }
    sort(answer.begin(), answer.end(), greater<>());
    return answer;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int minLength = 100001;
    int numOfGemKinds = 0;
    unordered_map<string, int>gemKind;
    for(string gem : gems){
        if(gemKind.find(gem) == gemKind.end()) numOfGemKinds++;
        gemKind[gem] = 0;
    }
    int left = 0, right = 0;
    int curGemKinds = 1;
    gemKind[gems[0]] = 1;
    while(left <= right){
        if(curGemKinds < numOfGemKinds){
            if(right == gems.size()-1) break;
            right++;    
            if(gemKind[gems[right]] == 0) curGemKinds++;
            gemKind[gems[right]]++;
        }
        else{
            gemKind[gems[left]]--;
            if(gemKind[gems[left]] == 0) {
                curGemKinds--;
                if(right-left < minLength) {
                    minLength = right - left;
                    answer = {left+1, right+1};
                }
            }
            left++;
        }
    }
    
    return answer;
}
#include<bits/stdc++.h>

using namespace std;

bool compare(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>nums;
    for(auto num : numbers){
        nums.push_back(to_string(num));
    }
    sort(nums.begin(), nums.end(), compare);
    for(int i = 0; i < nums.size(); i++){
        answer+=nums[i];
    }
    if(answer[0] == '0') answer = "0";
    return answer;
}
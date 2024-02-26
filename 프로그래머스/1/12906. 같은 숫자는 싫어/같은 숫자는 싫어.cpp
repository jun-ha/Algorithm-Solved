#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int before = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] != before) {
            answer.push_back(before);
            before = arr[i];
        }
    }
    answer.push_back(arr.back());

    return answer;
}
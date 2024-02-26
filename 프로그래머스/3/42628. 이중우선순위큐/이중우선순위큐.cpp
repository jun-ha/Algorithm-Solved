#include <bits/stdc++.h>
using namespace std;

bool isInsert(string operation){
    if(operation[0] == 'I') return true;
    return false;
}
bool isDeleteMin(string operation){
    if(operation[2] == '-') return true;
    return false;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int>s;
    for(string operation : operations){
        if(isInsert(operation)){
            int num = stoi(operation.substr(1)); 
            s.insert(num);
            continue;
        }
        
        if(!s.empty()){
            if(isDeleteMin(operation)) {
                s.erase(s.begin());    
            }
            else{
                auto iter = s.end();
                iter--;
                s.erase(iter);    
            }
        }
    }
    if(!s.empty()){
        auto iter = s.end();
        iter--;
        answer.push_back(*iter);
        answer.push_back(*(s.begin()));
    }
    else{
        answer.push_back(0);   
        answer.push_back(0);
    }
    return answer;
}
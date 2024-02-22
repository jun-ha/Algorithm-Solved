#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int>answer;
    int numOfQuestion = answers.size();
    vector<int>answer1 = {1,2,3,4,5};
    vector<int>answer2 = {2,1,2,3,2,4,2,5};
    vector<int>answer3 = {3,3,1,1,2,2,4,4,5,5};
    int idx1 = 0, idx2 = 0, idx3 = 0;
    int count1 = 0, count2 = 0, count3 = 0;

    for(int i = 0; i < numOfQuestion; i++){
        if(answers[i] == answer1[idx1++]) count1++;
        if(answers[i] == answer2[idx2++]) count2++;
        if(answers[i] == answer3[idx3++]) count3++;
        if(idx1 == 5) idx1 = 0;
        if(idx2 == 8) idx2 = 0;
        if(idx3 == 10) idx3 = 0;
    }
    int maxScore = max(count1, max(count2, count3));
    if(count1 == maxScore) answer.push_back(1);
    if(count2 == maxScore) answer.push_back(2);
    if(count3 == maxScore) answer.push_back(3);
    return answer;
}
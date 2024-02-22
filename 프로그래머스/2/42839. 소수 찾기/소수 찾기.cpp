#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPrime(int k){
    for(int i = 2; i*i <= k; i++){
        if(k%i == 0) return false;
    }
    return true;
}

bool isPossibleToMake(int prime, vector<int>nums){
    while(prime){
        int tmpNum = prime%10;
        if(nums[tmpNum] == 0) return false;
        nums[tmpNum]--;
        prime/=10;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int maxNum;
    vector<int>nums(10, 0);
    for(int i = 0; i < numbers.length(); i++){
        nums[numbers[i]-'0']++;
    }
    string maxNumStr = "";
    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < nums[i]; j++){
            maxNumStr += to_string(i);   
        }
    }
    maxNum = stoi(maxNumStr);
    vector<int>primes;
    for(int i = 2; i <= maxNum; i++){
        if(isPrime(i)) primes.push_back(i);
    }
    for(auto prime : primes){
        if(isPossibleToMake(prime, nums)) answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int k){
    if(k == 0 || k == 1) return false;
    for(int i = 2; i*i<=k; i++){
        if(k%i==0) return false;
    }
    return true;
}

int solution(string numbers) {
    int size = numbers.size();
    set<int>primes;
    sort(numbers.begin(), numbers.end());
    do{
        for(int i = 1; i <= size; i++){
            string sub = numbers.substr(0, i);
            if(isPrime(stoi(sub))) primes.insert(stoi(sub));
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    return primes.size();
}
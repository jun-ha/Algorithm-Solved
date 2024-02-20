#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string>users;
    for(auto str : record){
        stringstream stream;
        stream.str(str);
        string method, id, nickname;
        stream >> method >> id >> nickname;
        if(method == "Enter" || method == "Change") users[id] = nickname;
    }
    for(auto str : record){
        stringstream stream;
        stream.str(str);
        string method, id, nickname;
        stream >> method >> id >> nickname;
        if(method == "Enter"){
            answer.push_back(users[id]+"님이 들어왔습니다.");
        }
        if(method == "Leave"){
            answer.push_back(users[id]+"님이 나갔습니다.");
        }
    }
    
    return answer;
}
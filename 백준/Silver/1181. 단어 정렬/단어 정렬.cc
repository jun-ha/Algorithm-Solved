#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <cstring>
#define ENDL '\n'

using namespace std;
using ll = long long;

typedef struct _node {
	string str;
	struct _node* next;
}Node;

typedef struct _list {
	Node* head;
}List;

void ListInit(List* list);
void LInsert(List* list, string str);
void ListPrint(List* list);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	List* all = new List[50];
	for (int i = 0; i < 50; i++) {
		ListInit(&all[i]);
	}
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		int len = str.length();
		LInsert(&all[len-1], str);
	}
	for(int i = 0; i < 50; i++) ListPrint(&all[i]);
	return 0;
}

void ListInit(List* list) {
	list->head = new Node;
	list->head->next = nullptr;
}
void LInsert(List* list, string str) {
	Node* newNode = new Node;
	newNode->str = str;
	Node* cur = list->head;
	while (cur->next) {
		int func = strcmp(&str[0], &(cur->next->str[0]));
		if (func < 0) break;
		else if (func > 0) cur = cur->next;
		else return;
	}
	newNode->next = cur->next;
	cur->next = newNode;
}
void ListPrint(List* list) {
	Node* cur = list->head->next;
	while (cur) {
		cout << cur->str << ENDL;
		cur = cur->next;
	}
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#define ENDL '\n'

using namespace std;
using ll = long long;

using QData = int;

typedef struct _node {
	QData data;
	struct _node* next;
}Node;

typedef struct _queue {
	Node* rear;
	int size;
}Queue;

void QInit(Queue* q);
bool QIsEmpty(Queue* q);
void Enqueue(Queue* q, QData data);
QData Dequeue(Queue* q);
int QSize(Queue* q);
QData QFront(Queue* q);
QData QBack(Queue* q);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Queue q;
	QInit(&q);
	int N; cin >> N;
	while (N--) {
		string order; cin >> order;
		if (order == "push") {
			int X; cin >> X;
			Enqueue(&q, X);
		}
		else if (order == "pop") {
			if (QIsEmpty(&q)) cout << -1 << ENDL;
			else cout << Dequeue(&q) << ENDL;
		}
		else if (order == "size") {
			cout << QSize(&q) << ENDL;
		}
		else if (order == "empty") {
			if (QIsEmpty(&q)) cout << 1 << ENDL;
			else cout << 0 << ENDL;
		}
		else if (order == "front") {
			if (QIsEmpty(&q)) cout << -1 << ENDL;
			else cout << QFront(&q) << ENDL;
		}
		else {
			if (QIsEmpty(&q)) cout << -1 << ENDL;
			else cout << QBack(&q) << ENDL;
		}
	}
	return 0;
}
void QInit(Queue* q) {
	Node* head = new Node;
	head->next = head;
	q->rear = head;
	q->size = 0;
}
bool QIsEmpty(Queue* q) {
	if (q->size == 0) return true;
	return false;
}
void Enqueue(Queue* q, QData data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = q->rear->next;
	q->rear->next = newNode;
	q->rear = newNode;
	(q->size)++;
}
QData Dequeue(Queue* q) {
	if (QIsEmpty(q)) exit(-1);
	Node* rnode = q->rear->next->next;
	QData rdata = rnode->data;
	q->rear->next->next = rnode->next;
	if (rnode == q->rear) q->rear = q->rear->next;
	(q->size)--;
	delete rnode;
	return rdata;
}
int QSize(Queue* q) {
	return q->size;
}
QData QFront(Queue* q) {
	return q->rear->next->next->data;
}
QData QBack(Queue* q) {
	return q->rear->data;
}
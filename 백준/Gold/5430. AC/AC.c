#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

typedef int DQData;

typedef struct _node {
	DQData data;
	struct _node* next;
	struct _node* before; //양 옆으로 구현한 이유는 Remove함수 사용시 더 쉬워짐..
}Node;

typedef struct _Deque {
	Node* head;
	Node* tail;
}Deque;

void DequeInit(Deque* dq) {
	dq->head = (Node*)malloc(sizeof(Node));
	dq->tail = (Node*)malloc(sizeof(Node));
	dq->head->before = NULL;
	dq->tail->next = NULL;
	dq->head->next = dq->tail;
	dq->tail->before = dq->head;
}
int DQIsEmpty(Deque* dq) {
	if (dq->head->next == dq->tail) {
		return TRUE;
	}
	return FALSE;
}

void DQAddFirst(Deque* dq, DQData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = dq->head->next;
	newNode->before = dq->head;
	dq->head->next->before = newNode;
	dq->head->next = newNode;
}
void DQAddLast(Deque* dq, DQData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = dq->tail;
	newNode->before = dq->tail->before;
	dq->tail->before->next = newNode;
	dq->tail->before = newNode;
}

DQData DQRemoveFirst(Deque* dq) {
	if (DQIsEmpty(dq)) {
		printf("Function DQRemoveFirst Fail");
		exit(-1);
	}
	Node* rnode;
	DQData rdata;
	rnode = dq->head->next;
	rdata = rnode->data;

	dq->head->next = rnode->next;
	rnode->next->before = dq->head;
	free(rnode);
	return rdata;
}
DQData DQRemoveLast(Deque* dq) {
	if (DQIsEmpty(dq)) {
		printf("Function DQRemoveLast Fail");
		exit(-1);
	}
	Node* rnode;
	DQData rdata;
	rnode = dq->tail->before;
	rdata = rnode->data;

	rnode->before->next = dq->tail;
	dq->tail->before = rnode->before;

	free(rnode);
	return rdata;
}

DQData DQPeekFirst(Deque* dq) {
	if (DQIsEmpty(dq)) {
		printf("Function DQPeekFirst Fail");
		exit(-1);
	}
	return dq->head->next->data;
}
DQData DQPeekLast(Deque* dq) {
	if (DQIsEmpty(dq)) {
		printf("Function DQPeekLast Fail");
		exit(-1);
	}
	return dq->tail->before->data;
}

int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		Deque dq;
		DequeInit(&dq);
		char op[100005];
		scanf("%s", op);
		int num, count = 0;
		scanf("%d", &num);
		char nums[500000];
		scanf("%s", nums);
		char* ptr = strtok(nums, "[],");
		while (count < num&&ptr!=NULL) {
			int len = strlen(ptr); // 시간 초과 날 시 atoi 함수 사용 해보기!
			if (len == 3) {
				DQAddLast(&dq, 100);
				count++;
			}
			else if (len == 2) {
				int k = 0;
				k = (ptr[0] - '0') * 10 + (ptr[1] - '0');
				DQAddLast(&dq, k);
				count++;
			}
			else {
				DQAddLast(&dq, ptr[0] - '0');
				count++;
			}
			ptr = strtok(NULL, "[],");
		}

		/*while (!DQIsEmpty(&dq)) {
			printf("%d\n", DQRemoveFirst(&dq));
		}*/

		count = 0;
		int len = strlen(op);
		int flag = TRUE; //순방향
		int flag2 = FALSE; //error 확인 위함
		for (int i = 0; i < len; i++) {
			if (op[i] == 'R') {
				if (flag == TRUE) {
					flag = FALSE;
				}
				else {
					flag = TRUE;
				}
			}
			else if (count == num) {
				printf("error\n");
				flag2 = TRUE;
				break;
			}
			else if (flag) {
				DQRemoveFirst(&dq);
				count++;
			}
			else {
				DQRemoveLast(&dq);
				count++;
			}
		}
		if (flag2) continue;

		printf("[");
		if (num == 0||DQIsEmpty(&dq)) {

		}
		else if (flag) {
			printf("%d", DQRemoveFirst(&dq));
			while (!DQIsEmpty(&dq)) {
				printf(",%d", DQRemoveFirst(&dq));
			}
		}
		else {
			printf("%d", DQRemoveLast(&dq));
			while (!DQIsEmpty(&dq)) {
				printf(",%d", DQRemoveLast(&dq));
			}
		}
		printf("]\n");
	}

	return 0;
}
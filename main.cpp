#include <iostream>
using namespace std;

/*----DSLK đơn-----*/
struct Node {
	int data;
	Node* pnext;
};

Node* createNode(int data) {
	Node *pnew = new Node;
	if (pnew == NULL)	return NULL;
	else {
		pnew->data = data;
		pnew->pnext = NULL;
	}
	return pnew;
}

bool AddHead(Node* &pHead, int data) {
	Node* pnew = createNode(data);
	if (pnew == NULL)	return false;
	if (pHead == NULL)	pHead = pnew;
	else {
		pnew->pnext = pHead;
		pHead = pnew;
	}
	return true;
}

void printList(Node* list) {
	Node *pRun = list;
	while (pRun != NULL) {
		cout << pRun->data << " ";
		pRun = pRun->pnext;
	}
}

/*----DSLK đôi----*/
struct Node2 {
	int data;
	Node2* pnext;
	Node2* ppre;
};

Node2* createNode2(int data) {
	Node2 *pnew = new Node2;
	if (pnew == NULL)	return NULL;
	else {
		pnew->data = data;
		pnew->pnext = NULL;
		pnew->ppre = NULL;
	}
	return pnew;
}

bool AddHead2(Node2* &pHead, int data) {
	Node2* pnew = createNode2(data);
	if (pnew == NULL)	return false;
	if (pHead == NULL)	pHead = pnew;
	else {
		pnew->pnext = pHead;
		pHead->ppre = pnew;
		pHead = pnew;
	}
	return true;
}

void printList(Node2* list) {
	Node2 *pRun = list;
	while (pRun != NULL) {
		cout << pRun->data << " ";
		pRun = pRun->pnext;
	}
}

/*---Câu 1---*/
int findMiddle(Node* list, int n) {
	Node *pRun = list;
	for (int i = 0; i < n / 2; i++) {
		pRun = pRun->pnext;
	}
	return pRun->data;
}

/*---Câu 3---*/
void reverseList(Node* &pHead) {
	Node *pRun = pHead, *pPre = NULL, *pNext = NULL;
	while (pRun != NULL) {
		pNext = pRun->pnext;
		pRun->pnext = pPre;
		pPre = pRun;
		pRun = pNext;
	 }
	pHead = pPre;
}

/*---Câu 4---*/
bool deleteX(Node2 *&list, int x) {
	if (list == NULL)	return false;
	Node2* pRun = list;
	while (pRun != NULL) {
		if (pRun->data == x) {
			Node2 *ptmp = pRun;
			pRun->ppre->pnext = pRun->pnext;
			delete(ptmp);
			return true;
		}
		pRun = pRun->pnext;
	}
	return false;
}

/*---Câu 5---*/
void deleteSame(Node* &list) {
	//Code tham khảo từ trang web geeksforgeeks
	struct Node *ptr1, *ptr2, *dup;
	ptr1 = list;
	while (ptr1 != NULL && ptr1->pnext != NULL)
	{
		ptr2 = ptr1;
		while (ptr2->pnext != NULL)
		{
			if (ptr1->data == ptr2->pnext->data)
			{
				dup = ptr2->pnext;
				ptr2->pnext = ptr2->pnext->pnext;
				delete(dup);
			}
			else {
				ptr2 = ptr2->pnext;
			}
		}
		ptr1 = ptr1->pnext;
	}
}

void main() {
	Node2 *pRoot = NULL;
	int Data, count = 0;
	do	{
		cout << "Nhap vao du lieu, -1 de ket thuc: ";
		cin >> Data;
		if (Data == -1)	break;
		AddHead2(pRoot, Data);
		count++;
	} while (Data != -1);
	cout << "Danh sach: ";
	printList(pRoot);
	deleteX(pRoot, 2);
	cout << "Danh sach: ";
	printList(pRoot);
	cout << endl;
	system("pause");
}
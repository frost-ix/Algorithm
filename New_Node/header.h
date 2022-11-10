#include <iostream>
#include <cstdlib>

#define clearH std::cout << "< HEAD :: insert clear >" << std::endl;
#define clearM std::cout << "< MID&END :: insert clear >" << std::endl;

typedef int element;
typedef struct ListNode
{
	element nodeData;
	ListNode* nextNode;
}listN;

void main_ctrl();

listN* nodeCreate(element Node_data);
void nodeFree(listN* Node);

listN* nodeInsert(listN* HeadNode, listN* MainList);
void nodeDelete();
void getNode(listN* Head);
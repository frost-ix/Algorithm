#include <iostream>
#include <cstdlib>

#define clearH std::cout << "< HEAD :: insert clear >" << std::endl;
#define clearM std::cout << "< MID :: insert clear >" << std::endl;
#define clearE std::cout << "< TAIL :: insert clear >" << std::endl;
#define Line std::cout << "----------------------------" <<std::endl;

typedef int element;
typedef struct ListNode
{
	element nodeData;
	ListNode* nextNode;
}listN;

void main_ctrl();

void module_introduce();

listN* nodeCreate(element Node_data);
void nodeFree(listN* Node);

listN* nodeInsert(listN* MainList);
listN* nodeDelete(listN* MainList, element data);
void getNode(listN* List);

void dump();
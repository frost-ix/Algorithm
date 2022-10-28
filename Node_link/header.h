#pragma once
#include <iostream>
#include <cstdlib>

// ListNode == DATA & LINK Structure
// <int> element == user create data type
// <Ptr> Link == Saved pointer < Linker >
typedef int element;
typedef struct ListNode
{
	element node_data;
	struct ListNode* Link = NULL;
}LsNd;

// Main_List == Linked List < Node implement >
// List_Head == Head Pointer
// Active_Link == Now Node / Delete Node
// Past_Link == Previous Node
extern LsNd* Main_List, * input_Node;
extern LsNd* List_Head, * Active_Link, * Past_Link;

void linkedlistManage();
void Introduce();

void printLsNd(LsNd* Node, LsNd* Active_Link);

LsNd* createNode(element data);
void inputNode(const LsNd* Head, LsNd* Node, LsNd* Active);
void deleteNode(LsNd* Head, LsNd* Del_node, LsNd* Past_Node);
void freeNode(LsNd* delNode);

element chooseNode(LsNd* Node_choose);
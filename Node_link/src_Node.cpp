#include "header.h"

LsNd* Main_List = NULL;
LsNd* input_Node = NULL;
LsNd* List_Head = NULL;
LsNd* Active_Link = NULL;
LsNd* Past_Link = NULL;

// Selectable Find node
// All : 1    | Just One : other
void printLsNd(LsNd* Node, LsNd *Active_Link)
{
	static int searchMode;
	std::cout << "1 : All    | Other : Just One" << std::endl;
	std::cout << "Input >> ";
	std::cin >> searchMode;
	if (searchMode == 1)
	{
		for (Active_Link = Node; Active_Link->Link == NULL; Active_Link = Active_Link->Link)
		{
			std::cout << Active_Link->node_daåta << " -> ";
		}
		std::cout << "END < NULL >" << std::endl;
	}
	else
	{
		std::cout << "<Select node what you want>" << std::endl;
		std::cout << "Node data : " << chooseNode(Node);
	}
}

// Create Node module
// Return to Struct namde Main_List (PTR)
LsNd* createNode(element data)
{
	LsNd* insertNode = (LsNd*)malloc(sizeof(LsNd));
	insertNode->node_data = data;
	return insertNode;
}

// Insert Node module
// Return to Struct named Main_List (PTR)
// 
// Case of 4 >>
// First : NULL node in Struct
// Second : If node go to first
// Third : If node go to last
// Fourth : Other Case <Insert inside ListNode>
// 
// Head == Node's Head
// Node == Import Node
// Active == Past pointer
void inputNode(const LsNd* Head, LsNd* Node, LsNd* Active)
{
	if (Head == NULL)
	{
		Head->Link = Node;
		Node->Link = NULL;
	}
	else
	{

		//insertNode->Link = Active->Link;
		//Active->Link = insertNode;
	}
}

// Delete Node module
// Return to Struct named Main_List (PTR)
// 
// Case of 3 >>
// First : If want delete first node
// Second : If want delete last node
// Third : Other Case <Delete inside ListNode>
// 
// Head == Pointer as Head
// Del_node == Delete Node
// Past_node == Previous Node
void deleteNode(LsNd* Head, LsNd* Del_node, LsNd* Past_Node)
{
	if (Head == NULL)
	{
		Head = Del_node->Link;
		freeNode(Del_node);
	}
	else
	{
		Past_Node->Link = Del_node->Link;
		freeNode(Del_node);
	}
}

// Search Node Module
// Searchable <Unique Value>
element chooseNode(LsNd* Node_choose)
{
	int i;
	std::cout << "Select Node >> ";
	std::cin >> i;
	i -= 1;
	return Node_choose[i].node_data;
}
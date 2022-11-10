#include "header.h"

static element in_data;
listN* main_list = NULL;

int main()
{
	main_ctrl();
}

void main_ctrl()
{
	listN* HeadNode = NULL;

	std::cout << "<Single linked list -- Node create>" << std::endl;
	std::cout << "input data >> "; std::cin >> in_data;
	main_list = nodeCreate(in_data);
	HeadNode = main_list;

	nodeInsert(HeadNode, main_list);
	std::cout << "2nd insert >> " << HeadNode->nodeData << std::endl;
	nodeInsert(HeadNode, main_list);
	std::cout << "3rd insert >> " << HeadNode->nodeData << std::endl;

	getNode(HeadNode);
}

// Create node (new) module
listN* nodeCreate(element Node_data)
{
	listN* newNode = (listN*)malloc(sizeof(listN));
	newNode->nodeData = Node_data;
	newNode->nextNode = NULL;
	return newNode;
}

// Delete Node module
void nodeFree(listN* Node)
{
	std::cout << "<node deallocated>" <<std::endl;
	free(Node);
}

listN* nodeInsert(listN* Head, listN* MainList)
{
	listN* PreNode;
	std::cout << "Input data <New Node> >> "; std::cin >> in_data;
	listN* NEW = nodeCreate(in_data);
	if (MainList->nextNode == NULL && NEW->nodeData < Head->nodeData)
	{
		NEW->nextNode = Head;
		Head = NEW;
		clearH;
		return Head;
	}
	else
	{
		// Middle : PreNode->nextNode
		for (PreNode = Head; PreNode->nextNode!=NULL; PreNode = PreNode->nextNode)
		{
			NEW->nextNode = PreNode->nextNode;
			PreNode->nextNode = NEW;
		}
		clearM;
	}
}
void nodeDelete()
{

}

void getNode(listN* Head)
{
	if (main_list == NULL)
	{
		std::cout << "NULL List" << std::endl;
	}
	else
	{
		listN* PreNode;
		int i = 1;
		std::cout << "Head Data : " << Head->nodeData << std::endl;
		std::cout << "NODE -- START" << std::endl;
		for (PreNode = Head; PreNode->nextNode!=NULL ; PreNode = PreNode->nextNode)
		{
			std::cout << "Round " << i << " data : " << PreNode->nodeData << std::endl;
			i++;
		}
		std::cout << "NODE -- END" << std::endl;
	}
}
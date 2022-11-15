#include "header.h"

static element in_data;
listN* Mainlist;

int main()
{
	main_ctrl();
}

void module_introduce()
{
	Line;
	std::cout << "1. Insert node" << std::endl;
	std::cout << "2. Delete Node" << std::endl;
	std::cout << "3. Get All node" << std::endl;
	std::cout << "9. If One more look this introduce" << std::endl;
	std::cout << "0. Program EXIT" << std::endl;
	Line;
}

void main_ctrl()
{
	static int modeS;
	static element data;
	std::cout << "<Single linked list -- Node create>" << std::endl;
	std::cout << "input data >> "; std::cin >> in_data;
	Mainlist = nodeCreate(in_data);
	module_introduce();
	while (true)
	{
		std::cout << "Mode select >> "; std::cin >> modeS;
		switch (modeS)
		{
		case 1:
		{
			Mainlist = nodeInsert(Mainlist);
			break;
		}
		case 2:
		{
			std::cout << "input delete node's data >> "; std::cin >> data;
			Mainlist = nodeDelete(Mainlist, data);
			break;
		}
		case 3:
		{
			getNode(Mainlist);
			break;
		}
		case 9:
		{
			module_introduce();
			break;
		}
		case 0:
		{
			std::cout << "< Program EXIT >";
			exit(0);
		}
		default:
		{
			std::cout << "< INVAILED COMMAND >" << std::endl;
			break;
		}
		}
	}
}

// Create node (new) module
listN* nodeCreate(element Node_data)
{
	listN* newNode = (listN*)malloc(sizeof(listN));
	newNode->nodeData = Node_data;
	newNode->nextNode = NULL;
	return newNode;
}

/// <summary>
/// Node Insert Module.
/// This module's logic is insert 'New Node' into created Linked list
/// Can insert to Head / Middle / Tail (End Of Link)
/// </summary>
/// <param name="MainList">Main list</param>
/// <returns> MainList == Main linked list</returns>
listN* nodeInsert(listN* MainList)
{
	listN* move = MainList;
	std::cout << "Input data <New Node> >> "; std::cin >> in_data;
	listN* NEW = nodeCreate(in_data);

	if (NEW->nodeData < MainList->nodeData)
	{
		NEW->nextNode = move;
		move = NEW;
		clearH;
		return move;
	}
	else
	{
		listN* PreNode = move;
		for (; PreNode->nextNode; PreNode = PreNode->nextNode)
		{
			if (PreNode->nodeData < NEW->nodeData && NEW->nodeData < PreNode->nextNode->nodeData)
			{
				NEW->nextNode = PreNode->nextNode;
				PreNode->nextNode = NEW;
				clearM;
				return move;
			}
		}
		PreNode->nextNode = NEW;
		clearE;
		return move;
	}
}

// Delete Node module
void nodeFree(listN* Node)
{
	std::cout << "<node DE - allocated>" << std::endl;
	free(Node);
}

/// <summary>
/// Node Delete Module.
/// This module's logic is find node then de allocated node == delete
/// LOGIC
/// 1. input data -> 2. find data where node same as inputed data
/// 3. after find, free node
/// </summary>
/// <param name="MainList">Main link</param>
/// <param name="data">Delete data where main link</param>
/// <returns>Mainlist == Main linked list</returns>
listN* nodeDelete(listN* MainList, element data)
{
	if (MainList == NULL)
	{
		std::cout << "< NOT EXIST LINK >" << std::endl;
	}
	else
	{
		listN* Now, * Pre;
		Now = Pre = MainList;
		if (MainList->nodeData == data)
		{
			MainList = Now->nextNode;
			Now->nextNode = NULL;
			nodeFree(Now);
			return MainList;
		}
		for (; Now; Now = Now->nextNode)
		{
			if (data == Now->nodeData)
			{
				Pre->nextNode = Now->nextNode;
				Now->nextNode = NULL;
				nodeFree(Now);
				return MainList;
			}
			Pre = Now;
		}
		std::cout << "< NO DATA IN THIS LINK >" << std::endl;
		return MainList;
	}
}

void getNode(listN* List)
{
	if (List == NULL)
	{
		std::cout << "List is NULL" << std::endl;
	}
	else
	{
		listN* PreNode = List;
		int i = 0;
		std::cout << "Head Data : " << List->nodeData << std::endl;
		std::cout << "NODE -- START" << std::endl;
		for (; PreNode != NULL; PreNode = PreNode->nextNode)
		{
			std::cout << ++i << " data : " << PreNode->nodeData << " -> ";
			if (i%5==0)
			{
				std::cout << std::endl;
			}
		}
		std::cout << std::endl << "NODE -- END" << std::endl;
	}
}

void dump()
{
	// CODE TEST AREA
	//
	// >> ctrl function
	//std::cout << "input data >> "; std::cin >> in_data;
	//listN* New = nodeCreate(in_data);
	//Mainlist->nextNode = New;
	//std::cout << "input data >> "; std::cin >> in_data;
	//listN* New2 = nodeCreate(in_data);
	//New->nextNode = New2;
	// 
	//std::cout << "1st insert >> " << Mainlist->nodeData << std::endl;
	//std::cout << "2nd insert >> " << Mainlist->nextNode->nodeData << std::endl;
	//std::cout << "3rd insert >> " << Mainlist->nextNode->nextNode->nodeData << std::endl;
	// 
	// 
	// >> middle / tail insert loop
	// 
	// Middle : PreNode->nextNode
		//for (; PreNode->nextNode; PreNode = PreNode->nextNode)
		//{
		//	// MainList->nextNode == NULL || 
		//	if (PreNode->nodeData < NEW->nodeData)
		//	{
		//		NEW->nextNode = PreNode->nextNode;
		//		PreNode->nextNode = NEW;
		//		break;
		//	}
		//}

		/*while (PreNode->nextNode != NULL)
		{
			if (PreNode->nodeData < NEW->nodeData || PreNode->nextNode != NULL)
			{
				PreNode = PreNode->nextNode;
			}
		}
		NEW->nextNode = PreNode->nextNode;
		PreNode->nextNode = NEW;*/
}
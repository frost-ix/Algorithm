#include "header.h"

extern LsNd* Main_List, * input_Node,* List_Head, * Active_Link, * Past_Link;

int main()
{
	// Management Linked-list Structure system
	// Can control insert / delete / print
	// Renamed ListNode >> LsNd
	linkedlistManage();
}

void Introduce()
{
	std::cout << "Insert Node : 1" << std::endl;
	std::cout << "Delete : 2" << std::endl;
	std::cout << "Print : 3" << std::endl;
	std::cout << "Other : END" << std::endl;
}

void linkedlistManage()
{
	static int select_mode;
	static element inputData;

	Introduce();

	std::cout << "<Create Node>" << std::endl << "Input data >> ";
	std::cin >> inputData;
	Main_List = createNode(inputData);

	List_Head = Main_List;

	while (true)
	{
		std::cout << std::endl << "Select Module >> ";
		std::cin >> select_mode;
		switch (select_mode)
		{
			// Insert Module
			case 1:
			{
				std::cout << "Input node data >> ";
				std::cin >> inputData;
				input_Node = createNode(inputData);
				inputNode(List_Head, input_Node, Active_Link);
				break;
			}
			// Delete Module
			case 2:
			{
				deleteNode(List_Head, Active_Link, Past_Link);
				break;
			}
			// Print Node Module
			case 3:
			{
				printLsNd(Main_List, Active_Link);
				break;
			}
			default:
			{
				std::cout << "End Management";
				exit(0);
			}
			break;
		}
	}
}
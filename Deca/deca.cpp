#include <iostream>
#include <thread>

//int turn = 0;
bool flag[2] = { false, false };

void func0()
{
	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		flag[0] = true;
		//while (flag[1] == true)
		{
			//if (turn == 1)
			//{
			//	flag[0] = false;
			//	while (turn == 1)
			//	{
			//		flag[0] = true;
			//	}
			//}
			cnt++;
			std::cout << "func 1 cnt >> " << cnt << std::endl;
		}
	}
	//turn = 1;
	//flag[0] = false;
}

void func1()
{
	int cnt = 0;
	for (int i = 0; i < 100; i++)
	{
		flag[0] = true;
		//while (flag[1] == true)
		{
			//if (turn == 1)
			//{
			//	flag[0] = false;
			//	while (turn == 1)
			//	{
			//		flag[0] = true;
			//	}
			//}
			cnt++;
			std::cout << "func 2 cnt >> " << cnt << std::endl;
		}
	}
	//turn = 1;
	//flag[0] = false;
}

int main()
{
	std::thread t1(func0);
	std::thread t2(func1);

	std::cout << "t1 join" << std::endl;
	t1.join();
	std::cout << "t2 join" << std::endl;
	t2.join();
}
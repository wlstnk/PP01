#include <iostream>
#include <string>

namespace normal {
	void printf(std::string str)
	{
		std::cout << str;
	}
}

namespace visual_novel {
	void printf(std::string str)
	{
		std::cout << "박진수 " << str;
	}

}

using namespace visual_novel;

int main()
{
	printf("바보");
	return 0;
}

#include <iostream>

int main()
{
	int curr_element = 1;

	while ((std::cin >> curr_element) && curr_element != 0)
	{}

	if (!std::cin)
	{
		std::cerr << "The input data is not a sequence\n";
		return 1;
	}

	return 0;
}

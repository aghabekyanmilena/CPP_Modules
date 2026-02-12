#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<int, std::string> dict;

	dict.insert(std::pair<int, std::string>(1, "b"));
	dict.insert(std::pair<int, std::string>(2, "c"));
	dict.insert(std::pair<int, std::string>(0, "a"));
	std::cout << dict.size() << std::endl;
	for (auto pair: dict)
	{
		std::cout << pair.first << " " << pair.second << std::endl;
	}
	// dict.clear();
	std::cout << std::endl;
	// dict.erase(1);
	// for (auto pair: dict)
	// {
	// 	std::cout << pair.first << " " << pair.second << std::endl;
	// }

	std::cout << dict.at(5) << std::endl;
}
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDACK NOISE *\n";
		return (0);
	}
	std::string str;
	for (int j = 1; j < ac ; ++j) {
		std::string arg(av[j]);
		str.reserve(str.size() + arg.size() + 1);
		for (size_t i = 0; i < arg.size(); ++i) {
			str += std::toupper(arg[i]);
		}
		str += ' ';
	}
	std::cout << str << '\n';
	return 0;
}

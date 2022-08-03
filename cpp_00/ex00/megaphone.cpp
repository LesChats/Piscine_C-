#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	std::string str;
	std::string arg;
	for (int j = 1; j < ac ; ++j) {
		arg = av[j];
		str.reserve(str.size() + arg.size() + 1);
		for (std::string::iterator it = arg.begin(); it != arg.end(); ++it) {
			str += std::toupper(*it);
		}
		/* If you wish to deal with several args and have a readable result */
		//str += ' ';
	}
	std::cout << str << '\n';
	return 0;
}

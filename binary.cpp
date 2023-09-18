#include <iostream>
#include <string>
#include <vector>
#include <iterator>

long	binarySearch(std::vector<std::string> &vec, std::string name)
{
	long	low;
	long	high;
	long	ret;
	int	place;

	place = 0;
	low = 0;
	high = vec.size() - 1;
	ret = 0;
	while (low <= high)
	{
		place = 0;
		ret = low + (high - low) / 2;
		while (vec[ret][place] && name[place] && vec[ret][place] == name[place])
		{
			++place;
		}
		if (place == vec[ret].size())
		{
			return (ret);
		}
		if (vec[ret][place] > name[place])
		{
			high = ret - 1;
		}
		else
		{
			low = ret + 1;
		}
	}
	return (ret + (vec[ret][place] < name[place]));
}

void	put(std::vector<std::string> &vec, std::string name)
{
	std::vector<std::string>::iterator	it;
	long					pos;

	pos = binarySearch(vec, name);
	if (pos < vec.size() && vec[pos].compare(name) == 0)
		return ;
	it = vec.begin() + pos;
	vec.insert(it, name);
}
int	main(void)
{
	std::vector<std::string>	vec;

	vec.push_back("Anna");
	vec.push_back("Brenda");
	vec.push_back("Mona");
	vec.push_back("Zenya");

	put(vec, "Laura");
	put(vec, "Michelle");
	put(vec, "Mora");
	put(vec, "Monna");
	put(vec, "monna");
	put(vec, "Monna");
	put(vec, "Laura");
	put(vec, "Ala");

	for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	return (0);
}

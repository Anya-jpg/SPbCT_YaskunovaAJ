#include "DLL.h"

void writeToFile2(const std::vector<char>& vector)
{
	std::ofstream file2("2.txt", std::ios::app);
	copy(vector.begin(), vector.end(), std::ostream_iterator<char>(file2));
	file2 << "\n";
	file2.close();
}

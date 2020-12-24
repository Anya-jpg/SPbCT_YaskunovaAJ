#include "DLL.h"

void writeToFile2(const std::vector<char>& vector)
{
	std::ofstream file2("2.txt", std::ios::app);
	copy(vector.begin(), vector.end(), std::ostream_iterator<char>(file2));
	file2 << std::endl;
	file2.close();
}
void run(std::vector<char> v1, std::ifstream f, char values[]) {
	for (int i = 0; i < 10; i++)
	{
		f >> values[i];
		v1.push_back(values[i]);
	}
	sort(v1.begin(), v1.end());
	writeToFile2(v1);
}

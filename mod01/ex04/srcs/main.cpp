#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

std::string getFileContent(char *fileName)
{
	std::ifstream inputFileStream(fileName);
	if (!inputFileStream)
		(std::cerr << "Failed to open the input file stream\n", exit(1));
	std::string fileContent(
		(std::istreambuf_iterator<char>(inputFileStream)),
		(std::istreambuf_iterator<char>()));
	return fileContent;
}

void replaceSubString(std::string &fileContent, char *raw_from, char *raw_to)
{
	std::string from = raw_from;
	size_t pos = fileContent.rfind(from);
	while (pos != std::string::npos)
	{
		fileContent.erase(pos, from.size());
		fileContent.insert(pos, raw_to);
		pos = fileContent.rfind(from, pos - 1);
	}
}

void writeOuputFile(char *fileName, std::string &fileContent)
{
	std::ofstream outputFileStream((std::string(fileName) + ".replace").c_str());
	if (!outputFileStream)
		(std::cerr << "Failed to open the output file stream\n", exit(1));
	outputFileStream << fileContent;
	outputFileStream.close();
}

int main(int ac, char **av)
{
	if (ac != 4)
		(std::cerr << "Usage: <filename> <s1> <s2>\n", exit(1));
	std::string fileContent = getFileContent(av[1]);
	replaceSubString(fileContent, av[2], av[3]);
	writeOuputFile(av[1], fileContent);
}

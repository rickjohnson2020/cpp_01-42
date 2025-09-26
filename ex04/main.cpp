#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char** av) {
	if (ac != 4) {
		std::cout << "Number of arguments is wrong" << std::endl;
		return 0;
	}
	std::string filename = av[1];
	std::string str1 = av[2];
	if (str1.empty()) {
		std::cerr << "Search string must not be empty" << std::endl;
		return 1;
	}
	std::string str2 = av[3];
	unsigned long str1Size = ((std::string)str1).size();
	
	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open()) {
		std::cerr << "Error opening file for reading" << std::endl;
		return 1;
	}

	std::ofstream ofs((filename + ".replace").c_str());
	if (!ofs.is_open()) {
		std::cerr << "Error opening file for writing" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(ifs, line)) {
		std::size_t str1Pos = line.find(str1);
		std::size_t startPos = 0;
		while (str1Pos != std::string::npos) {
			ofs << line.substr(startPos, str1Pos - startPos) << str2;
			startPos = str1Pos + str1Size;
			str1Pos = line.find(str1, startPos);
		}
		ofs << line.substr(startPos, line.size()) << std::endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}
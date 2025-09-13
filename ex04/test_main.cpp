#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>

void writeFile(const std::string& filename, const std::string& content) {
	std::ofstream ofs(filename);
	ofs << content;
}

std::string readFile(const std::string& filename) {
	std::ifstream ifs(filename);
	return std::string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
}

bool test_replace(const std::string& input, const std::string& search, const std::string& replace, const std::string& expected, const std::string& test_name) {
	writeFile("input.txt", input);
	std::string cmd = "./replace input.txt \"" + search + "\" \"" + replace + "\"";
	std::system(cmd.c_str());
	std::string result = readFile("input.txt.replace");
	bool passed = (result == expected);
	if (passed)
		std::cout << "[PASS] " << test_name << std::endl;
	else {
		std::cout << "[FAIL] " << test_name << std::endl;
		std::cout << "  Expected: \"" << expected << "\"" << std::endl;
		std::cout << "  Got     : \"" << result << "\"" << std::endl;
	}
	std::remove("input.txt");
	std::remove("input.txt.replace");
	return passed;
}

int main() {
	int total = 0, passed = 0;
	total++; passed += test_replace("hello world\n", "hello", "hi", "hi world\n", "Basic replace");
	total++; passed += test_replace("foo bar foo\n", "foo", "baz", "baz bar baz\n", "Multiple replace");
	total++; passed += test_replace("abc def\n", "xyz", "123", "abc def\n", "No match");
	total++; passed += test_replace("abc def abc\n", "abc", "", " def \n", "Replace with empty");
	total++; passed += test_replace("aaa aaa aaa\n", "aaa", "b", "b b b\n", "Multiple in one line");
	std::cout << "Passed " << passed << " / " << total << " tests." << std::endl;
	return (passed == total ? 0 : 1);
}
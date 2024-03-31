#include <fstream>
#include <iterator>
#include <iostream>
#include <vector>
#include "tucan_module.h"

int main()
{
    std::ifstream file("C:\\DotNetProjects\\Tester\\x64\\Debug\\main.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string src((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    file.close();

    auto mod = std::make_shared<tucan_script::tucan_module>();
	mod->load_from_source(src);

	mod->execute();
	std::cout << mod->tryGetVariable("x")->getIntValue();

	return 0;
}
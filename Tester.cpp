#include <iostream>
#include <vector>
#include "tucan_expression.h"

int main()
{
	std::shared_ptr<tucan_script::tucan_expression> executable = std::make_shared<tucan_script::tucan_expression>();

	auto tokens = tucan_script::tokenize("2 + 2 * 2");

	for (auto& token : tokens)
		if (auto operable = dynamic_cast<tucan_script::tucan_operable*>(token.get()))
			executable->appendOperable(std::make_shared<tucan_script::tucan_operable>(*operable));
		else
			executable->append(token);

	executable->execute();

	std::cout << executable->getIntValue();
}
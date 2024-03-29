#pragma once
#include <vector>
#include <unordered_map>
#include "tucan_expression.h"

namespace tucan_script
{
	class tucan_function_argument : public tucan_operable_clone
	{
	public:
		bool is_reference;

		tucan_function_argument(bool reference, std::shared_ptr<tucan_operable> operable);
	};

	class tucan_function : public tucan_operable, public tucan_executable, public tucan_returnable
	{
	private:
		std::unordered_map<std::string, tucan_function_argument*> m_arguments;
		bool m_running;

	public:
		~tucan_function();

		int involvedArgumentCount;

		tucan_function_argument& getArgById(int index);
		tucan_function_argument& getArgByName(const std::string& name);

		void setArg(int index, std::shared_ptr<tucan_operable>& operable);

		void append(std::shared_ptr<tucan_executable>& executable);
		void append(const std::string& name, bool reference);

		void execute() override;
		void return_value() override;
		void reset() override;
	};

	class tucan_function_call : tucan_entity
	{
	private:
		std::vector<std::shared_ptr<tucan_operable>> m_arguments;
		std::shared_ptr<tucan_function> m_function;
		tucan_operable m_result;

	public:
		tucan_function_call(std::shared_ptr<tucan_function>& function);

		void append(std::shared_ptr<tucan_function>& arg);
		tucan_operable& invoke();
	};
}


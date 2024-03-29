#include "tucan_entity.h"

namespace tucan_script
{
	tucan_entity::tucan_entity() : m_type(TUCAN_TYPE::NONE) {}

	tucan_entity::tucan_entity(const TUCAN_TYPE& type) : m_type(type) {}

	tucan_entity::~tucan_entity() {}

	TUCAN_TYPE tucan_entity::getType() const
	{
		return m_type;
	}

	void tucan_entity::setType(const TUCAN_TYPE& type)
	{
		m_type = type;
	}

	tucan_undefined::tucan_undefined(const std::string& content) : m_content(content) {}

	tucan_undefined::~tucan_undefined()
	{
		m_content = std::string();
	}

	tucan_break_point::tucan_break_point(std::shared_ptr<tucan_loop> loop) : m_loop(loop) {}
	
	void tucan_break_point::execute()
	{
		m_loop->break_loop();
	}

	tucan_continue_point::tucan_continue_point(std::shared_ptr<tucan_loop> loop) : m_loop(loop) {}

	void tucan_continue_point::execute()
	{
		m_loop->continue_loop();
	}

	tucan_return_point::tucan_return_point(std::shared_ptr<tucan_returnable> returnable) : m_returnable(returnable) {}

	void tucan_return_point::execute()
	{
		m_returnable->return_value();
	}
}
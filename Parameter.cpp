#include "Parameter.h"

void Parameter::set(std::string key, int val)
{
	_map[key] = val;
}

int Parameter::get(std::string key) const
{
	auto id = _map.find(key);//�w��L�[���擾

	if (_map.end() == id) {
		return false;
	}

	return 0;
}

#include <iostream>

class Weapon
{
	std::string type;
    public:
	Weapon(const std::string& type)
	{
		this->type = type;
	}
	const std::string& getType()
	{
		return this->type;
	}
	void setType(const std::string& type)
	{
		this->type = type;
	}
};


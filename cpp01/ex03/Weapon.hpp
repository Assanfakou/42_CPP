#include <iostream>

class Weapon
{
	std::string type;
    public:
	Weapon(const std::string& type);
	const std::string& getType();
	void setType(const std::string& type);
};

class HumanB
{
	Weapon *w;
	std::string name;
	public:
	HumanB(const std::string& name) : name(name) {}
	void setWeapon(Weapon& w) {this->w = &w;}
	void attack()
	{
		std::cout << name << " attack with their " << w->getType() << std::endl;
	}
};

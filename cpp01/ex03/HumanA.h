
class HumanA
{
	std::string name;
	Weapon &w;
	public:
	HumanA(const std::string& name, Weapon& w) : name(name), w(w) {}
	void attack()
	{
		std::cout << name << " attack with their " << w.getType() << std::endl;
	}
};

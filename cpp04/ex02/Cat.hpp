#include "AAnimal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
# define CAT_HPP 

class Cat : public AAnimal
{
	private:
		Brain* b;
	public:
		Cat();
		Cat(const Brain& brain);
		Cat& operator=(const Cat& animal);
		Cat(const Cat& animal);
		void makeSound() const;
		void printIdea(int ) const;
		void printIdeas() const;
		~Cat();
};
#endif

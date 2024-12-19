#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

std::cout << "\n\n<<< TEST ANIMAL CLASS >>>\n" << std::endl;

	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	std::cout << "Type class Cat: " << i->getType() << std::endl;
	std::cout << "Type class Dog: " << j->getType() << std::endl;
	std::cout << "Type class Animal: " << meta->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();


	delete(meta);
	delete(i);
	delete(j);

	std::cout << "\n\n<<< TEST WRONG CLASS >>>\n" << std::endl;

	const WrongAnimal* wMeta = new WrongAnimal();
	const WrongAnimal* w = new WrongCat();

	std::cout << "Type class Wrong Cat: " << w->getType() << std::endl;
	std::cout << "Type class Wrong Animal: " << wMeta->getType() << std::endl;
	w->makeSound();
	wMeta->makeSound();

	delete(wMeta);
	delete(w);

	system("leaks Animal");

	return (0);
}
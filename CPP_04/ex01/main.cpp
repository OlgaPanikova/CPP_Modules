#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const int size = 6;
	Animal* animals[size];

	for (int i = 0; i < size / 2; ++i) {
		animals[i] = new Dog();
	}
	for (int i = size / 2; i < size; ++i) {
		animals[i] = new Cat();
	}

	for (int i = 0; i < size; ++i) {
		std::cout << "Type class: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	for (int i = 0; i < size; ++i) {
		delete animals[i];
	}

	std::cout << "\n\n<<< Testing deep copy >>>\n" << std::endl;
	
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "Chase the ball!");
	Dog copiedDog = originalDog;
	std::cout << "Original idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;

	system("leaks Brain");
	return 0;
}
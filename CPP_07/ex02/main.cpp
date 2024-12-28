#include "Array.hpp"


int main() {
	try {
		Array<int> arr1(5);
		std::cout << "Size of arr1: " << arr1.size() << std::endl;

		arr1[0] = 10;
		std::cout << "First element: " << arr1[0] << std::endl;

		Array<int> arr2 = arr1;
		std::cout << "First element of arr2 (copied): " << arr2[0] << std::endl;

		Array<int> arr3(3);
		arr3 = arr1;
		std::cout << "First element of arr3 (assigned): " << arr3[0] << std::endl;

		std::cout << "Accessing out-of-bounds element: " << arr1[10] << std::endl;

	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	system("leaks Array");

	return 0;
}
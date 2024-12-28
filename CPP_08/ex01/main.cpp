#include "Span.hpp"

int main() {
	try {
		Span sp(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		Span bigSpan(10000);
		std::vector<int> range(10000);
		int value = 0;
		for (std::vector<int>::iterator it = range.begin(); it != range.end(); ++it) {
    	*it = value++;
		}
		bigSpan.addRange(range.begin(), range.end());

		std::cout << "Shortest Span (big): " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span (big): " << bigSpan.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
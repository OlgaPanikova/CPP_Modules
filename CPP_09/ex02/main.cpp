#include "PmergeMe.hpp"

    bool isNumber(const std::string &str) {
    if (str.empty()) {
        return false;
    }
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cerr << "Error: No input sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> container;
    std::list<int> container2;

    // Перебор аргументов и добавление в контейнеры
    for (int i = 1; i < argc; ++i) {
        const char* arg = argv[i];

        if (!isNumber(arg)) {
            std::cerr << "Error: Invalid input. All inputs must be positive integers." << std::endl;
            return 1;
        }

        int num = std::atoi(argv[i]);
        if (num < 0) {
            std::cerr << "Error: Invalid input. All numbers must be positive integers." << std::endl;
            return 1;
        }

        container.push_back(num);
        container2.push_back(num);
    }

    // Выводим неотсортированную последовательность
    std::cout << "Unsorted sequence: ";
    for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Сохраняем время начала для первого контейнера
    clock_t start = clock();

    // Применяем алгоритм сортировки для первого контейнера
    PmergeMe sorter;
    if(!sorter.CheckContainer(container))
        return 1;

    sorter.FordJonsonMerge(container);

    // Сохраняем время окончания для первого контейнера
    clock_t end = clock();

    // Выводим отсортированную последовательность
    std::cout << "Sorted sequence: ";
    for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Рассчитываем и выводим время выполнения для первого контейнера
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time used by first container: " << timeTaken << " seconds." << std::endl;

    // Выводим неотсортированную последовательность для второго контейнера
    std::cout << "Unsorted sequence (second container): ";
    for (std::list<int>::iterator it = container2.begin(); it != container2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Сохраняем время начала для второго контейнера
    start = clock();

    if(!sorter.CheckContainer(container2))
        return 1;
    // Применяем алгоритм сортировки для второго контейнера
    sorter.FordJonsonMerge(container2);

    // Сохраняем время окончания для второго контейнера
    end = clock();

    // Выводим отсортированную последовательность для второго контейнера
    std::cout << "Sorted sequence (second container): ";
    for (std::list<int>::iterator it = container2.begin(); it != container2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Рассчитываем и выводим время выполнения для второго контейнера
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time used by second container: " << timeTaken << " seconds." << std::endl;

    return 0;
}

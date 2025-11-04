#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    std::ofstream outfile("inputSomething2.txt");
    if (!outfile) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    const int NUM_COUNT = 1500000;

    for (int i = 0; i < NUM_COUNT; ++i) {
        int num = std::rand();
        outfile << num << '\n';
    }

    outfile.close();
    std::cout << "Generated " << NUM_COUNT << " random numbers in inputSomething2.txt\n";
    return 0;
}
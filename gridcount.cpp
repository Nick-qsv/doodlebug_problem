#include <iostream>
#include <string>

int main() {
    std::string grid = "- o - - - - - - - - - o o - - - o - o - - - - - o - - o - o - - - - - - - - - - -o o - - - - - - - - - - o - - - o - - - o - - - - - - o - - - - - - - o o - - - - - - o - - - - o - - - - - - - o - - - o - - - - - - o o - - - o - - - o - - - - - - o o - - o - o - - o o - - - - - - - - - o - o - - - o - - - - - - - - - - o o o - - - - - - - o - o - - - - o - - o - o - - o o - - o o - - o - o o - - o - - - - X - - - - - o - o - - - X - - - - - - o - - - - o - - - - o - - - - - - o - - - - - - - - - - - - - - o - - - - - o o - o - - o o o o - - - - o - o - - o - - - - - - o - - - o - o - - - o - - o o - - - - - - - - - X - - o - o - - o o - - - - - - - - - o X o - - - - - - - - o - - - - o o o - o o - o o - - o o o o - - - - o - - o o - - - - o - - - - o o o - - - - X - - o - - o - o - - - -";

    int count = 0;
    for (char c : grid) {
        if (c == 'o') {
            count++;
        }
    }
    std::cout << "The number of 'o' characters in the grid is: " << count << std::endl;

    return 0;
}

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

void printSlowly(const std::string& text, unsigned int delay_ms) {
    for (char c : text) {
        std::cout << c << std::flush;  // Print character and flush the output
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));  // Delay
    }
    std::cout << std::endl;  // Print newline after the text is complete
}

int main() {
    std::string text = "Hello, World!";
    unsigned int delay = 100;  // 100 milliseconds delay between each character

    printSlowly(text, delay);

    return 0;
}

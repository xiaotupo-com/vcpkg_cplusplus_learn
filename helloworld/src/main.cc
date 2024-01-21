#include <vector>
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <fmt/ranges.h>
#include <fmt/os.h>
#include <fmt/color.h>
#include <string>

int main(void) {
    setlocale(LC_ALL, "chs");
    fmt::println("Hello,World!");
    std::string s = fmt::format("I'd rather be {1} than {0}.", "right", "happy");
    fmt::println(s);

    // Print dates and times
    auto now = std::chrono::system_clock::now();
    fmt::println("Date and time: {}", now);
    fmt::println("Time: {:%H:%M}", now);

    // Print a container
    std::vector<int> v = {1, 2, 3};
    fmt::println("{}", v); // output: [1, 2, 3]

    // Write a file from a single thread
    auto out = fmt::output_file("guide.txt");
    out.print("Don't {}", "Panic"); // guide.txt: Don't Panic

    // Print with colors and text styles
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
               "Hello,{}!\n", "world");
    fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) | fmt::emphasis::underline,
               "Olá, {}!\n", "Mundo");
    fmt::print(fg(fmt::color::steel_blue) | fmt::emphasis::italic,
               "你好{}!\n", "世界");
}

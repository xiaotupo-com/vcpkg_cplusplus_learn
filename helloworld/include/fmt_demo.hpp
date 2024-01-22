#pragma once

#include <vector>
#include <string>
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <fmt/ranges.h>
#include <fmt/os.h>
#include <fmt/color.h>

namespace Test::Fmt {
void test();
} // namespace Test::Fmt

namespace Test::CPlusPlus {
    void test();

    inline namespace V2 {
        void foo() {
            fmt::println("foo() V2");
        }
    }
}

// fmtlib 库的相关演示代码
void Test::Fmt::test() {
    fmt::println("Hello,World!");
    std::string s = fmt::format("I'd rather be {1} than {0}.", "right", "happy");
    fmt::println(s);

    fmt::println(stderr, "System error code = {}", 101);

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

    // 命名参数
    fmt::println("Hello, {name}! The answer is {number}. Goodbye, {name}.",
               fmt::arg("name", "World"), fmt::arg("number", 42));
}

void Test::CPlusPlus::test() {

}
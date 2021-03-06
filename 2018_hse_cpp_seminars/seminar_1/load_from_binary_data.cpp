#include <cassert>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <vector>

template<class C>
void PrintContainer(const C& containter, std::ostream& output_stream = std::cout) {
    for (const auto& item: containter) {
        output_stream << item << ' ';
    }
    output_stream << '\n';
}

std::vector<uint64_t> LoadNumbers(std::istream& input_stream) {
    size_t size = 0;
    input_stream.read(reinterpret_cast<char*>(&size), sizeof(size));
    std::vector<uint64_t> numbers(size, 0);
    input_stream.read(reinterpret_cast<char*>(numbers.data()), sizeof(uint64_t) * size);
    return numbers;
}

int main(const int argc, const char* argv[]) {
    // check that at least two arguments are presented
    assert(argc == 2);
    std::ifstream file{argv[1], std::ios::binary};

    const auto numbers = LoadNumbers(file);
    PrintContainer(numbers);

    return 0;
}

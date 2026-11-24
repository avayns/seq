#include <iostream>
#include "CLI11.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    CLI::App app{"Числовая последовательность"};

    int start = 0;
    int end = 0;
    int n = 0;

    app.add_option("start", start, "начальный элемент")->required();
    app.add_option("end", end, "конечный элемент")->required();
    app.add_option("-n,--multiple", n, "выводить только числа, кратные n")
        ->check(CLI::PositiveNumber);

    CLI11_PARSE(app, argc, argv);

    for (int i = start; i <= end; i++) {
        if (n == 0 || i % n == 0) {
            cout << i << endl;
        }
    }
    return 0;
}

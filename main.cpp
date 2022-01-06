#include <iostream>
#include <cassert>
#include <ostream>

#include "MyArray.h"
#include "ArgParser.h"

int main(int argc, char *argv[]) {
    MyArray arr = ParseArgs(argc, argv);
    arr.Print(std::cout);
    arr.Sort(MyArray::SortType::BUBBLE);
    arr.Print(std::cout);

    return 0;
}
#include <iostream>
#include "util/cmdline.h"


int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    std::cout << argc << std::endl;
    CMDLine cmdline(argc, argv);
    for (auto it = cmdline.value.begin(); it != cmdline.value.end(); it++){
        std::cout << it -> first << ": " << it -> second << std::endl;
    }



    return 0;
}

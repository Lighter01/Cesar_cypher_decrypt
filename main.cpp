#include <iostream>

#include "run_decryptor.h"
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(1251);

    methods::testProg();
    for (const auto& it : containers::address) {
        std::cout << it << "\n";
    }
}

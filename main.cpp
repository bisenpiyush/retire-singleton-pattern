//#include <QCoreApplication>
#include <cstdlib>
#include "process.h"
void atexit_handler_1()
{
    std::cout << "at exit #1\n";
}
int main()
{
    const int result_1 = std::atexit(atexit_handler_1);
    if ((result_1 != 0)) {
        std::cerr << "exist failed\n";
        return EXIT_FAILURE;
    }
    Data d(22);
    Process p;
    p.sendData(d);
    std::cout << "returning from main" << std::endl;
    return EXIT_SUCCESS;
}

#include <iostream>
#include "networking/ssh.h"

int main()
{
    try
    {
        networking::ssh ssh;
        ssh.connect("localhost");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
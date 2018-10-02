#include <iostream>
#include <pqxx/pqxx>

int main()
{
    try
    {
        pqxx::connection c;
        pqxx::work       w(c);
        pqxx::result     r = w.exec("SELECT 'aze'");
        std::cout << r[0][0].as<std::string>() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

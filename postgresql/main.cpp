#include <iostream>
#include <pqxx/pqxx>


void create_table_tasks(pqxx::connection &connection)
{
    pqxx::work w(connection);
    w.exec("CREATE TABLE tasks( "
           "    task_id BIGSERIAL NOT NULL PRIMARY KEY, "
           "    task_name VARCHAR(50) NOT NULL "
           ")");
    w.commit();
}

void insert_dummy_tuple(pqxx::connection &connection, const std::string &name)
{
    pqxx::work w(connection);
    w.exec("INSERT INTO tasks( task_name ) "
           "VALUES ('" + name + "')");
    w.commit();
}


void insert_dummy_prepared_tuple(pqxx::connection &connection, const std::string &name)
{
    connection.prepare("mystatement", "INSERT INTO tasks( task_name ) "
                                      "VALUES ($1)");
    pqxx::work w(connection);
    w.prepared("mystatement")(name).exec();
    w.commit();
}


void selectTuple(pqxx::connection &connection)
{
    pqxx::work   w(connection);
    pqxx::result r = w.exec(
            "SELECT task_name "
            "FROM tasks "
            "WHERE task_id>0"
    );

    std::cout << r[0][0].as<std::__cxx11::string>() << std::endl;
}

int main()
{
    try
    {
        pqxx::connection c;
//        selectTuple(c);
//        create_table_tasks(c);
//        insert_dummy_tuple(c,"Yo momma so fat");
        insert_dummy_prepared_tuple(c, "Yo momma so fat 2");


    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

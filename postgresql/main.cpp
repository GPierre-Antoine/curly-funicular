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

void create_table_tasks_recursion(pqxx::connection &connection)
{
    pqxx::work w(connection);
    w.exec("CREATE TABLE tasks_recursion ( "
           "  task_parent BIGINT NOT NULL REFERENCES tasks (task_id) ON DELETE CASCADE, "
           "  task_child  BIGINT NOT NULL REFERENCES tasks (task_id) ON DELETE CASCADE, "
           "  PRIMARY KEY (task_parent, task_child)"
           ")");
    w.commit();
}

void insert_dummy_tuple(pqxx::connection &connection, const std::string &name)
{
    pqxx::work w(connection);
    w.exec("INSERT INTO tasks( task_name ) "
           "VALUES ('" + name + "') "
                                "RETURNING task_id");
    w.commit();
}

void insert_dummy_prepared_tuple(pqxx::connection &connection, const std::string &name)
{
    connection.prepare("mystatement", "INSERT INTO tasks( task_name ) "
                                      "VALUES ($1)"
                                      "RETURNING task_id");
    pqxx::work w(connection);
    auto       result = w.prepared("mystatement")(name).exec();
    std::cout << result[0][0] << std::endl;
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

    std::cout << r[0][0].as<std::string>() << std::endl;
}


void selectRecursiveTuple(pqxx::connection &connection)
{
    pqxx::work   w(connection);
    pqxx::result r = w.exec(
            "WITH RECURSIVE recursion(ancestor, descendant) AS ( "
            "  SELECT task_parent, task_child FROM tasks_recursion "
            "  UNION ALL "
            "      SELECT ancestor, task_child FROM tasks_recursion, recursion WHERE task_parent= descendant "
            ") "
            "SELECT ancestor, task_id, task_name FROM recursion "
            "JOIN tasks ON descendant=task_id"
    );

    for (const auto &i: r)
    {
        std::cout << "Task #" << i[0].as<int>() << " has descendant #" << i[1].as<int>() << " with title «" << i[2].as<std::string>() << "»\n";
    }
}

int main()
{
    try
    {
        pqxx::connection c;
//        selectTuple(c);
//        create_table_tasks(c);
//        insert_dummy_tuple(c,"Yo momma so fat");
//        insert_dummy_prepared_tuple(c, "Yo momma so fat 4");
        selectRecursiveTuple(c);

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

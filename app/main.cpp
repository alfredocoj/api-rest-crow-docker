#include "crow_all.h"

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "mysql_driver.h"
#include "mysql_error.h"

#define EXAMPLE_HOST "localhost"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "1234"
#define EXAMPLE_DB "festa"

using namespace std;

int main(int argc, const char **argv) {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
            ([] {

                try {
                    sql::Driver *driver;
                    sql::Connection *con;
                    sql::Statement *stmt;
                    sql::ResultSet *res;

                    /* Create a connection */
                    driver = get_driver_instance();
                    con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
                    /* Connect to the MySQL test database */
                    con->setSchema("festa");

                    stmt = con->createStatement();
                    res = stmt->executeQuery("SELECT * from convidado");
                    while (res->next()) {
                        cout << "\t... MySQL replies: ";
                        /* Access column data by alias or column name */
                        cout << res->getString("nome") << endl;
                        cout << "\t... MySQL says it again: ";
                        /* Access column data by numeric offset, 1 is the first column */
                        cout << res->getString(1) << endl;
                    }

                    delete res;
                    delete stmt;
                    delete con;
                    return "Hello, world!";

                } catch (sql::SQLException &e) {
                    cout << "# ERR: SQLException in " << __FILE__;
                    cout << "(" << __FUNCTION__ << ") on line ";
                    cout << "# ERR: " << e.what();
                    cout << " (MySQL error code: " << e.getErrorCode();
                    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
                }


            });

    app
            .port(8084)
            .run();
}
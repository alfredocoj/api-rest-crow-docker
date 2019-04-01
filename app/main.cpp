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
//                    while (res->next()) {
//                        cout << "\t... MySQL replies: ";
//                        //Access column data by alias or column name
//                        cout << res->getString("nome") << endl;
//                        cout << "\t... MySQL says it again: ";
//                        //Access column data by numeric offset, 1 is the first column
//                        cout << res->getString(1) << endl;
//                    }

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

    CROW_ROUTE(app, "/convidados")
            .methods("POST"_method)
                    ([] {
                        sql::Driver *driver;
                        sql::Connection *con;
                        sql::Statement *stmt;
                        sql::PreparedStatement *pstmt;
                        sql::ResultSet *res;

                        /* Create a connection */
                        driver = get_driver_instance();
                        con = driver->connect("tcp://127.0.0.1:3306", "root", "1234");
                        /* Connect to the MySQL test database */
                        con->setSchema("festa");

                        pstmt = con->prepareStatement("INSERT INTO convidado(nome, numero_convidado) VALUES (?, ?)");
                        pstmt->setString(1, "Sarah");
                        pstmt->setInt(2, 4);
                        pstmt->executeQuery();
                        /* '?' is the supported placeholder syntax */
//                for (int i = 1; i <= 10; i++) {
//                    pstmt->setInt(1, i);
//                    pstmt->executeUpdate();
//                }

                        stmt = con->createStatement();
                        res = stmt->executeQuery("SELECT * from convidado");
//                        while (res->next()) {
//                            cout << "\t... MySQL replies: ";
//                            //Access column data by alias or column name
//                            cout << res->getString("nome") << endl;
//                            cout << "\t... MySQL says it again: ";
//                            //Access column data by numeric offset, 1 is the first column
//                            cout << res->getString(1) << endl;
//                        }

                        crow::json::wvalue data;

                        data["nome"] = "Sarah";
                        data["numero_convidado"] = 3;

                        delete pstmt;
                        delete stmt;
                        delete con;
                        delete res;


                        return crow::response(201, data);

                    });


    app
            .port(8084)
            .run();
}
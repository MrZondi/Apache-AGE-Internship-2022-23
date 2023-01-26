#include <iostream>
#include <libpq-fe.h>
#include <jsoncpp/json/json.h>

int main(int argc, char *argv[]) {
    // Connect to the database
    PGconn *conn = PQconnectdb("dbname=testdb user=postgres password=password");
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cout << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;
        return 1;
    }
    // Execute the query
    PGresult *res = PQexec(conn, "SELECT * FROM public.user_table");
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        std::cout << "Query failed: " << PQresultErrorMessage(res) << std::endl;
        PQclear(res);
        PQfinish(conn);
        return 1;
    }
    // Build the JSON output
    Json::Value data;
    for (int i = 0; i < PQntuples(res); i++) {
        Json::Value row;
        row["user_id"] = std::stoi(PQgetvalue(res, i, 0));
        row["name"] = PQgetvalue(res, i, 1);
        row["age"] = std::stoi(PQgetvalue(res, i, 2));
        row["phone"] = PQgetvalue(res, i, 3);
        data.append(row);
    }
    Json::Value output;
    output["status_code"] = 200;
    output["data"] = data;
    std::cout << output.toStyledString() << std::endl;
    // Cleanup
    PQclear(res);
   

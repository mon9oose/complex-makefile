#include "boost/json.hpp"
#include "crow_all.h"
#include "param/param.hpp"
#include <iostream>

int main(void)
{
    crow::SimpleApp app;

    Param *p = new Param("a", "b", "c", "d");

    CROW_ROUTE(app, "/param")
    ([p]()
     { return p->GetParam1(); });

    CROW_ROUTE(app, "/")
    ([]()
     { return "Hello, World!"; });

    CROW_ROUTE(app, "/json")
    ([]()
     {
        crow::json::wvalue x({{"message", "Hello, World!"}});
        x["message2"] = "Hello, World... Again!";
        return x; });

    app.port(5400).run();
    return 0;
}

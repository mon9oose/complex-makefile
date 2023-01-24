#include "boost/json.hpp"
#include "crow_all.h"
#include "param/param.hpp"
#include <iostream>
#include <sstream>

std::string GetRequestQueryString(const crow::query_string &qs) {
  auto keys = qs.keys();

  std::ostringstream ss;
  for (auto i = 0; i < keys.size(); ++i) {
    if (i != 0)
      ss << "&";
    ss << keys[i] << "=" << qs.get(keys[i]);
  }

  return ss.str();
}

int main(void) {
  crow::SimpleApp app;

  Param *p = new Param("a", "b", "c", "d");

  CROW_ROUTE(app, "/")
  ([](const crow::request &req) {
    std::string queryString = GetRequestQueryString(req.url_params);
    std::cout << queryString << std::endl;

    crow::json::wvalue x({});
    x["message"] = "Hello, World!";
    x["message2"] = "Hello, World!... Again !!";
    x["result"] = {};
    x["result"]["item"] = "hihi";
    x["querys"] = queryString;

    return x;
  });

  CROW_ROUTE(app, "/param")
  ([p]() { return p->GetParam1(); });

  app.port(5400).run();
  return 0;
}

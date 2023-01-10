#ifndef __PARAM_HPP__
#define __PARAM_HPP__

#include <string>

class Param
{
private:
    std::string param1;
    std::string param2;
    std::string param3;
    std::string param4;

public:
    Param(std::string a, std::string b, std::string c, std::string d);
    ~Param();

    const std::string &GetParam1();
    const std::string &GetParam2();
    const std::string &GetParam3();
    const std::string &GetParam4();
};

#endif
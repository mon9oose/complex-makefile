#include "param.hpp"
#include <iostream>

Param::Param(std::string a, std::string b, std::string c, std::string d)
{
    param1 = a;
    param2 = b;
    param3 = c;
    param4 = d;

    std::cout << "construct param" << std::endl;
}

Param::~Param()
{
    std::cout << "destory param" << std::endl;
}

const std::string &Param::GetParam1()
{
    return param1;
}

const std::string &Param::GetParam2()
{
    return param2;
}

const std::string &Param::GetParam3()
{
    return param3;
}

const std::string &Param::GetParam4()
{
    return param4;
}
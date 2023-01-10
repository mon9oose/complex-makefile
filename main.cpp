#include "param/param.hpp"
#include <iostream>
#include <string>
#include <memory>

int main(void)
{
    std::cout << "start main function" << std::endl;

    std::unique_ptr<Param> p(new Param("a", "b", "c", "d"));
    std::cout << "p's data : " << p->GetParam1() << " " << p->GetParam2() << " " << p->GetParam3() << " " << p->GetParam4() << std::endl; 

    return 0;
}
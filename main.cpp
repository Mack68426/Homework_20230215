#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include "mystr.h"


int main(int argc, char* argv[])
{
    my::str str1 = "abcd"; // abcd
    my::str str2 = "efgh"; // efgh
    my::str sum = str1 + str2;
    my::str str3 = std::move(sum) ; // xvalue(expire value)
                                    // prvalue + xvalue = rvalue

    // chaining
    // std::cout << 1 << 2 << 3 << std::endl;
    
    
    my::str str4 = ("1234" + str1) * 3;

    std::cout << my::str('a') + 'd' + 'e' << std::endl;
    
    return 0;
}

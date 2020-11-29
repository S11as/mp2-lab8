#include <iostream>
#include "TStackList.h"

int main()
{
    TStackList<int> s;
    for (int i = 0; i < 20; ++i) {
        s.push(i);
    }
    s.save("tmp.txt");

    TStackList<int> b = TStackList<int>::load("tmp.txt");
    std::cout<<b<<std::endl;
    return 0;
}

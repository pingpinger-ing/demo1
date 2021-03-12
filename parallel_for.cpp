#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char **argv)
{
    auto values = std::vector<double>(1000000000);
    
    for (int i=0; i<values.size(); ++i)
    {
        values[i] = std::i ;
    }

    double total = 0;

    for (double value : values)
    {
        total += value;
    }

    std::cout << total << std::endl;

    return 0;
}

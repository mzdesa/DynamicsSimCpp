#include <NumCpp.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;
 
int main()
{
    auto a = nc::random::randInt<int>({10, 10}, 0, 100);

    auto x = nc::zeros<double>(3, 3);   
    std::cout << x <<"\n";

    auto y = nc::ones<double>(3, 3);

    y = nc::hstack({x, y});

    std::cout<< y << "\n";

    nc::NdArray<double> tTemp = {1.0};
;

    std::cout<<tTemp<<"\n";
 
    return EXIT_SUCCESS;
}






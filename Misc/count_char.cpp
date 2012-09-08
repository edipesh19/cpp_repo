#include <algorithm>
#include <iostream>
//unsing namespace std;
int main()
{
    std::string s = "a_b_c";
    int i = std::count(s.begin(), s.end(), '_');
    std::cout<<"i :"<<i<<std::endl;;
}

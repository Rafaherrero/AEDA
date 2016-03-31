#include "numero_t.hpp"

using namespace std;

ostream& operator<<(ostream& os, const numero_t& num)
{
    num.toStream(os);
    return os;
}

istream& operator>>(istream& is, numero_t& num)
{
    num.fromStream(is);
    return is;
}


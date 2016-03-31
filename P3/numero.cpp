#include "numero_t.hpp"

using namespace std;

ostream& numero_t::operator<<(ostream& os, const numero_t& num)
{
    num.toStream(os);
    return os;
}

istream& numero_t::operator>>(istream& is, numero_t& num)
{
    num.fromStream(is);
    return is;
}


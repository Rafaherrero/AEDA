#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class numero_t{
public:
    virtual ostream& toStream(ostream& os) const=0;
    virtual istream& fromStream(istream& is)=0;
};
#include <iostream>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/base_units/si/meter.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/io.hpp>
#include "base/Position.h"
#include "sensors/Accelerometer.h"

using namespace std;
using namespace boost::units;

int main()
{
    base::ENU<double> p;
    p.east = 2.7 * degree::degrees;

    quantity<si::length, double> l;
    l = 2.7 * si::meters;

    cout << *p.east << "and" << (p.north.has_value()? "yes" : "no") << endl;

    return 0;
}

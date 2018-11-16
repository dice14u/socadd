#include <boost/units/systems/si/velocity.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/base_unit.hpp>
#include <optional>

using namespace boost::units;
using namespace boost::units::si;
using namespace std;

namespace base {

    template <typename  size>
    struct Velocity {
        quantity<si::time, size> time;
        optional<quantity<velocity, size>> forward;
        optional<quantity<velocity, size>> rightward;
        optional<quantity<velocity, size>> downard;
        optional<quantity<velocity, size>> error;
    };
}

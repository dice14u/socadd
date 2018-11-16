#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/units/base_unit.hpp>
#include <optional>

using namespace boost::units;

namespace base {
    //ENU coordinate system
    template <typename  size>
    struct Orientation {
        quantity<si::time, size> time;
        optional<quantity<degree::plane_angle, size>> roll; // forward axis
        optional<quantity<degree::plane_angle, size>> pitch; // right axis
        optional<quantity<degree::plane_angle, size>> yaw; // degrees off north down axis
        optional<quantity<degree::plane_angle, size>> error;
    };
}

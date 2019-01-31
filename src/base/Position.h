#include <boost/units/systems/si/length.hpp>
#include <boost/units/base_units/si/meter.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/units/systems/si/plane_angle.hpp>
#include <boost/units/base_unit.hpp>
#include <optional>

using namespace boost::units;
using namespace std;

namespace base {
    //ENU coordinate system
    template <typename  size>
    struct ENU {
        quantity<si::time, size> time;
        optional<quantity<degree::plane_angle, size>> east;
        optional<quantity<degree::plane_angle, size>> north;
        optional<quantity<si::length, size>> up;
        optional<quantity<degree::plane_angle, size>> xyError;
        optional<quantity<si::length, size>> zError;
    };

    template <typename T>
    quantity<si::length, T> haversine(ENU<T> p1, ENU<T> p2) {
        double earthRadiusKm = 6371.0;

        auto toRadianT = [](quantity<degree::plane_angle, T> val) -> T {
            return static_cast<quantity<si::plane_angle, T>>(val).value();
        };

        T lat1 = toRadianT(*p1.north);
        T lat2 = toRadianT(*p2.north);
        T lon1 = toRadianT(*p1.east);
        T lon2 = toRadianT(*p2.east);

        T u = sin((lat2 - lat1)/2);
        T v = sin((lon2 - lon1)/2);

        return 2000.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1) * cos(lat2) * v * v)) * si::meters;
    }

    template <typename T>
    quantity<si::plane_angle, T> bearing(ENU<T> p1, ENU<T> p2) {
        auto toRadianT = [](quantity<degree::plane_angle, T> val) -> T {
            return static_cast<quantity<si::plane_angle, T>>(val).value();
        };

        T lat1 = toRadianT(*p1.north);
        T lat2 = toRadianT(*p2.north);
        T lon1 = toRadianT(*p1.east);
        T lon2 = toRadianT(*p2.east);

        T u = sin(lon2 - lon1) * cos(lat2);
        T v = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lon2-lon1);

        T result = atan2(u, v);

        return result * si::radians;
    }

    template <typename  size>
    struct FRD {
        quantity<si::time, size> time;
        optional<quantity<si::length, size>> forward;
        optional<quantity<si::length, size>> right;
        optional<quantity<si::length, size>> down;
        optional<quantity<si::length, size>> error;
    };
}

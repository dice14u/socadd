#include "../base/Velocity.h"
#include "../base/Position.h"
#include "../base/Orientation.h"

using namespace base;

template<typename T>
struct Acceleration {
    T xdd;
    T ydd;
    T zdd;
};

namespace sensors {
    class IMU {
        private:
            Velocity velocity;
            Position position;
        public:
            // an integration based position from time of last reset
            Position getPosition();
            // an integration based velocity from time of last reset (called on calibrate)
            Velocity getVelocity();

            // get the instantanious last acceleration
            template<typename T>
            Acceleration<T> getAcceleration<T>();

            // generally off the gyro or emptys if not possible
            Orientation getOrientation();

            void calibrate(); // zeros the internal v and p

            void setVelocity(Velocity);
            void setPosition(Position);

            void update();
    }
}

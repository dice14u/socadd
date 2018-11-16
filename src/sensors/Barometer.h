#include "../base/Position.h"

class Altimeter {
    private:
        float pressure;
    public:
        Altimiter(float pressure): pressure(pressure);
        Position getAltitude();
        void setPressure(float);
}

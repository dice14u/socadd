template <class Authority>
class SticksInput {
    public:
        Authority getRoll();
        Authority getPitch();
        Authority getYaw();
        Authority getForward();
        Authority getRightward();
        Authority getDownward();
}

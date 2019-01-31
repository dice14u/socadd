#include <iostream>
#include <mutex>
#include <thread>
#include "base/Position.h"
#include "condition_variable"

using namespace std;


int main()
{
    thread workWaiter;
    cout << "app running press ctrl+c to stop" << endl;
    condition_variable cv;
    mutex space;

    lock_guard<mutex> guard(space);
    unique_lock<mutex> lk(space);
    cout << "about to block" << endl;


    cv.wait(lk);
    cout << "signaled" << endl;
}

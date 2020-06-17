//
// Created by Joseph Cresswell on 16/06/2020.
//

/*
  ==============================================================================

    SingletonWavetable.h
    Created: 29 May 2020 2:40:10pm
    Author:  Joseph Cresswell

  ==============================================================================
*/

#pragma once
//#include <android/log.h>
#include <iostream>

namespace juce {
    class Accelerometer {
    public:

        ~Accelerometer() {};

        Accelerometer(
                const Accelerometer &) = delete; //Don't allow copy of object to made by deleting the copy constructor


        static Accelerometer &get() //Getting singleton wavetable
        {
            static Accelerometer masterAcc; //This will stay constant for duration of use
            return masterAcc; //Return reference to the only object
        }

        float getXVal() {
            return xVal;
        }

        float getYVal() {
            return yVal;
        }

        float getZVal() {
            return zVal;
        }

        void setXVal(float x) {
            xVal = x;
            //__android_log_print(ANDROID_LOG_ERROR, "TRACKERS", "%f", x);
        }

        void setYVal(float y) {
            yVal = y;
        }

        void setZVal(float z) {
            zVal = z;
        }


    private:
        Accelerometer() {
            DBG("Creation2.0");
        }; //Making constructor private to avoid making muilitple

        std::atomic<float> xVal{0.0f};
        std::atomic<float> yVal{0.0f};
        std::atomic<float> zVal{0.0f};

        /*float xVal{0.0f};
        float yVal{0.0f};
        float zVal{0.0f};*/

        //Android_Accelerometer thisNewAcc;
    };
}

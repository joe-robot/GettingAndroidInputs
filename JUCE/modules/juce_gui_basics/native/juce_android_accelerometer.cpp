//
// Created by Joseph Cresswell on 14/06/2020.
//

namespace juce {

    class Android_Accelerometer {

    public:
        static GlobalRef activityCallbackListener2;

        Android_Accelerometer() {
            andACC = this;
            DBG("Creation");
            auto *env = getEnv();
            DBG("1");
            // NB: must not put this in the initialiser list, as it invokes a callback,
            // which will fail if the peer is only half-constructed.
            view2 = GlobalRef(LocalRef<jobject>(
                    env->NewObject(SensorRetrieve, SensorRetrieve.constructor))); //Fails here
            DBG("2");


            /*Android_Accelerometer::activityCallbackListener2 = GlobalRef (CreateJavaInterface (
                    new Android_Accelerometer::StartupActivityCallbackListener,
                    "android/app/Sensor$Event$Listener"));

            env->CallVoidMethod (getAppContext(),
                                 AndroidApplication.registerActivityLifecycleCallbacks,
                                 Android_Accelerometer::activityCallbackListener2.get());*/
        }

        ~Android_Accelerometer() {
            // auto* env = getEnv();

            // env->CallVoidMethod (view, SensorRetrieve.clear);
        }

        void handleAccelerometerCallback(float x, float y, float z) {
            DBG(x);
            Accelerometer::get().setXVal(x);

        }


        //private:

#define JNI_CLASS_MEMBERS(METHOD, STATICMETHOD, FIELD, STATICFIELD, CALLBACK) \
    METHOD   (constructor,                      "<init>",                      "()V") \
    CALLBACK (handleAccelerometerJni, "handleAccelerometer",  "(FFF)V") \

        DECLARE_JNI_CLASS_WITH_MIN_SDK (SensorRetrieve,
        "com/roli/juce/SensorRetrieve", 16)
#undef JNI_CLASS_MEMBERS

        static void JNICALL
        handleAccelerometerJni     (JNIEnv
        *, jobject /*view*/,
        jfloat x, jfloat
        y,
        jfloat z
        )
        {
            if (auto *myself = reinterpret_cast<Android_Accelerometer *> (andACC)) {
                myself->handleAccelerometerCallback((float) x, (float) y, (float) z);
            }
        }

        static Android_Accelerometer *andACC;

        GlobalRef view2;

        /*struct StartupActivityCallbackListener : ActivityLifecycleCallbacks
        {
            void onActivityStarted (jobject /*activity) override
            {
                auto* env = getEnv();
                LocalRef<jobject> appContext (getAppContext());

                if (appContext.get() != nullptr)
                {

                    env->CallVoidMethod (appContext.get(),
                                         AndroidApplication.unregisterActivityLifecycleCallbacks,
                                         activityCallbackListener2.get());
                    //clear();
                    activityCallbackListener2.clear();

                    //const_cast<Displays &> (Desktop::getInstance().getDisplays()).refresh();
                }
            }
        };

    };*/
    };
    //Android_Accelerometer myAcc;
    Android_Accelerometer::SensorRetrieve_Class Android_Accelerometer::SensorRetrieve;
    Android_Accelerometer* Android_Accelerometer::andACC = nullptr;
    //GlobalRef Android_Accelerometer::activityCallbackListener2;


}
package com.roli.juce;

import android.app.Activity;
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.FrameLayout;
import android.widget.TextView;

import android.util.Log;

import java.util.ArrayList;

public class SensorRetrieve extends Activity implements SensorEventListener{
    private SensorManager sensorManager;
    double ax,ay,az;   // these are the acceleration in x,y and z axis

    public SensorRetrieve()
    {
        Log.d("Test: ","testing");
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.main_activity);
        Log.d("Test: ","test");
        sensorManager=(SensorManager) getSystemService(SENSOR_SERVICE);
        sensorManager.registerListener(this, sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER), SensorManager.SENSOR_DELAY_NORMAL);
    }
    @Override
    public void onAccuracyChanged(Sensor arg0, int arg1) {
    }

    @Override
    public void onSensorChanged(SensorEvent event) {

        if (event.sensor.getType()==Sensor.TYPE_ACCELEROMETER){
            ax=event.values[0];
            ay=event.values[1];
            az=event.values[2];
            Log.d("Test: ", "x:" + ax);

            handleAccelerometer((float)ax, (float)ay, (float)az);
        }
    }

    /**
     * @param x
     * @param y
     * @param z
     */
    private native void handleAccelerometer(float x, float y, float z);
}

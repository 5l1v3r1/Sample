package com.bgstation0.android.sample.log_;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

	// ���O���������₷�����邽�߂̃^�O���`.
	private final String TAG = "MainActivity";	// TAG��"MainActivity"�Ƃ���.(final�Ȃ̂ŕύX�s�̕�����.)
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ���O�̕\��
        Log.v(TAG, "onCreate(VERBOSE)");	// Log.v�Ń��O���x��VERBOSE�ȃ��O�Ƃ���"onCreate(VERBOSE)"���o��.
        Log.d(TAG, "onCreate(DEBUG)");		// Log.d�Ń��O���x��DEBUG�ȃ��O�Ƃ���"onCreate(DEBUG)"���o��.
        Log.i(TAG, "onCreate(INFO)");		// Log.i�Ń��O���x��INFO�ȃ��O�Ƃ���"onCreate(INFO)"���o��.
        Log.w(TAG, "onCreate(WARN)");		// Log.w�Ń��O���x��WARN�ȃ��O�Ƃ���"onCreate(WARN)"���o��.
        Log.e(TAG, "onCreate(ERROR)");		// Log.e�Ń��O���x��ERROR�ȃ��O�Ƃ���"onCreate(ERROR)"���o��.
    }
}

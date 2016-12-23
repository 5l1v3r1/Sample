package com.bgstation0.android.sample.pendingintent_;

import java.util.Calendar;

import android.app.Activity;
import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // "CUSTOM_ACTION"�ɔ�������Intent�̍쐬.
        Intent intent = new Intent("CUSTOM_ACTION");	// "CUSTOM_ACTION"�ɔ�������intent���쐬.
        
        // intent��x��Ď��s����PendingIntent�̍쐬.
        PendingIntent pendingIntent = PendingIntent.getBroadcast(this, 1, intent, 0);	// PendingIntent.getBroadcast��intent�Ɏw�肵���A�N�V������x��Ď��s����pendingIntent���쐬.

        // Calendar��5�b��̎������Z�b�g.
        Calendar calendar = Calendar.getInstance();	// Calendar.getInstance�ŃC���X�^���Xcalendar���擾.
        calendar.setTimeInMillis(System.currentTimeMillis());	// System.currentTimeMillis()�Ō��ݎ������擾��, �����calendar.setTimeInMillis��calendar�ɃZ�b�g.
        calendar.add(Calendar.SECOND, 5);	// calendar.add��5�b��ɃZ�b�g.
        
        // AlarmManager��pendingIntent��calendar���Z�b�g.
        AlarmManager alarmManager = (AlarmManager)getSystemService(ALARM_SERVICE);	// getSystemService(ALARM_SERVICE)��alarmManager���擾.
        alarmManager.set(AlarmManager.RTC, calendar.getTimeInMillis(), pendingIntent);	// alarmManager.set��calendar.getTimeInMillis��pendingIntent���Z�b�g��, ����ŃA���[���Z�b�g����.
        
    }
}

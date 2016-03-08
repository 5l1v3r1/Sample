package com.bgstation0.android.sample.service_;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

// MainActivity�ɂ���ċN�������MainService.
public class MainService extends Service {	// MainService�̒�`.

	// �^�O�̒�`
	private final String TAG = "MainService";	// TAG��"MainService"
		
	@Override
	public IBinder onBind(Intent intent) {
		// TODO Auto-generated method stub
		return null;
	}
	
	// �T�[�r�X���������ꂽ�Ƃ�
	@Override
	public void onCreate(){	// onCreate�̒�`
		
		// �e�N���X�̊��菈��
		super.onCreate();	// super.onCreate�Őe�N���X�̊��菈��.
		
		// ���O�̕\��
		Log.v(TAG, "onCreate()");	// Log.v��"onCreate()"��\��.
		
	}
	
	// �T�[�r�X�̊J�n�v�����󂯂��Ƃ�
	@Override
	public int onStartCommand(Intent intent, int flags, int startId){	// onStartCommand�̒�`
		
		// ���O�̕\��
		Log.v(TAG, "onStartCommand()");	// Log.v��"onStartCommand()"��\��.
		
		// �߂�l��Ԃ�.
		return START_STICKY;	// �߂�l��START_STICKY���w��.(�T�[�r�X�������I��������, �ċN������ݒ�.)

	}
	
	// �T�[�r�X���j�����ꂽ�Ƃ�
	@Override
	public void onDestroy(){	// onDestroy�̒�`
		
		// �e�N���X�̊��菈��
		super.onDestroy();	// super.onDestroy�Őe�N���X�̊��菈��.
				
		// ���O�̕\��
		Log.v(TAG, "onDestroy()");	// Log.v��"onDestroy()"��\��.
		
	}
}

package com.bgstation0.android.sample.application_;

import android.app.Application;
import android.widget.Toast;

public class CustomApplication extends Application {

	// �����o�t�B�[���h�̒�`
	private int appCount = 0;	// int�^appCount��0�ɏ�����.

	// �A�v���P�[�V�����쐬��.
	@Override
	public void onCreate(){
		super.onCreate();
		
		// Toast��appCount��\��.
		Toast.makeText(this, "appCount = " + appCount, Toast.LENGTH_LONG).show();
	}
	
	// �A�v���P�[�V�����I����.(���ۂɂ͌Ă΂�Ȃ��̂Œ���!)
	@Override
	public void onTerminate(){
		// Toast��appCount��\��.
		Toast.makeText(this, "appCount = " + appCount, Toast.LENGTH_LONG).show();
				
		super.onTerminate();
	}
	
	// appCount�̎擾
	public int getAppCount(){
		return appCount;	// appCount��Ԃ�.
	}
	
	// appCount�̐ݒ�
	public void setAppCount(int count){
		appCount = count;	// appCount��count����.
	}
}

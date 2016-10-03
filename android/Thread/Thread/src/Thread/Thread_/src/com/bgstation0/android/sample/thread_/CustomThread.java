package com.bgstation0.android.sample.thread_;

import android.util.Log;

public class CustomThread extends Thread {
	
	// �����o�t�B�[���h�̒�`.
	private final String TAG = "Thread_";	// TAG"Thread_"�̒�`.
	
	public void run(){
		
		// Thread.sleep�ŋ[���I�ɏd�������������s.
    	// try�ň͂܂Ȃ��Ƃ����Ȃ�.
    	try{
    		Log.d(TAG, "Thread.sleep before");	// Log.d��"Thread.sleep before"�ƃ��O�o��.
    		Thread.sleep(10000);	// Thread.sleep��10�b�x�~.
    		Log.d(TAG, "Thread.sleep after");	// Log.d��"Thread.sleep after"�ƃ��O�o��.
    	}
    	catch(Exception ex){
    		Log.d(TAG, "ex = " + ex.toString());	// Log.d��ex���o��.
    	}
		
	}

}

package com.bgstation0.android.sample.aaa_;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

public class AuthenticationService extends Service {

	// �����o�t�B�[���h�̒�`.
	private CustomAuthenticator mCustomAuthenticator = null;	// mCustomAuthenticator��null�ŏ�����.
	
	// �T�[�r�X�̐���.
	@Override
	public void onCreate(){
		super.onCreate();	// �e�N���X�̐���.
		mCustomAuthenticator = new CustomAuthenticator(this);	// mCustomAuthenticator�𐶐�.
	}
	
	// �o�C���h.
	@Override
	public IBinder onBind(Intent intent) {
		// TODO Auto-generated method stub
		return mCustomAuthenticator.getIBinder();	// mCustomAuthenticator.getIBinder�̖߂�l��Ԃ�.
	}

}
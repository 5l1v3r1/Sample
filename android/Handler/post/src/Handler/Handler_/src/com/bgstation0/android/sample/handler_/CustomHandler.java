package com.bgstation0.android.sample.handler_;

import android.content.Context;
import android.os.Handler;
import android.widget.Button;

public class CustomHandler extends Handler implements Runnable{

	// �����o�t�B�[���h�̒�`.
	Context mContext = null;	// mContext��null�ŏ�����.
	
	// �R���X�g���N�^
	public CustomHandler(Context context){
		
		// �����o�ɃZ�b�g.
		mContext = context;	// mContext��context���Z�b�g.
		
	}
	
	// ���b�Z�[�W�L���[�Ƀ|�X�g.
	public boolean post(){
		return super.post(this);
	}
	
	// ���s����.
	@Override
	public void run(){
		Button button1 = (Button)((MainActivity)mContext).findViewById(R.id.button1);	// button1���擾.
		button1.setText("Pushed!");	// "Pushed!"�ɕύX.
	}
	
}

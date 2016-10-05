package com.bgstation0.android.sample.asynctask_;

import android.app.Activity;
import android.content.Context;
import android.os.AsyncTask;
import android.widget.TextView;

public class CustomAsyncTask extends AsyncTask<Integer, Integer, String> {	// �񓯊������ɓn���p�����[�^��Integer, �i����Ԃ�Integer, �񓯊������̌��ʂ�String��CustomAsyncTask.

	// �����o�t�B�[���h�̒�`
	Context context;	// Context�^context
	
	// �R���X�g���N�^
	public CustomAsyncTask(Context context){
		this.context = context;	// this.context�����o�Ɋi�[.
	}
	
	// �񓯊�����
	@Override
	protected String doInBackground(Integer... params){
		// �I�u�W�F�N�g�̐錾
		String ret = "";	// �߂�l�̕�����ret��""���Z�b�g.
		// try�ň͂�.
		try{
			Thread.sleep(10000);	// 10�b�x�~
			if (params.length > 0){	// params�̗v�f����1�ł�����.
				ret = "params[0] = " + params[0];	// ret��0�Ԗڂ̈���.
			}
			else{
				ret = "params[0] = nothing";	// ret��nothing.
			}
		}
		catch (Exception ex){
			ret = "excaption";	// ret��exception.
		}
		return ret;
	}
	
	// UI�X���b�h�̍X�V
	@Override
	protected void onPostExecute(String result){
		// textview1�̍X�V
		Activity activity = (Activity)context;	// context��activity�ɃL���X�g.
		TextView textview1 = (TextView)activity.findViewById(R.id.textview1);	// textview1���擾.
		textview1.setText(result);	// textview1.setText��result���Z�b�g.
	}
	
}

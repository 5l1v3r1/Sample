package com.bgstation0.android.sample.application_;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

public class SubActivity extends Activity {

	// �����o�t�B�[���h�̒�`
	private CustomApplication customApp;	// CustomApplication�^customApp
	private int subCount = 0;	// int�^subCount��0�ɏ�����.
	
	// Activity���������ꂽ�Ƃ�.
	@Override
	protected void onCreate(Bundle savedInstanceState) {	// onCreate�̒�`
		super.onCreate(savedInstanceState);
			
		// "SubActivity!"�̕\��.
		TextView tv = new TextView(this);	// TextView�I�u�W�F�N�gtv�̐���.
		tv.setText("SubActivity!");	// tv.setText��"SubActivity!"�̃Z�b�g.
		setContentView(tv);	// setContentView��tv��\��.

		// Toast��subCount�̒l��\��.
		Toast.makeText(this, "subCount = " + subCount, Toast.LENGTH_LONG).show();		
				
		// subCount��1���₷.
		subCount++;	// subCount���C���N�������g.
		
		// CustomApplication�I�u�W�F�N�g�̎擾.
		customApp = (CustomApplication)getApplication();	// getApplication��customApp���擾.
		
		// customApp��appCount�擾.
		int appCount = customApp.getAppCount();	// customApp.getAppCount��appCount���擾.
		
		// Toast��appCount�̒l��\��.
		Toast.makeText(this, "appCount = " + appCount, Toast.LENGTH_LONG).show();
		
		// appCount��1���₷.
		appCount++;	// appCount���C���N�������g.
		
		// customApp��aooCount�ݒ�.
		customApp.setAppCount(appCount);	// customApp.setAppCount��appCount��ݒ�.
	}
		
	// Activity���j�����ꂽ�Ƃ�.
	@Override
	protected void onDestroy(){
		
		// Toast��subCount�̒l��\��.
		Toast.makeText(this, "subCount = " + subCount, Toast.LENGTH_LONG).show();
		
		// customApp��appCount�擾.
		int appCount = customApp.getAppCount();	// customApp.getAppCount��appCount���擾.
				
		// Toast��appCount�̒l��\��.
		Toast.makeText(this, "appCount = " + appCount, Toast.LENGTH_LONG).show();
						
		super.onDestroy();
	}
}

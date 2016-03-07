package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

//�_�C�A���O���A�N�e�B�r�e�BDialogActivity.
public class DialogActivity extends Activity {	// DialogActivity�̒�`.

	// �^�O�̒�`
	private final String TAG = "DialogActivity";	// TAG��"DialogActivity"
	
	// Activity���������ꂽ�Ƃ�.
	@Override
	protected void onCreate(Bundle savedInstanceState) {	// onCreate�̒�`
		
		// �e�N���X�̏���
		super.onCreate(savedInstanceState);	// super.onCreate�Őe�N���X�̊��菈��.
		
		// "SubActivity!"�̕\��.
		TextView tv = new TextView(this);	// TextView�I�u�W�F�N�gtv�̐���.
		tv.setText("DialogActivity!");	// tv.setText��"DialogActivity!"�̃Z�b�g.
		setContentView(tv);	// setContentView��tv��\��.
	}
}

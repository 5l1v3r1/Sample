package com.bgstation0.android.sample.bundle_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class SubActivity extends Activity {

	// Activity���������ꂽ�Ƃ�.
	@Override
	protected void onCreate(Bundle savedInstanceState) {	// onCreate�̒�`
		super.onCreate(savedInstanceState);
		
		// �n���ꂽIntent�����擾.
		Intent intent = getIntent();	// getIntent�œn���ꂽintent���擾.
		Bundle args = intent.getExtras();	// intent.getExtras��Bundle�^args���擾.
		String str = args.getString("str");	// args.getString��"str"���L�[�Ƃ���l���擾.
		int num = args.getInt("num");	// args.getInt��"num"���L�[�Ƃ���l���擾.
		boolean bool = args.getBoolean("bool");	// args.getBoolean��"bool"���L�[�Ƃ���l���擾.
		
		// SubActivity�ɓn���ꂽ�l��\��.
		TextView tv = new TextView(this);	// TextView�I�u�W�F�N�gtv�̐���.
		String tvStr = "";	// �\�����镶����tvStr��""�ŏ�����.
		tvStr = tvStr + "str = ";	// "str = "��A��.
		tvStr = tvStr + str;	// str��A��.
		tvStr = tvStr + ", ";	// ", "��A��.
		tvStr = tvStr + "num = ";	// "num = "��A��.
		tvStr = tvStr + num;	// num��A��.
		tvStr = tvStr + ", ";	// ", "��A��.
		tvStr = tvStr + "bool = ";	// "bool = "��A��.
		if (bool){
			tvStr = tvStr + "true";	// "true"��A��.
		}
		else{
			tvStr = tvStr + "false";	// "false"��A��.
		}
		tv.setText(tvStr);	// tv.setText��tvStr���Z�b�g.
		setContentView(tv);	// setContentView��tv��\��.
	}
}

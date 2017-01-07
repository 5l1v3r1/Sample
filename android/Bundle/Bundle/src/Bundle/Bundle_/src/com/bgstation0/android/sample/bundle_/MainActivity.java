package com.bgstation0.android.sample.bundle_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.

    	// SubActivity�ɓn���p�����[�^�̏���.
    	Bundle args = new Bundle();	// Bundle�I�u�W�F�N�gargs�̐���.
    	args.putString("str", "ABCDE");	// �L�[��"str", �l��"ABCDE"�Ƃ���putString�ŃZ�b�g.
    	args.putInt("num", 10);	// �L�[��"num", �l��10�Ƃ���putInt�ŃZ�b�g.
    	args.putBoolean("bool", true);	// �L�[��"bool", �l��true�Ƃ���putBoolean�ŃZ�b�g.
    	
    	// �A�N�e�B�r�e�B�̊J�n.
    	Intent intent1 = new Intent(this, SubActivity.class);	// SubActivity��ΏۂƂ���Intent�I�u�W�F�N�gintent1�𐶐�.
    	intent1.putExtras(args);	//  intent1.putExtras��args��intent1�ɃZ�b�g.
    	startActivity(intent1);	// startActivity��intent1���w�肵��Activity���N��.
    	
    }
    
}

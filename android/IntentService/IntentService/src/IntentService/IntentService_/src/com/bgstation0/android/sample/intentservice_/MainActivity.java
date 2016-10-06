package com.bgstation0.android.sample.intentservice_;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
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
    	// CustomIntentService�̋N��
    	int param = 10;	// int�^param��10�ɃZ�b�g.
    	Intent intent = new Intent(this, CustomIntentService.class);	// CustomIntentService���N������intent���쐬.
    	intent.putExtra("param", param);	// intent.putExtra�ŃL�[��"param", �l��param( = 10)�Ƃ��Ĉ�����n��.
    	Log.d("MainActivity", "startService, param = " + param);	// Log.d��"startService"��param�̒l���o��.
    	startService(intent);	// startService��intent�̎w���T�[�r�X���N��.   	
    }
}

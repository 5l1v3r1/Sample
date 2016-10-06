package com.bgstation0.android.sample.asynctaskloader_;

import android.app.Activity;
import android.app.LoaderManager.LoaderCallbacks;
import android.content.Loader;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity implements OnClickListener, LoaderCallbacks<String>{	// View.OnClickListener, LoaderCallbacks������.
    
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
    	// Loader�̏�����
        Bundle args = new Bundle();	// Bundle�^
        args.putInt("param", 10);	// args.putInt�ŃL�[��"param", �l��10�Ƃ��Ĉ�����n��.
        getLoaderManager().initLoader(0, args, this);	// initLoader��Loader������.(������̊J�n.)
    }
    
    // Loader�̍쐬��
    @Override
    public Loader<String> onCreateLoader(int id, Bundle args){
    	// args������������o��, CustomAsyncTaskLoader�ɓn���Đ���.
    	int param = args.getInt("param");	// �L�["param"�̒l��param�Ɋi�[.
    	return new CustomAsyncTaskLoader(this, param);	// new��this��param��CustomAsyncTaskLoader�ɓn���Đ���, return�ŕԂ�.
    }
    
    // Loader�̏I����
    @Override
    public void onLoadFinished(Loader<String> loader, String data){
    	// textview1�ɔ񓯊������̌���data���Z�b�g.
    	TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
		textview1.setText(data);	// textview1.setText��data���Z�b�g.
    }
    
    // Loader�̃��Z�b�g��
    @Override
    public void onLoaderReset(Loader<String> loader){
    	
    }
}
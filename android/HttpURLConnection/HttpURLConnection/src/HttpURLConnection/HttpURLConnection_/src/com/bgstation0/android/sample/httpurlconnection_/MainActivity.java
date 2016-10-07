package com.bgstation0.android.sample.httpurlconnection_;

import android.app.Activity;
import android.app.LoaderManager.LoaderCallbacks;
import android.content.Loader;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

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
    	EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1�̎擾.
    	String url = edittext1.getText().toString();	// edittext1�̓��e��url�ɑ��.
    	args.putString("url", url);	// args.putString��url��args�ɃZ�b�g.
    	getLoaderManager().initLoader(0, args, this);	// initLoader��Loader������.(������̊J�n.)
    }
    
    // Loader�̍쐬��
    @Override
    public Loader<String> onCreateLoader(int id, Bundle args){
    	// args������������o��, CustomAsyncTaskLoader�ɓn���Đ���.
    	String url = args.getString("url");	// �L�["url"�̒l��url�Ɋi�[.
    	return new CustomAsyncTaskLoader(this, url);	// new��this��url��CustomAsyncTaskLoader�ɓn���Đ���, return�ŕԂ�.
    }

    // Loader�̏I����
    @Override
    public void onLoadFinished(Loader<String> loader, String data){
    	// edittext1�ɔ񓯊������̌���data���Z�b�g.
    	EditText edittext2 = (EditText)findViewById(R.id.edittext2);	// edittext2���擾.
    	edittext2.setText(data);	// edittext2.setText��data���Z�b�g.
    }
    
    // Loader�̃��Z�b�g��
    @Override
    public void onLoaderReset(Loader<String> loader){
    	
    }
}
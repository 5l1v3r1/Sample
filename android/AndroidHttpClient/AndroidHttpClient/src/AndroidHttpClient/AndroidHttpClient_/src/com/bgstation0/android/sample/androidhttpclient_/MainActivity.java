package com.bgstation0.android.sample.androidhttpclient_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

// ���C���A�N�e�B�r�e�B
public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`
	CustomAsyncTask mTask = null;	// CustomAsyncTask�I�u�W�F�N�gmTask��null�ŏ�����.
		
	// �A�N�e�B�r�e�B������.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// ����̏���
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // CustomAsyncTask�̐����Ǝ��s.
        mTask = new CustomAsyncTask(this);	// CustomAsyncTask�I�u�W�F�N�g���쐬��mTask�Ɋi�[.
        mTask.execute("http://bgstation0.com/");	// "http://bgstation0.com/"��n���Ď��s.
        
    }
    
}
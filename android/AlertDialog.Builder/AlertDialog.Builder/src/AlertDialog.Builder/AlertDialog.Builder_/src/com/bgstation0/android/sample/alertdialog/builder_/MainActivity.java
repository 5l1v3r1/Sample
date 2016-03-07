package com.bgstation0.android.sample.alertdialog.builder_;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

	// �^�O�̒�`
	private final String TAG = "MainActivity";	// TAG��"MainActivity"
		
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        //button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    	
    	// �A���[�g�_�C�A���O�r���_�[�̐���
    	AlertDialog.Builder builder = new AlertDialog.Builder(this);	// AlertDialog.Builer�̃C���X�^���Xbuilder�̐���.
    	
    	// �A���[�g�_�C�A���O�̐ݒ�
    	builder.setTitle("AlertDialog.Builder");	// setTitle�Ń^�C�g��"AlertDialog.Builder"���Z�b�g.
    	builder.setMessage("AlertDialog.Builder");	// setMessage�Ŗ{��"AlertDialog.Builder"���Z�b�g.

    	// �|�W�e�B�u�{�^���̐ݒ�
    	builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {	// builder.setPositiveButton�Ń|�W�e�B�u�{�^��"OK"��DialogInterface.OnClickListener���Z�b�g. 
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
				Log.v(TAG, "AlertDialog OK onClick!");	// Log.v��"AlertDialog OK onClick!"��\��.
			}
		});

    	// �A���[�g�_�C�A���O�̕\��
    	builder.show();	// builder.show�ŃA���[�g�_�C�A���O��\��
    }
}

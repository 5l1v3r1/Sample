package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

	// �^�O�̒�`
	private final String TAG = "MainActivity";	// TAG��"MainActivity"
	private final int DIALOG_ID_1 = 1;	// DIALOG_ID_1��1�ɂ���.
	private final int DIALOG_ID_2 = 2;	// DIALOG_ID_2��2�ɂ���.
	
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
        
        // button2�𗘗p��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewById��R.id.button2���擾.
        button2.setOnClickListener(this);	// button2.setOnClickListener��this(���g)���Z�b�g.
        
    }
	
	// View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    
    	// �{�^����ID���Ƃɕ�����.
    	if (v.getId() == R.id.button1){ // button1

    		// DIALOG_ID_1�̕\��.
    		showDialog(DIALOG_ID_1);	// showDialog��DIALOG_ID_1�̃_�C�A���O�\��.
    		
    	}
    	else if (v.getId() == R.id.button2){ // button2
    		
    		// DIALOG_ID_2�̕\��.
    		showDialog(DIALOG_ID_2);	// showDialog��DIALOG_ID_2�̃_�C�A���O�\��.
    		
    	}
    	
    }
    
    // onCreateDialog�Ń_�C�A���O�쐬.
    @Override
    protected Dialog onCreateDialog(int id){
    	
    	// �A���[�g�_�C�A���O�r���_�[�̐���
    	AlertDialog.Builder builder = new AlertDialog.Builder(this);	// AlertDialog.Builer�̃C���X�^���Xbuilder�̐���.
    
    	// ID���Ƃɕς���.
    	if (id == DIALOG_ID_1){	// DIALOG_ID_1
    		
	    	// �A���[�g�_�C�A���O�̐ݒ�
	    	builder.setTitle("Activity.showDialog(1)");	// setTitle�Ń^�C�g��"Activity.showDialog(1)"���Z�b�g.
	    	builder.setMessage("Activity.showDialog(1)");	// setMessage�Ŗ{��"Activity.showDialog(1)"���Z�b�g.
	
	    	// �|�W�e�B�u�{�^���̐ݒ�
	    	builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {	// builder.setPositiveButton�Ń|�W�e�B�u�{�^��"OK"��DialogInterface.OnClickListener���Z�b�g. 
				
				@Override
				public void onClick(DialogInterface dialog, int which) {
					// TODO Auto-generated method stub
					Log.v(TAG, "Activity.showDialog(1) OK onClick!");	// Log.v��"Activity.showDialog(1) OK onClick!"��\��.
				}
				
			});
    	
    	}
    	else if (id == DIALOG_ID_2){ // DIALOG_ID_2
    		
    		// �A���[�g�_�C�A���O�̐ݒ�
	    	builder.setTitle("Activity.showDialog(2)");	// setTitle�Ń^�C�g��"Activity.showDialog(2)"���Z�b�g.
	    	builder.setMessage("Activity.showDialog(2)");	// setMessage�Ŗ{��"Activity.showDialog(2)"���Z�b�g.
	
	    	// �|�W�e�B�u�{�^���̐ݒ�
	    	builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {	// builder.setPositiveButton�Ń|�W�e�B�u�{�^��"OK"��DialogInterface.OnClickListener���Z�b�g. 
				
				@Override
				public void onClick(DialogInterface dialog, int which) {
					// TODO Auto-generated method stub
					Log.v(TAG, "Activity.showDialog(2) OK onClick!");	// Log.v��"Activity.showDialog(2) OK onClick!"��\��.
				}
				
			});
    		
    	}

    	// �A���[�g�_�C�A���O�̍쐬
    	return builder.create();	// builder.create�ō쐬����Dialog�I�u�W�F�N�g��Ԃ�.
    	
    }
	
}
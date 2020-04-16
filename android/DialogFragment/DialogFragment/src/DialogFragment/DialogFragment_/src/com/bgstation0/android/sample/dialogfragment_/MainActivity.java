package com.bgstation0.android.sample.dialogfragment_;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.DialogFragment;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

// ���C���A�N�e�B�r�e�B
public class MainActivity extends Activity {

	// �^�O�̒�`.
    private final String TAG = "MainActivity";	// TAG��"MainActivity".
    
    // �A�N�e�B�r�e�B�쐬��.
    protected void onCreate(Bundle savedInstanceState) {
    	
    	// �r���[�̃Z�b�g.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1���擾��, �V����OnClickListener���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(new View.OnClickListener() {	// button1.setOnClickListener�ɐV����View.OnClickListener���Z�b�g.
			
        	// �N���b�N��.
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				
				// DialogFragment�̍쐬.
				DialogFragment dialogFragment = new DialogFragment(){	// �����N���X��`.
					
					// �_�C�A���O�쐬��.
					@Override
					public Dialog onCreateDialog(Bundle savedInstanceState){
						
						// �A���[�g�_�C�A���O�r���_�[�̐ݒ�.
						AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());	// builder�̐���.
						builder.setTitle("DialogFragment");	// �^�C�g��"DialogFragment".
						builder.setMessage("DialogFragment");	// ���b�Z�[�W""DialogFragment".
						builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {	// �|�W�e�B�u�{�^��"OK".
							@Override
							public void onClick(DialogInterface dialog, int which) {
								// TODO Auto-generated method stub

							}
						});
						
						// �A���[�g�_�C�A���O�̍쐬.
						return builder.create();	// builder.create�Ő���.
						
					}
					
				};
				
				// DialogFragment�̕\��.
				dialogFragment.show(getFragmentManager(), TAG);
				
			}
			
		});
        
    }
    
}
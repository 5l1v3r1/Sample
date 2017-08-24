package com.bgstation0.android.sample.view.onlongclicklistener_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`
	Context context = null;	// Context�^context��null�ɏ�����.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // context�̎擾.
        context = this;	// context��this���Z�b�g.
        
        // button1�I�u�W�F�N�g���擾��, OnClickListener���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1��Button���擾��, button1�Ɋi�[.
        button1.setOnClickListener(new View.OnClickListener() {	// button1.setOnClickListener��View.OnClickListener�̓����N���X���`��, �C���X�^���X��n��.
			
        	// �N���b�N���ꂽ��.
			@Override
			public void onClick(View v) {	// onClick�̒�`(�I�[�o�[���C�h)
				// TODO Auto-generated method stub
				Toast.makeText(context, "Clicked!", Toast.LENGTH_LONG).show();	// Toast��"Clicked!"��\��.
			}
		});
        // button1�I�u�W�F�N�g��OnLongClickListener���Z�b�g.
        button1.setOnLongClickListener(new View.OnLongClickListener() {	// button1.setOnLongClickListener��View.OnLongClickListener�̓����N���X���`��, �C���X�^���X��n��.
        	
			// ���������ꂽ��.
			@Override
			public boolean onLongClick(View v) {	// onLongClick�̒�`(�I�[�o�[���C�h)
				// TODO Auto-generated method stub
				Toast.makeText(context, "Long Clicked!", Toast.LENGTH_LONG).show();	// Toast��"Long Clicked!"��\��.
				return false;	// false����OnClick������.
			}
		});
    }
}
package com.bgstation0.android.sample.edittext_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

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
    	// �G�f�B�b�g�e�L�X�g�̕�������擾��, �g�[�X�g�ŕ\��.
    	EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// findViewById��R.id.edittext1���擾��, edittext1�Ɋi�[.
    	CharSequence str = edittext1.getText();	// edittext1.getText�ŃG�f�B�b�g�e�L�X�g�̕�������擾��, CharSequence��str�Ɋi�[.(���ۂɂ�, EditText�̐e�N���X��TextView��getText���Ăяo���Ă���.)
    	Toast.makeText(this, str, Toast.LENGTH_SHORT).show();	// Toast.makeText��str���Z�b�g��,�@���̂܂�show�ŕ\��.
    }
}

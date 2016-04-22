package com.bgstation0.android.sample.checkbox_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.CheckBox;
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
    	// checkbox1���擾��, �`�F�b�N��Ԃ��m�F����.
    	CheckBox checkbox1 = (CheckBox)findViewById(R.id.checkbox1);	// findViewById��R.id.checkbox1���擾.
    	if (checkbox1.isChecked()){	// checkbox1.isChecked�Ń`�F�b�N����Ă���ꍇ.
    		Toast.makeText(this, "Checked!", Toast.LENGTH_SHORT).show();	// Toast��"Checked!"�ƕ\��.
    	}
    	else{	// �`�F�b�N����Ă��Ȃ��ꍇ.
    		Toast.makeText(this,  "Not checked!", Toast.LENGTH_SHORT).show();	// Toast��"Not checked!"�ƕ\��.
    	}
    }
}

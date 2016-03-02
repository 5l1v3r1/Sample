package com.bgstation0.android.sample.view_;

import android.app.Activity;
import android.os.Bundle;
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
        
        // button2���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button2 = (Button)findViewById(R.id.button2);	// findViewById��R.id.button2���擾.
        button2.setOnClickListener(this);	// button2.setOnClickListener��this(���g)���Z�b�g.
        
        // button3���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button3 = (Button)findViewById(R.id.button3);	// findViewById��R.id.button3���擾.
        button3.setOnClickListener(this);	// button3.setOnClickListener��this(���g)���Z�b�g.       
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    	// �{�^����id�����Ƃɏ�����U�蕪����.
    	switch (v.getId()) {	// v.getId��View(Button)��id���擾.
    		case R.id.button1:	// R.id.button1�̎�.
    			Button b1 = (Button)v;	// v��(Button)�ɃL���X�g����b1�Ɋi�[.
    			b1.setText("Clicked!");	// b1.setText��"Clicked!"�ɕύX.
    			break;	// break�Ŕ�����.
    		case R.id.button2:	// R.id.button2�̎�.
    			Button b2 = (Button)v;	// v��(Button)�ɃL���X�g����b2�Ɋi�[.
    			b2.setText("Clicked!");	// b2.setText��"Clicked!"�ɕύX.
    			break;	// break�Ŕ�����.
    		case R.id.button3:	// R.id.button3�̎�.
    			Button b3 = (Button)v;	// v��(Button)�ɃL���X�g����b3�Ɋi�[.
    			b3.setText("Clicked!");	// b3.setText��"Clicked!"�ɕύX.
    			break;	// break�Ŕ�����.		
    	}
    }
}
package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button_save_pref���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button saveButton = (Button)findViewById(R.id.button_save_pref);	// findViewById��R.id.button_save_pref���擾.
        saveButton.setOnClickListener(this);	// saveButton.setOnClickListener��this(���g)���Z�b�g. 
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    	// �G�f�B�b�g�e�L�X�g�̕�������擾.
    	EditText editPref = (EditText)findViewById(R.id.edit_pref);	// findViewById��R.id.edit_pref���擾��, editPref�Ɋi�[.
    	CharSequence str = editPref.getText();	// editPref.getText�ŃG�f�B�b�g�e�L�X�g�̕�������擾��, CharSequence��str�Ɋi�[.(���ۂɂ�, EditText�̐e�N���X��TextView��getText���Ăяo���Ă���.)
    	// �v���t�@�����X���擾��, ����ɓ��͒l��ۑ�.
    	SharedPreferences prefs = getPreferences(MODE_PRIVATE);	// getPreferences��SharedPreferences���擾.
    	Editor editor = prefs.edit();	// prefs.edit��Editor�I�u�W�F�N�geditor�擾.
    	editor.putString("Key", str.toString());	// putString�ŃL�[��"Key", �l��str�ŏ�������.
    	editor.commit();	// commit�Ŋm��.
    }
}

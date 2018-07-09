package com.bgstation0.android.sample.recognizerintent_;

import java.util.ArrayList;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.speech.RecognizerIntent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // �{�^���Ƀ��X�i�[���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setOnClickListener(this);	// this���Z�b�g.
    }
    
    // �N���b�N���ꂽ��.
    @Override
    public void onClick(View v){
    
    	// �C���e���g�쐬.
    	try{	// try�ň͂�.
    		Intent intent = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);	// Intent�̃R���X�g���N�^��RecognizerIntent.ACTION_RECOGNIZE_SPEECH��n����intent�쐬.
    		intent.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);	// ���ꃂ�f���̓t���[�t�H�[��.
    		intent.putExtra(RecognizerIntent.EXTRA_PROMPT, "RecognizerIntent");	// �v�����v�g�������"RecognizerIntent".
    		startActivityForResult(intent, 100);	// ���N�G�X�g�R�[�h100��intent���s.
    	}
    	catch (Exception ex){
    		Toast.makeText(this, "ex = " + ex.toString(), Toast.LENGTH_LONG).show();	// ex.toString()���o��.
    	}
    	
    }
    
    // �A�N�e�B�r�e�B���N����������.
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

    	// ���U���g�R�[�h�ƃ��N�G�X�g�R�[�h�ŐU�蕪����.
    	if (resultCode == RESULT_OK){	// RESULT_OK�Ȃ�.
    		if (requestCode == 100){	// 100�Ȃ�.
    			// ArrayList<String>�ŕԂ��Ă���.
    			ArrayList<String> aryListStrs = data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);	// aryListStrs���擾.
    			String result = "";	// result��""�ŏ�����.
    			for (int i = 0; i < aryListStrs.size() - 1; i++){	// (�P��̌� - 1)��J��Ԃ�.
    				result = result + aryListStrs.get(i);	// result��i�Ԗڂ�A��.
    				result = result + " ";	// �X�y�[�X��A��.
    			}
    			result = result + aryListStrs.get(aryListStrs.size() - 1);	// �Ō�̗v�f��A��.
    			EditText edittext1 = (EditText)findViewById(R.id.edittext1);
    			edittext1.setText(result);	// edittext1.setText��result���Z�b�g.
    		}
    	}
    	
    }
    
}
package com.bgstation0.android.sample.adapterview_;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`.
	Context mContext;	// Context�I�u�W�F�N�gmContext.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mContext = this;	// mContext��this���Z�b�g.
        
        // ArrayAdapter�̐���.
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_item);	// �����android.R.layout.simple_spinner_item�ŃA�_�v�^�쐬.
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);	// �h���b�v�_�E�����X�g�\�����̃r���[�͊����android.R.layout.simple_spinner_dropdown_item���Z�b�g.
        // �A�C�e���̒ǉ�.
        adapter.add("Item1");	// Item1��ǉ�.
        adapter.add("item2");	// Item2��ǉ�.
        adapter.add("Item3"); 	// Item3��ǉ�.
        // �X�s�i�[�ɃA�_�v�^���Z�b�g.
        final Spinner spinner = (Spinner)findViewById(R.id.spinner);	// spinner���擾.(final�ɂ��Ă���.)
        spinner.setAdapter(adapter);	// adapter���Z�b�g.
        // �{�^���̃N���b�N���X�i�[���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				String itemStr = (String)spinner.getSelectedItem();	// AdapterView.getSelectedItem�őI�����ꂽ�A�C�e��itemStr���擾.
				Toast.makeText(mContext, itemStr, Toast.LENGTH_LONG).show();	// itemStr��\��.
			}
			
        });
        // �X�s�i�[�ŃA�C�e�����I�����ꂽ���̃��X�i�[���Z�b�g.
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
        	
        	 @Override
        	 public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        		 
        		 // �I�����ꂽ�A�C�e���̎擾.
        		 Spinner spnr = (Spinner)parent;	// parent���L���X�gspnr��.
        		 String itemStr = (String)spnr.getSelectedItem();	// spnr.getSelectedItem��itemStr�擾.
        		 Toast.makeText(mContext, itemStr, Toast.LENGTH_LONG).show();	// itemStr��\��.
        		 
        	 }
        	 
        	 @Override
             public void onNothingSelected(AdapterView<?> arg0) {
             
        	 }
        	 
        });
        
    }
    
}
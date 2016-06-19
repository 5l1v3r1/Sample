package com.bgstation0.android.sample.context_;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import android.app.Activity;
import android.os.Bundle;
import android.text.Editable;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    
    // �I�v�V�������j���[���쐬����鎞.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){

    	// ���j���[�̍쐬
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflater��MenuItem���擾��, ���̂܂�inflate�Ŏw�肳�ꂽR.menu.main������menu���쐬.
    	return true;	// true��Ԃ�.
    	
    }
    
    // ���j���[���I�����ꂽ��.
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
    	
    	// �ǂ̃��j���[���I�����ꂽ��.
    	switch (item.getItemId()){	// �A�C�e��ID���ƂɐU�蕪��.
    	
    		// Write file
    		case R.id.menu_write_file:
    			
    			// Write file �u���b�N
    			{
    				
    				// �t�@�C�������擾.
    				EditText edittextName = (EditText)findViewById(R.id.edittext_filename);	// findViewById��edittext_filename���擾.
    				Editable textName = edittextName.getText();	// edittextName.getText�Ńe�L�X�g�擾.
    				String filename = textName.toString();	// textName.toString�ŕ�����擾.
    			
    				// �t�@�C�����e���擾.
    				EditText edittextContent = (EditText)findViewById(R.id.edittext_filecontent);	// findViewById��edittext_filecontent���擾.
    				Editable textContent = edittextContent.getText();	// edittextContent.getText�Ńe�L�X�g�擾.
    				String filecontent = textContent.toString();	// textContent.toString�ŕ�����擾.
    			
    				// �t�@�C�����`�F�b�N.
    				if (filename.length() == 0){
    					Toast.makeText(this, "filename is empty!", Toast.LENGTH_SHORT).show();	// "filename is empty!"�ƕ\��.
    					break;	// �r���Ŕ�����.
    				}
    			
    				// �t�@�C���ɏ�������.
    				try{	// try�ň͂�.
    					FileOutputStream out = openFileOutput(filename, MODE_PRIVATE);	// openFileOutput��filename�̃t�@�C�����J���ăt�@�C���o�̓X�g���[�����擾.
    					out.write(filecontent.getBytes());	// out.write��filecontent����������.
    					out.close();	// out.close�ŕ���.
    				}
    				catch (FileNotFoundException fileNotEx){	// �t�@�C����������Ȃ�.
    					Toast.makeText(this, "File not found!", Toast.LENGTH_SHORT).show();	// "File not found!"�ƕ\��.
    				}
    				catch (IOException ioEx){	// IO�G���[.
    					Toast.makeText(this, "IO error!", Toast.LENGTH_SHORT).show();	// "IO Error!"�ƕ\��.
    				}
    				break;	// �����Ŕ�����.
    				
    			}
    			
    		// Read file
    		case R.id.menu_read_file:
    			
    			// Read file �u���b�N
    			{
    				
    				// �t�@�C�������擾.
    				EditText edittextName = (EditText)findViewById(R.id.edittext_filename);	// findViewById��edittext_filename���擾.
    				Editable textName = edittextName.getText();	// edittextName.getText�Ńe�L�X�g�擾.
    				String filename = textName.toString();	// textName.toString�ŕ�����擾.
    				
    				// �t�@�C�����`�F�b�N.
    				if (filename.length() == 0){
    					Toast.makeText(this, "filename is empty!", Toast.LENGTH_SHORT).show();	// "filename is empty!"�ƕ\��.
    					break;	// �r���Ŕ�����.
    				}
    				
    				// �t�@�C������ǂݍ���.
    				try{	// try�ň͂�.
    					FileInputStream in = openFileInput(filename);	// openFileInput��filename�̃t�@�C�����J���ăt�@�C�����̓X�g���[�����擾.
    					byte[] bytes = new byte[in.available()];	// in.available�Ńt�@�C�����̓X�g���[�����ǂݍ��߂鐄��T�C�Y���킩��̂�, ���̕��̃o�C�g��m��.
    	                in.read(bytes);	// in.read�œǂݍ���.
    	                String content = new String(bytes);	// ������ɕϊ�.
    	                EditText edittextContent = (EditText)findViewById(R.id.edittext_filecontent);	// findViewById��edittext_filecontent���擾.
    	                edittextContent.setText(content);	// edittextContent.setText�Ńe�L�X�g���Z�b�g.
    	                in.close();	// in.close�ŕ���.
    				}
    				catch (FileNotFoundException fileNotEx){	// �t�@�C����������Ȃ�.
    					Toast.makeText(this, "File not found!", Toast.LENGTH_SHORT).show();	// "File not found!"�ƕ\��.
    				}
    				catch (IOException ioEx){	// IO�G���[.
    					Toast.makeText(this, "IO error!", Toast.LENGTH_SHORT).show();	// "IO Error!"�ƕ\��.
    				}
    				break;	// �����Ŕ�����.
    				
    			}
    	}
    	return super.onOptionsItemSelected(item);	// �e�N���X���菈��
    }
}
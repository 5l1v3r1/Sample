package com.bgstation0.android.sample.sqliteopenhelper_;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.ContentValues;
import android.content.DialogInterface;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ListView;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`.
	public List<ListItem> list = null;	// ListItem�^List�I�u�W�F�N�glist��null�ɂ��Ă���.
	public ListView listView1 = null;	// ListView�I�u�W�F�N�glistview1��null�ɂ��Ă���.
	public ListItemAdapter adapter = null;	// ListItemAdapter�I�u�W�F�N�gadapter��null�ɂ��Ă���.
	public ListItemDBHelper hlpr = null;	// ListItemDBHelper�I�u�W�F�N�ghlpr��null�ɂ��Ă���.
	public SQLiteDatabase sqlite = null;	// SQLiteDatabase�I�u�W�F�N�gsqlite��null�ɂ��Ă���.
	
	// �����o���\�b�h�̒�`.
	// �A�N�e�B�r�e�B���쐬����鎞.
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // list�I�u�W�F�N�g�̍쐬.
        list = new ArrayList<ListItem>();	// ArrayList<ListItem>�C���X�^���X���쐬����list�Ɋi�[.
        // adapter�̎擾.
        adapter = new ListItemAdapter(this, R.layout.list_item, list);	// ListItemAdapter�̃R���X�g���N�^��list��n����, adapter�擾.
        // listView1�̎擾.
        listView1 = (ListView)findViewById(R.id.listview1);	// findViewById��listView1���擾.
        // listView1��adapter���Z�b�g.
        listView1.setAdapter(adapter);	// listView1.setAdapter��adapter���Z�b�g.
        
        // DB����̓ǂݍ���.
		try{
			if (hlpr == null){	// hlpr��null�Ȃ�.
				hlpr = new ListItemDBHelper(getApplicationContext());	// hlpr���쐬.
			}
			if (sqlite == null){	// sqlite��null�Ȃ�.
				sqlite = hlpr.getReadableDatabase();	// �ǂݍ��݉\DB���擾.
			}
			Cursor cursor = null;	// Cursor�I�u�W�F�N�gcursor��null.
			cursor = sqlite.rawQuery("SELECT * FROM listitem;", null);	// sqlite.rawQuery��"SELECT * FROM listitem;"�����s.
			int c = cursor.getCount();	// getCount�Ō������������擾��, c�Ɋi�[.
			cursor.moveToFirst();	// cursor���ŏ��̈ʒu�Ɉړ�.
			for (int i = 0; i < c; i++){	// c�̐������J��Ԃ�.
				
				// �e�[�u��������o��.
				int _id = cursor.getInt(0);	// 0��ڂ�_id.
				String name = cursor.getString(1);	// 1��ڂ�name.
				int age = cursor.getInt(2);	// 2��ڂ�age.
				String address = cursor.getString(3);	// 3��ڂ�address.
				
				// �A�C�e���̒ǉ�
				ListItem item = new ListItem();	// ListItem�I�u�W�F�N�gitem�𐶐�.
				item.name = name;	// item.name��name.
				item.age = age;	// item.age��age. 
				item.address = address;	// item.address��address.
				list.add(item);	// list.add��item��ǉ�.
				
				// ���ֈړ�.
				cursor.moveToNext();	// cursor.moveToNext�Ŏ��ֈړ�.
			}
			cursor.close();	// cursor�����.
		}
		catch (Exception ex){	// ��O�L���b�`.
			Log.e("SQLiteOpenHelper_", ex.toString());	// ex.toString��Log�ɏo��.
		}
		finally{
			sqlite.close();	// sqlite.close�ŕ���.
			sqlite = null;	// null����Ă���.
		}
		
		// �A�_�v�^�̍X�V.
		adapter.notifyDataSetChanged();	// adapter.notifyDataSetChanged��UI�X�V.
		
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
    	
    		// Add
    		case R.id.menu_add:
    			
    			// Add�u���b�N
    			{
    				
    				// �A���[�g�_�C�A���O�쐬.
    				LayoutInflater inflater = (LayoutInflater)getSystemService(LAYOUT_INFLATER_SERVICE);	// inflater�T�[�r�X���擾.
    				final View layout = inflater.inflate(R.layout.dialog, null);	// inflate�Ń��\�[�XR.layout.dialog����_�C�A���O��View���쐬.
    				AlertDialog.Builder builder = new AlertDialog.Builder(this);	// AlertDialog.Builder�̍쐬.
    				builder.setTitle("Add");	// setTitle�Ń^�C�g����"Add"���Z�b�g.
    				builder.setView(layout);	// setView�Ńr���[��layout���Z�b�g.
    				builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {	// setPositiveButton��"OK"�{�^���̃��X�i�[���Z�b�g.
    					
						@Override
						public void onClick(DialogInterface dialog, int which) {
							// TODO Auto-generated method stub
							// �G�f�B�b�g�e�L�X�g�̓��e���擾.
							EditText editName = (EditText)layout.findViewById(R.id.edit_text_name);	// editName���擾.
							String strName = editName.getText().toString();	// �Z�b�g����Ă���e�L�X�g���擾.
							EditText editAge = (EditText)layout.findViewById(R.id.edit_text_age);	// editAge���擾.
							String strAge = editAge.getText().toString();	// �Z�b�g����Ă���e�L�X�g���擾.
							int intAge = Integer.parseInt(strAge);	// int�ɕϊ�.
							EditText editAddress = (EditText)layout.findViewById(R.id.edit_text_address);	// editAddress���擾.
							String strAddress = editAddress.getText().toString();	// �Z�b�g����Ă���e�L�X�g���擾.
							
							// DB�ւ̒ǉ�.
							try{
								if (hlpr == null){	// hlpr��null�Ȃ�.
									hlpr = new ListItemDBHelper(getApplicationContext());	// hlpr���쐬.
								}
								if (sqlite == null){	// sqlite��null�Ȃ�.
									sqlite = hlpr.getWritableDatabase();	// �������݉\DB���擾.
								}
								ContentValues values = new ContentValues();	// �ǉ�����v�f�L�[ContentValues�̍쐬.
								values.put("name", strName);	// name
								values.put("age", intAge);	// age
								values.put("address", strAddress);	// address
								long id = -1;	// id��-1���Z�b�g���Ă���.
								id = sqlite.insertOrThrow("listitem", null, values);	// sqlite.insertOrThrow��INSERT.
							}
							catch (Exception ex){	// ��O�L���b�`.
								Log.e("SQLiteOpenHelper_", ex.toString());	// ex.toString��Log�ɏo��.
							}
							finally{
								sqlite.close();	// sqlite.close�ŕ���.
								sqlite = null;	// null����Ă���.
							}
							
							// �A�C�e���̒ǉ�
							ListItem item = new ListItem();	// ListItem�I�u�W�F�N�gitem�𐶐�.
							item.name = strName;	// name��strName.
							item.age = intAge;	// age��intAge. 
							item.address = strAddress;	// address��strAdress.
							list.add(item);	// list.add��item��ǉ�.
							
							// �A�_�v�^�̍X�V.
							adapter.notifyDataSetChanged();	// adapter.notifyDataSetChanged��UI�X�V.
						}
						
    				});
					builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {	// setNegativeButton��"Cancel"�{�^���̃��X�i�[���Z�b�g.
						
						@Override
						public void onClick(DialogInterface dialog, int which) {
							// TODO Auto-generated method stub
							//�@�L�����Z������.(���ۂɂ͉������Ȃ�.)
						}
						
					});
					builder.create().show();	// �_�C�A���O�\��.
    				
    				break;	// ������.
    			}
    		
    	}
    	return super.onOptionsItemSelected(item);	// �e�N���X���菈��
    }
}

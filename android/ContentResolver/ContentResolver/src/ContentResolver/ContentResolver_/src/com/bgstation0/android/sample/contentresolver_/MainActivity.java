package com.bgstation0.android.sample.contentresolver_;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.content.ContentResolver;
import android.database.Cursor;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ListView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ContentResolver�ŘA������擾��, ListView�ɒǉ����ĕ\��.
        ContentResolver contentResolver = getContentResolver();	// getContentResolver��contentResolver���擾.
        List<ListItem> listitems = new ArrayList<ListItem>();	// listitems�𐶐�.
        Cursor c = contentResolver.query(ContactsContract.Contacts.CONTENT_URI, null, null, null, null);	// contentResolver.query�ŘA����ɃA�N�Z�X.
        if (c.moveToFirst()){	// �ŏ��Ȃ�.
        	for (int i = 0; i < c.getCount(); i++){	// c.getCount�̐�, �J��Ԃ�.
        		String name = c.getString(c.getColumnIndex(ContactsContract.Contacts.DISPLAY_NAME));	// �\�������擾.
        		ListItem item = new ListItem();	// item�𐶐�.
        		item.name = name;	// item.name��name����.
        		listitems.add(item);	// listitems.add��item��ǉ�.
        		c.moveToNext();	// ����.
        	}
        }
        c.close();	// ����.
        ListView listview1 = (ListView)findViewById(R.id.listview1);	// findViewById��listview1���擾.
        ListItemAdapter adapter = new ListItemAdapter(this, R.layout.list_item, listitems);	// ListItemAdapter�R���X�g���N�^��ListView�̃A�C�e���e���v���[�g��list_item�ƃ��X�g�f�[�^��listitems���Z�b�g.
        listview1.setAdapter(adapter);	// listview1.setAdapter��adapter���Z�b�g����, ListView��Adapter��R�t����.      
    }
}

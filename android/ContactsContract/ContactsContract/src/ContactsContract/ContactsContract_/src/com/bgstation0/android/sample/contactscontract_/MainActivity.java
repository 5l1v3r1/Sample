package com.bgstation0.android.sample.contactscontract_;

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
        		
        		// ID�̎擾.
        		String id = c.getString(c.getColumnIndex(ContactsContract.Contacts._ID));	// ID���擾.
        		
        		// �\�����̎擾.
        		String name = c.getString(c.getColumnIndex(ContactsContract.Contacts.DISPLAY_NAME));	// �\�������擾.
        		
        		// �d�b�ԍ����X�g�̎擾.
        		String phoneNumberList = "";	// �d�b�ԍ����X�gphoneNumberList��""�ŏ�����.
        		Cursor phoneCursor = contentResolver.query(ContactsContract.CommonDataKinds.Phone.CONTENT_URI, null, ContactsContract.CommonDataKinds.Phone.CONTACT_ID + "=" + id, null, null);	// ID����d�b�ԍ����Ђ�.
        		if (phoneCursor.moveToFirst()){	// �ŏ��Ȃ�.
        			for (int j = 0; j < phoneCursor.getCount(); j++){	// phoneCursor.getCount�̐�, �J��Ԃ�.
        				phoneNumberList = phoneNumberList + phoneCursor.getString(phoneCursor.getColumnIndex(ContactsContract.CommonDataKinds.Phone.NUMBER));
        				phoneNumberList = phoneNumberList + ";";	// �����̏ꍇ���l����";"�ŋ�؂�.
        				phoneCursor.moveToNext();	// moveToNext�Ŏ���.
        			}
        		}
        		phoneCursor.close();	// ����.
        		
        		// ���[���A�h���X���X�g�̎擾.
        		String emailAddressList = "";	// ���[���A�h���X���X�gemailAddressList��""�ŏ�����.
        		Cursor emailCursor = contentResolver.query(ContactsContract.CommonDataKinds.Email.CONTENT_URI, null, ContactsContract.CommonDataKinds.Email.CONTACT_ID + "=" + id, null, null);	// ID���烁�[���A�h���X���Ђ�.
        		if (emailCursor.moveToNext()){	// �ŏ��Ȃ�.
        			for (int k = 0; k < emailCursor.getCount(); k++){	// emailCursor.getCount�̐�, �J��Ԃ�.
        				emailAddressList = emailAddressList + emailCursor.getString(emailCursor.getColumnIndex(ContactsContract.CommonDataKinds.Email.ADDRESS));
        				emailAddressList = emailAddressList + ";";	// �����̏ꍇ���l����";"�ŋ�؂�.
        				emailCursor.moveToNext();	// moveToNext�Ŏ���.
        			}
        		}
        		emailCursor.close();	// ����.
        		
        		// item�̒ǉ�.
        		ListItem item = new ListItem();	// item�𐶐�.
        		item.name = name;	// item.name��name����.
        		item.phoneNumber = phoneNumberList;	// item.phoneNumber��phoneNumberList����.
        		item.emailAddress = emailAddressList;	// item.emailAddress��emailAddressList����.
        		listitems.add(item);	// listitems.add��item��ǉ�.
        		
        		// ����.
        		c.moveToNext();	// moveToNext�Ŏ���.
        		
        	}
        }
        c.close();	// ����.
        ListView listview1 = (ListView)findViewById(R.id.listview1);	// findViewById��listview1���擾.
        ListItemAdapter adapter = new ListItemAdapter(this, R.layout.list_item, listitems);	// ListItemAdapter�R���X�g���N�^��ListView�̃A�C�e���e���v���[�g��list_item�ƃ��X�g�f�[�^��listitems���Z�b�g.
        listview1.setAdapter(adapter);	// listview1.setAdapter��adapter���Z�b�g����, ListView��Adapter��R�t����.      
    }    
}
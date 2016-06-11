package com.bgstation0.android.sample.arrayadapter_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ListItem�z��Œǉ�����v�f���`.
        ListItem[] listitems = new ListItem[3];	// ListItem�z��listitems(�v�f��3)
        for (int i = 0; i < 3; i++){	// �I�u�W�F�N�g�z��̍쐬��, �C���X�^���X�𐶐��E�i�[�����Ƃ͕ʂȂ̂Œ���!
        	listitems[i] = new ListItem();	// ListItem�I�u�W�F�N�g�C���X�^���X�𐶐���, �e�v�f�Ɋi�[.
        }
        listitems[0].name = "Taro";
        listitems[0].age = 20;
        listitems[0].address = "Tokyo";
        listitems[1].name = "Jiro";
        listitems[1].age = 18;
        listitems[1].address = "Osaka";
        listitems[2].name = "Saburo";
        listitems[2].age = 16;
        listitems[2].address = "Nagoya";
        
        // ListView�I�u�W�F�N�g���擾.
        ListView listview1 = (ListView)findViewById(R.id.listview1);	// findViewById��listview1���擾.
        
        // ListItemAdapter��adapter�𐶐�����, listview1��adapter��listitems��R�t����.
        ListItemAdapter adapter = new ListItemAdapter(this, R.layout.list_item, listitems);	// ListItemAdapter�R���X�g���N�^��ListView�̃A�C�e���e���v���[�g��list_item�ƃ��X�g�f�[�^��listitems���Z�b�g.
        listview1.setAdapter(adapter);	// listview1.setAdapter��adapter���Z�b�g����, ListView��Adapter��R�t����.
    }
}
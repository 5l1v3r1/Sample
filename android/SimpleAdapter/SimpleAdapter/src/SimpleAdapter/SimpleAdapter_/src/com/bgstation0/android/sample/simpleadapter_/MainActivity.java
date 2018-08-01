package com.bgstation0.android.sample.simpleadapter_;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ListView;
import android.widget.SimpleAdapter;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ListView�̎擾.
        ListView listView1 = (ListView)findViewById(R.id.listview1);	// listView1���擾.
        
        // SimpleAdapter�̒�`.
        Map<String, String> map1 = new HashMap<String, String>();	// �L�[��String, �l��String�Ƃ���HashMap�𐶐���, map1�Ɋi�[.
        map1.put("Name", "Taro");	// "Name"���L�[, "Taro"��l�Ƃ���.
        map1.put("Age", "20");	// "Age"���L�[, "20"��l�Ƃ���.
        Map<String, String> map2 = new HashMap<String, String>();	// �L�[��String, �l��String�Ƃ���HashMap�𐶐���, map2�Ɋi�[.
        map2.put("Name", "Jiro");	// "Name"���L�[, "Jiro"��l�Ƃ���.
        map2.put("Age", "18");	// "Age"���L�[, "18"��l�Ƃ���.
        Map<String, String> map3 = new HashMap<String, String>();	// �L�[��String, �l��String�Ƃ���HashMap�𐶐���, map3�Ɋi�[.
        map3.put("Name", "Saburo");	// "Name"���L�[, "Saburo"��l�Ƃ���.
        map3.put("Age", "16");	// "Age"���L�[, "16"��l�Ƃ���.
        List<Map<String, String>> list = new ArrayList<Map<String, String>>();	// list�𐶐�.
        list.add(map1);	// map1��ǉ�.
        list.add(map2);	// map2��ǉ�.
        list.add(map3);	// map3��ǉ�.
        SimpleAdapter adapter = new SimpleAdapter(this, list, R.layout.list_item, new String[]{"Name", "Age"}, new int[]{R.id.list_item_name, R.id.list_item_age});	// adapter�𐶐�.
        listView1.setAdapter(adapter);	// adapter���Z�b�g.
        
    }
    
}
package com.bgstation0.android.sample.autocompletetextview_;

import java.util.ArrayList;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // AutoCompleteTextView��adapter���Z�b�g.
        ArrayList<String> strArrayList = new ArrayList<String>();	// strArrayList���쐬.
        strArrayList.add("AAC");	// "AAC"
        strArrayList.add("ABC");	// "ABC"
        strArrayList.add("ABCDE");	// "ABCDE"
        strArrayList.add("BBB");	// "BBB"
        strArrayList.add("CCC");	// "CCC"
        strArrayList.add("PQRS");	// "PQRS"
        strArrayList.add("VWXYZ");	// "VWXYZ"
        strArrayList.add("XYZ");	// "XYZ"
        strArrayList.add("ZZZ");	// "ZZZ"
        AutoCompleteTextView autoCompleteTextView = (AutoCompleteTextView)findViewById(R.id.autocompletetextview1);	// autoCompleteTextView���擾.
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, R.layout.auto_complete_list_item, strArrayList);	// adapter�쐬.
        autoCompleteTextView.setAdapter(adapter);	// adapter���Z�b�g.
        autoCompleteTextView.setThreshold(1);	// 1�������͂�����I�[�g�R���v���[�g�J�n.
        
    }
    
}
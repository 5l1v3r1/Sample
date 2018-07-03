package com.bgstation0.android.sample.resources_;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ���\�[�X��(�t��)���擾����, TextView�ɃZ�b�g.
        Resources resources = getResources();	// resources���擾.
        TextView tv1 = (TextView)findViewById(R.id.textview1);	// tv1���擾.
        String typeName1 = resources.getResourceTypeName(R.id.textview1);	// resources.getResourceTypeName��R.id.textview1�̃^�C�v�����擾.
        tv1.setText("tv1: " + typeName1);	// typeName1���Z�b�g.
        TextView tv2 = (TextView)findViewById(R.id.textview2);	// tv2���擾.
        String typeName2 = resources.getResourceTypeName(android.R.id.text1);	// resources.getResourceTypeName��android.R.id.text1�̃^�C�v�����擾.
        tv2.setText("tv2: " + typeName2);	// typeName2���Z�b�g.
        
    }
}
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
        String entryName1 = resources.getResourceEntryName(R.id.textview1);	// resources.getResourceEntryName��R.id.textview1�̃G���g�������擾.
        tv1.setText("tv1: " + entryName1);	// entryName1���Z�b�g.
        TextView tv2 = (TextView)findViewById(R.id.textview2);	// tv2���擾.
        String entryName2 = resources.getResourceEntryName(android.R.id.text1);	// resources.getResourceEntryName��android.R.id.text1�̃G���g�������擾.
        tv2.setText("tv2: " + entryName2);	// entryName2���Z�b�g.
        
    }
}
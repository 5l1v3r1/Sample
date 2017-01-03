package com.bgstation0.android.sample.actionbar.tab_;

import android.app.ActionBar;
import android.app.ActionBar.Tab;
import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ActionBar.Tab�Ń^�u��ǉ�.
        ActionBar actionBar = getActionBar();	// getActionBar��actionBar�擾.
        actionBar.setNavigationMode(ActionBar.NAVIGATION_MODE_TABS);	// setNavigationMode��NAVIGATION_MODE_TABS�ɃZ�b�g.
        // tab1
        ActionBar.Tab tab1 = actionBar.newTab();	// actionBar.newTab�Ń^�u�𐶐���, tab1�Ɋi�[.
        tab1.setText("�^�u1");
        CustomTabListener listener1 = new CustomTabListener(this, "tag1", Fragment1.class);	// listener1�𐶐�.
        tab1.setTabListener(listener1);
        actionBar.addTab(tab1);	// addTab��tab1��ǉ�.
        // tab2
        ActionBar.Tab tab2 = actionBar.newTab();	// actionBar.newTab�Ń^�u�𐶐���, tab2�Ɋi�[.
        tab2.setText("�^�u2");
        CustomTabListener listener2 = new CustomTabListener(this, "tag2", Fragment2.class);	// listener2�𐶐�.
        tab2.setTabListener(listener2);
        actionBar.addTab(tab2);	// addTab��tab2��ǉ�.
        // tab3
        ActionBar.Tab tab3 = actionBar.newTab();	// actionBar.newTab�Ń^�u�𐶐���, tab3�Ɋi�[.
        tab3.setText("�^�u3");
        CustomTabListener listener3 = new CustomTabListener(this, "tag3", Fragment3.class);	// listener3�𐶐�.
        tab3.setTabListener(listener3);
        actionBar.addTab(tab3);	// addTab��tab3��ǉ�.
    }
}
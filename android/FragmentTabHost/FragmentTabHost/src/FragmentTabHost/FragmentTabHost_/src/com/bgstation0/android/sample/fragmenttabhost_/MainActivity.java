package com.bgstation0.android.sample.fragmenttabhost_;

import android.support.v4.app.FragmentActivity;
import android.os.Bundle;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTabHost;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TabHost;

public class MainActivity extends FragmentActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // fragmentManager�̎擾.
        FragmentManager fragmentManager = getSupportFragmentManager();	// getSupportFragmentManager��fragmentManager���擾.
        
        // tabHost�̎擾.
        FragmentTabHost tabHost = (FragmentTabHost)findViewById(android.R.id.tabhost);	// findViewById��tabHost���擾.
        
        // tabHost�̏���.
        tabHost.setup(this, fragmentManager, R.id.content);	// tabHost.setup�ŏ���(this, fragmentManager�ƃt���O�����g�̑}����R.id.content��n��.)

        // tab1�̒ǉ�.
        TabHost.TabSpec tabSpec1 = tabHost.newTabSpec("tab1");	// tabSpec1"tab1"�̐���.
        tabSpec1.setIndicator("�^�u1");	// tabSpec1.setIndicator�ŕ\����"�^�u1"���Z�b�g.
        Bundle bundle1 = new Bundle();	// bundle1����.
        bundle1.putString("name", "tab1"); 	// bundle1.putString��"name", "tab1"�̑g�œo�^.
        tabHost.addTab(tabSpec1, TabFragment.class, bundle1);	// tabHost.addTab��tabSpec1, TabFragment.class, bundle1��ǉ�.
        
        // tab2�̒ǉ�.
        TabHost.TabSpec tabSpec2 = tabHost.newTabSpec("tab2");	// tabSpec"tab2"�̐���.
        tabSpec2.setIndicator("�^�u2");	// tabSpec2.setIndicator�ŕ\����"�^�u2"���Z�b�g.
        Bundle bundle2 = new Bundle();	// bundle2����.
        bundle2.putString("name", "tab2"); 	// bundle2.putString��"name", "tab2"�̑g�œo�^.
        tabHost.addTab(tabSpec2, TabFragment.class, bundle2);	// tabHost.addTab��tabSpec2, TabFragment.class, bundle2��ǉ�.
        
    }
}
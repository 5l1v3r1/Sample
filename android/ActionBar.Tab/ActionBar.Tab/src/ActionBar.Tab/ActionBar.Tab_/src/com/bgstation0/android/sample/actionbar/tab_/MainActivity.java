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
        
        // ActionBar.Tabでタブを追加.
        ActionBar actionBar = getActionBar();	// getActionBarでactionBar取得.
        actionBar.setNavigationMode(ActionBar.NAVIGATION_MODE_TABS);	// setNavigationModeでNAVIGATION_MODE_TABSにセット.
        // tab1
        ActionBar.Tab tab1 = actionBar.newTab();	// actionBar.newTabでタブを生成し, tab1に格納.
        tab1.setText("タブ1");
        CustomTabListener listener1 = new CustomTabListener(this, "tag1", Fragment1.class);	// listener1を生成.
        tab1.setTabListener(listener1);
        actionBar.addTab(tab1);	// addTabでtab1を追加.
        // tab2
        ActionBar.Tab tab2 = actionBar.newTab();	// actionBar.newTabでタブを生成し, tab2に格納.
        tab2.setText("タブ2");
        CustomTabListener listener2 = new CustomTabListener(this, "tag2", Fragment2.class);	// listener2を生成.
        tab2.setTabListener(listener2);
        actionBar.addTab(tab2);	// addTabでtab2を追加.
        // tab3
        ActionBar.Tab tab3 = actionBar.newTab();	// actionBar.newTabでタブを生成し, tab3に格納.
        tab3.setText("タブ3");
        CustomTabListener listener3 = new CustomTabListener(this, "tag3", Fragment3.class);	// listener3を生成.
        tab3.setTabListener(listener3);
        actionBar.addTab(tab3);	// addTabでtab3を追加.
    }
}

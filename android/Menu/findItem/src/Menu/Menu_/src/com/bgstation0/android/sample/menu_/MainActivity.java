package com.bgstation0.android.sample.menu_;

import android.app.ActionBar;
import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

	// メンバフィールドの定義.
	Context mContext = null;	// mContextをnullに初期化.
		
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mContext = this;	// mContextにthisをセット.
    }
    
    // メニューが作成された時.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// メニューの作成
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflaterでMenuItemを取得し, そのままinflateで指定されたR.menu.mainを元にmenuを作成.
    	ActionBar actionBar = getActionBar();	// getActionBarでactionBarを取得.
    	actionBar.setDisplayShowTitleEnabled(false);	// actionBar.setDisplayShowTitleEnabledをfalseにしてタイトルを非表示.
    	actionBar.setDisplayShowHomeEnabled(false);	// actionBar.setDisplayShowHomeEnabledをfalseにしてアイコンも非表示.
    	
    	// MenuItemの取得.
    	MenuItem menuItem1 = menu.findItem(R.id.menu_item1);	// menuItem1の取得.
    	String title = menuItem1.getTitle().toString();	// titleを取得.
    	Toast.makeText(mContext, title, Toast.LENGTH_LONG).show();	// titleを表示.
    	return true;
    	
    }
    
}
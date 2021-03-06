package com.bgstation0.android.sample.popupwindow_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.PopupWindow;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListenerを実装.

	// メンバフィールドの定義.
	PopupWindow mPopupWindow = null;	// PopupWindowクラスオブジェクトmPopupWindowをnullに初期化.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ポップアップウィンドウの生成.
        mPopupWindow = new PopupWindow(this);	// PopupWindowオブジェクトを生成し, mPopupWindowに格納.
        LinearLayout popLayout = (LinearLayout)getLayoutInflater().inflate(R.layout.popup_layout, null);	// getLayoutInflater().inflateでpopLauyoutを取り出す.
        mPopupWindow.setWidth(LinearLayout.LayoutParams.WRAP_CONTENT);	// 幅は中身のWRAP_CONTENT.
        mPopupWindow.setHeight(LinearLayout.LayoutParams.WRAP_CONTENT);	// 高さも中身のWRAP_CONTENT.
        mPopupWindow.setContentView(popLayout);	// mPopupWindow.setContentViewでpopLayoutをセット.
        
        // show_pupup_buttonを取得し, OnClickListenerとして自身をセット.
        Button ShowPopupButton = (Button)findViewById(R.id.show_popup_button);	// ShowPopupButtonを取得.
        ShowPopupButton.setOnClickListener(this);	// ShowPopupButton.setOnClickListenerでthisをセット.
        
    }
    
    // メニューが作成された時.
    @Override
    public boolean onCreateOptionsMenu(Menu menu){
    	
    	// メニューの作成
    	getMenuInflater().inflate(R.menu.main, menu);	// getMenuInflaterでMenuItemを取得し, そのままinflateで指定されたR.menu.mainを元にmenuを作成.
    	return true;	// trueを返す.
    	
    }
    
    // メニューが選択された時.
    @Override
    public boolean onOptionsItemSelected(MenuItem item){
    
    	// どのメニューが選択されたか.
    	switch (item.getItemId()){	// アイテムIDごとに振り分け.
    	
    		// Always
    		case R.id.menu_always:
    			
    			// Alwaysブロック
    			{
    				
    				// "Always"と表示.
    				Toast.makeText(this, "Always", Toast.LENGTH_LONG).show();	// Toastで"Always"と表示.
    				
    			}
    			
    			break;
 
    		// Never
    		case R.id.menu_never:
    			
    			// Neverブロック
    			{
    			
    				// "Never"と表示.
    				Toast.makeText(this, "Never", Toast.LENGTH_LONG).show();	// Toastで"Never"と表示.
    				
    			}
    			
    			break;
    			
    	}
    		    	
    	return super.onOptionsItemSelected(item);	// 親クラス既定処理
    	
    }

    // View.OnClickListenerインタフェースのオーバーライドメソッドを実装.
    public void onClick(View v){	// onClickをオーバーライド.
    	
    	// ボタンのidをごとに処理を振り分ける.
    	switch (v.getId()) {	// v.getIdでView(Button)のidを取得.
    		
    		case R.id.show_popup_button:	// R.id.show_popup_buttonの時.
    			
    			// show_popup_buttonブロック
				{
					
					// ポップアップウィンドウの表示.
					mPopupWindow.showAsDropDown(v);	// mPopupWindow.showAsDropDownでvの位置にポップアップウィンドウを表示.
					
    				// 抜ける.
    				break;	// breakで抜ける.
    				
				}
				
    	}
    	
    }
    
}
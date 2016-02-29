package com.bgstation0.android.sample.view.onclicklistener_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1オブジェクトを取得し, OnClickListenerをセット.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewByIdでR.id.button1のButtonを取得し, button1に格納.
        button1.setOnClickListener(new View.OnClickListener() {	// button1.setOnClickListenerでView.OnClickListenerの匿名クラスを定義し, インスタンスを渡す.
			
        	// クリックされた時.
			@Override
			public void onClick(View v) {	// onClickの定義(オーバーライド)
				// TODO Auto-generated method stub
				Button b1 = (Button)v;	// イベント発生元オブジェクトvがViewで返されるのでButtonにキャストしてb1に格納.
				b1.setText("Clicked!");	// b1.setTextで表示名を"Clicked!"に変更.
			}
		});
    }
}

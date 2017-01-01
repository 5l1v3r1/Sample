package com.bgstation0.android.sample.drawable_;

import android.app.Activity;
import android.content.res.Resources;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // DrawableをButtonの背景にセット.
        Resources res = getResources();	// getResourcesでresを取得.
        Drawable drawable1 = res.getDrawable(R.drawable.ic_launcher);	// res.getDrawableでR.drawable.ic_launcherで定義された画像をDrawableリソースとして取得.
        Button button1 = (Button)findViewById(R.id.button1);	// button1を取得.
        button1.setBackgroundDrawable(drawable1);	// button1.setBackgroundDrawableでdrawable1をセット.
        Drawable drawable2 = res.getDrawable(R.drawable.drawable_button);	// res.getDrawableでR.drawable.drawable_buttonで定義された描画情報をDrawableリソースとして取得.
        Button button2 = (Button)findViewById(R.id.button2);	// button2を取得.
        button2.setBackgroundDrawable(drawable2);	// button2.setBackgroundDrawableでdrawable2をセット.
    }
}

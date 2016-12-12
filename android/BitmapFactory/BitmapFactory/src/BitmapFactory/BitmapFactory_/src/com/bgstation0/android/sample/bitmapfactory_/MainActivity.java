package com.bgstation0.android.sample.bitmapfactory_;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ImageView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ImageView��drawable��test.png��\��.
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.test);	// BitmapFactory.decodeResource��R.drawable.test��Bitmap�ɕϊ����ǂݍ���, bitmap�Ɋi�[.
        ImageView imageView1 = (ImageView)findViewById(R.id.imageview1);	// findViewById��imageView1���擾.
        imageView1.setImageBitmap(bitmap);	// setImageBitmap��bitmap���Z�b�g.
        
    }
}

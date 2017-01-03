package com.bgstation0.android.sample.bitmap_;

import java.io.File;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ImageView;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ImageView��test.png��\��.
        Bitmap bitmap = BitmapFactory.decodeFile(getFilesDir().getPath() + "/" + "test.png");	// BitmapFactory.decodeFile�Ńt�@�C��"test.png"��Bitmap�ɕϊ����ǂݍ���, bitmap�Ɋi�[.(�p�X�̎����ɒ���!)
        ImageView imageView1 = (ImageView)findViewById(R.id.imageview1);	// findViewById��imageView1���擾.
        imageView1.setImageBitmap(bitmap);	// setImageBitmap��bitmap���Z�b�g.
        
    }
}
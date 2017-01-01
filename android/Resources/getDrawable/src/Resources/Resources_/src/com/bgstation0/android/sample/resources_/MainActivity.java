package com.bgstation0.android.sample.resources_;

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
        
        // drawable�ɂ���摜���擾����, Button�̔w�i�ɃZ�b�g.
        Resources res = getResources();	// getResources��res���擾.
        Drawable drawable1 = res.getDrawable(R.drawable.ic_launcher);	// res.getDrawable��R.drawable.ic_launcher�Œ�`���ꂽ�摜��Drawable���\�[�X�Ƃ��Ď擾.
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setBackgroundDrawable(drawable1);	// button1.setBackgroundDrawable��drawable1���Z�b�g.
        Drawable drawable2 = res.getDrawable(R.drawable.test);	// res.getDrawable��R.drawable.test�Œ�`���ꂽ�摜��Drawable���\�[�X�Ƃ��Ď擾.
        Button button2 = (Button)findViewById(R.id.button2);	// button2���擾.
        button2.setBackgroundDrawable(drawable2);	// button2.setBackgroundDrawable��drawable2���Z�b�g.
    }
}

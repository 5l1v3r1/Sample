package com.bgstation0.android.sample.color_;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // Button�ɐԗΐ��Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setBackgroundColor(Color.RED);	// button1.setBackgroundColor��Color.RED���Z�b�g.
        Button button2 = (Button)findViewById(R.id.button2);	// button2���擾.
        button2.setBackgroundColor(Color.GREEN);	// button2.setBackgroundColor��Color.GREEN���Z�b�g.
        Button button3 = (Button)findViewById(R.id.button3);	// button3���擾.
        button3.setBackgroundColor(Color.BLUE);	// button3.setBackgroundColor��Color.BLUE���Z�b�g.
    }
}

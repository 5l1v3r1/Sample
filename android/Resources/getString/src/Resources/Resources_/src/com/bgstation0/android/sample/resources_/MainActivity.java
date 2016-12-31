package com.bgstation0.android.sample.resources_;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // Resources���當������擾����TextView�ɃZ�b�g.
        Resources res = getResources();	// getResources��res���擾.
        String strTextView1 = res.getString(R.string.textview1_text);	// res.getString��R.string.textview1_text�ɒ�`����Ă��镶������擾.
        TextView textView1 = (TextView)findViewById(R.id.textview1);	// textView1���擾.
        textView1.setText(strTextView1);	// textView1.setText��strTextView1���Z�b�g.
        String strTextView2 = res.getString(R.string.textview2_text);	// res.getString��R.string.textview2_text�ɒ�`����Ă��镶������擾.
        TextView textView2 = (TextView)findViewById(R.id.textview2);	// textView2���擾.
        textView2.setText(strTextView2);	// textView2.setText��strTextView2���Z�b�g.
        String strTextView3 = res.getString(R.string.textview3_text);	// res.getString��R.string.textview3_text�ɒ�`����Ă��镶������擾.
        TextView textView3 = (TextView)findViewById(R.id.textview3);	// textView3���擾.
        textView3.setText(strTextView3);	// textView3.setText��strTextView3���Z�b�g.
        
    }
}

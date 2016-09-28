package com.bgstation0.android.sample.intentfilter_;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // �����Ă����C���e���g��Uri��\��.
        Intent intent = getIntent();	// getIntent��intent���擾.
        Uri uri = intent.getData();		// intent.getData��uri���擾.
        Toast.makeText(this, uri.toString(), Toast.LENGTH_LONG).show();	// uri��Toast�ŕ\��.
        
    }
}

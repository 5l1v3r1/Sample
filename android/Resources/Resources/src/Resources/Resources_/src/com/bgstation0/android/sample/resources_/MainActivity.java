package com.bgstation0.android.sample.resources_;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // Resources����hello_world���擾����Toast�ŕ\��.
        Resources res = getResources();	// getResources��res���擾.
        String strHello = res.getString(R.string.hello_world);	// res.getString��R.string.hello_world�ɒ�`����Ă��镶������擾.
        Toast.makeText(this, strHello, Toast.LENGTH_LONG).show();	// strHello��Toast�ŕ\��.
        
    }
}

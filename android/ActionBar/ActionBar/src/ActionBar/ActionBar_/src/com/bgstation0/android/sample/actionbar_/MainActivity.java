package com.bgstation0.android.sample.actionbar_;

import android.app.ActionBar;
import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // ActionBar���擾.
        ActionBar actionBar = getActionBar();	// getActionBar��ActionBar�I�u�W�F�N�gactionBar���擾.
        if (actionBar == null){	// actionBar��null�Ȃ�.
        	// "actionBar is null!"�ƕ\��.
        	Toast.makeText(this, "actionBar is null!", Toast.LENGTH_SHORT).show();	// Toast��"actionBar is null!"��\��.
        }
        else{	// �擾�ł����ꍇ.
        	actionBar.setTitle("Exist actionBar!!");	// actionBar.setTitle�Ń^�C�g����"Exist actionBar!!"�ɕύX.
        }
    }
}

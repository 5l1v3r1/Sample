package com.bgstation0.android.sample.configuration_;

import android.app.Activity;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // "onCreate"�ɗ�����g�[�X�g�\��.
        Toast.makeText(this, "onCreate", Toast.LENGTH_LONG).show();	// "onCreate"�ƕ\��.
        
    }
    
    // �ݒ�ύX������������.(��]�Ȃ�.)
    @Override
    public void onConfigurationChanged(Configuration newConfig){
    	
    	// �e�N���X�̊��菈��.
    	super.onConfigurationChanged(newConfig);	// super.onConfigurationChanged��newConfig��n��.
    	
    	// ������\��.
    	if (newConfig.orientation == Configuration.ORIENTATION_PORTRAIT){	// �c.
    		Toast.makeText(this, "PORTRAIT", Toast.LENGTH_LONG).show();	// "PORTRAIT"�ƕ\��.
    	}
    	else if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE){	// ��.
    		Toast.makeText(this, "LANDSCAPE", Toast.LENGTH_LONG).show();	// "LANDSCAPE"�ƕ\��.
    	}
    	
    }
    
}
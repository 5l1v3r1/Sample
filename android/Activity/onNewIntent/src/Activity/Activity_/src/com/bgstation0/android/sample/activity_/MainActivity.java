package com.bgstation0.android.sample.activity_;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Parcelable;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {

	// �����o�t�B�[���h�̒�`.
	Context mContext = null;	// mContext��null�ŏ�����.
		
    @Override
    protected void onCreate(Bundle savedInstanceState) {
    	
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mContext = this;	// mContext��this���Z�b�g.
        
        // �C���e���g�̎擾.
        Intent intent = getIntent();	// �C���e���g�̎擾.
        if (intent != null){	// intent��null�łȂ���.
        	String title = intent.getStringExtra(Intent.EXTRA_TEXT);	// title���擾.
        	if (title != null){	// title��null�łȂ���.
        		Toast.makeText(mContext, "onCreate: " + title, Toast.LENGTH_LONG).show();	// title��\��.
        	}
        	else{
        		Toast.makeText(mContext, "onCreate: title = null", Toast.LENGTH_LONG).show();	// title��null.
        	}
        	String url = intent.getDataString();	// url���擾.
        	if (url != null){	// url��null�łȂ���.
        		Toast.makeText(mContext, "onCreate: " + url, Toast.LENGTH_LONG).show();	// url��\��.
        	}
        	else{
        		Toast.makeText(mContext, "onCreate: url = null", Toast.LENGTH_LONG).show();	// url��null.
        	}
        }
        else{
        	Toast.makeText(mContext, "onCreate: intent = null", Toast.LENGTH_LONG).show();	// intent��null.
        }
        
        // �{�^���ɃN���b�N���X�i�[���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				
				// URL��\������C���e���g�̍쐬.
				Intent launcherIntent = new Intent(Intent.ACTION_VIEW);	// launcherIntent���쐬.
				launcherIntent.addCategory(Intent.CATEGORY_DEFAULT);	// CATEGORY_DEFAULT��ǉ�.
				launcherIntent.setClassName(mContext.getPackageName(), mContext.getClass().getName());	// �N���X�����Z�b�g.
				String url = "http://bgstation0.com";	// url�̃Z�b�g.
				String title = "B.G-STATION";	// title�̃Z�b�g.
				launcherIntent.putExtra(Intent.EXTRA_TEXT, title);	// title��launcherIntent�ɃZ�b�g.
				launcherIntent.setData(Uri.parse(url));	// url��launcherIntent�ɃZ�b�g.
				
				// �V���[�g�J�b�g���쐬����C���e���g�̍쐬.
				Intent shortcutIntent = new Intent();	// shortcutIntent���쐬.
				shortcutIntent.putExtra(Intent.EXTRA_SHORTCUT_INTENT, launcherIntent);	// launcherIntent��n��.
				shortcutIntent.putExtra(Intent.EXTRA_SHORTCUT_NAME, title);	// title��n��.
				Parcelable iconResource = Intent.ShortcutIconResource.fromContext(mContext, R.drawable.ic_launcher);	// �V���[�g�J�b�g�A�C�R�����\�[�X�̎擾.
				shortcutIntent.putExtra(Intent.EXTRA_SHORTCUT_ICON_RESOURCE, iconResource);	// iconResource�̃Z�b�g.
				shortcutIntent.setAction("com.android.launcher.action.INSTALL_SHORTCUT");	// �V���[�g�J�b�g�쐬�A�N�V�������Z�b�g.
				sendBroadcast(shortcutIntent);	// sendBroadcast��shortcutIntent�𑗐M.
				
			}
			
		});
            
    }
    
    @Override
    protected void onNewIntent(Intent intent){
    	super.onNewIntent(intent);
    	
    	// �n���ꂽintent�̔���.
        if (intent != null){	// intent��null�łȂ���.
        	String title = intent.getStringExtra(Intent.EXTRA_TEXT);	// title���擾.
        	if (title != null){	// title��null�łȂ���.
        		Toast.makeText(mContext, "onNewIntent: " + title, Toast.LENGTH_LONG).show();	// title��\��.
        	}
        	else{
        		Toast.makeText(mContext, "onNewIntent: title = null", Toast.LENGTH_LONG).show();	// title��null.
        	}
        	String url = intent.getDataString();	// url���擾.
        	if (url != null){	// url��null�łȂ���.
        		Toast.makeText(mContext, "onNewIntent: " + url, Toast.LENGTH_LONG).show();	// url��\��.
        	}
        	else{
        		Toast.makeText(mContext, "onNewIntent: url = null", Toast.LENGTH_LONG).show();	// url��null.
        	}
        }
        else{
        	Toast.makeText(mContext, "onNewIntent: intent = null", Toast.LENGTH_LONG).show();	// intent��null.
        }
    	
    }
    
}
package com.bgstation0.android.sample.downloadmanager_;

import android.app.Activity;
import android.app.DownloadManager;
import android.content.IntentFilter;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity implements OnClickListener {	// View.OnClickListener������.

	// �����o�t�B�[���h�̒�`.
	public DownloadManager downloadManager = null;	// DownloadManager�^downloadManager��null�ɃZ�b�g.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
        // DownloadManager�̊m��.
        if (downloadManager == null){	// downloadManager��null�Ȃ�.
        	downloadManager = (DownloadManager)getSystemService(DOWNLOAD_SERVICE);	// getSystemService��DOWNLOAD_SERVICE���擾��, downloadManager�Ɋi�[.
        }
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.
    	// URL�̑O����
    	EditText edittext1 = (EditText)findViewById(R.id.edittext1);	// edittext1�̎擾.
    	String url = edittext1.getText().toString();	// edittext1�̓��e��url�ɑ��.
    	Uri downloadUri = Uri.parse(url);	// url��Uri.parse�Ńp�[�X��, downloadUri�Ɋi�[.
    	String downloadFilename = downloadUri.getLastPathSegment();	// downloadUri.getLastPathSegment�Ńt�@�C�����̕����������o��.
    	// �_�E�����[�h���N�G�X�g�̍쐬
    	DownloadManager.Request request = new DownloadManager.Request(downloadUri);	// DownloadManager.Request�I�u�W�F�N�g��downloadUri��n���č쐬, request�Ɋi�[.
    	request.setDestinationInExternalFilesDir(getApplicationContext(), Environment.DIRECTORY_DCIM, "/" + downloadFilename);	// request.setDestinationInExternalFilesDir�Ń_�E�����[�h����w��.
    	request.setTitle("DownloadManager_");	// �ʒm��ʂ̃^�C�g�����Z�b�g.
    	request.setAllowedNetworkTypes(DownloadManager.Request.NETWORK_MOBILE | DownloadManager.Request.NETWORK_WIFI);	// �l�b�g���[�N�^�C�v�̓��o�C��(3G/LTE)��WiFi����.
    	request.setMimeType("application/octet-stream");	// MIME�^�C�v��"application/octet-stream".
    	// �_�E�����[�h���V�[�o�[�̍쐬.
    	DownloadReceiver downloadReceiver = new DownloadReceiver(this);	// DownloadReceiver�^downloadReceiver���쐬.
    	registerReceiver(downloadReceiver, new IntentFilter(DownloadManager.ACTION_DOWNLOAD_COMPLETE));  // downloadReceiver��ACTION_DOWNLOAD_COMPLETE��IntentFilter�̃C���X�^���X��registerReceiver�œo�^.
    	// ���N�G�X�g�𓊂���.
    	downloadManager.enqueue(request);	// downloadManager��request��ǉ�.
    }
}

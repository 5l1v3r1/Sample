package com.bgstation0.android.sample.progressbar_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ProgressBar;

public class MainActivity extends Activity implements OnClickListener{	// View.OnClickListener������.

	// �����o�t�B�[���h�̒�`
	private ProgressBar progressBar = null;	// ProgressBar�I�u�W�F�N�gprogressBar��null�ɏ�����.
	private int progress = 0; // �i����\��int�^progress.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // button1���擾��, OnClickListener�Ƃ��Ď��g���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// findViewById��R.id.button1���擾.
        button1.setOnClickListener(this);	// button1.setOnClickListener��this(���g)���Z�b�g.
        
        // progressBar���擾��, �����ݒ�.
        progressBar = (ProgressBar)findViewById(R.id.progressbar);	// findViewById��R.id.progressbar���擾��, progressBar�Ɋi�[.
        progressBar.setMax(100);	// progressBar.setMax�ōő�l��100�ɃZ�b�g.
        progress = 0;	// progress��0�ɏ�����.
        progressBar.setProgress(0);	// progressBar.setProgress�Ői����progress�̒l���Z�b�g.
    }
    
    // View.OnClickListener�C���^�t�F�[�X�̃I�[�o�[���C�h���\�b�h������.
    public void onClick(View v){	// onClick���I�[�o�[���C�h.

    	// progress��10�i�߂�.
    	if (progress < 100){	// progress��100�����Ȃ�.
    		progress += 10;	// progress��10���₷.
    	}
    	
    	// progress��progressBar�ɃZ�b�g.
    	progressBar.setProgress(progress);	// progressBar.setProgress��progress���Z�b�g.
    }
}

package com.bgstation0.android.sample.webviewclient_;

import android.app.Activity;
import android.content.Context;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.widget.ProgressBar;
import android.widget.TextView;

public class CustomWebChromeClient extends WebChromeClient {

	// �����o�t�B�[���h�̒�`
	private Context context;	// Context�^context
	private TextView progressTextView;	// TextView�^progressTextView
	private ProgressBar progressBar;	// ProgressBar�^progressBar.
	
	// �R���X�g���N�^
	public CustomWebChromeClient(Context context){
		
		// �����o�̏�����
		this.context = context;	// ������context�������o��context�ɃZ�b�g.
		Activity activity = (Activity)context;	// context��Activity�^��activity�ɃL���X�g.
		progressTextView = (TextView)activity.findViewById(R.id.progresstextview);	// progressTextView���擾.
		progressBar = (ProgressBar)activity.findViewById(R.id.progressbar);	// findViewById��R.id.progressbar���擾��, progressBar�Ɋi�[.
		
	}
	
	// ���[�h�̐i�����ω�������.
	@Override
	public void onProgressChanged(WebView view, int newProgress){
		
		// �i���̍X�V.
		progressTextView.setText(newProgress + "%");	// progressTextView.setText��newProgress��"%"��t���ĕ\��.
		progressBar.setProgress(newProgress);	// progressBar.setProgress�Ői����newProgress���Z�b�g.
		
	}
	
}
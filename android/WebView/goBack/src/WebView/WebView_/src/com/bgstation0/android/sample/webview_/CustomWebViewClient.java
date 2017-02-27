package com.bgstation0.android.sample.webview_;

import android.app.Activity;
import android.content.Context;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.EditText;

public class CustomWebViewClient extends WebViewClient {

	// �����o�t�B�[���h�̒�`
	private Context context;	// Context�^context
	private EditText urlBar;	// EditText�^urlBar
	
	// �R���X�g���N�^
	public CustomWebViewClient(Context context){
		
		// �����o�̏�����
		this.context = context;	// ������context�������o��context�ɃZ�b�g.
		Activity activity = (Activity)context;	// context��Activity�^��activity�ɃL���X�g.
		urlBar = (EditText)activity.findViewById(R.id.urlbar);	// urlBar���擾.
		
	}
	
	// ���[�h����URL���ς������.
	@Override
	public boolean shouldOverrideUrlLoading(WebView view, String url){
		
		// URL�̍X�V
		urlBar.setText(url);	// urlBar.setText��url���Z�b�g.
		
		// false��Ԃ���, �K������WebView�ŏ�������悤�ɂȂ�.
		return false;	// false��Ԃ�.
		
	}
	
}

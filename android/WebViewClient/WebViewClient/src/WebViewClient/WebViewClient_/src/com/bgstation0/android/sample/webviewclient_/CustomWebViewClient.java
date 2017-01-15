package com.bgstation0.android.sample.webviewclient_;

import android.content.Context;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Toast;

public class CustomWebViewClient extends WebViewClient {

	// �����o�t�B�[���h�̒�`
	private Context context;	// Context�^context
	
	// �R���X�g���N�^
	public CustomWebViewClient(Context context){
		
		// �����o�̏�����
		this.context = context;	// ������context�������o��context�ɃZ�b�g.
		
	}
	
	// ���[�h����URL���ς������.
	@Override
	public boolean shouldOverrideUrlLoading(WebView view, String url){
		
		// URL�̕\��
		Toast.makeText(context, url, Toast.LENGTH_LONG).show();	// url��\��.
		
		// false��Ԃ���, �K������WebView�ŏ�������悤�ɂȂ�.
		return false;	// false��Ԃ�.
		
	}
	
}
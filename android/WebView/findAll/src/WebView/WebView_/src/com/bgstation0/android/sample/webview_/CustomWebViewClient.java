package com.bgstation0.android.sample.webview_;

import android.content.Context;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class CustomWebViewClient extends WebViewClient {

	// �����o�t�B�[���h�̒�`
	private Context mContext;	// Context�^mContext

	// �R���X�g���N�^
	public CustomWebViewClient(Context context){
			
			// �����o�̏�����
			mContext = context;	// ������context�������o��mContext�ɃZ�b�g.
			
	}
	
	// ���[�h����URL���ς������.
	@Override
	public boolean shouldOverrideUrlLoading(WebView view, String url){
		
		// false��Ԃ���, �K������WebView�ŏ�������悤�ɂȂ�.
		return false;	// false��Ԃ�.
		
	}
	
}

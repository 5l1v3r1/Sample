package com.bgstation0.android.sample.wv.wvt_;

import android.app.Activity;
import android.content.Context;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class CustomWebViewClient extends WebViewClient {

	// �����o�t�B�[���h�̒�`
	private Context mContext;	// Context�^mContext
	private MainActivity mMainActivity;	// mMainActivity.
		
	// �R���X�g���N�^
	public CustomWebViewClient(Context context, Activity mainActivity){
		
		// �����o�̏�����
		mContext = context;	// ������context�������o��mContext�ɃZ�b�g.
		mMainActivity = (MainActivity)mainActivity;	// mainActivity���Z�b�g.
		
	}
	
	// ���[�h����URL���ς������.
	@Override
	public boolean shouldOverrideUrlLoading(WebView view, String url){
		
		// false��Ԃ���, �K������WebView�ŏ�������悤�ɂȂ�.
		return false;	// false��Ԃ�.
		
	}
		
}
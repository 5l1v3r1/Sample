package com.bgstation0.android.sample.wv.wvt_;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Message;
import android.view.View;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.widget.FrameLayout;

public class CustomWebChromeClient extends WebChromeClient {

	// �����o�t�B�[���h�̒�`
	private Context mContext;	// Context�^mContext
	private MainActivity mMainActivity;	// mMainActivity.
	
	// �R���X�g���N�^
	public CustomWebChromeClient(Context context, Activity mainActivity){
		
		// �����o�̏�����
		mContext = context;	// ������context�������o��mContext�ɃZ�b�g.
		mMainActivity = (MainActivity)mainActivity;	// mainActivity���Z�b�g.
		
	}
	
	// �E�B���h�E�쐬��.
	@Override
	public boolean onCreateWindow(WebView view, boolean dialog, boolean userGesture, Message resultMsg){
		
		// SubActivity(2)�̍쐬.
        Intent intent2 = new Intent(mMainActivity, SubActivity.class);	// intent2�̍쐬.
        intent2.putExtra("id", "tab2");	// "id"���L�[, "tab2"��l�Ƃ��ēo�^.
        intent2.putExtra("url", "");	// "url"���L�[, ""��l�Ƃ��ēo�^.
        mMainActivity.mWindow2 = mMainActivity.mLAM.startActivity("tab2",  intent2);
        // mainContentView��decorView2���擾���Ă���.
        FrameLayout mainContentView = (FrameLayout)mMainActivity.findViewById(android.R.id.content);	// android.R.id.content���擾.        
        View decorView2 = mMainActivity.mWindow2.getDecorView();	// decorView2�̎擾.
        // WebView���̑��M.
        WebView newWebView = (WebView)decorView2.findViewById(R.id.webview);	// �V����WebView���擾.
        WebView.WebViewTransport transport = (WebView.WebViewTransport)resultMsg.obj;	// transport���擾.
        transport.setWebView(newWebView);	// newWebView���Z�b�g.
        resultMsg.sendToTarget();	// ���M.
        // mainContentView�͍폜����, ��������setContentView���Ȃ����Ă���, fl���擾��, ������decorView2��ǉ�.
        mainContentView.removeAllViews();	// �S���폜.
        mMainActivity.setContentView(R.layout.activity_main);
        FrameLayout fl = (FrameLayout)mMainActivity.findViewById(R.id.frame_main);	// fl���擾.
        fl.addView(decorView2);	// fl.addView��decorView2��ǉ�.
        return false;	// false��Ԃ�.
        
	}
	
}
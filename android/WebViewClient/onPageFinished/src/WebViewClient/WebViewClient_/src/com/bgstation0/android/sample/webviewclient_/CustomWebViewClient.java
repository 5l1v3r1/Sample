package com.bgstation0.android.sample.webviewclient_;

import android.app.Activity;
import android.content.Context;
import android.graphics.Bitmap;
import android.opengl.Visibility;
import android.view.View;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.EditText;
import android.widget.TextView;

public class CustomWebViewClient extends WebViewClient {

	// �����o�t�B�[���h�̒�`
	private Context context;	// Context�^context
	private EditText urlBar;	// EditText�^urlBar
	private TextView progressTextView;	// TextView�^progressTextView
	
	// �R���X�g���N�^
	public CustomWebViewClient(Context context){
		
		// �����o�̏�����
		this.context = context;	// ������context�������o��context�ɃZ�b�g.
		Activity activity = (Activity)context;	// context��Activity�^��activity�ɃL���X�g.
		urlBar = (EditText)activity.findViewById(R.id.urlbar);	// urlBar���擾.
		progressTextView = (TextView)activity.findViewById(R.id.progresstextview);	// progressTextView���擾.
		progressTextView.setVisibility(View.INVISIBLE);	// progressTextView.setVisibility��INVISIBLE�ɃZ�b�g.
		
	}
	
	// ���[�h����URL���ς������.
	@Override
	public boolean shouldOverrideUrlLoading(WebView view, String url){
		
		// false��Ԃ���, �K������WebView�ŏ�������悤�ɂȂ�.
		return false;	// false��Ԃ�.
		
	}
	
	// �y�[�W�̃��[�h���J�n���ꂽ��.
	@Override
    public void onPageStarted(WebView view, String url, Bitmap favicon){
		
		// �i����(�v���O���X�e�L�X�g)�̕\��.
		progressTextView.setVisibility(View.VISIBLE);	// progressTextView.setVisibility��VISIBLE�ɃZ�b�g.
		
		// URL�̍X�V
		urlBar.setText(url);	// urlBar.setText��url���Z�b�g.
				
	}
	
	// �y�[�W�̃��[�h���I��������.
	@Override
	public void onPageFinished (WebView view, String url){
		
		// �i����(�v���O���X�e�L�X�g)�̔�\��.
		progressTextView.setVisibility(View.INVISIBLE);	// progressTextView.setVisibility��INVISIBLE�ɃZ�b�g.
				
	}
	
}
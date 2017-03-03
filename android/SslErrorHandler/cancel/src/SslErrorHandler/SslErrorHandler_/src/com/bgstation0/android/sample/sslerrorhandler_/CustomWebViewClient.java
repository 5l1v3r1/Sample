package com.bgstation0.android.sample.sslerrorhandler_;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.graphics.Bitmap;
import android.net.http.SslError;
import android.opengl.Visibility;
import android.view.View;
import android.webkit.SslErrorHandler;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

public class CustomWebViewClient extends WebViewClient {

	// �����o�t�B�[���h�̒�`
	private Context context;	// Context�^context
	private EditText urlBar;	// EditText�^urlBar
	private TextView progressTextView;	// TextView�^progressTextView
	private ProgressBar progressBar;	// ProgressBar�^progressBar.
	
	// �R���X�g���N�^
	public CustomWebViewClient(Context context){
		
		// �����o�̏�����
		this.context = context;	// ������context�������o��context�ɃZ�b�g.
		Activity activity = (Activity)context;	// context��Activity�^��activity�ɃL���X�g.
		urlBar = (EditText)activity.findViewById(R.id.urlbar);	// urlBar���擾.
		progressTextView = (TextView)activity.findViewById(R.id.progresstextview);	// progressTextView���擾.
		progressTextView.setVisibility(View.INVISIBLE);	// progressTextView.setVisibility��INVISIBLE�ɃZ�b�g.
        progressBar = (ProgressBar)activity.findViewById(R.id.progressbar);	// findViewById��R.id.progressbar���擾��, progressBar�Ɋi�[.
        progressBar.setMax(100);	// progressBar.setMax�ōő�l��100�ɃZ�b�g.
        progressBar.setProgress(0);	// progressBar.setProgress�Ői����0���Z�b�g.
        progressBar.setVisibility(View.INVISIBLE);	// progressBar.setVisibility��INVISIBLE�ɃZ�b�g.
        
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
		
		// �i����(�v���O���X�o�[)�̕\��.
		progressBar.setProgress(0);	// progressBar.setProgress�Ői����0���Z�b�g.
        progressBar.setVisibility(View.VISIBLE);	// progressBar.setVisibility��VISIBLE�ɃZ�b�g.
        
		// URL�̍X�V
		urlBar.setText(url);	// urlBar.setText��url���Z�b�g.
				
	}
	
	// �y�[�W�̃��[�h���I��������.
	@Override
	public void onPageFinished(WebView view, String url){
		
		// �i����(�v���O���X�e�L�X�g)�̔�\��.
		progressTextView.setVisibility(View.INVISIBLE);	// progressTextView.setVisibility��INVISIBLE�ɃZ�b�g.
		
		// �i����(�v���O���X�o�[)�̔�\��.
		progressBar.setProgress(100);	// progressBar.setProgress�Ői����100���Z�b�g.
		progressBar.setVisibility(View.INVISIBLE);	// progressBar.setVisibility��INVISIBLE�ɃZ�b�g.
				
	}
	
	// �G���[������������.
	@Override
	public void onReceivedError(WebView view, int errorCode, String description, String failingUrl){
		
		// �G���[�R�[�h�Ɛ����̕\��.
		Toast.makeText(context, Integer.toString(errorCode) + ":" + description, Toast.LENGTH_LONG).show();	// Toast��errorCode��description��\��.
		
	}
	
	// SSL�G���[������������.
	@Override
	public void onReceivedSslError(WebView view, final SslErrorHandler handler, SslError error){
		
		// SSL�G���[�̃G���[���b�Z�[�W��\��.
		Toast.makeText(context, "SSL Error!", Toast.LENGTH_LONG).show();	// Toast��"SSL Error!"��\��.
		
    	// �A���[�g�_�C�A���O�r���_�[�̐���
    	AlertDialog.Builder builder = new AlertDialog.Builder(context);	// AlertDialog.Builer�̃C���X�^���Xbuilder�̐���.
    	
    	// �A���[�g�_�C�A���O�̐ݒ�
    	builder.setTitle("SSL Error!");	// setTitle�Ń^�C�g��"SSL Error!"���Z�b�g.
    	builder.setMessage("SSL Error!");	// setMessage�Ŗ{��"SSL Error!"���Z�b�g.

    	// �|�W�e�B�u�{�^���̐ݒ�
    	builder.setPositiveButton("Proceed", new DialogInterface.OnClickListener() {	// builder.setPositiveButton�Ń|�W�e�B�u�{�^��"Proceed"��DialogInterface.OnClickListener���Z�b�g. 
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
				handler.proceed();	// handler.proceed�Ői�߂�.
			}
		});
    	// �l�K�e�B�u�{�^���̐ݒ�
    	builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {		// builder.setNegativeButton�Ńl�K�e�B�u�{�^��"Cancel"��DialogInterface.OnClickListener���Z�b�g.
			
			@Override
			public void onClick(DialogInterface dialog, int which) {
				// TODO Auto-generated method stub
				handler.cancel();	// handler.cancel�ŃL�����Z��.
			}
		});

    	// �A���[�g�_�C�A���O�̕\��
    	builder.show();	// builder.show�ŃA���[�g�_�C�A���O��\��
    	
	}
	
}
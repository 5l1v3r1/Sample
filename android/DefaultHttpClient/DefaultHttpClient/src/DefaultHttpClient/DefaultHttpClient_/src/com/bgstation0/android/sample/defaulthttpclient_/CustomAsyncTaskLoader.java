package com.bgstation0.android.sample.defaulthttpclient_;

import java.io.ByteArrayOutputStream;

import org.apache.http.HttpResponse;
import org.apache.http.HttpStatus;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

import android.content.AsyncTaskLoader;
import android.content.Context;

public class CustomAsyncTaskLoader extends AsyncTaskLoader<String> {	// �񓯊������̌��ʂ�String��CustomAsyncTaskLoader.

	// �����o�t�B�[���h�̒�`
	Context context;	// Context�^context
	String url;	// String�^url
	
	// �R���X�g���N�^
	public CustomAsyncTaskLoader(Context context, String url){
		super(context);	// �e�N���X�̃R���X�g���N�^���Ă�.
		this.context = context;	// this.context�����o�Ɋi�[.
		this.url = url;	// this.url�����o�Ɋi�[.
	}
	
	// �񓯊�����
	@Override
	public String loadInBackground(){
		// �I�u�W�F�N�g�̐錾
		String ret = "";	// �߂�l�̕�����ret��""���Z�b�g.
		ByteArrayOutputStream stream = null;	// �o�C�g��o�̓X�g���[��stream��null��.
		// try�ň͂�.
    	try{
    		//�@HTTP���N�G�X�g
    		HttpClient httpClient = new DefaultHttpClient();	// DefaultHttpClient��httpClient�擾.
    		HttpGet httpGetReq = new HttpGet(url);	// url��n����HTTP GET�ȃ��N�G�X�g�擾.
    		HttpResponse httpRes = httpClient.execute(httpGetReq);	// ���N�G�X�g�����s��, ���X�|���X���擾.
    		int status = httpRes.getStatusLine().getStatusCode();	// HTTP�X�e�[�^�X�R�[�h�擾.
    		if (status == HttpStatus.SC_OK){	// HTTP 200 OK
    			stream = new ByteArrayOutputStream();	// �o�C�g��o�̓X�g���[������.
    			httpRes.getEntity().writeTo(stream);	// ���X�|���X�̃{�f�B��stream�ɏ�������.
    			ret = stream.toString();	// stream�𕶎���ɂ������̂�ret�Ɋi�[.
    		}
    	}
    	catch (Exception ex){
    		ret = ex.toString();	// ret��ex�̓��e���Z�b�g.
    	}
    	finally{
    		if (stream != null){
    			try{
    				stream.close();	// stream�����.
    				stream = null;	// stream��null��.
    			}
    			catch (Exception ex){
    	    		ret = ex.toString();	// ret��ex�̓��e���Z�b�g.
    	    	}
    		}
    	}
		return ret;
	}
	
	// Loader�̊J�n��
    @Override
    protected void onStartLoading(){
    	forceLoad();	// �����I�Ƀ��[�h�J�n.
    }
}

package com.bgstation0.android.sample.httpurlconnection_;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Iterator;
import java.util.Map;

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
		HttpURLConnection connection = null;	// HttpURLConnection�^connection��null�ɃZ�b�g.
		BufferedReader reader = null;	// BufferedReader�^reader��null�ɃZ�b�g.
		// try�ň͂�.
		try{
			// ���N�G�X�g�쐬�Ɛڑ�
			URL url = new URL(this.url);	// new��URL�I�u�W�F�N�gurl�𐶐�, ���̂Ƃ�this.url��n��.(��₱������url�����[�J��URL�I�u�W�F�N�g, this.url��String�^�����o.)
			connection = (HttpURLConnection)url.openConnection();	// url.openConnection�ŃR�l�N�V�������J����, URLConnection�I�u�W�F�N�g���Ԃ�̂�, HttpURLConnection�ɃL���X�g����connection�Ɋi�[.
			connection.setRequestMethod("GET");	// connection.setRequestMethod��"GET"���w��.
			connection.setInstanceFollowRedirects(true);	// connection.setInstanceFollowRedirects��true�ɂ��邱�ƂŎ������_�C���N�g.
			connection.connect();	// connection.connect�Őڑ�.
			//�@��M, ���X�|���X�{�f�B�擾.
			reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));	// connection.getInputStream����BufferedReader�I�u�W�F�N�greader���쐬.
			String inputLine;	// �擾�ł����X�g���[��������.
			while ((inputLine = reader.readLine()) != null){	// null�łȂ����.
				ret += inputLine;	// ret��inputLine��ǉ�.
			}
		}
		catch (Exception ex){
			ret = ex.toString();	// ret��ex�̓��e���Z�b�g.
		}
		finally{
			try{
				if (reader != null){
					reader.close();	// reader�����.
					reader = null;	// reader��null��.
				}
				if (connection != null){
					connection.disconnect();	// connection�ؒf.
					connection = null;	// connection��null��.
				}
			}
			catch (Exception ex){
				ret = ex.toString();	// ret��ex�̓��e���Z�b�g.
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

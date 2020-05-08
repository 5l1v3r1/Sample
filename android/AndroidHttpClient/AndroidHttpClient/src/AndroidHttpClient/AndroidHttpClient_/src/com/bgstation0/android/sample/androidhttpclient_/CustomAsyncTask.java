package com.bgstation0.android.sample.androidhttpclient_;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;

import android.app.Activity;
import android.content.Context;
import android.net.http.AndroidHttpClient;
import android.os.AsyncTask;
import android.util.Log;
import android.widget.TextView;

// �J�X�^���A�V���N�^�X�N
public class CustomAsyncTask extends AsyncTask<String, Void, String> {	// �񓯊�����CustomAsyncTask.

	// �����o�t�B�[���h�̒�`
	final String TAG = getClass().getName();	// �N���X�����^�O�ɂ���.
    Context mContext = null;	// mContext��null�ŏ�����.
	
	// �R���X�g���N�^
	public CustomAsyncTask(Context context){
		mContext = context;	// mContext��context���Z�b�g.
	}
	
	// �񓯊�����
	@Override
	protected String doInBackground(String... params) {
		
		// TODO Auto-generated method stub
		// ���N�G�X�g�쐬�ƃ��X�|���X�̎擾.
		try{
			String url = params[0];	// 0�Ԗڂ̕������URL.
			AndroidHttpClient httpClient = AndroidHttpClient.newInstance("bgst");	// �C���X�^���X����.
			HttpResponse httpResponse = httpClient.execute(new HttpGet(url));	// url��n����HttpGet��execute�Ŏ��s.
			BufferedReader reader = new BufferedReader(new InputStreamReader(httpResponse.getEntity().getContent(), "UTF-8"));	// reader�擾.
			StringBuffer sb = new StringBuffer();	// �o�b�t�@����.
			String line = null;	// line��null�ŏ�����.
			while ((line = reader.readLine()) != null){	// �s�ǂݍ��݂��J��Ԃ�.
				sb.append(line + "\n");	// �s��ǉ�.
			}
			return sb.toString();	// ������ɂ��ĕԂ�.
		}
		catch (Exception ex){	// ��O���L���b�`.
			Log.d(TAG, ex.getMessage());	// �G���[���O�o��.
			return "";	// ""��Ԃ�.
		}
		
	}
	
	// UI�X���b�h�̍X�V
	@Override
	protected void onPostExecute(String result){
		// textview1�̍X�V
		Activity activity = (Activity)mContext;	// mContext��activity�ɃL���X�g.
		TextView textView1 = (TextView)activity.findViewById(R.id.textview1);	// textview1���擾.
		textView1.setText(result);	// textview1.setText��result���Z�b�g.
	}
	
}
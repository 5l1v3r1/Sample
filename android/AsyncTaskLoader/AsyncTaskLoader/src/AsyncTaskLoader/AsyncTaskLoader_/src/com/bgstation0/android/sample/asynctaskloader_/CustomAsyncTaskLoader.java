package com.bgstation0.android.sample.asynctaskloader_;

import android.content.AsyncTaskLoader;
import android.content.Context;

public class CustomAsyncTaskLoader extends AsyncTaskLoader<String> {	// �񓯊������̌��ʂ�String��CustomAsyncTaskLoader.

    // �����o�t�B�[���h�̒�`
    Context context;	// Context�^context
    int param;	// int�^param
    
    // �R���X�g���N�^
    public CustomAsyncTaskLoader(Context context, int param){
    	super(context);	// �e�N���X�̃R���X�g���N�^���Ă�.
        this.context = context;	// this.context�����o�Ɋi�[.
        this.param = param;	// this.param�����o�Ɋi�[.
	}
    
    // �񓯊�����
    @Override
    public String loadInBackground(){
    	// �I�u�W�F�N�g�̐錾
    	String ret = "";	// �߂�l�̕�����ret��""���Z�b�g.
    	// try�ň͂�.
    	try{
    		Thread.sleep(10000);	// 10�b�x�~
    		ret = "param = " + param;	// ret��param�̒l.
    	}
    	catch (Exception ex){
    		ret = "exception";	// ret��exception.
    	}
    	return ret;
    }
    
    // Loader�̊J�n��
    @Override
    protected void onStartLoading(){
    	forceLoad();	// �����I�Ƀ��[�h�J�n.
    }
    
}

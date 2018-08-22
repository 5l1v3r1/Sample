package com.bgstation0.android.sample.camera.picturecallback_;

import java.io.File;
import java.io.FileOutputStream;

import android.app.Activity;
import android.content.res.Configuration;
import android.hardware.Camera;
import android.os.Bundle;
import android.os.Environment;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.widget.Toast;

public class MainActivity extends Activity implements SurfaceHolder.Callback, Camera.ShutterCallback, Camera.PictureCallback{

	// �����o�t�B�[���h�̒�`.
	private Camera camera;	// Camera�I�u�W�F�N�gcamera.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // SurfaceView�̎擾�ƃR�[���o�b�N�̃Z�b�g.
        SurfaceView surfaceView = (SurfaceView)findViewById(R.id.surfaceView);	// surfaceView�̎擾.
        SurfaceHolder holder = surfaceView.getHolder();	// surfaceView.getHolder��holder���擾.
        holder.addCallback(this);	// holder.addCallback�ŃR�[���o�b�N(���X�i�[)�Ƃ���this���Z�b�g.
        
    }
    
    // Surface�쐬��.
    @Override
    public void surfaceCreated(SurfaceHolder holder){
    	
    	// �J�����̎擾.
    	camera = Camera.open();	// camera�I�[�v��.
    	try{	// try�ň͂�.
    		camera.setDisplayOrientation(90);	// 90�x�E�ɉ�].
    		camera.setPreviewDisplay(holder);	// setPreviewDisplay��holder�̎w��SurfaceView���v���r���[�f�B�X�v���C��.
    	}
    	catch(Exception ex){	// ��O��
    		ex.printStackTrace();	// �X�^�b�N�g���[�X�o��.
    	}
    	
    }
    
    // Surface�j����.
    @Override
    public void surfaceDestroyed(SurfaceHolder holder){
    	
    	// �J�����̔j��.
    	camera.stopPreview();	// stopPreview�Ńv���r���[��~.
    	camera.release();	// release��camera�̃����[�X.
    	camera = null;	// null�Ŗ��߂�.
    	
    }
    
    // Surface�ύX��.
    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height){
    	
    	// �p�����[�^�̎擾.
    	Camera.Parameters parameters = camera.getParameters();	// parameters���擾.
    	//Toast.makeText(this, "before width = " + String.valueOf(parameters.getPreviewSize().width) + ", before height = " + String.valueOf(parameters.getPreviewSize().height), Toast.LENGTH_LONG).show();	// �ݒ�O�̃v���r���[�̃T�C�Y��\��.
    	//parameters.setPreviewSize(1920, 1080);	// �v���r���[�T�C�Y��(1920, 1080)���Z�b�g.
    	//Toast.makeText(this, "after width = " + String.valueOf(parameters.getPreviewSize().width) + ", after height = " + String.valueOf(parameters.getPreviewSize().height), Toast.LENGTH_LONG).show();	// �ݒ��̃v���r���[�̃T�C�Y��\��.
    	/*
    	for (int i = 0; i < parameters.getSupportedPreviewSizes().size(); i++){	// �T�|�[�g���Ă�T�C�Y�ꗗ�̐������J��Ԃ�.
    		Toast.makeText(this, "width = " + String.valueOf(parameters.getSupportedPreviewSizes().get(i).width) + ", height = " + String.valueOf(parameters.getSupportedPreviewSizes().get(i).height), Toast.LENGTH_LONG).show();	// i�Ԗڂ�\��.
    	}
    	*/
    	try{	// try��
    		camera.setParameters(parameters);	// camera��parameters���Z�b�g.
    	}
    	catch (Exception ex){	// ��O�L���b�`.
    		Toast.makeText(this, "ex = " + ex.toString(), Toast.LENGTH_LONG).show();	// ex�̕\��.
    	}
    	
    	// �v���r���[�J�n.
    	camera.startPreview();	// startPreview�Ńv���r���[�J�n.
    	
    }
    
    // �ݒ�ύX������������.(��]�Ȃ�.)
    @Override
    public void onConfigurationChanged(Configuration newConfig){
    	
    	// �e�N���X�̊��菈��.
    	super.onConfigurationChanged(newConfig);	// super.onConfigurationChanged��newConfig��n��.
    	
    	// ������\��.
    	if (newConfig.orientation == Configuration.ORIENTATION_PORTRAIT){	// �c.
    		camera.setDisplayOrientation(90);	// 90�x�E�ɉ�].
    	}
    	else if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE){	// ��.
    		camera.setDisplayOrientation(0);	// 0�x.
    	}
    	
    }
    
    // �^�b�`�C�x���g������������.
    @Override
    public boolean onTouchEvent(MotionEvent event){
    
    	// �C�x���g�̃`�F�b�N.
    	int action = event.getAction();	// event.getAction��action���擾.
    	if (action == MotionEvent.ACTION_DOWN){	// �����ꂽ��.
    		camera.takePicture(this,
			null,
			this);	// ShutterCallback��PictureCallback��n��.
    	}
    	return true;	// ���������̂�true��Ԃ�.
    	
    }
    
    // �V���b�^�[���؂�ꂽ��.
    @Override
	public void onShutter() {
		// TODO Auto-generated method stub
		// "onShutter"��\��.
    	Toast.makeText(this, "onShutter", Toast.LENGTH_LONG).show();	// Toast��"onShutter"�ƕ\��.
	}
    
    // �摜���擾�ł�����.
    @Override
	public void onPictureTaken(byte[] data, Camera camera) {
		// TODO Auto-generated method stub
		// data���t�@�C���ɕۑ�.
    	FileOutputStream out = null;	// out��null�ŏ�����.
    	try{	// try�ň͂�.
    		String state = Environment.getExternalStorageState();	// Environment.getExternalStorageState�œ������state���擾.
			if (Environment.MEDIA_MOUNTED.equals(state)){	// MEDIA_MOUNTED�Ȃ�.
				File ext_dcim_dir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DCIM);	// Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DCIM)��DCIM�f�B���N�g��ext_dcim_dir���擾.
				File ext_file = new File(ext_dcim_dir, "camera_image.jpg");	// filename��File�I�u�W�F�N�gext_file�𐶐�.
				out = new FileOutputStream(ext_file);	// ext_file��FileOutputStream�I�u�W�F�N�gout�𐶐�.
				out.write(data);	// out.write��data����������.
				Toast.makeText(this, "Save!", Toast.LENGTH_LONG).show();	// "Save!"�ƕ\��.
			}
    	}
    	catch (Exception ex){	// ��O����.
    		Toast.makeText(this, "Exception!", Toast.LENGTH_LONG).show();	// "Exception!"�ƕ\��.
    	}
    	finally{	// �K���s���I������.
    		if (out != null){	// out��null�łȂ����.
    			try{
    				out.close();	// out.close�ŕ���.
    				out = null;		// out��null���Z�b�g.
    			}
    			catch (Exception ex){	// ��O����.
    				Toast.makeText(this, "Exception!!", Toast.LENGTH_LONG).show();	// "Exception!!"�ƕ\��.
    			}
    		}
    	}
	}
    
}
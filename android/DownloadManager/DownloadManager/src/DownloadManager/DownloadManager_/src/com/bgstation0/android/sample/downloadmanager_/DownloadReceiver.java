package com.bgstation0.android.sample.downloadmanager_;

import android.app.Activity;
import android.app.DownloadManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.widget.Toast;


public class DownloadReceiver extends BroadcastReceiver {

	// �����o�t�B�[���h�̒�`
	private MainActivity mainActivity = null;	// MainActivity�^mainActivity��null�ɃZ�b�g.
	
	// �R���X�g���N�^
	public DownloadReceiver(MainActivity mainActivity){
		this.mainActivity = mainActivity;	// mainActivity��this.mainActivity�Ɋi�[.
	}
	
	// �u���[�h�L���X�g�C���e���g���󂯎������.
	@Override
	public void onReceive(Context context, Intent intent) {
		// TODO Auto-generated method stub
		// �A�N�V�������擾��, �A�N�V���������񂲂Ƃɏ����𕪂���.
		String action = intent.getAction();	// intent.getAction��action���擾.
		if (action.equals(DownloadManager.ACTION_DOWNLOAD_COMPLETE)){	// action���_�E�����[�h�����Ȃ�.
			long id = intent.getLongExtra(DownloadManager.EXTRA_DOWNLOAD_ID, -1);	// intent����_�E�����[�hID���擾.
			DownloadManager.Query query = new DownloadManager.Query();	// DownloadManager.Query�I�u�W�F�N�gquery�쐬.
			query.setFilterById(id);	// query.setFilterById�Ń_�E�����[�hID���Z�b�g��, ����ID�Ńt�B���^�����O.
			Cursor c = this.mainActivity.downloadManager.query(query);	// this.mainActivity.downloadManager.query��query���Z�b�g����, Cursor�^c���擾.
			if (c.moveToFirst()){	// �J�[�\���̍ŏ��Ɉړ�.
				int status = c.getInt(c.getColumnIndex(DownloadManager.COLUMN_STATUS));	// �X�e�[�^�X���擾.
				// �X�e�[�^�X�������Ȃ�g�[�X�g�\��.
				if (status == DownloadManager.STATUS_SUCCESSFUL){	// �����Ȃ�.
					Toast.makeText(this.mainActivity, "STATUS_SUCCESSFUL", Toast.LENGTH_LONG).show();	// "STATUS_SUCCESSFUL"�ƕ\��.
				}
			}
			c.close();
		}
	}
}

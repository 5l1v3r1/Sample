package com.bgstation0.android.sample.alarmmanager_;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.widget.Toast;

public class CustomReceiver extends BroadcastReceiver {

	// �����o�t�B�[���h�̒�`
	private final String PACKAGE_NAME = getClass().getPackage().getName();	// �p�b�P�[�W����������擾.
	private final String CLASS_NAME_SUBACTIVITY = SubActivity.class.getName();	// SubActivity�̃N���X����������擾.
	
	// �u���[�h�L���X�g�C���e���g���󂯂���.
	@Override
	public void onReceive(Context context, Intent intent) {
		// TODO Auto-generated method stub	
		// SubActivity���N��.
		Intent i = new Intent();	// �C���e���gi���쐬.
		i.setClassName(PACKAGE_NAME, CLASS_NAME_SUBACTIVITY);	// �p�b�P�[�W���ƋN������A�N�e�B�r�e�B�̃N���X�����w��.
		i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);	// ���ɓ����A�N�e�B�r�e�B�����Ă��V���ɐ�������t���O.
		context.startActivity(i);	// context.startActivity��SubActivity���N��.
	}

}

package com.bgstation0.android.sample.fragmentmanager_;

import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

// Fragment2�N���X�̒�`.
public class Fragment2 extends Fragment{
	
	// �t���O�����g�̃r���[������.
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		// Fragment2�̃��\�[�X���x�[�X�Ƀ��C�A�E�g�쐬.
		return inflater.inflate(R.layout.fragment2_main, null);	// inflater.inflace��R.layout.fragment2_main���x�[�X�Ƀ��C�A�E�g�쐬.
	}
}

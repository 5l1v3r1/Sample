package com.bgstation0.android.sample.actionbar.tab_;

import android.app.ActionBar;
import android.app.ActionBar.TabListener;
import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentTransaction;

public class CustomTabListener<T extends Fragment> implements ActionBar.TabListener {

	// �����o�t�B�[���h�̒�`.
	private Activity activity = null;	// Activity�^activity��null�ɃZ�b�g.
	private String tag = null;	// String�^tag��null�ɃZ�b�g.
	private Class<T> c = null;	// Class<T>�^c��null�ɃZ�b�g.
	
	// �R���X�g���N�^
	public CustomTabListener(Activity activity, String tag, Class<T> c){
		// �p�����[�^���Z�b�g.
		this.activity = activity;
		this.tag = tag;
		this.c = c;
	}
	
	// �^�u�̑I����
	public void onTabSelected(ActionBar.Tab tab, FragmentTransaction ft) {
		// �t���O�����g�����邩�T��.
		Fragment f = activity.getFragmentManager().findFragmentByTag(tag);	// findFragmentByTag��tag��fragment�����邩�T��.
		if (f == null){	// �Ȃ���Βǉ�.
			f = Fragment.instantiate(activity, c.getName());	// Fragment.instantiate��f�𐶐�.
			activity.getFragmentManager().beginTransaction().add(R.id.framelayout1, f, tag).show(f).commit();	// f��ǉ����ĕ\�����Ċm��.
		}
		else{	// ����Ε\��.
			activity.getFragmentManager().beginTransaction().show(f).commit();	// show�ŕ\��.
		}
	}

	// �^�u�̑I��������
	public void onTabUnselected(ActionBar.Tab tab, FragmentTransaction ft) {
		// �t���O�����g�����邩�T���Ĕ�\��.
		Fragment f = activity.getFragmentManager().findFragmentByTag(tag);	// findFragmentByTag��tag��fragment�����邩�T��.
		activity.getFragmentManager().beginTransaction().hide(f).commit();	// hide�Ŕ�\��.
	}
	
	// �^�u�̍đI����
	public void onTabReselected(ActionBar.Tab tab, FragmentTransaction ft) {
		// �t���O�����g�����邩�T���ĕ\��.
		Fragment f = activity.getFragmentManager().findFragmentByTag(tag);	// findFragmentByTag��tag��fragment�����邩�T��.
		activity.getFragmentManager().beginTransaction().show(f).commit();	// show�ŕ\��.
	}
}

package com.bgstation0.android.sample.fragmenttabhost_;

import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

public class TabFragment extends Fragment {

	// �r���[�̐�����
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		View view = inflater.inflate(R.layout.fragment_tab, container, false);	// inflater.inflate��R.layout.fragment_tab�����Ƃ�View���쐬.
		Bundle bundle = getArguments();	// bundle���擾.
		String name = bundle.getString("name");	// name���擾.
		TextView textView = (TextView)view.findViewById(R.id.tab_textview);	// textView���擾.
		textView.setText(name);	// textView��name���Z�b�g.
		return view;	// view��Ԃ�.
	}
	
}

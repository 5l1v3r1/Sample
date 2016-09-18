package com.bgstation0.android.sample.fragmenttransaction_;

import android.app.Fragment;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

// MainFragment�N���X�̒�`.
public class MainFragment extends Fragment {

	// �����o�t�B�[���h�̒�`
	int count = 0;	// int�^count��0�ɏ�����.
	
	// �t���O�����g�̐�����.
	@Override
    public void onCreate(Bundle savedInstanceState) {
		// Toast��\��
		MainActivity mainActivity = (MainActivity)getActivity();	// getActivity��mainActivity���擾.
		Toast.makeText(mainActivity, "onCreate()", Toast.LENGTH_LONG).show();	// Toast.makeText.show��"onCreate()"��\��.
        super.onCreate(savedInstanceState);
	}
	
	// �t���O�����g�̃r���[������.
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState){
		
		// Toast��\��
        MainActivity mainActivity = (MainActivity)getActivity();	// getActivity��mainActivity���擾.
        Toast.makeText(mainActivity, "onCreateView()", Toast.LENGTH_LONG).show();	// Toast.makeText.show��"onCreateView()"��\��.
        
		// MainFragment�̃��\�[�X���x�[�X�Ƀ��C�A�E�g���쐬.
		View fragmentView = inflater.inflate(R.layout.fragment_main, null);	// inflater.inflace��R.layout.fragment_main���x�[�X�Ƀ��C�A�E�g�쐬��, fragmentView�Ɋi�[.
		
		// �p�����[�^���擾.
		Bundle args = getArguments();	// getArguments��Bundle�^args���擾.
		String text = args.getString("text");	// �L�[��"text"�̒l���擾.
		String color = args.getString("color");	// �L�[��"color"�̒l���擾.

		// text��TextView�ɃZ�b�g.
		TextView textView = (TextView)fragmentView.findViewById(R.id.fragment_main_textview);	// fragmentView.findViewById��textView���擾.
		textView.setText(text);	// textView.setText��text���Z�b�g.
		
		// color���Ƃ�fragmentView�̔w�i���J�X�^�}�C�Y.
		LinearLayout linearLayout = (LinearLayout)fragmentView.findViewById(R.id.fragment_main_linearlayout);	// fragmentView.findViewById��LinearLayout���擾.
		if (color.equals("red")){	// "red"�Ȃ�.
			linearLayout.setBackgroundColor(Color.RED);	// linearLayout.setBackgroundColor��Color.RED���w��.
		}
		else if (color.equals("green")){	// "green"�Ȃ�.
			linearLayout.setBackgroundColor(Color.GREEN);	// linearLayout.setBackgroundColor��Color.GREEN���w��.
		}
		else if (color.equals("blue")){	// "blue"�Ȃ�.
			linearLayout.setBackgroundColor(Color.BLUE);	// linearLayout.setBackgroundColor��Color.BLUE���w��.
		}
				
		// View��Ԃ�.
		return fragmentView;	// fragmentView��Ԃ�.
		
	}
	
	// �t���O�����g�̊J�n��
	@Override
    public void onStart(){
        super.onStart();
        // Toast��\��
        MainActivity mainActivity = (MainActivity)getActivity();	// getActivity��mainActivity���擾.
        Toast.makeText(mainActivity, "onStart()", Toast.LENGTH_LONG).show();	// Toast.makeText.show��"onStart()"��\��.
    }
	
	// �t���O�����g�̕��A��
	@Override
    public void onResume(){
		super.onResume();
		// Toast��\��
        MainActivity mainActivity = (MainActivity)getActivity();	// getActivity��mainActivity���擾.
        Toast.makeText(mainActivity, "onResume()", Toast.LENGTH_LONG).show();	// Toast.makeText.show��"onResume()"��\��.   
        count++;	// count�𑝂₷.
        Toast.makeText(mainActivity, "count = " + Integer.toString(count), Toast.LENGTH_LONG).show();	// Toast.makeText.show��count��\��.
    }
	
	// �t���O�����g�̈ꎞ��~��
	@Override
	public void onPause(){
		super.onPause();
		// Toast��\��
	    MainActivity mainActivity = (MainActivity)getActivity();	// getActivity��mainActivity���擾.
	    Toast.makeText(mainActivity, "onPause()", Toast.LENGTH_LONG).show();	// Toast.makeText.show��"onPause()"��\��.
	}
		
	// �t���O�����g�̒�~��
	@Override
    public void onStop(){
		super.onStop();
		// Toast��\��
        MainActivity mainActivity = (MainActivity)getActivity();	// getActivity��mainActivity���擾.
        Toast.makeText(mainActivity, "onStop()", Toast.LENGTH_LONG).show();	// Toast.makeText.show��"onStop()"��\��.
    }
	
	// �t���O�����g�̃r���[�j����
	@Override
    public void onDestroyView() {
		// Toast��\��
        MainActivity mainActivity = (MainActivity)getActivity();	// getActivity��mainActivity���擾.
        Toast.makeText(mainActivity, "onDestroyView()", Toast.LENGTH_LONG).show();	// Toast.makeText.show��"onDestroyView()"��\��.
        super.onDestroyView();
    }
	
	// �t���O�����g�̔j����
	@Override
    public void onDestroy(){
		// Toast��\��
		MainActivity mainActivity = (MainActivity)getActivity();	// getActivity��mainActivity���擾.
		Toast.makeText(mainActivity, "onDestroy()", Toast.LENGTH_LONG).show();	// Toast.makeText.show��"onDestroy()"��\��.
        super.onDestroy();
    }
	
}

package com.bgstation0.android.sample.gridview_;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

public class GridItemAdapter extends ArrayAdapter<GridItem> {

	// �C���t���[�^�[�̒�`.
	LayoutInflater inflater;	// �C���t���[�^�[inflater.
	
	// �R���X�g���N�^
	public GridItemAdapter(Context context, int resource, GridItem[] objects){
		super(context, resource, objects);
		inflater = (LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);	// �C���t���[�^�[�̎擾.
	}
	
	// �A�C�e���\���̃J�X�^�}�C�Y
	@Override
	public View getView(int position, View convertView, ViewGroup parent){
		// convertView��null�̎�.
		if (convertView == null){
			convertView = inflater.inflate(R.layout.grid_item, null);	// convertView��null�Ȃ�inflater.inflate�Ŏ擾.
		}
		TextView tvname = (TextView)convertView.findViewById(R.id.grid_item_name);	// convertView.findViewById��R.id.grid_item_name��tvname�Ɋi�[.
		tvname.setText(getItem(position).name);	// position�Ԗڂ̃A�C�e����name��tvname.setText�ŃZ�b�g.
		ImageView ivimage = (ImageView)convertView.findViewById(R.id.grid_item_image);	// convertView.findViewById��R.id.grid_item_image��ivimage�Ɋi�[.
		if (getItem(position).colorno == 0){	// colorno��0(��).
			ivimage.setBackgroundResource(R.drawable.red);	// ivimage.setBackgroundResource�Ŕw�i��ԉ摜��.
		}
		else{
			ivimage.setBackgroundResource(R.drawable.blue);	// ivimage.setBackgroundResource�Ŕw�i��摜��.
		}
		return convertView;	// convertView��Ԃ�.
	}
	
}

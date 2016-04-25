package com.bgstation0.android.sample.arrayadapter_;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

// ListItem�p�A�_�v�^�[ListItemAdapter
public class ListItemAdapter extends ArrayAdapter<ListItem> {	// ArrayAdapter<ListItem>���p������ListItemAdapter�̒�`.
	
	// �C���t���[�^�[�̒�`.
	LayoutInflater inflater;	// �C���t���[�^�[inflater.

	// �R���X�g���N�^
	public ListItemAdapter(Context context, int resource, ListItem[] objects) {
		super(context, resource, objects);
		// TODO Auto-generated constructor stub
		inflater = (LayoutInflater)context.getSystemService(context.LAYOUT_INFLATER_SERVICE);	// �C���t���[�^�[�̎擾.(�����͓���̂łЂƂ܂������������̂��Ƒ����Ă���.)
	}

	// �A�C�e���\���̃J�X�^�}�C�Y
	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		// convertView��null�̎�.
		if (convertView == null){
			convertView = inflater.inflate(R.layout.list_item, null);	// convertView��null�Ȃ�inflater.inflate�Ŏ擾.(�����͓���̂łЂƂ܂������������̂��Ƒ����Ă���.)
		}
		TextView tvname = (TextView)convertView.findViewById(R.id.list_item_name);	// convertView.findViewById��R.id.list_item_name��tvname�Ɋi�[.
		tvname.setText(getItem(position).name);	// position�Ԗڂ̃A�C�e����name��tvname.setText�ŃZ�b�g.
		TextView tvage = (TextView)convertView.findViewById(R.id.list_item_age);	// convertView.findViewById��R.id.list_item_age��tvage�Ɋi�[.
		tvage.setText(Integer.toString(getItem(position).age));	// position�Ԗڂ̃A�C�e����age��tvage.setText�ŃZ�b�g.(Integer.toString�ŕ�����ϊ�.)
		TextView tvaddress = (TextView)convertView.findViewById(R.id.list_item_address);	// convertView.findViewById��R.id.list_item_address��tvaddress�Ɋi�[.
		tvaddress.setText(getItem(position).address);	// position�Ԗڂ̃A�C�e����address��tvaddress.setText�ŃZ�b�g.
		return convertView;	// convertView��Ԃ�.
	}
	
}

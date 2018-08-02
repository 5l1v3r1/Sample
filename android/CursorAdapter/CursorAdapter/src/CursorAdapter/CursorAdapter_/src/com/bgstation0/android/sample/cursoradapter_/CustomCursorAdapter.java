package com.bgstation0.android.sample.cursoradapter_;

import android.content.Context;
import android.database.Cursor;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CursorAdapter;
import android.widget.TextView;

public class CustomCursorAdapter extends CursorAdapter {

	// �����o�t�B�[���h�̒�`.
	private LayoutInflater mInflater = null;	// mInflater��null���Z�b�g.
	
	// �T�u�N���X�̒�`.
	private class ViewHolder{
		TextView name;	// ���Oname.
		TextView age;	// �N��age.
	}
	
	// �R���X�g���N�^.
	public CustomCursorAdapter(Context context, Cursor c, boolean autoRequery){
		super(context, c, autoRequery);	// �e�R���X�g���N�^���Ă�.
		mInflater = (LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);	// mInflater�̐���.
	}
	
	// View�̐���.
	@Override
	public View newView(Context context, Cursor cursor, ViewGroup parent) {

		// TODO Auto-generated method stub
		// View�̐���.
		final View view = mInflater.inflate(R.layout.list_item, null);	// view����.
		
		// ViewHolder�̐���.
		ViewHolder viewHolder = new ViewHolder();	// viewHolder�̐���.
		viewHolder.name = (TextView)view.findViewById(R.id.list_item_name);	// list_item_name�ŕ\�����TextView��viewHolder.name�ɃZ�b�g.
		viewHolder.age = (TextView)view.findViewById(R.id.list_item_age);	// list_item_age�ŕ\�����TextView��viewHolder.age�ɃZ�b�g.
		
		// ViewHolder���^�O�ɃZ�b�g.
		view.setTag(viewHolder);	// viewHolder���Z�b�g.
		
		// view��Ԃ�.
		return view;	// view��Ԃ�.
		
	}

	// View�̍ė��p.
	@Override
	public void bindView(View view, Context context, Cursor cursor) {
		
		// TODO Auto-generated method stub
		// �^�O����ViewHolder�̎擾.
		ViewHolder viewHolder = (ViewHolder)view.getTag();	// viewHolder�̎擾.
		
		// Cursor����l�����o��.
		final String name = cursor.getString(cursor.getColumnIndex("name"));	// name���擾.
		final String age = String.valueOf(cursor.getInt(cursor.getColumnIndex("age")));	// age���擾.
		
		// View�ɃZ�b�g.
		viewHolder.name.setText(name);	// name���Z�b�g.
		viewHolder.age.setText(age);	// age���Z�b�g.
		
	}

}
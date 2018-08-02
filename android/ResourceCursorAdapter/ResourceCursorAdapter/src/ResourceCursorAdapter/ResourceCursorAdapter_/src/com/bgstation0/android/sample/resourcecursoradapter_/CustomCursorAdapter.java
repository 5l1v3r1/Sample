package com.bgstation0.android.sample.resourcecursoradapter_;

import android.content.Context;
import android.database.Cursor;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ResourceCursorAdapter;
import android.widget.TextView;

public class CustomCursorAdapter extends ResourceCursorAdapter {

	// �T�u�N���X�̒�`.
	private class ViewHolder{
		TextView name;	// ���Oname.
		TextView age;	// �N��age.
	}
		
	// �R���X�g���N�^.
	public CustomCursorAdapter(Context context, int layout, Cursor c){
		super(context, layout, c, 0);	// �e�R���X�g���N�^���Ă�.
	}
		
	// View�̐���.
	@Override
	public View newView(Context context, Cursor cursor, ViewGroup parent) {
		
		// View�̐���.
		final View view = super.newView(context, cursor, parent);	// �e�N���X��newView��view����.
		
		// ViewHolder�̐���.
		ViewHolder viewHolder = new ViewHolder();	// viewHolder�̐���.
		viewHolder.name = (TextView)view.findViewById(R.id.list_item_name);	// list_item_name�ŕ\�����TextView��viewHolder.name�ɃZ�b�g.
		viewHolder.age = (TextView)view.findViewById(R.id.list_item_age);	// list_item_age�ŕ\�����TextView��viewHolder.age�ɃZ�b�g.
		
		// ViewHolder���^�O�ɃZ�b�g.
		view.setTag(viewHolder);	// viewHolder���Z�b�g.
				
		// view��Ԃ�.	
		return view;	// view��Ԃ�.
		
	}
		
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

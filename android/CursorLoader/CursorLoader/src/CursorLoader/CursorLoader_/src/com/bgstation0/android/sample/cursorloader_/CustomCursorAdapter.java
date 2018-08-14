package com.bgstation0.android.sample.cursorloader_;

import android.content.Context;
import android.database.Cursor;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CursorAdapter;
import android.widget.TextView;

public class CustomCursorAdapter extends CursorAdapter {

	// メンバフィールドの定義.
	private LayoutInflater mInflater = null;	// mInflaterにnullをセット.
	private Context mContext = null;	// mContextにnullをセット.
	
	// サブクラスの定義.
	private class ViewHolder{
		TextView text1;	// text1.
		TextView text2;	// text2.
	}
	
	// コンストラクタ.
	public CustomCursorAdapter(Context context, Cursor cursor, boolean autoRequery){
		super(context, cursor, autoRequery);	// 親コンストラクタを呼ぶ.
		mInflater = (LayoutInflater)context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);	// mInflaterの生成.
		mContext = context;	// mContextにcontextをセット.
	}
	
	// Viewの生成.
	@Override
	public View newView(Context context, Cursor cursor, ViewGroup parent) {

		// TODO Auto-generated method stub
		// Viewの生成.
		final View view = mInflater.inflate(R.layout.list_item, null);	// view生成.
		
		// ViewHolderの生成.
		ViewHolder viewHolder = new ViewHolder();	// viewHolderの生成.
		viewHolder.text1 = (TextView)view.findViewById(R.id.list_item_text1);	// list_item_text1で表されるTextViewをviewHolder.text1にセット.
		viewHolder.text2 = (TextView)view.findViewById(R.id.list_item_text2);	// list_item_text2で表されるTextViewをviewHolder.text2にセット.
		
		// ViewHolderをタグにセット.
		view.setTag(viewHolder);	// viewHolderをセット.
		
		// viewを返す.
		return view;	// viewを返す.
		
	}

	// Viewの再利用.
	@Override
	public void bindView(View view, Context context, Cursor cursor) {
		
		// TODO Auto-generated method stub
		// タグからViewHolderの取得.
		ViewHolder viewHolder = (ViewHolder)view.getTag();	// viewHolderの取得.
		
		// Cursorから値を取り出す.
		final String text1 = cursor.getString(cursor.getColumnIndex("text1"));	// text1を取得.
		final String text2 = cursor.getString(cursor.getColumnIndex("text2"));	// text2を取得.
		
		// Viewにセット.
		viewHolder.text1.setText(text1);	// text1をセット.
		viewHolder.text2.setText(text2);	// text2をセット.
		
	}

}
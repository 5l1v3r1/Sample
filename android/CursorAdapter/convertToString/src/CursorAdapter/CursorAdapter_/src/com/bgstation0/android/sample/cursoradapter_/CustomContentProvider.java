package com.bgstation0.android.sample.cursoradapter_;

import android.content.SearchRecentSuggestionsProvider;

public class CustomContentProvider extends SearchRecentSuggestionsProvider {

	// �����o�t�B�[���h�̒�`.
	public final static String AUTHORITY = "com.bgstation0.android.sample.cursoradapter_.CustomContentProvider";
	public final static int MODE =  DATABASE_MODE_QUERIES | DATABASE_MODE_2LINES;	// DATABASE_MODE_2LINES��ǉ�.
	
	// �R���X�g���N�^
	public CustomContentProvider(){
		
		// ����������.
		super();	// �e�N���X�̃R���X�g���N�^���Ă�.
		setupSuggestions(AUTHORITY, MODE);	// setupSuggestions��AUTHORITY��MODE���Z�b�g����, �Z�b�g�A�b�v.
		
	}
	
}
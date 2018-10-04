package com.bgstation0.android.sample.aaa_;

import android.accounts.AbstractAccountAuthenticator;
import android.accounts.Account;
import android.accounts.AccountAuthenticatorResponse;
import android.accounts.AccountManager;
import android.accounts.NetworkErrorException;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

public class CustomAuthenticator extends AbstractAccountAuthenticator {

	// �����o�t�B�[���h�̒�`.
	final Context mContext;	// mContext.
	
	// �R���X�g���N�^
	public CustomAuthenticator(Context context){
		super(context);	// �e�R���X�g���N�^��context��n��.
		mContext = context;	// mContext�Ɋi�[.
	}
	
	@Override
	public Bundle editProperties(AccountAuthenticatorResponse response,
			String accountType) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Bundle addAccount(AccountAuthenticatorResponse response,
			String accountType, String authTokenType,
			String[] requiredFeatures, Bundle options)
			throws NetworkErrorException {
		// TODO Auto-generated method stub
		// ���O�C����ʂ��N������C���e���g�̍쐬.
		Intent intent = new Intent(mContext, MainActivity.class);	// intent�̍쐬.
		intent.putExtra(AccountManager.KEY_ACCOUNT_AUTHENTICATOR_RESPONSE, response);	// response��o�^.
		// intent��bundle�ɓ���ĕԂ�.
		Bundle bundle = new Bundle();	// bundle�𐶐�.
		bundle.putParcelable(AccountManager.KEY_INTENT, intent);	// intent��o�^.
		return bundle;	// bundle��Ԃ�.
	}

	@Override
	public Bundle confirmCredentials(AccountAuthenticatorResponse response,
			Account account, Bundle options) throws NetworkErrorException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Bundle getAuthToken(AccountAuthenticatorResponse response,
			Account account, String authTokenType, Bundle options)
			throws NetworkErrorException {
		// TODO Auto-generated method stub
		AccountManager accountManager = AccountManager.get(mContext);	// accountManager���擾.
		String name = account.name;	// name���擾.
		String password = accountManager.getPassword(account);	// password���擾.
		String token = "TEST_TOKEN";	// token��"TEST_TOKEN"�Ƃ���.
		accountManager.setAuthToken(account, authTokenType, token);	// token���Z�b�g.
		// bundle�ŕԋp.
		Bundle bundle = new Bundle();	// bundle�𐶐�.
		bundle.putString(AccountManager.KEY_ACCOUNT_NAME, name);	// name��o�^.
		bundle.putString(AccountManager.KEY_ACCOUNT_TYPE, "com.bgstation0.android.sample");	// type��o�^.
		bundle.putString(AccountManager.KEY_AUTHTOKEN, token);	// token��o�^.
		return bundle;	// bundle��Ԃ�.
	}

	@Override
	public String getAuthTokenLabel(String authTokenType) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Bundle updateCredentials(AccountAuthenticatorResponse response,
			Account account, String authTokenType, Bundle options)
			throws NetworkErrorException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Bundle hasFeatures(AccountAuthenticatorResponse response,
			Account account, String[] features) throws NetworkErrorException {
		// TODO Auto-generated method stub
		return null;
	}

}

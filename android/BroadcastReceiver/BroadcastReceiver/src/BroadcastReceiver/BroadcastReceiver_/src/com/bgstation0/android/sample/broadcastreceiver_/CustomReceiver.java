package com.bgstation0.android.sample.broadcastreceiver_;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.widget.Toast;

public class CustomReceiver extends BroadcastReceiver {

	@Override
	public void onReceive(Context context, Intent intent) {
		// TODO Auto-generated method stub
		// �󂯎�����u���[�h�L���X�g�C���e���g��ACTION_AIRPLANE_MODE_CHANGED�����m�F.
		if (intent.getAction().equals(Intent.ACTION_AIRPLANE_MODE_CHANGED)){
			Toast.makeText(context, "Received! ACTION_AIRPLANE_MODE_CHANGED", Toast.LENGTH_LONG).show();	// Toast��"Received! ACTION_AIRPLANE_MODE_CHANGED"�ƕ\��.
		}
	}

}

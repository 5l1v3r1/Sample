package com.bgstation0.android.sample.webchromeclient_;

import android.app.Activity;
import android.content.Context;
import android.os.Message;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

public class CustomWebChromeClient extends WebChromeClient {

	// メンバフィールドの定義
	private Context context;	// Context型context
	private TextView progressTextView;	// TextView型progressTextView
	private ProgressBar progressBar;	// ProgressBar型progressBar.
	
	// コンストラクタ
	public CustomWebChromeClient(Context context){
		
		// メンバの初期化
		this.context = context;	// 引数のcontextをメンバのcontextにセット.
		Activity activity = (Activity)context;	// contextをActivity型のactivityにキャスト.
		progressTextView = (TextView)activity.findViewById(R.id.progresstextview);	// progressTextViewを取得.
		progressBar = (ProgressBar)activity.findViewById(R.id.progressbar);	// findViewByIdでR.id.progressbarを取得し, progressBarに格納.
		
	}
	
	// ロードの進捗が変化した時.
	@Override
	public void onProgressChanged(WebView view, int newProgress){
		
		// 進捗の更新.
		progressTextView.setText(newProgress + "%");	// progressTextView.setTextでnewProgressを"%"を付けて表示.
		progressBar.setProgress(newProgress);	// progressBar.setProgressで進捗にnewProgressをセット.
		
	}
	
	// ウィンドウ作成時.
	@Override
	public boolean onCreateWindow(WebView view, boolean dialog, boolean userGesture, Message resultMsg){
		
		// "onCreateWindow"を表示.
		Activity activity = (Activity)context;	// contextをActivity型のactivityにキャスト.
		String url = view.getUrl();	// 元のWebViewがロードしている(表示している)URL.(リンク先ではないので注意!)
		Toast.makeText(activity, "onCreateWindow, url = " + url, Toast.LENGTH_LONG).show();	// "onCreateWindow"とurlを表示.
		WebView.HitTestResult hr = view.getHitTestResult();	// リンク先はHitTestResultに.
		Toast.makeText(activity, "new url = " + hr.getExtra(), Toast.LENGTH_LONG).show();	// hr.getExtraを表示.
		
		// 開いた先に制御が行っても, こちらも反応するようにfalseにする.
		return false;	// falseを返す.
		
	}
	
}
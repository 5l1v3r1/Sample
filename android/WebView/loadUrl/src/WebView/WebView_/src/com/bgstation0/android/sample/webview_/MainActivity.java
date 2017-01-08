package com.bgstation0.android.sample.webview_;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.webkit.WebView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // WebView�Ń��[�J��HTML�t�@�C����\��.
        WebView webView = (WebView)findViewById(R.id.webview);	// findViewById��webView���擾.
        webView.loadUrl("file:///android_asset/test.html");	// webView.loadUrl��assets�t�H���_��test.html�����[�h.
    }
}

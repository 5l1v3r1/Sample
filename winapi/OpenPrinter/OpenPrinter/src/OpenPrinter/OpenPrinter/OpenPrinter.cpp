// ヘッダファイルのインクルード
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 変数の宣言と初期化.
	DWORD dwSize = 0;	// サイズdwSizeを0で初期化.
	TCHAR *ptszBuf = NULL;	// 文字列バッファポインタptszBufをNULLで初期化.
	BOOL bOpen = FALSE;	// BOOL型のbOpenをFALSEで初期化.
	HANDLE hPrinter = NULL;	// HANDLE型hPrinterをNULLで初期化.

	// バッファサイズを取得.
	GetDefaultPrinter(NULL, &dwSize);	// GetDefaultPrinterにNULLを渡してバッファサイズを取得.

	// バッファの確保.
	ptszBuf = new TCHAR[dwSize];	// サイズdwSize分のバッファ確保.

	// 既定のプリンタ名を取得.
	GetDefaultPrinter(ptszBuf, &dwSize);	// GetDefaultPrinterでプリンタ名を取得し, バッファに格納.

	// 既定のプリンタ名の出力.
	_tprintf(_T("Default Printer: %s\n"), ptszBuf);	// ptszBufを出力.

	// プリンタを開く.
	bOpen = OpenPrinter(ptszBuf, &hPrinter, NULL);	// OpenPrinterでプリンタ名ptszBufとなるプリンタを開く.
	if (bOpen){	// プリンタを開けたら.
		if (hPrinter != NULL){	// NULLではない.
			_tprintf(_T("hPrinter = 0x%08x\n"), (unsigned long)hPrinter);	// hPrinterの値を出力.
			ClosePrinter(hPrinter);	// ClosePrinterでhPrinterを閉じる.
		}
	}

	// バッファの解放.
	delete[] ptszBuf;	// ptszBufの解放.

	// プログラムの終了.
	return 0;

}
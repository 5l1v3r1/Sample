/* ヘッダファイルのインクルード */
#include <stdio.h> /* C標準入出力 */
#include <unistd.h> /* UNIX標準 */
#include <X11/Xlib.h> /* Xlib */

/* main関数 */
int main(void){

  /* 変数の宣言 */
  Display *d; /* Display構造体へのポインタd. */
  Window wr; /* ウィンドウ生成の結果を表す値wr.(Window == XID == unsigned long) */
  int result; /* マップの結果result. */
  unsigned long white; /* 白のRGB値white. */

  /* Xサーバとの接続. */
  d = XOpenDisplay(NULL); /* XOpenDisplayでXサーバに接続し, 戻り値のアドレスをdに格納. */

  /* dを出力. */
  printf("d = %08x\n", d); /* dの値を16進数で出力. */

  /* 白のRGB値を取得. */
  white = XWhitePixel(d, 0); /* XWhitePixelでスクリーン0における白のRGB値を取得し, whiteに格納. */

  /* ウィンドウの生成. */
  wr = XCreateSimpleWindow(d, DefaultRootWindow(d), 100, 100, 640, 480, 1, white, white); /* XCreateSimpleWindowでウィンドウ生成し, 結果はwrに格納.(DefaultRootWindowでルートウィンドウを取得.) */

  /* ウィンドウ生成の結果を出力. */
  printf("wr = %08x\n", wr); /* wrを出力. */

  /* ウィンドウのマッピング(表示要求) */
  result = XMapWindow(d, wr); /* XMapWindowでマッピング. */

  /* マッピング結果を出力. */
  printf("result = %d\n", result); /* resultの値を出力. */

  /* 表示要求イベントをフラッシュ. */
  XFlush(d); /* XFlushでフラッシュ. */

  /* 10秒待つ. */
  printf("sleep 10 seconds...\n"); /* "sleep 10 seconds..."と出力. */
  sleep(10); /* sleepで10秒休止. */

  /* Xサーバとの接続を終了する. */
  XCloseDisplay(d); /* XCloseDisplayで切断する. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

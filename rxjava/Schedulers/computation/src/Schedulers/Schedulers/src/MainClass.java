import rx.Observable;
import rx.Subscriber;
import rx.schedulers.Schedulers;

// メインクラス
class MainClass {	// MainClassクラスの定義

	// Javaのエントリポイント
	public static void main(String[] args) {	// mainメソッドの定義

		// スレッド名とIDの出力.
		System.out.println("[1]:id = " + Thread.currentThread().getId() + ", name = " + Thread.currentThread().getName());	// idとnameの出力.

		// オブザーバブルの生成.
		Observable<Integer> observable = Observable.create(new Observable.OnSubscribe<Integer>() {	// createの引数で発行処理を書く.

			@Override
			public void call(Subscriber<? super Integer> arg0) {
				// TODO 自動生成されたメソッド・スタブ
				// tryで囲む.
				try {

					// スレッド名とIDの出力.
					System.out.println("[2]:id = " + Thread.currentThread().getId() + ", name = " + Thread.currentThread().getName());	// idとnameの出力.

					// 発行と完了通知.
					arg0.onNext(1);	// 1を発行.
					arg0.onNext(2);	// 2を発行.
					arg0.onNext(3);	// 3を発行.
					arg0.onCompleted();	// 完了通知.

				}
				catch (Exception e) {	// 例外をcatchで拾う.
					arg0.onError(e);	// エラー通知.
				}
			}

		})
		.subscribeOn(Schedulers.computation());	// キャッシュされたスレッド(I/O以外)で実行.

		// スレッド名とIDの出力.
		System.out.println("[3]:id = " + Thread.currentThread().getId() + ", name = " + Thread.currentThread().getName());	// idとnameの出力.

		// 登録.
		observable.subscribe(x -> {

			// スレッド名とIDの出力.
			System.out.println("[4]:id = " + Thread.currentThread().getId() + ", name = " + Thread.currentThread().getName());	// idとnameの出力.

			// 通知された値の出力.
			System.out.println(x);

		},e -> {
			new Exception(e);
		}, () -> {
			System.out.println("Completed!");
		});	// subscribeでxを出力するようなアクションを登録.(エラー通知と完了通知も登録.)

		// スレッド名とIDの出力.
		System.out.println("[5]:id = " + Thread.currentThread().getId() + ", name = " + Thread.currentThread().getName());	// idとnameの出力.

	}

}
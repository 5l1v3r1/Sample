﻿// 名前空間の登録
using System;   // 共通データ型と基本クラス(System名前空間)
using System.Collections.Generic;   // ジェネリクスコレクションクラス(System.Collections.Generic名前空間)
using System.Linq;  // LINQクラス(System.Linq名前空間)

// メインクラス
class MainClass // MainClassの定義
{

    // メインメソッド
    static void Main()  // Mainメソッドの定義
    {

        // ボディリストの生成.
        var bodies = new List<Body>();  // BodyクラスのListを生成し, bodiesに格納.

        // ボディの追加.
        bodies.Add(new Body("Taro", 30, 170, 60));  // bodies.Addで"Taro"なBodyオブジェクトを追加.
        bodies.Add(new Body("Jiro", 28, 160, 68));  // bodies.Addで"Jiro"なBodyオブジェクトを追加.
        bodies.Add(new Body("Saburo", 25, 180, 70));    // bodies.Addで"Saburo"なBodyオブジェクトを追加.
        bodies.Add(new Body("Shiro", 19, 156, 50)); // bodies.Addで"Shiro"なBodyオブジェクトを追加.
        bodies.Add(new Body("Goro", 17, 175, 65));  // bodies.Addで"Goro"なBodyオブジェクトを追加.

        // LINQで身長170以上のボディの名前を出力.
        bodies.Where(x => x.Height >= 170).Select(x => x.Name).ToList().ForEach(x => Console.WriteLine(x)); // 身長170以上の名前xを出力.

    }

}
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using System.Reactive.Subjects;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Observable_
{
    class Program
    {
        // メインメソッド
        static void Main(string[] args)
        {

            // 1から10までの偶数だけを発行.
            var observable1 = Observable.Range(1, 10).Where(x => x % 2 == 0);    // 偶数を発行.

            // 発行された値が来たら出力.
            var subscriber1 = observable1.Subscribe(x => Console.WriteLine("x = " + x));  // xを出力.

            // 停止.
            subscriber1.Dispose();   // 解放.

            // 偶数だけ通すサブジェクト.
            var subject1 = new Subject<int>();  // subject1を生成.

            // Whereで偶数だけ通す.
            subject1.Where(y => y % 2 == 0).Subscribe(y => Console.WriteLine("y = " + y));  // yを出力.

            // 発行.
            subject1.OnNext(1);     // 1を発行.
            subject1.OnNext(2);     // 2を発行.
            subject1.OnNext(3);     // 3を発行.
            subject1.OnNext(4);     // 4を発行.
            subject1.OnNext(5);     // 5を発行.
            subject1.OnNext(6);     // 6を発行.
            subject1.OnNext(7);     // 7を発行.
            subject1.OnNext(8);     // 8を発行.
            subject1.OnNext(9);     // 9を発行.
            subject1.OnNext(10);    // 10を発行.

            // 停止.
            subject1.Dispose(); // 解放.

        }
    }
}
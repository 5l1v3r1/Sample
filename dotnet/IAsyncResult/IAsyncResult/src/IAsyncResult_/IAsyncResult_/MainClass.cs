// ���O��Ԃ̓o�^
using System;           // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Threading; // �}���`�X���b�h(System.Threading���O���)

// �f���Q�[�g�̒�`.
delegate void AsyncronousFuncDelegate();   // �����Ɩ߂�l�������֐������f���Q�[�gAsyncronousFuncDelegate.

// MainClass�̒�`
class MainClass
{
    // Main���\�b�h�̒�`
    static void Main()
    {

        // �f���Q�[�g�̐���.
        AsyncronousFuncDelegate asyncronousFunc = new AsyncronousFuncDelegate(AsyncronousFunc); // AsyncronousFunc��񓯊����s����AsyncronousFuncDelegate�I�u�W�F�N�gasyncronousFunc�𐶐�.

        // �񓯊������̎��s.
        IAsyncResult iar = asyncronousFunc.BeginInvoke(null, null);    // �R���p�C���ɂ���Đ������ꂽasyncronousFunc.BeginInvoke�Ŕ񓯊����s��, �߂�l��IAsyncResult�I�u�W�F�N�g��iar�Ɋi�[.

        // �񓯊������̏�Ԃ��Ď�.
        while (!iar.IsCompleted)    // iar.IsCompleted��false�̎��͌J�肩����.
        {

            // "AsyncronousFunc Running..."�̏o��.
            Console.WriteLine("AsyncronousFunc Running...");    // Console.WriteLine��"AsyncronousFunc Running..."���o��.

            // 1�b�x�~.
            Thread.Sleep(1000);    // Thread.Sleep��1000�~���b(1�b)�x�~.

        }

        // �񓯊������͊������Ă���̂ł����I���.
        asyncronousFunc.EndInvoke(iar); // asyncronousFunc.EndInvoke�Ŋ����܂ő҂�.(iar.IsCompleted��true�ɂȂ�, �����ɔ����Ă��Ă�̂�, �����I���.)

        // "Finish!"�̏o��.
        Console.WriteLine("Finish!");   // Console.WriteLine��"Finish!"�Əo��.


    }

    // �񓯊������X�^�e�B�b�N���\�b�hAsyncronousFunc.
    static void AsyncronousFunc()
    {

        // "AsyncronousFunc(1)"�`"AsyncronousFunc(5)"���o��.
        for (int i = 1; i <= 5; i++)    // i��1����5�܂ŌJ��Ԃ�.
        {

            // "AsyncronousFunc(i)"�̏o��.
            Console.WriteLine("AsyncronousFunc(" + i + ")");   // Console.WriteLine��"AsyncronousFunc(i)"���o��.

            // 1�b�x�~.
            Thread.Sleep(1000);    // Thread.Sleep��1000�~���b(1�b)�x�~.

        }

    }

}
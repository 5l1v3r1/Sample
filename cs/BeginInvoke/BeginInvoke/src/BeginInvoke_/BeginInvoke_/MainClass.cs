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

        // "Main(1)"�`"Main(3)"���o��.
        for (int i = 1; i <= 3; i++)    // i��1����3�܂ŌJ��Ԃ�.
        {

            // "Main(i)"�̏o��.
            Console.WriteLine("Main(" + i + ")");   // Console.WriteLine��"Main(i)"���o��.

            // 1�b�x�~.
            Thread.Sleep(1000);    // Thread.Sleep��1000�~���b(1�b)�x�~.

        }

        // �񓯊������̊����܂őҋ@.
        asyncronousFunc.EndInvoke(iar); // asyncronousFunc.EndInvoke�Ŋ����܂ő҂�.(iar��n��.)

        // "Finish!"�Əo��.
        Console.WriteLine("Finish!");   // "Finish!"�Əo��.

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
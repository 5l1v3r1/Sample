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

        // �񓯊������Ŏ��s����f���Q�[�gasyncronousFunc�̐���.
        AsyncronousFuncDelegate asyncronousFunc = new AsyncronousFuncDelegate(AsyncronousFunc); // AsyncronousFunc��񓯊����s����AsyncronousFuncDelegate�I�u�W�F�N�gasyncronousFunc�𐶐�.

        // �񓯊������̊�����Ɏ��s����AsyncCallback�f���Q�[�gcallback�̐���.
        AsyncCallback callback = new AsyncCallback(AsyncCallbackFunc);  // �񓯊������������AsyncCallbackFunc�����s����AsyncCallback�I�u�W�F�N�gcallback�𐶐�.

        // �񓯊������̎��s.
        IAsyncResult iar = asyncronousFunc.BeginInvoke(callback, null);    // �R���p�C���ɂ���Đ������ꂽasyncronousFunc.BeginInvoke�Ŕ񓯊����s��, �߂�l��IAsyncResult�I�u�W�F�N�g��iar�Ɋi�[.(�񓯊����s������̃R�[���o�b�N�֐�callback��n��.)

        // �񓯊������̊����܂őҋ@.
        asyncronousFunc.EndInvoke(iar); // asyncronousFunc.EndInvoke�Ŋ����܂ő҂�.(iar��n��.)

        // AsyncCallbackFunc�̏������c���Ă�̂�3�b�҂�.
        Thread.Sleep(3000); // Thread.Sleep��3�b�x�~.

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

    // �񓯊�����������̃X�^�e�B�b�N�R�[���o�b�N���\�b�hAsyncCallbackFunc.
    static void AsyncCallbackFunc(IAsyncResult ar)
    {

        // "AsyncCallbackFunc!"�Əo��.
        Console.WriteLine("AsyncCallbackFunc!");    // Console.WriteLine��"AsyncCallbackFunc!"�Əo��.

    }

}
// ���O��Ԃ̓o�^
using System;                               // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Runtime.Remoting.Messaging;    // AsyncResult�N���X(System.Runtime.Remoting.Messaging���O���)
using System.Threading;                     // �}���`�X���b�h(System.Threading���O���)

// �f���Q�[�g�̒�`.
delegate int AsyncronousFuncDelegate(int a, int b);   // ������int�^a, b��, �߂�l��int�Ȋ֐������f���Q�[�gAsyncronousFuncDelegate.

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
        IAsyncResult iar = asyncronousFunc.BeginInvoke(10, 20, callback, null);    // �R���p�C���ɂ���Đ������ꂽasyncronousFunc.BeginInvoke�Ŕ񓯊����s��, �߂�l��IAsyncResult�I�u�W�F�N�g��iar�Ɋi�[.(�����Ƃ���10, 20��n��, ����ɔ񓯊����s������̃R�[���o�b�N�֐�callback��n��.)

        // "AsyncronousFunc..."�Əo��.
        Console.WriteLine("AsyncronousFunc...");    // Console.WriteLine��"AsyncronousFunc..."�Əo��.

        // Main���������I����Ă��܂��̂�, �����L�[�����͂����܂ő҂�.
        Console.ReadKey();  // Console.ReadKey�œ��͂����܂ő҂�.

    }

    // �񓯊������X�^�e�B�b�N���\�b�hAsyncronousFunc.
    static int AsyncronousFunc(int a, int b)
    {

        // 3�b�x�~.
        Thread.Sleep(3000);    // Thread.Sleep��3�b�x�~.

        // a��b�̑��������ʂ�Ԃ�.
        return a + b;   // a + b��Ԃ�.

    }

    // �񓯊�����������̃X�^�e�B�b�N�R�[���o�b�N���\�b�hAsyncCallbackFunc.
    static void AsyncCallbackFunc(IAsyncResult ar)
    {

        // IAsyncResult�^ar��AsyncResult�ɃL���X�g.
        AsyncResult asyncRes = (AsyncResult)ar; // ar��AsyncResult�^asyncRes�ɃL���X�g.

        // �񓯊������Ŏg�����f���Q�[�g���擾.
        AsyncronousFuncDelegate asyncronousFunc = (AsyncronousFuncDelegate)asyncRes.AsyncDelegate;   // asyncRes.AsyncDelegate���L���X�g����asyncronousFunc���擾.

        // �񓯊������̌��ʂ��擾.(�񓯊������͊������Ă�̂ł����I���.)
        int result = asyncronousFunc.EndInvoke(ar); // asyncronousFunc.EndInvoke�Ō���result���擾.

        // ���ʂ̏o��.
        Console.WriteLine("result = " + result);    // Console.WriteLine��result���o��.

    }

}
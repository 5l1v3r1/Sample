// ���O��Ԃ̓o�^
using System;           // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Threading; // �}���`�X���b�h(System.Threading���O���)

// MainClass�̒�`
class MainClass
{
    // Main���\�b�h�̒�`
    static void Main()
    {

        // �X���b�h�̐���.
        Thread thread = new Thread(new ThreadStart(ThreadFunc));    // Thread�I�u�W�F�N�gthread���쐬.(�R���X�g���N�^�ɂ�ThreadStart�f���Q�[�g�̃R���X�g���N�^.����ɂ��̈�����ThreadFunc��n��.)

        // �X���b�h�̊J�n.
        thread.Start(); // thread.Start�ŃX���b�h�J�n.

        // 5��ManagedThreadId���o��.
        for (int i = 1; i <= 5; i++)    // i��1����5�܂ŌJ��Ԃ�.
        {

            // ManagedThreadId���o��.
            Console.WriteLine("Main Thread ID: " + Thread.CurrentThread.ManagedThreadId);   // Thread.CurrentThread.ManagedThreadId���o��.

            // 1�b�x�~.
            Thread.Sleep(1000);    // Thread.Sleep��1000�~���b(1�b)�x�~.

        }

    }

    // ���������X���b�h�Ŏ��s���郁�\�b�hThreadFunc�̒�`
    static void ThreadFunc()
    {

        // 5��ManagedThreadId���o��.
        for (int i = 1; i <= 5; i++)    // i��1����5�܂ŌJ��Ԃ�.
        {

            // ManagedThreadId���o��.
            Console.WriteLine("ThreadFunc Thread ID: " + Thread.CurrentThread.ManagedThreadId);   // Thread.CurrentThread.ManagedThreadId���o��.

            // 1�b�x�~.
            Thread.Sleep(1000);    // Thread.Sleep��1000�~���b(1�b)�x�~.

        }

    }

}
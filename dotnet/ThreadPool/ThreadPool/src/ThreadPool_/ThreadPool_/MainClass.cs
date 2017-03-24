// ���O��Ԃ̓o�^
using System;           // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Threading; // �}���`�X���b�h(System.Threading���O���)

// MainClass�̒�`
class MainClass
{
    // Main���\�b�h�̒�`
    static void Main()
    {

        // ThreadFunc������f���Q�[�g�̍쐬.
        WaitCallback waitCallback = new WaitCallback(ThreadFunc); // WaitCallback�f���Q�[�gwaitCallback���쐬��, �R���X�g���N�^��ThreadFunc��n��.

        // �X���b�h�v�[���Ƀ��[�N�A�C�e��(�^�X�N)��3�o�^.
        ThreadPool.QueueUserWorkItem(waitCallback); // ThreadPool.QueueUserWorkItem��waitCallback�̎���ThreadFunc�����s���郏�[�N�A�C�e����o�^.
        ThreadPool.QueueUserWorkItem(waitCallback); // ThreadPool.QueueUserWorkItem��waitCallback�̎���ThreadFunc�����s���郏�[�N�A�C�e����o�^.
        ThreadPool.QueueUserWorkItem(waitCallback); // ThreadPool.QueueUserWorkItem��waitCallback�̎���ThreadFunc�����s���郏�[�N�A�C�e����o�^.

        // "Main(1)�`Main(5)"�܂ŏo��.
        for (int i = 1; i <= 5; i++)    // i��1����5�܂ŌJ��Ԃ�.
        {

            // "Main"��i���o��.
            Console.WriteLine("Main(" + i + ")"); // "Main(i)"���o��.

            // 1�b�x�~.
            Thread.Sleep(1000);    // Thread.Sleep��1000�~���b(1�b)�x�~.

        }

        // ���炩�̃L�[���������܂őҋ@.
        Console.ReadKey();      // Console.ReadKey�ŃL�[���������܂Ńu���b�L���O.

    }

    // �X���b�h�v�[���Ŏ��s���郁�\�b�hThreadFunc�̒�`
    static void ThreadFunc(object state)
    {

        // "ThreadFunc(1)"�`"ThreadFunc(5)"�܂ŏo��.
        for (int i = 1; i <= 5; i++)    // i��1����5�܂ŌJ��Ԃ�.
        {

            // "ThreadFunc"��i���o��.
            Console.WriteLine("ThreadFunc(" + i + ")"); // "ThreadFunc(i)"���o��.

            // 1�b�x�~.
            Thread.Sleep(1000);    // Thread.Sleep��1000�~���b(1�b)�x�~.

        }

    }

}
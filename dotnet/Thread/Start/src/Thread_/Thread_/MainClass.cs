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
        Thread thread = new Thread(ThreadFunc);    // Thread�I�u�W�F�N�gthread���쐬.(�R���X�g���N�^�ɂ�ThreadFunc�����̂܂ܓn��.)

        // �X���b�h�Ɉ�����n���ĊJ�n.
        thread.Start(3); // thread.Start�ŃX���b�h�J�n.(3��n��.)

        // "Main(1)�`Main(5)"�܂ŏo��.
        for (int i = 1; i <= 5; i++)    // i��1����5�܂ŌJ��Ԃ�.
        {

            // "Main"��i���o��.
            Console.WriteLine("Main(" + i + ")"); // "Main(i)"���o��.

            // 1�b�x�~.
            Thread.Sleep(1000);    // Thread.Sleep��1000�~���b(1�b)�x�~.

        }

        // "Main Finished!"�Əo��.
        Console.WriteLine("Main Finished!"); // "Main Finished!"���o��.

    }

    // ���������X���b�h�Ŏ��s���郁�\�b�hThreadFunc�̒�`
    static void ThreadFunc(object data)
    {

        // "ThreadFunc(1)"�`"ThreadFunc(data)"�܂ŏo��.
        for (int i = 1; i <= (int)data; i++)    // i��1����data�܂ŌJ��Ԃ�.
        {

            // "ThreadFunc"��i���o��.
            Console.WriteLine("ThreadFunc(" + i + ")"); // "ThreadFunc(i)"���o��.

            // 1�b�x�~.
            Thread.Sleep(1000);    // Thread.Sleep��1000�~���b(1�b)�x�~.

        }

    }

}
// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.IO;    // �t�@�C�����o�͂ƃf�[�^�X�g���[��(System.IO���O���)

// MainClass�̒�`
class MainClass
{
    // Main���\�b�h�̒�`
    static void Main()
    {
        // �ϐ��̏�����
        Stream stream = null;           // Stream�N���X�ϐ�stream��null�ɏ�����.
        byte[] buf = new byte[128];     // byte�^�z��o�b�t�@(����128)

        // �t�@�C��"test.txt"����f�[�^��ǂݍ���.
        try
        {   // try�u���b�N
            stream = new FileStream("test.txt", FileMode.Open); // FileStream��"test.txt"���J����, �߂�l�̃X�g���[����stream�Ɋi�[.
            int len = stream.Read(buf, 0, 128);   // stream.Read��buf�ɓǂݍ���, �ǂݍ��񂾃f�[�^�̒������߂�l�Ƃ��ĕԂ�̂�, �����len�Ɋi�[.
            for (int i = 0; i < len; i++)
            {   // len���J��Ԃ�.
                Console.Write((char)buf[i]); // buf�̗v�f��1����char�ɃL���X�g���ďo��.
            }
            Console.WriteLine();    // ���s.
            stream.Close(); // stream.Close�ŕ���.
        }
        catch (Exception e) // Exception�ł����Ă��E����.
        {
            // ��O���e�̏o��.
            Console.WriteLine(e.ToString());    // e.ToString()�̓��e���o��.
            if (stream != null)
            {   // stream�I�u�W�F�N�g�������.
                stream.Close(); // �Ƃ肠��������.
            }
        }
    }
}
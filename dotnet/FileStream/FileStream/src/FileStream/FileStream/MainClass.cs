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
        FileStream fs = null;           // FileStream�N���X�ϐ�fs��null�ɏ�����.
        byte[] buf = new byte[5];       // byte�^�z��o�b�t�@(����5)

        // buf�̊e�v�f�ɒl���Z�b�g.
        buf[0] = 0x41;   // 'A'
        buf[1] = 0x42;   // 'B'
        buf[2] = 0x43;   // 'C'
        buf[3] = 0x44;   // 'D'
        buf[4] = 0x45;   // 'E'

        // �t�@�C��"test.txt"�Ƀf�[�^��������.
        try
        {   // try�u���b�N
            fs = new FileStream("test.txt", FileMode.Create);   // FileStream��"test.txt"��FileMode.Create�ŊJ����, �߂�l�̃X�g���[����fs�Ɋi�[.
            fs.Write(buf, 0, 5);    // fs.Write��buf�̓��e����������.
            fs.Close(); // fs.Close�ŕ���.
        }
        catch (Exception e) // Exception�ł����Ă��E����.
        {
            // ��O���e�̏o��.
            Console.WriteLine(e.ToString());    // e.ToString()�̓��e���o��.
            if (fs != null)
            {   // fs�I�u�W�F�N�g�������.
                fs.Close(); // �Ƃ肠��������.
            }
        }
    }
}
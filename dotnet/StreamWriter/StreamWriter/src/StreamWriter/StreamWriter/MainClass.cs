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
        StreamWriter sw = null; // StreamWriter�N���X�ϐ�sw��null�ɏ�����.

        // �e�L�X�g�t�@�C��"test.txt"�ɕ��������������.
        try
        {   // try�u���b�N
            sw = new StreamWriter("test.txt");  // StreamWriter��"test.txt"���J����, �߂�l�̃��C�^��sw�Ɋi�[.
            sw.Write("����������"); // sw.Write�ŕ�����"����������"����������.
            sw.Close(); // sw.Close�ŕ���.
        }
        catch (Exception e) // Exception�ł����Ă��E����.
        {
            // ��O���e�̏o��.
            Console.WriteLine(e.ToString());    // e.ToString()�̓��e���o��.
            if (sw != null)
            {   // sw�I�u�W�F�N�g�������.
                sw.Close(); // �Ƃ肠��������.
            }
        }
    }
}
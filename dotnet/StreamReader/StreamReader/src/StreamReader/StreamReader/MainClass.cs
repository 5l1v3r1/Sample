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
        StreamReader sr = null; // StreamReader�N���X�ϐ�sr��null�ɏ�����.
        char[] buf = new char[128]; // char�^�z��o�b�t�@buf(����128)

        // �e�L�X�g�t�@�C��"test.txt"���當�����ǂݍ���.
        try
        {   // try�u���b�N
            sr = new StreamReader("test.txt");  // StreamReader��"test.txt"���J����, �߂�l�̃��[�_��sr�Ɋi�[.
            sr.Read(buf, 0, 128);   // sr.Read�ŕ������buf�ɓǂݍ���.
            Console.WriteLine(buf); // Console.WriteLine��buf�̓��e���o��.
            sr.Close(); // sr.Close�ŕ���.
        }
        catch (Exception e) // Exception�ł����Ă��E����.
        {
            // ��O���e�̏o��.
            Console.WriteLine(e.ToString());    // e.ToString()�̓��e���o��.
            if (sr != null)
            {   // sr�I�u�W�F�N�g�������.
                sr.Close(); // �Ƃ肠��������.
            }
        }
    }
}
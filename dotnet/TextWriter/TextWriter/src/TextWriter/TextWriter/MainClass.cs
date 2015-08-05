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
        FileStream fs = null;   // FileStream�N���X�ϐ�fs��null�ɏ�����.
        TextWriter tw = null;   // TextWriter�N���X�ϐ�tw��null�ɏ�����.

        // �e�L�X�g�t�@�C��"test.txt"�ɕ��������������.
        try
        {   // try�u���b�N
            fs = new FileStream("test.txt", FileMode.Create);   // FileStream��"test.txt"���J����, �߂�l�̃X�g���[����fs�Ɋi�[.
            tw = new StreamWriter(fs);  // StreamWriter�Ŏw��̃X�g���[��fs�Ƀe�L�X�g���������ރ��C�^���쐬, �߂�l�̃��C�^��tw�Ɋi�[.(�f�t�H���g�̃G���R�[�h��UTF-8.)
            tw.Write("����������"); // tw.Write�ŕ�����"����������"����������.
            tw.Close(); // tw.Close�ŕ���.
            fs.Close(); // fs.Close�ŕ���.
        }
        catch (Exception e) // Exception�ł����Ă��E����.
        {
            // ��O���e�̏o��.
            Console.WriteLine(e.ToString());    // e.ToString()�̓��e���o��.
            if (tw != null)
            {   // tw�I�u�W�F�N�g�������.
                tw.Close(); // �Ƃ肠��������.
            }
            if (fs != null)
            {   // fs�I�u�W�F�N�g�������.
                fs.Close(); // �Ƃ肠��������.
            }
        }
    }
}
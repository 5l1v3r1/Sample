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
        FileStream fs = null;       // FileStream�N���X�ϐ�fs��null�ɏ�����.
        TextReader tr = null;       // TextReader�N���X�ϐ�tr��null�ɏ�����.
        char[] buf = new char[128]; // char�^�z��o�b�t�@buf(����128)

        // �e�L�X�g�t�@�C��"test.txt"���當�����ǂݍ���.
        try
        {   // try�u���b�N
            fs = new FileStream("test.txt", FileMode.Open); // FileStream��"test.txt"���J����, �߂�l�̃X�g���[����fs�Ɋi�[.
            tr = new StreamReader(fs);  // StreamReader�Ŏw��̃X�g���[��fs����e�L�X�g��ǂݍ��ރ��[�_���쐬, �߂�l�̃��[�_��tr�Ɋi�[.(�f�t�H���g�̃G���R�[�h��UTF-8.)
            tr.Read(buf, 0, 128);   // tr.Read�ŕ������buf�ɓǂݍ���.
            Console.WriteLine(buf); // Console.WriteLine��buf�̓��e���o��.
            tr.Close(); // tr.Close�ŕ���.
            fs.Close(); // fs.Close�ŕ���.
        }
        catch (Exception e) // Exception�ł����Ă��E����.
        {
            // ��O���e�̏o��.
            Console.WriteLine(e.ToString());    // e.ToString()�̓��e���o��.
            if (tr != null)
            {   // tr�I�u�W�F�N�g�������.
                tr.Close(); // �Ƃ肠��������.
            }
            if (fs != null)
            {   // fs�I�u�W�F�N�g�������.
                fs.Close(); // �Ƃ肠��������.
            }
        }
    }
}
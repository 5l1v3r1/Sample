// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.IO;    // �t�@�C�����o�͂ƃf�[�^�X�g���[��(System.IO���O���)

// MainClass�̒�`
class MainClass
{
    // Main���\�b�h�̒�`
    static void Main()
    {
        // �t�@�C�������݂��Ă��邩�`�F�b�N.
        if (!File.Exists("test.txt"))   // File.Exist��"test.txt"�����݂��Ȃ��ꍇ.
        {
            // �t�@�C��"test.txt"���쐬.
            FileStream fs = File.Create("test.txt");    // File.Create��"test.txt"���쐬��, �߂�l��FileStream�^��fs�Ɋi�[.
            fs.Close();                                 // fs.Close�ŕ���.
            Console.WriteLine("Create File!");          // Console.WriteLine��"Create File!"�Əo��.
        }
        else
        {
            // ���݂���ꍇ.
            Console.WriteLine("File Exist!");          // Console.WriteLine��"File Exist!"�Əo��.
        }
    }
}
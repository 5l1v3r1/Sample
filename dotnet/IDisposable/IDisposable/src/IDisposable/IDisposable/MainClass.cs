// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {
        // �ϐ��̏�����.
        CustomReader cr = null; // CustomReader�^cr��null�ɏ�����.

        // CustomReader���쐬��, 2�t�@�C����ǂݍ���.
        cr = new CustomReader("test1.txt", "test2.txt");    // CustomReader��"test1.txt"��"text2.txt"��ǂݍ���.
        if (cr.ReadAll())   // cr.ReadAll()�œǂݍ��ݐ����Ȃ�.
        {
            Console.WriteLine("cr.text1 = " + cr.text1);    // cr.text1�̓��e���o��.
            Console.WriteLine("cr.text2 = " + cr.text2);    // cr.text2�̓��e���o��.
        }
    }
}
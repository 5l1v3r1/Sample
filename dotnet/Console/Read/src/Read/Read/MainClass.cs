// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// MainClass�̒�`
class MainClass
{
    // Main���\�b�h�̒�`
    static void Main()
    {
        // �ϐ��̐錾
        int c;  // ���͕����̃o�C�i���l���i�[����int�^�ϐ�c.

        // ���͕����̓ǂݎ��
        c = Console.Read(); // Console.Read�œ��͂��ꂽ�����̃o�C�i���l��int�^��c�Ɋi�[.

        // c�𕶎��Ƃ��ďo��.
        Console.Write((char)c); // c��char�ɃL���X�g���ĕ����Ƃ��ďo��.
        Console.Write('\n');    // ���s
    }
}
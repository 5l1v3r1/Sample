// �V���{���̒�`
#define TEST

// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // TEST����`�ς݂Ȃ�R���p�C���Ώ�.
#if TEST

        // "Test"�Əo��.
        Console.WriteLine("Test");  // Console.WriteLine��"Test"�Əo��.

#endif

        // "ABCDE"�Əo��.
        Console.WriteLine("ABCDE"); // Console.WriteLine��"ABCDE"�Əo��.

    }

}
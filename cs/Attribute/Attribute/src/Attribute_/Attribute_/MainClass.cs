// �V���{���̒�`
#define TEST

// ���O��Ԃ̓o�^
using System;               // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Diagnostics;   // �V�X�e���v���Z�X��C�x���g���O�Ƃ̑Θb���邽�߂̃N���X.(System.Diagnostics���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �����t�����\�b�hTest���Ă�.
        Test(); // Test���Ă�.

        // "ABCDE"�Əo��.
        Console.WriteLine("ABCDE"); // Console.WriteLine��"ABCDE"�Əo��.

    }

    // �����t�����\�b�hTest
    [Conditional("TEST")]   // ����Conditional("TEST")��, �V���{��"TEST"����`����Ă���ΌĂ΂��.
    static void Test()
    {

        // "Test"�Əo��.
        Console.WriteLine("Test");  // Console.WriteLine��"Test"�Əo��.

    }

}
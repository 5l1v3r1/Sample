// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // int�^��Int32�\���̂̃I�u�W�F�N�g�̐錾.
        int intType;        // int�^�ϐ�intType.
        Int32 intStruct;    // Int32�^�\���̕ϐ�intStruct.
        int intAfter;       // int�^�ϐ�intAfter.

        // �l�̑��.(������intType��intStruct�ɒl��ݒ肵���C���X�^���X���R�s�[�����̂�, ����ȑO�ł̓��\�b�h���ĂׂȂ�.)
        intType = 10;       // intType��10����.
        intStruct = 100;    // intStruct��100����.

        // �^(�\����)�����o��.
        Console.WriteLine("intType: " + intType.GetType().ToString());  // intType.GetType().ToString()�Ŏ擾�ł���^�����o��.
        Console.WriteLine("intStruct: " + intStruct.GetType().ToString());    // intStruct.GetType().ToString()�Ŏ擾�ł���\���̖����o��.

        // ��������p�[�X����, ���l���擾.
        intAfter = Int32.Parse("123");  // Int32.Parse��"123"���p�[�X����, ���l123��intAfter�ɑ��.
        Console.WriteLine("intAfter = " + intAfter);    // Console.WriteLine��intAfter���o��.

    }

}
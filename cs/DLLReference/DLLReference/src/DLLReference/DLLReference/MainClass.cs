// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using BGST; // �Ǝ����C�u����ClassLibrary�̖��O���BGST

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ClassLibraryClass�I�u�W�F�N�g�̍쐬.
        ClassLibraryClass clc = new ClassLibraryClass();    // ClassLibraryClass�I�u�W�F�N�gclc�̍쐬.

        // ���C�u�����ւ̃A�N�Z�X.
        int i = clc.number; // i��clc.number����.
        string str = clc.GetString();   // str��clc.GetString����.

        // �o��.
        Console.WriteLine("i = {0}, str = {1}", i, str);    // i��str���o��.

    }

}
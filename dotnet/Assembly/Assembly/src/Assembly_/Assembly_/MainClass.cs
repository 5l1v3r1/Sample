// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Reflection;    // ���t���N�V����(System.Reflection���O���)
using BGST; // �Ǝ����C�u����ClassLibrary�̖��O���BGST

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ClassLibraryClass��Assembly���擾.
        Type type = typeof(ClassLibraryClass);  // typeof��ClassLibraryClass��Type�I�u�W�F�N�gtype���擾.
        Assembly asm = type.Assembly;   // type.Assembly��Assembly�I�u�W�F�N�gasm���擾.
        Console.WriteLine("asm = " + asm);  // asm���o��.

    }

}
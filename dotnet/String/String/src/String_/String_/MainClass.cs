// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // string�^��String�N���X�̃I�u�W�F�N�g�̐錾.
        string strType;     // string�^�ϐ�strType.
        String strClass;    // String�N���X�I�u�W�F�N�gstrClass.

        // ������̑��.
        strType = "ABC";    // strType��"ABC"���i�[.
        strClass = "XYZ";   // strClass��"XYZ"���i�[.(�N���X����new���Ȃ��Ă�"XYZ"�ŃC���X�^���X���������.)

        // �^(�N���X)�����o��.
        Console.WriteLine("strType: " + strType.GetType().ToString());  // strType.GetType().ToString()�Ŏ擾�ł���^�����o��.
        Console.WriteLine("strClass: " + strClass.GetType().ToString());    // strClass.GetType().ToString()�Ŏ擾�ł���N���X�����o��.

        // 'B'���������ڂ����擾.
        int index = strType.IndexOf('B');   // strType.IndexOf��B�̈ʒu���擾.
        Console.WriteLine("index = " + index);  // index�̒l���o��.

    }

}
// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// �f���Q�[�g�̒�`.
delegate string BracketsDelegate(string message);   // �����Ɩ߂�l��string�Ȋ֐������f���Q�[�gBracketsDelegate.

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �ϐ��̐錾
        string str1;    // string�^str1.
        string str2;    // string�^str2.

        // �f���Q�[�g�̐���.
        BracketsDelegate brackets1 = new BracketsDelegate(Brackets1);       // new��BracketsDelegate��brackets1�𐶐�.(�R���X�g���N�^�ɂ�Brackets1��n��.)
        BracketsDelegate brackets2 = new BracketsDelegate(Brackets2);       // new��BracketsDelegate��brackets2�𐶐�.(�R���X�g���N�^�ɂ�Brackets2��n��.)

        // �f���Q�[�g�̎Q�ƂŃR�[���o�b�N���\�b�h���Ă΂��.
        str1 = brackets1("ABCDE");  // brackets1��"ABCDE"���w�肷���. �R�[���o�b�N���\�b�h��Brackets1���Ă΂��̂�, �߂�l��str1�Ɋi�[.
        str2 = brackets2("XYZ");    // brackets2��"XYZ"���w�肷���, �R�[���o�b�N���\�b�h��Brackets2���Ă΂��̂�, �߂�l��str2�Ɋi�[.

        // ���ʂ̏o��.
        Console.WriteLine("str1 = " + str1);    //  Console.WriteLine��str1���o��.
        Console.WriteLine("str2 = " + str2);    // Console.WriteLine��str2���o��.

    }

    // ����('('��')')�ň͂ޏꍇ�̃��\�b�hBrackets1.
    static string Brackets1(string message)
    {

        // ���ʂň͂񂾕������Ԃ�.
        return "(" + message + ")"; // message�����ʂň͂񂾕������Ԃ�.

    }

    // �^�O('<'��'>')�ň͂ޏꍇ�̃��\�b�hBrackets2.
    static string Brackets2(string message)
    {

        // �^�O�ň͂񂾕������Ԃ�.
        return "<" + message + ">"; // message���^�O�ň͂񂾕������Ԃ�.

    }

}
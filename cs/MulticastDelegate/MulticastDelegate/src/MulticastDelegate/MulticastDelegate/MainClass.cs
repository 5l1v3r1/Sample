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
        string str;    // string�^str.

        // �f���Q�[�g�̐���.
        BracketsDelegate brackets = new BracketsDelegate(Brackets1); // new��BracketsDelegate��brackets��Brackets1���Ăяo���f���Q�[�g���Z�b�g.
        brackets += new BracketsDelegate(Brackets2);    // new��brackets��Brackets2���Ăяo���f���Q�[�g��ǉ�.

        // �f���Q�[�g�̎Q�ƂŃR�[���o�b�N���\�b�h���Ă΂��.
        str = brackets("ABCDE");    // brackets��"ABCDE"���w�肷���, Brackets1��Brackets2�����ɗ����Ă΂��.(str�ɂ͌ォ��ǉ����ꂽ�f���Q�[�g�̂����\�b�h�̌��ʂ��Ԃ�.)

        // ���ʂ̏o��.
        Console.WriteLine("str = " + str);  // Console.WriteLine��str���o��.

    }

    // ����('('��')')�ň͂ޏꍇ�̃��\�b�hBrackets1.
    static string Brackets1(string message)
    {
        
        // �ϐ��̐錾
        string innerStr;    // string�^innerStr.

        // ���ʂ�t����.
        innerStr = message; // innerStr��message����.
        innerStr = "(" + innerStr + ")";    // ���ʂ�t����.
        Console.WriteLine("innerStr = " + innerStr);    // Console.WriteLine��innerStr���o��.

        // ���ʂň͂񂾕������Ԃ�.
        return innerStr;    // innerStr��Ԃ�.

    }

    // �^�O('<'��'>')�ň͂ޏꍇ�̃��\�b�hBrackets2.
    static string Brackets2(string message)
    {

        // �ϐ��̐錾
        string innerStr;    // string�^innerStr.

        // �^�O��t����.
        innerStr = message; // innerStr��message����.
        innerStr = "<" + innerStr + ">";    // �^�O��t����.
        Console.WriteLine("innerStr = " + innerStr);    // Console.WriteLine��innerStr���o��.

        // �^�O�ň͂񂾕������Ԃ�.
        return innerStr;    // innerStr��Ԃ�.

    }

}
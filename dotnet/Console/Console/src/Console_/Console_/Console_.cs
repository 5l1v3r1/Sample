// ���O��Ԃ̎w��
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(Console)

// Console_�N���X�̒�`
class Console_
{
    // Main���\�b�h�̒�`
    static void Main()
    {
        // Console.Write, Console.WriteLine�ɂ���{�I�ȕW���o��
        Console.Write("Console_\n");    // Console.Write��"Console_"���o��.(���s�������K�v)
        Console.WriteLine("Console_");  // Console.WriteLine��"Console_"���o��.(���s�������s�v)
        Console.WriteLine("{0}, {1}, {2}", "Console_(1)", "Console_(2)", "Console_(3)");    // �����w��q��3�̕����񃊃e�������o��.
        Console.WriteLine("{0:D}, {1:N}, {2:X}", 123, 0.25, 10);    // �����w��q��10�i����, ����, 16�i�������o��.
    }
}
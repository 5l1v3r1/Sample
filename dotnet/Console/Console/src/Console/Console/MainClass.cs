// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// MainClass�̒�`
class MainClass
{
    // Main���\�b�h�̒�`
    static void Main()
    {
        // Console.Write, Console.WriteLine�ɂ���{�I�ȕW���o��
        Console.Write("Console\n");    // Console.Write��"Console"���o��.(���s�������K�v)
        Console.WriteLine("Console");  // Console.WriteLine��"Console"���o��.(���s�������s�v)
        Console.WriteLine("{0}, {1}, {2}", "Console(1)", "Console(2)", "Console(3)");    // �����w��q��3�̕����񃊃e�������o��.
        Console.WriteLine("{0:D}, {1:N}, {2:X}", 123, 0.25, 10);    // �����w��q��10�i����, ����, 16�i�������o��.
    }
}

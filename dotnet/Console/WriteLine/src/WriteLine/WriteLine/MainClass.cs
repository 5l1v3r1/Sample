// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// MainClass�̒�`
class MainClass
{
    // Main���\�b�h�̒�`
    static void Main()
    {
        // �ϐ��̏�����
        bool b = true;      // b��true�ɏ�����.
        char c = 'X';       // c��'X'�ɏ�����.
        int i = 100;        // i��100�ɏ�����.
        float f = 0.25f;    // f��0.25�ɏ�����
        string s = "XYZ";   // s��"XYZ"�ɏ�����.

        // Console.WriteLine()�ł��܂��܂ȏo��.
        Console.WriteLine(false);   // Console.WriteLine��false���o�͂����s.
        Console.WriteLine('A');     // Console.WriteLine��'A'���o�͂����s.
        Console.WriteLine(10);      // Console.WriteLine��10���o�͂����s.
        Console.WriteLine(1.23f);   // Console.WriteLine��1.23f���o�͂����s.
        Console.WriteLine("ABC");   // Console.WriteLine��"ABC"���o�͂����s.
        Console.WriteLine();        // Console.WriteLine�ň����Ȃ��ɂ����, ���s�̂ݍs��.
        Console.WriteLine("b = {0}, c = {1}, i = {2}, f = {3}, s = {4}", b, c, i, f, s);  // Console.WriteLine��b, c, i, f, s�̒l���o�͂����s.
    }
}
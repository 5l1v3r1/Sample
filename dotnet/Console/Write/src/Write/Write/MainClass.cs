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

        // Console.Write()�ł��܂��܂ȏo��.
        Console.Write(false);   // Console.Write��false���o��.
        Console.Write('\n');    // ���s.
        Console.Write('A');     // Console.Write��'A'���o��.
        Console.Write('\n');    // ���s.
        Console.Write(10);      // Console.Write��10���o��.
        Console.Write('\n');    // ���s.
        Console.Write(1.23f);    // Console.Write��1.23f���o��.
        Console.Write('\n');    // ���s.
        Console.Write("ABC");   // Console.Write��"ABC"���o��.
        Console.Write('\n');    // ���s.
        Console.Write("b = {0}, c = {1}, i = {2}, f = {3}, s = {4}\n", b, c, i, f, s);  // Console.Write��b, c, i, f, s�̒l���o��.
    }
}
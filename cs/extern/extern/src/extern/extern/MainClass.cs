// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Runtime.InteropServices;   // COM���݉^�p�ƃv���b�g�t�H�[���Ăяo��(System.Runtime.InteropServices���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // DLL�̃C���|�[�g
    [DllImport("kernel32.dll")] // DllImport��"kernel32.dll"�̃C���|�[�g.
    public static extern bool Beep(uint dwFreq, uint dwDuration);   // WindowsAPI��Beep�̐錾.

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �J�n
        Console.WriteLine("Beep 440Hz Start!"); // "Beep 440Hz Start!"�Əo��.

        // �r�[�v����炷.
        Beep(440, 3000);    // Beep��440Hz�̉���3�b�Ԗ炷.

        // �I��
        Console.WriteLine("Beep 440Hz End!"); // "Beep 440Hz End!"�Əo��.

    }

}
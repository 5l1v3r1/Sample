// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Runtime.InteropServices;   // COM���݉^�p�ƃv���b�g�t�H�[���Ăяo��(System.Runtime.InteropServices���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // DLL�̃C���|�[�g
    [DllImport("user32.dll", CharSet = CharSet.Unicode)] // DllImport��"user32.dll"�̃C���|�[�g.(Charset��Unicode�ɂ���.)
    public static extern int MessageBoxW(IntPtr hWnd, string lpText, string lpCaption, uint Type);   // WindowsAPI��MessageBoxW�̐錾.

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �J�n
        Console.WriteLine("MessageBoxW Start!"); // "MessageBoxW Start!"�Əo��.

        // ���b�Z�[�W�{�b�N�X�̕\��
        MessageBoxW((IntPtr)0, "MessageBoxW", "DllImportAttribute_", 0);    // MessageBoxW��"MessageBoxW"��\��.

        // �I��
        Console.WriteLine("MessageBoxW End!"); // "MessageBoxW End!"�Əo��.

    }

}
// ���O��Ԃ̓o�^
using System;               // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �I�u�W�F�N�g�̐錾
        Swap<int> iSwap = new Swap<int>(); // Swap<int>�I�u�W�F�N�giSwap�𐶐�.
        
        // �l�̑��.
        iSwap.X = 10;   // iSwap.X��10����.
        iSwap.Y = 20;   // iSwap.Y��20����.

        // �X���b�v�O�̒l���o��.
        Console.WriteLine("X = " + iSwap.X + ", Y = " + iSwap.Y);   // Console.WriteLine��iSwap�̊e�l���o��.
        // �X���b�v���s.
        iSwap.DoSwap(); // iSwap.DoSwap�ŃX���b�v�����s.
        // �X���b�v��̒l���o��.
        Console.WriteLine("X = " + iSwap.X + ", Y = " + iSwap.Y);   // Console.WriteLine��iSwap�̊e�l���o��.

        // ���s
        Console.WriteLine();    // Console.WriteLine�ŉ��s.

        // �I�u�W�F�N�g�̐錾
        Swap<string> strSwap = new Swap<string>(); // Swap<string>�I�u�W�F�N�gstrSwap�𐶐�.

        // �l�̑��.
        strSwap.X = "ABC";   // strSwap.X��"ABC"����.
        strSwap.Y = "XYZ";   // strSwap.Y��"XYZ"����.

        // �X���b�v�O�̒l���o��.
        Console.WriteLine("X = " + strSwap.X + ", Y = " + strSwap.Y);   // Console.WriteLine��strSwap�̊e�l���o��.
        // �X���b�v���s.
        strSwap.DoSwap(); // strSwap.DoSwap�ŃX���b�v�����s.
        // �X���b�v��̒l���o��.
        Console.WriteLine("X = " + strSwap.X + ", Y = " + strSwap.Y);   // Console.WriteLine��strSwap�̊e�l���o��.

    }

}
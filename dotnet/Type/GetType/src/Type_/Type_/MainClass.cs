// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ���݂̌^���擾.
        int i = 10; // i��10�ŏ�����.
        Type tint = i.GetType();    // i��Type���擾.
        Console.WriteLine("tint = " + tint);    // i��Type��tint���o��.
        Type t1 = tint.GetType();   // tint�̌��݂�Type�ł���t1���擾.
        Console.WriteLine("t1 = " + t1);    // t1�̏o��.

    }

}
// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ����������N���X
class TestClass // TestClass�N���X�̒�`
{
    // �����o�t�B�[���h�̒�`
    private string str; // string�^�t�B�[���hstr
    public string Str   // str�̐ݒ�Ǝ擾������v���p�e�BStr.
    {
        get
        {
            // str��Ԃ�.
            return str;
        }
        set
        {
            // str��value���i�[.
            str = value;
        }
    }
    private int i;  // int�^�t�B�[���hi
    public int I    // i�̐ݒ�Ǝ擾������v���p�e�BI.
    {
        get
        {
            // i��Ԃ�.
            return i;
        }
        set
        {
            // i��value���i�[.
            i = value;
        }
    }
    // i��str��\��.
    public void Show()
    {
        Console.WriteLine("i = " + i + ", str = " + str);
    }
}
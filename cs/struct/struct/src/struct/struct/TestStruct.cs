// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ����������\����
struct TestStruct // TestStruct�\���̂̒�`
{
    // �����o�t�B�[���h�̒�`
    public string str; // string�^�t�B�[���hstr(�����Ă�����public�ɂ���.)
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
    public int i;  // int�^�t�B�[���hi(�����Ă�����public�ɂ���.)
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
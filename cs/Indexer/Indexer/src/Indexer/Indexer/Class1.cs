// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// Class1�̒�`
class Class1
{
    // �t�B�[���h�̒�`.
    private int size;   // �z��̑傫��size.
    private int[] intArray; // int�^�z��intArray;

    // �R���X�g���N�^�̒�`
    public Class1(int size)
    {
        intArray = new int[size];   // size���̔z���p��.
        this.size = size;   // �����o�ɃZ�b�g.
    }

    // �C���f�N�T�̒�`
    public int this[int index]
    {    // index�Ԗڂ̏���.
        // �擾��.
        get
        {
            if (index < 0)  // index�����̓G���[.
            {
                Console.WriteLine("invalid!(index < 0)");    // "invalid!(index < 0)"���o��.
                return -1;  // -1��Ԃ�.
            }
            else if (index > size - 1)  // index��size - 1���傫���ꍇ���G���[.
            {
                Console.WriteLine("invalid!(index > size - 1)");    // "invalid!(index > size - 1)"���o��.
                return -1;  // -1��Ԃ�.
            }
            else
            {
                return intArray[index]; // intArray��index�Ԗڂ̒l��Ԃ�.
            }
        }
        // �ݒ莞.
        set
        {
            if (index < 0)  // index�����̓G���[.
            {
                Console.WriteLine("invalid!(index < 0)");    // "invalid!(index < 0)"���o��.
            }
            else if (index > size - 1)  // index��size - 1���傫���ꍇ���G���[.
            {
                Console.WriteLine("invalid!(index > size - 1)");    // "invalid!(index > size - 1)"���o��.
            }
            else if (value < 0)  // ���̒l�Ȃ�G���[
            {
                Console.WriteLine("invalid!(value < 0)");    // "invalid!(value < 0)"���o��.
            }
            else // 0�ȏ�Ȃ�l��ݒ�.
            {
                intArray[index] = value;    // intArray��index�Ԗڂ�value���Z�b�g.
            }
        }
    }
}
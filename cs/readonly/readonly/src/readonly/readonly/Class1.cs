// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// Class1�̒�`
class Class1
{

    // �t�B�[���h�̒�`.
    private readonly int size;  // �z��̑傫��int�^�ϐ�size.(readonly�ɂ���.)
    private int[] intArray; // int�^�z��intArray.

    // �R���X�g���N�^�̒�`
    public Class1(int size)
    {
        // ������
        this.size = size;   // this.size��size���Z�b�g.(readonly�̓R���X�g���N�^�ŏ������ł���.)
        intArray = new int[size];   // size���̔z���p��.
    }

    // �z��̏o��
    public void print()
    {
        // ����͕s��.
        //size = 20;  // readonly�Ȃ̂�, ���Ƃ���ύX�s��.

        // �T�C�Y�o��
        Console.WriteLine("size = " + size);    // size���o��.
        
        // �z��ɒl������.
        for (int i = 0; i < size; i++)    // size���J��Ԃ�.
        {
            intArray[i] = i;    // i�Ԗڂ�i������.
        }

        // �z��̕\��
        for (int i = 0; i < size; i++)    // size���J��Ԃ�.
        {
            Console.WriteLine("intArray[" + i + "] = " + intArray[i]); // i�Ԗڂ��o��.
        }
    }

}
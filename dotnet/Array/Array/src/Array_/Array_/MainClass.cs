// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �z��̐錾
        int[] intArray; // int�^�z��intArray.
        
        // �z��̐���.
        intArray = new int[5];  // �v�f��5��int�^�z����쐬.

        // intArray��Array�N���X�̔h���N���X�I�u�W�F�N�g���ǂ����`�F�b�N.
        Console.WriteLine("intArray: " + intArray.GetType().ToString());  // intArray.GetType().ToString())�Ō^�����o��.
        if (intArray is Array)  // is���Z�q��Array�ɃL���X�g�\�����ׂ�.
        {
            Console.WriteLine("intArray is Array!");    // "intArray is Array!"�Əo��.
        }

        // �z��̗v�f�����擾.
        int size = intArray.Length; // �z��̗v�f��intArray.Length��size�Ɋi�[.
        Console.WriteLine("size = " + size);    // size���o��.

    }

}
// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {
        
        // �R���N�V�����̐錾
        TestCollection testCollection;  // TestCollection�^testCollection��p��.

        // testCollection�̐���.
        testCollection = new TestCollection();  // TestCollection�I�u�W�F�N�gtestCollection�𐶐�.

        // foreach��testCollection�̒l���o��.
        foreach (int value in testCollection)   // foreach��testCollection�̒��g�����ׂĎ��o��.
        {

            // value���o��.
            Console.WriteLine("value = " + value);  // Console.WriteLine��value���o��.

        }

    }

}
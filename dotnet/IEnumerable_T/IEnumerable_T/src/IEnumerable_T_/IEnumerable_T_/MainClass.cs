// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �R���N�V�����̐錾
        TestCollection<int> testCollection;  // TestCollection<int>�^testCollection��p��.

        // testCollection�̐���.
        testCollection = new TestCollection<int>(5);  // TestCollection<int>�I�u�W�F�N�gtestCollection�𐶐�.

        // �l�̃Z�b�g
        testCollection.Set(0, 10);
        testCollection.Set(1, 11);
        testCollection.Set(2, 12);
        testCollection.Set(3, 13);
        testCollection.Set(4, 14);

        // foreach��testCollection�̒l���o��.
        foreach (int value in testCollection)   // foreach��testCollection�̒��g�����ׂĎ��o��.
        {

            // value���o��.
            Console.WriteLine("value = " + value);  // Console.WriteLine��value���o��.

        }

    }

}
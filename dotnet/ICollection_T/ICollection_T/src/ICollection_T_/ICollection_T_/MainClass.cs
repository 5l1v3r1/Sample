// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �R���N�V�����̐錾
        TestCollection<string> testCollection;  // TestCollection<string>�^testCollection��p��.

        // testCollection�̐���.
        testCollection = new TestCollection<string>(5); // TestCollection<string>�I�u�W�F�N�gtestCollection�𐶐�.

        // �l�̃Z�b�g.
        testCollection[0] = "A";
        testCollection[1] = "B";
        testCollection[2] = "C";
        testCollection[3] = "D";
        testCollection[4] = "E";

        // foreach��testCollection�̒l���o��.
        foreach (string value in testCollection)   // foreach��testCollection�̒��g�����ׂĎ��o��.
        {

            // value���o��.
            Console.WriteLine("value = " + value);  // Console.WriteLine��value���o��.

        }

        // ��؂���̏o��.
        Console.WriteLine("-----"); // "-----"���o��.

        // �v�f�̒ǉ�.
        testCollection.Add("F");    // "F"��ǉ�.

        // foreach��testCollection�̒l���o��.
        foreach (string value in testCollection)   // foreach��testCollection�̒��g�����ׂĎ��o��.
        {

            // value���o��.
            Console.WriteLine("value = " + value);  // Console.WriteLine��value���o��.

        }

    }

}
// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // TestCollection����.
        TestCollection testCollection = new TestCollection(5);  // �v�f��5��testCollection����.
        Console.WriteLine("Count = " + testCollection.Count);   // Count���o��.
        foreach (int i in testCollection)   // testCollection����l�����o��.
        {
            Console.WriteLine("i = " + i);  // i���o��.
        }
       
    }

}
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
        testCollection = new TestCollection(5);  // TestCollection�I�u�W�F�N�gtestCollection�𐶐�.(�����Ƃ��ėv�f����5���w��.)

        // �l���Z�b�g.
        testCollection[0] = 4;  // testCollection[0]��4���Z�b�g.
        testCollection[1] = 2;  // testCollection[1]��2���Z�b�g.
        testCollection[2] = 1;  // testCollection[2]��1���Z�b�g.
        testCollection[3] = 3;  // testCollection[3]��3���Z�b�g.
        testCollection[4] = 5;  // testCollection[4]��5���Z�b�g.

        // foreach��testCollection�̒l���o��.
        foreach (int value in testCollection)   // foreach��testCollection�̒��g�����ׂĎ��o��.
        {

            // value���o��.
            Console.WriteLine("value = " + value);  // Console.WriteLine��value���o��.

        }

    }

}
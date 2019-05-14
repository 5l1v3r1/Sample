// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// �f���Q�[�g�̒�`.
delegate void TestDelegate();   // �����Ɩ߂�l��void�Ȋ֐������f���Q�[�gTestDelegate.

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �f���Q�[�g�̐���.
        TestDelegate test1 = new TestDelegate(Test1);   // new��TestDelegate��test1�𐶐�.(�R���X�g���N�^�ɂ�Test1��n��.)
        TestDelegate test2 = new TestDelegate(Test2);   // new��TestDelegate��test2�𐶐�.(�R���X�g���N�^�ɂ�Test2��n��.)
        
        // �f���Q�[�g�̎Q�ƂŃR�[���o�b�N���\�b�h���Ă΂��.
        test1();    // test1��"()"��t����ƃR�[���o�b�N���\�b�h��Test1���Ă΂��.

        // ���s
        Console.WriteLine();    // Console.WriteLine()�ŉ��s.

        // �f���Q�[�g�̎Q�ƂŃR�[���o�b�N���\�b�h���Ă΂��.
        test2();    // test2��"()"��t����ƃR�[���o�b�N���\�b�h��Test2���Ă΂��.

        // ���s
        Console.WriteLine();    // Console.WriteLine()�ŉ��s.

        // 3�ڂ̃f���Q�[�g�̏�����.
        TestDelegate test3 = null;  // TestDelegate��test3��null�ŏ�����.

        // �f���Q�[�g�̌���.
        test3 = (TestDelegate)Delegate.Combine(test1, test2);   // test1��test2�̒��g���Ă�TestDelegate��test3.

        // �f���Q�[�g�̎Q�ƂŃR�[���o�b�N���\�b�h���Ă΂��.
        test3();    // test3��"()"��t����ƃR�[���o�b�N���\�b�h��Test1��Test2���Ă΂��.

    }

    // "ABC"�Əo�͂��郁�\�b�hTest1.
    static void Test1()
    {

        // "ABC"�Əo��.
        Console.WriteLine("ABC");   // Console.WriteLine��"ABC"���o��.

    }

    // "DEF"�Əo�͂��郁�\�b�hTest2.
    static void Test2()
    {

        // "DEF"�Əo��.
        Console.WriteLine("DEF");   // Console.WriteLine��"DEF"���o��.

    }

}
// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �I�u�W�F�N�g�̐錾
        TestClass testClass;    // TestClass�I�u�W�F�N�gtestClass�̐錾
        TestStruct testStruct;  // TestStruct�I�u�W�F�N�gtestStruct�̐錾

        // �C���X�^���X�̐���
        testClass = new TestClass();    // TestClass�̃C���X�^���X��testClass�Ɋi�[.(���ۂɂ͎Q�Ƃ��Ă���.)
        
        // �l�̑��.
        testClass.I = 10;       // testClass.I��10����.(�v���p�e�B�o�R��)
        testClass.Str = "A";    // testClass.Str��"A"����.(�v���p�e�B�o�R��)
        testClass.Show();       // testClass.Show��i��str��\��.(���\�b�h���Ăׂ�.)
        
        // �\���̂�new���Ă��Ȃ��ꍇ, �����o�̑����Q�Ƃ݂̂ł���.(���\�b�h��v���p�e�B�̓_��.)
        testStruct.i = 100;     // testStruct.i��100����.
        testStruct.str = "ABC"; // testStruct.str��"ABC"����.
        
        // �\���̂�new�͐����C���X�^���X�̃R�s�[.
        testStruct = new TestStruct();  // testStruct��new TestStruct�͕ʕ��Œ��g���R�s�[�����.
        testStruct.I = 100; // ���g���R�s�[���ꂽ�󋵂��ƃv���p�e�B�o�R��.
        testStruct.Str = "ABC"; // ���g���R�s�[���ꂽ�󋵂��ƃv���p�e�B�o�R��.
        testStruct.Show();  // testStruct.Show��i��str���o��.

        // �N���X�ƍ\���̂����\�b�h�ɓn��, ���Ń����o��ύX.
        ClassStructMethod(testClass, testStruct);   // ClassStructMethod��testClass��testStruct��n��.

        // �Ăу����o��\��
        testClass.Show();   // testClass.Show��i��str��\��.
        testStruct.Show();  // testStruct.Show��i��str���o��.

    }

    // �N���X�ƍ\���̂��󂯎�郁�\�b�h.
    static void ClassStructMethod(TestClass tc, TestStruct ts)
    {

        // �N���X�̒l��ύX.
        tc.I = 20; // tc.I��20���Z�b�g.
        tc.Str = "X"; // tc.Str��"X"���Z�b�g.

        // �\���̂̒l��ύX.
        ts.I = 200; // ts.I��200���Z�b�g.
        ts.Str = "XYZ"; // ts.Str��"XYZ"���Z�b�g.

    }

}
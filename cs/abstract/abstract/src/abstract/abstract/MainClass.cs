// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ���ۃN���X�ϐ��̐錾.
        AbstractClass abstobj;  // ���ۃN���XAbstractClass�̕ϐ�abstobj��錾.

        // �h���N���X�I�u�W�F�N�g�C���X�^���X�̐���.
        abstobj = new DerivedClass(10, "ABC");  // DerivedClass�I�u�W�F�N�g�𐶐�.(�R���X�g���N�^��10��"ABC"���Z�b�g.)

        // �o��.
        abstobj.Output();   // Output�ŏo��.(DerivedClass��Output�ŏo�͂����.)

        // �h�����Ă��Ȃ����\�b�h���Ă�.
        abstobj.Set(20, "XYZ"); // DerivedClass��Set���Ȃ��̂�, ���ۃN���XAbstractClass��Set���Ă΂��.

        // �o��.
        abstobj.Output();   // Output�ŏo��.(DerivedClass��Set���Ȃ��̂�, �l��10, "ABC"�̂܂�.)

    }

}
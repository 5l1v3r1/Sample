// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �I�u�W�F�N�g�̐���.
        BaseClass baseobj = new BaseClass();    // BaseClass�I�u�W�F�N�gbaseobj�𐶐�.
        DerivedClass derivedobj = new DerivedClass();   // DerivedClass�I�u�W�F�N�gderivedobj�𐶐�.

        // �l�̃Z�b�g.
        baseobj.Set(10, "ABC");     // Set���\�b�h��10��"ABC"���Z�b�g.
        derivedobj.Set(20, "XYZ");  // Set���\�b�h��20��"XYZ"���Z�b�g.

        // �l�̏o��.
        baseobj.Output();       // BaseClass��Output�ŏo��.
        derivedobj.Output();    // DerivedClass��Output�ŏo��.

    }

}
// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �I�u�W�F�N�g�̐���.
        BaseClass obj = new DerivedClass1();    // DerivedClass1�I�u�W�F�N�g�𐶐���, BaseClass�̃I�u�W�F�N�g�C���X�^���Xobj�Ɋi�[.

        // ���\�b�h���Ă�ł݂�.
        obj.Output();   // obj.Output���Ă�.

        // is���Z�q�Ŏw��̃N���X���ǂ����𔻒�.(�A�b�v�L���X�g�ł�����N���X���܂�.)
        System.Console.WriteLine("(obj is DerivedClass1) = " + (obj is DerivedClass1)); // (obj is DerivedClass1)�̒l���o��.
        System.Console.WriteLine("(obj is DerivedClass2) = " + (obj is DerivedClass2)); // (obj is DerivedClass2)�̒l���o��.
        System.Console.WriteLine("(obj is BaseClass) = " + (obj is BaseClass)); // (obj is BaseClass)�̒l���o��.

    }

}
// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �h���N���X�̐���
        DerivedClass derived = new DerivedClass();  // DerivedClass�I�u�W�F�N�gderived�𐶐�.
        derived.Output();   // Output�ŏo��.

        derived.Set(10, "ABC"); // BaseClass��Set��10, "ABC"���Z�b�g.
        derived.Output();   // Output�ŏo��.

        int i = derived.GetInt();   // i��derived.GetInt�̖߂�l���i�[.
        System.Console.WriteLine("i = " + i);   // i���o��.
        string str = derived.GetString();    // str��derived.GetString�̖߂�l���i�[.
        System.Console.WriteLine("str = " + str);   // str���o��.

        derived.Add(20);    // derived�̐����l��20�����Z.
        derived.Add("XYZ"); // derived�̕������"XYZ"��A��.
        derived.Output();   // Output�ŏo��.

    }

}
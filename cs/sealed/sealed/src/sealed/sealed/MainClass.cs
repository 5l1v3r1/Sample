// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {
        // Class1�ŏo��.
        Class1 class1 = new Class1();   // Class1�C���X�^���Xclass1�𐶐�.
        class1.Print(); // class1.Print�ŏo��.
        // Class2�ŏo��.
        Class1 obj2 = new Class2();   // Class2�C���X�^���X�𐶐���Class1�I�u�W�F�N�gobj2�Ɋi�[.
        obj2.Print(); // obj2.Print�ŏo��.
        // Class3�ŏo��.
        //Class1 obj3 = new Class3();   // Class3�C���X�^���X�𐶐���Class1�I�u�W�F�N�gobj3�Ɋi�[.
        //obj3.Print(); // obj3.Print�ŏo��.
    }

}
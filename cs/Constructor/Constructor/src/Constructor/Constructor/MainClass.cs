// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �I�u�W�F�N�gclass1a�̐���.
        Class1 class1a = new Class1();	// Class1�I�u�W�F�N�gclass1a�𐶐�.

        // �I�u�W�F�N�g�̎��t�B�[���h�̓��e���o��.
        class1a.Output();	// Output���\�b�h�Ńt�B�[���h�̓��e���o��.

        // �I�u�W�F�N�g�ɒl���Z�b�g.
        class1a.Set(10, "ABC");	// Set���\�b�h��class1a��10��"ABC"���Z�b�g.

        // �I�u�W�F�N�g�̎��t�B�[���h�̓��e���o��.
        class1a.Output();	// Output���\�b�h�Ńt�B�[���h�̓��e���o��.

        // �I�u�W�F�N�gclass1b�̐���.
        Class1 class1b = new Class1(20, "XYZ");	// Class1�I�u�W�F�N�gclass1b�𐶐�.(�����l��20, "XYZ"���Z�b�g.)

        // �I�u�W�F�N�g�̎��t�B�[���h�̓��e���o��.
        class1b.Output();	// Output���\�b�h�Ńt�B�[���h�̓��e���o��.

        // �I�u�W�F�N�g�ɒl���Z�b�g.
        class1b.Set(30, "ZZZ");	// Set���\�b�h��class1b��30��"ZZZ"���Z�b�g.

        // �I�u�W�F�N�g�̎��t�B�[���h�̓��e���o��.
        class1b.Output();	// Output���\�b�h�Ńt�B�[���h�̓��e���o��.

    }
}
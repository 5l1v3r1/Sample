// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using BGST; // �Ǝ��̖��O���BGST

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �I�u�W�F�N�g�̐���.
        BaseClass baseObj = new BaseClass();    // BaseClass�I�u�W�F�N�gbaseObj
        BaseClass baseD1Obj = new DerivedClass1();  // BaseClass�I�u�W�F�N�gbaseD1Obj(DerivedClass1�C���X�^���X)
        BaseClass baseD2Obj = new DerivedClass2();  // BaseClass�I�u�W�F�N�gbaseD2Obj(DerivedClass2�C���X�^���X)

        // GetType��Type�I�u�W�F�N�g�擾.
        Type baseType = baseObj.GetType();  // baseObj.GetType��baseType���擾.
        Type d1Type = baseD1Obj.GetType();  //  baseD1Obj.GetType��d1Type���擾.
        Type d2Type = baseD2Obj.GetType();  //  baseD2Obj.GetType��d2Type���擾.

        // ToString�ŏo��.
        System.Console.WriteLine(baseType.ToString());  // baseType.ToString�̖߂�l���o��.
        System.Console.WriteLine(d1Type.ToString()); // d1Type.ToString�̖߂�l���o��.
        System.Console.WriteLine(d2Type.ToString()); // d2Type.ToString�̖߂�l���o��.

        // ���̂܂܏o��.
        System.Console.WriteLine(baseType);  // baseType�����̂܂܎w�肵�ďo��.
        System.Console.WriteLine(d1Type); // d1Type�����̂܂܎w�肵�ďo��.
        System.Console.WriteLine(d2Type); // d2Type�����̂܂܎w�肵�ďo��.

        // FullName���o��.
        System.Console.WriteLine(baseType.FullName);  // baseType.FullName���o��.
        System.Console.WriteLine(d1Type.FullName); // d1Type.FullName���o��.
        System.Console.WriteLine(d2Type.FullName); // d2Type.FullName���o��.

    }

}
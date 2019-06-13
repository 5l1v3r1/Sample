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

        // typeof�ɂ��^�錾�̎擾.
        Type baseT = typeof(BaseClass); // typeof��BaseClass��Type�^baseT���擾.
        Type baseD1T = typeof(DerivedClass1);   // typeof��DerivedClass1��Type�^baseD1T���擾.
        Type baseD2T = typeof(DerivedClass2);   // typeof��DerivedClass2��Type�^baseD2T���擾.

        // baseType���ǂ�Ɠ���������.
        if (baseType == baseT)
        {
            System.Console.WriteLine("baseType == baseT");
        }
        else if (baseType == baseD1T)
        {
            System.Console.WriteLine("baseType == baseD1T");
        }
        else if (baseType == baseD2T)
        {
            System.Console.WriteLine("baseType == baseD2T");
        }
        // d1Type���ǂ�Ɠ���������.
        if (d1Type == baseT)
        {
            System.Console.WriteLine("d1Type == baseT");
        }
        else if (d1Type == baseD1T)
        {
            System.Console.WriteLine("d1Type == baseD1T");
        }
        else if (d1Type == baseD2T)
        {
            System.Console.WriteLine("d1Type == baseD2T");
        }
        // d2Type���ǂ�Ɠ���������.
        if (d2Type == baseT)
        {
            System.Console.WriteLine("d2Type == baseT");
        }
        else if (d2Type == baseD1T)
        {
            System.Console.WriteLine("d2Type == baseD1T");
        }
        else if (d2Type == baseD2T)
        {
            System.Console.WriteLine("d2Type == baseD2T");
        }

    }

}
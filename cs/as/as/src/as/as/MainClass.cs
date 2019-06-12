// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{
    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �I�u�W�F�N�g�̐���.
        BaseClass obj = new DerivedClass1();    // DerivedClass1�I�u�W�F�N�g�𐶐���, BaseClass�̃I�u�W�F�N�g�C���X�^���Xobj�Ɋi�[.

        // as���Z�q�ŃL���X�g�ł��邩�`�F�b�N.
        BaseClass b = obj as BaseClass; // as��BaseClass�Ƃ��ăL���X�g.
        if (b != null)  // b��null�łȂ��ꍇ.
        {
            System.Console.WriteLine("BaseClass b = obj as BaseClass Success!");    // "BaseClass b = obj as BaseClass Success!"���o��.
        }
        else
        {
            System.Console.WriteLine("b == null!");    // "b == null!"���o��.
        }
        DerivedClass1 d1 = obj as DerivedClass1; // as��DerivedClass1�Ƃ��ăL���X�g.
        if (d1 != null)  // d1��null�łȂ��ꍇ.
        {
            System.Console.WriteLine("DerivedClass1 d1 = obj as DerivedClass1 Success!");    // "DerivedClass1 d1 = obj as DerivedClass1"���o��.
        }
        else
        {
            System.Console.WriteLine("d1 == null!");    // "d1 == null!"���o��.
        }
        DerivedClass2 d2 = obj as DerivedClass2; // as��DerivedClass2�Ƃ��ăL���X�g.
        if (d2 != null)  // d2��null�łȂ��ꍇ.
        {
            System.Console.WriteLine("DerivedClass1 d2 = obj as DerivedClass2 Success!");    // "DerivedClass2 d2 = obj as DerivedClass2"���o��.
        }
        else
        {
            System.Console.WriteLine("d2 == null!");    // "d2 == null!"���o��.
        }

    }

}
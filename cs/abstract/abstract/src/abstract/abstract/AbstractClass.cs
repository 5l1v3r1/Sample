// ���ۃN���X
abstract class AbstractClass    // ���ۃN���XAbstractClass�̒�`
{

    // ���\�b�h�̒�`
    public AbstractClass()  // �R���X�g���N�^
    {
        // �Ƃ肠�������\�b�h���̏o��.
        System.Console.WriteLine("AbstractClass()");    // System.Console.WriteLine�Ń��\�b�h�����o��.
    }

    public AbstractClass(int i, string str) // �R���X�g���N�^(��������)
    {
        // �Ƃ肠�������\�b�h���̏o��.
        System.Console.WriteLine("AbstractClass(int i, string str)");    // System.Console.WriteLine�Ń��\�b�h�����o��.
    }

    virtual public void Set(int i, string str)  // �����l�ƕ�������Z�b�g.
    {
        // �Ƃ肠�������\�b�h���̏o��.
        System.Console.WriteLine("Set(int i, string str)");    // System.Console.WriteLine�Ń��\�b�h�����o��.
    }

    virtual public void Output()    // �o��.
    {
        // �Ƃ肠�������\�b�h���̏o��.
        System.Console.WriteLine("Output()");    // System.Console.WriteLine�Ń��\�b�h�����o��.
    }

}
// �����l�ƕ���������h���N���X
class DerivedClass : AbstractClass // AbstractClass����h������DerivedClass�̒�`
{
    // �t�B�[���h�̒�`
    private int i;  // int�^�t�B�[���hi
    private string str; // string�^�t�B�[���hstr
    
    // ���\�b�h�̒�`
    public DerivedClass() : base()  // �R���X�g���N�^
    {
        // ������.
        this.i = 0; // i��0���Z�b�g.
        this.str = "-"; // str��"-"���Z�b�g.
    }

    public DerivedClass(int i, string str) : base(i, str) // �R���X�g���N�^(��������)
    {
        // �������Z�b�g.
        this.i = i; // this.i��i���Z�b�g.
        this.str = str; // this.str��str���Z�b�g.
    }
    
    override public void Output()    // �o��.
    {
        // i��str�̏o��.
        System.Console.WriteLine("i = " + i + ", str = " + str);    //i��str�̒l���o��.
    }

}
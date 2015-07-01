// �ݒ�ɉ�����, �擾, ���Z���ł���悤�ɂȂ����h���N���X.
class DerivedClass : BaseClass, IGet, IAdd // DerivedClass�N���X�̒�`
{

    // ���\�b�h�̒�`
    // ����������
    public DerivedClass() : base()  // �R���X�g���N�^DerivedClass()�̒�`.(���N���XBaseClass�̃R���X�g���N�^���Ă�.)
    {

    }

    // �����̒l�ɏ�����.
    public DerivedClass(int i, string str) : base(i, str)   //  �R���X�g���N�^DerivedClass(int i, string str)�̒�`.(���N���XBaseClass�̃R���X�g���N�^(i, str)���Ă�.)
    {

    }

    // �e�t�B�[���h���o��.
    override public void Output()    // ���\�b�hOutput�̒�`(���N���XBaseClass��Output���I�[�o�[���C�h.)
    {
        // �t�B�[���h�̒l���o��.
        System.Console.WriteLine("(i, str) = (" + i + ", " + str + ")");    //i��str�̒l���o��.
    }

    // �����l���擾
    public int GetInt() // IGet�C���^�[�t�F�C�X��GetInt���`.
    {
        // i��Ԃ�.
        return i;   // return i��i��Ԃ�.
    }

    // ��������擾
    public string GetString()   // IGet�C���^�[�t�F�C�X��GetString���`.
    {
        // str��Ԃ�.
        return str;  // return str��str��Ԃ�.
    }

    // �����l�̉��Z
    public int Add(int i)  // IAdd�C���^�[�t�F�C�X��Add(int i)���`.
    {
        // i�𑫂�.
        this.i = this.i + i;    // this.i��i�𑫂�.
        return this.i;  // this.i��Ԃ�.
    }

    // ������̘A��
    public string Add(string str)  // IAdd�C���^�[�t�F�C�X��Add(string str)���`.
    {
        // str�𑫂�.
        this.str = this.str + str;  // this.str��str��A��.
        return this.str;    // this.str��Ԃ�.
    }

}
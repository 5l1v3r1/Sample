// �����l�ƕ����������{�N���X
class BaseClass // BaseClass�N���X�̒�`
{

    // �t�B�[���h�̒�`
    protected int i;      // int�^�t�B�[���hi(�h���N���X����A�N�Z�X�ł���悤��protected�ɂ���.)
    protected string str; // string�^�t�B�[���hstri(�h���N���X����A�N�Z�X�ł���悤��protected�ɂ���.)

    // ���\�b�h�̒�`
    // ����������
    public BaseClass()  // �R���X�g���N�^BaseClass()�̒�`
    {
        // ������
        i = 0;      // 0��i�ɃZ�b�g.
        str = "-";  // "-"��str�ɃZ�b�g.
    }

    // ����������(�w��̒l���Z�b�g.)
    public BaseClass(int i, string str)   // �R���X�g���N�^BaseClass(int i, string str)�̒�`
    {
        // �����̒l�ɏ�����.
        this.i = i;         // i��this.i�ɃZ�b�g.
        this.str = str;     // str��this.str�ɃZ�b�g.
    }

    // �����l�ƕ�������t�B�[���h�ɃZ�b�g.
    virtual public void Set(int i, string str)  // ���\�b�hSet�̒�`
    {
        // �������t�B�[���h�ɃZ�b�g.
        this.i = i;     // i��this.i�ɃZ�b�g.
        this.str = str; // str��this.str�ɃZ�b�g.
    }

    // �e�t�B�[���h���o��.
    virtual public void Output()    // ���\�b�hOutput�̒�`
    {
        // �t�B�[���h�̒l���o��.
        System.Console.WriteLine("i = " + i + ", str = " + str);    //i��str�̒l���o��.
    }

}
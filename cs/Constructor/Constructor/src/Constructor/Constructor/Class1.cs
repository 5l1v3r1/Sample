// �����l�ƕ���������N���X
class Class1    // Class1�N���X�̒�`
{

    // �t�B�[���h�̒�`
    private int i;      // int�^�t�B�[���hi
    private string str; // string�^�t�H�[���hstr

    // ���\�b�h�̒�`
    // ����������
    public Class1()    // �R���X�g���N�^Class1()�̒�`
    {
        // ������
        i = 0;	// 0��i�ɃZ�b�g.
        str = "-";	// "-"��str�ɃZ�b�g.
    }

    // ����������(�w��̒l���Z�b�g.)
    public Class1(int n, string s) // �R���X�g���N�^Class1(int n, string s)�̒�`
    {
        // �����̒l�ɏ�����.
        i = n;	// n��i�ɃZ�b�g.
        str = s;	// s��str�ɃZ�b�g.
    }

    // �����l�̕�������t�B�[���h�ɃZ�b�g.
    public void Set(int n, string s)    // ���\�b�hSet�̒�`
    {
        // �������t�B�[���h�ɃZ�b�g.
        i = n;      // n��i�ɃZ�b�g.
        str = s;    // s��str�ɃZ�b�g.
    }

    // �e�t�B�[���h���o��.
    public void Output()    // ���\�b�hOutput�̒�`
    {
        // �t�B�[���h�̒l���o��.
        System.Console.WriteLine("i = " + i + ", str = " + str);    // i��str�̒l���o��.
    }

}
// �����l�ƕ���������N���X
class Class1    // Class1�N���X�̒�`
{

    // �t�B�[���h�̒�`
    private int i;      // int�^�t�B�[���hi
    private string str; // string�^�t�H�[���hstr

    // ���\�b�h�̒�`
    // �����l�ƕ�������t�B�[���h�ɃZ�b�g.
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
// �����l�ƕ���������N���X
class Class1    // Class1�N���X�̒�`
{
    // �v���p�e�B�̒�`
    private int i;  // int�^�t�B�[���hi
    public int I    // int�^�v���p�e�BI
    {
        // �擾���̓���̒�`.
        get // get�̉��̃u���b�N�Ɏ擾�����������.
        {
            // i�̒l��Ԃ�.
            return i;   // return i��i��Ԃ�.
        }
        // �ݒ莞�̓���̒�`.
        set // set�̉��̃u���b�N�ɐݒ莞���������.
        {
            // �ݒ�l�����Ȃ�G���[���b�Z�[�W.
            if (value < 0)  // value < 0�̎�.
            {
                // �G���[
                System.Console.WriteLine("invalid!(i < 0)");    // "invalid!(i < 0)"���o��.
            }
            else
            {
                // �ݒ�l��i�Ɋi�[.
                i = value;  // value��i�Ɋi�[.
            }
        }
    }
    private string str; // string�^�t�B�[���hstr
    public string Str   // string�^�v���p�e�BStr
    {
        // �擾���̓���̒�`.
        get // get�̉��̃u���b�N�Ɏ擾�����������.
        {
            // str�̒l��Ԃ�.
            return str;
        }
        // �ݒ莞�̓���̒�`.
        set // set�̉��̃u���b�N�ɐݒ莞���������.
        {
            // �����񂪋󕶎��Ȃ�G���[���b�Z�[�W.
            if (value == "")   // value == ""�̎�.
            {
                // �G���[
                System.Console.WriteLine("invalid!(str == \"\")");    // "invalid!(str == \"\")"���o��.
            }
            else
            {
                // �ݒ�l��str�Ɋi�[.
                str = value;    // value��str�Ɋi�[.
            }
        }
    }
    // ���\�b�h�̒�`
    // ������
    public Class1() // �R���X�g���N�^Class1()�̒�`
    {
        // ������.
        i = 0;  // i��0�ɃZ�b�g.
        str = "-";  // str��"-"���Z�b�g.
    }
}